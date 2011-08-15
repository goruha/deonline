<?php
/**
 * @file
 * Provide administertooltip settings.
 */

function administertooltip_admin_settings() {
  $entities = _administertooltip_get_entities();
  $form = array();

  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General administer tool tip settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['general']['administertooltip_dragndrop'] = array(
    '#type' => 'radios',
    '#title' => t('Drag and drop blocks (experimental)'),
    '#description' => t('Enable or disable the dragging and saving of block-positions.'),
    '#options' => array(1 => t('on'), 0 => t('off')),
    '#default_value' => variable_get('administertooltip_dragndrop', 0),
  );

  $form['entities'] = array(
    '#type' => 'fieldset',
    '#title' => t('Entities settings'),
    '#description' => t('Select the entities where a administer tool tip should appear on.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  foreach ($entities as $entity => $array) {
    $form['entities']['administertooltip_'. $entity .'_enabled'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable administer tool tips for %entity', array('%entity' => $entity)),
      '#default_value' => variable_get('administertooltip_'. $entity .'_enabled', 1),
    );
  }

  $form['types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Node content type settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['types']['administertooltip_content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types'),
    '#description' => t('Select the content types where a node administer tool tip should appear on.'),
    '#options' => node_get_types('names'),
    '#default_value' => variable_get('administertooltip_content_types', array_keys(node_get_types('names'))),
  );
  $display_options = array(
    'both' => 'Both',
    'teaser' => 'Teaser only',
    'full' => 'Full page only',
    'none' => 'None',
  );
  $form['types']['administertooltip_display_options'] = array(
    '#type' => 'radios',
    '#title' => t('Display options'),
    '#description' => t('Choose which display modes the node administer tool tip should be displayed on.'),
    '#options' => $display_options,
    '#default_value' => variable_get('administertooltip_display_options', 'both'),
  );
  return system_settings_form($form);
}
