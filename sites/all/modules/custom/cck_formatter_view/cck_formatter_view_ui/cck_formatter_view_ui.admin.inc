<?php

function cck_formatter_view_ui_list() {
  $list = cck_formatter_view_load_all();
  $types = cck_formatter_view_types($with_names = TRUE);
  $header = array(t('Label'), t('Name'), t('Type'), t('Actions'));
  $rows = array();
  foreach ($list as $formatter) {
    $row = array();
    $row[] = $formatter->label;
    $row[] = $formatter->name;    
    $row[] = $types[$formatter->type];
    $links = array();
    $links[] = l(t('Edit'), "admin/content/formatters/views/edit/$formatter->id");
    $links[] = l(t('Delete'), "admin/content/formatters/views/delete/$formatter->id");
    $row[] = implode('&nbsp;&nbsp;&nbsp;&nbsp;', $links);;
    $rows[] = $row;
  }    
  return theme('table', $header, $rows);
}

function cck_formatter_view_ui_add($type) {
  $formatter = new stdClass();
  $formatter->type = $type;
  $formatter->field_types = array();
  return drupal_get_form('cck_formatter_view_ui_form', $formatter);
}

function cck_formatter_view_ui_edit($id) {
  $formatter = cck_formatter_view_load($id);
  return drupal_get_form('cck_formatter_view_ui_form', $formatter);
}

function cck_formatter_view_ui_delete($form_state, $id) {
  $formatter = cck_formatter_view_load($id);
  $form = array();
  $form['id'] = array('#type' => 'value', '#value' => $formatter->id);
  return confirm_form(
    $form,
    t('Are you sure you want to delete the formatter %preset?',
      array('%preset' => $formatter->label)
    ),
    'admin/content/formatters/views/list',
    t('This action cannot be undone.'),
    t('Delete'),  t('Cancel')
  );
}

function cck_formatter_view_ui_delete_submit($form, &$form_state) {
  $id = $form_state['values']['id'];
  $formatter = cck_formatter_view_load($id);
  cck_formatter_view_delete($id);
  drupal_set_message(t('Formatter %name (ID: @id) was deleted.', array('%name' => $formatter->label, '@id' => $formatter->name)));
  $form_state['redirect'] = 'admin/content/formatters/views/list';
}


function cck_formatter_view_ui_form($form_state, $formatter) {
  $form = array();
  $form['#redirect'] = 'admin/content/formatters/views/list';

  $locked = isset($formatter->id);

  $form['id'] = array(
      '#type' => 'value',
      '#value' => isset($formatter->id) ? $formatter->id : 0,
  );  
  
  $form['identity'] = array(
    '#type' => 'fieldset',
    '#title' => t('Identification'),
  );

  $form['identity']['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $formatter->label,
    '#description' => t('The human-readable name of this formatter. This name must be unique.'),
    '#required' => TRUE,
  );

  if (!$locked) {
    $form['identity']['name'] = array(
      '#title' => t('Name'),
      '#type' => 'textfield',
      '#default_value' => $formatter->name,
      '#maxlength' => 32,
      '#required' => TRUE,
      '#description' => t('The machine-readable name of this formatter. This name must be unique.'),
    );
  }
  else {
    $form['identity']['name'] = array(
      '#type' => 'value',
      '#value' => $formatter->name,
    );
    $form['identity']['name_display'] = array(
      '#title' => t('Name'),
      '#type' => 'item',
      '#value' => theme('placeholder', $formatter->name),
      '#description' => t('The machine-readable name of this formatter. This name must be unique.'),
    );
  }

  $avaliable_fields_types = cck_formatter_view_avaliable_fields_types($formatter->type, $with_names = TRUE);

  $form['field_types'] = array(
      '#title' => t('Field types'),
      '#type' => 'select',
      '#default_value' => $formatter->field_types,
      '#options' => $avaliable_fields_types,
      '#required' => TRUE,
      '#multiple' => TRUE,
      '#description' => t('Select list of cck field type this formatter will be used for'),
  );

  $views_list = array();
  $views = views_get_all_views();
  foreach ($views as $view) {
    $views_list[$view->name] = array();
    foreach ($view->display as $display) {
      $views_list[$view->name][$view->name .'|'. $display->id] = $view->name .' - '. $display->display_title;
    }
  }

  $form['view'] = array(
      '#title' => t('View'),
      '#type' => 'select',
      '#default_value' => $formatter->view .'|'. $formatter->display,
      '#options' => $views_list,
      '#required' => TRUE,
      '#description' => t('Select view to use in this formatter.'),
  );

  if ($formatter->type == CCK_FORMATTER_VIEW_MULTIPLE) {
    $form['options'] = array(
      '#type' => 'fieldset',
      '#title' => t('Options'),
      '#tree' => TRUE,
    );

    $form['options']['multiple_operation'] = array(
      '#title' => t('Operation for multiple values'),
      '#type' => 'radios',
      '#default_value' => $formatter->options['multiple_operation'],
      '#options' => array('+' => t('AND'), ',' => t('OR')),
      '#required' => TRUE,
      '#description' => t('Operation will be used for multiple values to merge.'),
    );
  }
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

function cck_formatter_view_ui_form_validate($form, &$form_state) {
  $sql = "SELECT id FROM {cck_formatter_views_formatters} WHERE %s = '%s'";
  $result = db_result(db_query($sql, 'label', $form_state['values']['label']));
  if ($result && $result != $form['#parameters'][2]->id) {
    form_set_error('label', t('Label field should be unique.'));
  }
  
  $result = db_result(db_query($sql, 'name', $form_state['values']['name']));
  if ($result && $result != $form['#parameters'][2]->id) {
    form_set_error('name', t('Name field should be unique.'));
  }  
}

function cck_formatter_view_ui_form_submit($form, &$form_state) {
  $formatter = $form['#parameters'][2];
  $formatter->id = $form_state['values']['id'];
  $formatter->label = $form_state['values']['label'];
  $formatter->name = $form_state['values']['name'];
  $formatter->field_types = $form_state['values']['field_types'];
  $view_info = explode('|', $form_state['values']['view']);
  $formatter->view = $view_info[0];
  $formatter->display = $view_info[1];
  $formatter->options = $form_state['values']['options'];
  cck_formatter_view_save($formatter);
}