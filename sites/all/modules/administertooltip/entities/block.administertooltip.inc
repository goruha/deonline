<?php
/**
 * @file
 * Provide administertooltip handling for block.module.
 */

/**
 * Implements hook_administertooltip_ENTITY_data().
 */
function administertooltip_administertooltip_block_data($variables=array()) {
  return array(
    'handle' => array(
      'title' => t('edit block'),
    ),
    'header' => array(
      'title' => t('Block: @subject', array('@subject' => $variables['block']->subject)),
    ),
    'footer' => array(
       'description' => '',
    ),
  );
}

/**
 * Implements hook_administertooltip_ENTITY_AREA().
 */
function administertooltip_administertooltip_block_links($variables=array()) {

  $admin_links = array();

  // Link to block admin page;
  if (user_access('administer blocks')) {
    $admin_links[] = l(t('Administer blocks'),
      'admin/build/block/',
      array('query' => drupal_get_destination()));

    $admin_links[] = l(t('Block settings'),
      'admin/build/block/configure/'. $variables['block']->module .'/'. $variables['block']->delta,
      array('query' => drupal_get_destination()));
  }

  // Link to menu:
  if (user_access('administer menu') && $variables['block']->module == 'menu') {
    $menu_name =  $variables['block']->delta;
    $admin_links[] = l(t('Edit menu "@subject"', array('@subject' => $variables['block']->subject)),
      'admin/build/menu-customize/' . $menu_name,
      array('query' => drupal_get_destination()));
  }

  // Link to view:
  if ($variables['block']->module == 'views' && user_access('administer views')) {
    // get the views data and link directly to the displayed block...
    $view_bits = explode('-', $variables['block']->delta);
    $view = views_get_view($view_bits[0]);
    $view_display = preg_replace('/' . $view->name . '-' . '/', '', $variables['block']->delta);
    $admin_links[] = l(t('Edit view @name', array('@name' => $view->name)),
      'admin/build/views/edit/' . $view->name,
      array('fragment' => 'views-tab-' . $view_display, 'query' => drupal_get_destination()));
  }

  // General module settings...
  if (user_access('access administration pages')) {
    // check if there is a link to the modules settings...
    $test_url = menu_get_item('admin/settings/'. $variables['block']->module);
    if ($test_url['access'] && $test_url['path'] == 'admin/settings/'. $variables['block']->module) {
      $admin_links[] = l(t('Module settings @module',  array('@module' => $variables['block']->module)),
        'admin/settings/'. $variables['block']->module);
    }
  }

  return $admin_links;
}

/**
 * Implements hook_administertooltip_ENTITY_AREA().
 * @warning: Note the "administertooltip_get_form" function.
 */
function administertooltip_administertooltip_block_actions($variables=array()) {
  $items = array();
  if (user_access('administer blocks')) {
    $items[] = administertooltip_get_form('administertooltip_block_hide_form', $variables['block']);
    $dragndrop = variable_get('administertooltip_dragndrop', FALSE);
    if (!$dragndrop || !user_access('drag and drop blocks')) {
      $items[] = administertooltip_get_form('administertooltip_block_region_form', $variables['block']);
      $items[] = administertooltip_get_form('administertooltip_block_weight_form', $variables['block']);
    }
  }
  return $items;
}

/**
 * Implements hook_form().
 */
function administertooltip_block_hide_form($form_state, $block) {

  $key = $block->module .'_'. $block->delta .'2';
  $edit = db_fetch_array(db_query("SELECT pages, visibility, custom, title FROM {blocks} WHERE module = '%s' AND delta = '%s'", $block->module, $block->delta));
  if ($edit['visibility'] != 0) return array();

  $form = array(
    '#tree' => TRUE,
    '#submit' => array('administertooltip_block_form_submit'),
    '#redirect' => drupal_get_path_alias($_GET['q']),
  );
  $form['hide'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide on this page'),
    '#default_value' => 0,
  );
  $form['pages'] = array(
    '#type' => 'value',
    '#value' => $edit['pages'],
  );
  $form['module'] = array(
    '#type' => 'value',
    '#value' => $block->module,
  );
  $form['delta'] = array(
    '#type' => 'value',
    '#value' => $block->delta,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('submit'),
  );
  return $form;
}

/**
 * Implements hook_form().
 */
function administertooltip_block_region_form($form_state, $block) {
  global $theme_key;

  $key = $block->module .'_'. $block->delta .'1';

  $form = array(
    '#tree' => TRUE,
    '#submit' => array('administertooltip_block_form_submit'),
    '#redirect' => drupal_get_path_alias($_GET['q']),
  );
  $form[$key]['region'] = array(
    '#type' => 'select',
    '#title' => t('Change position'),
    '#default_value' => $block->region,
    '#options' => system_region_list($theme_key)
  );
  $form[$key]['module'] = array(
    '#type' => 'value',
    '#value' => $block->module,
  );
  $form[$key]['delta'] = array(
    '#type' => 'value',
    '#value' => $block->delta,
  );
  $form[$key]['theme'] = array(
    '#type' => 'hidden',
    '#value' => $theme_key
  );
  $form[$key]['weight'] = array(
    '#type' => 'value',
    '#value' => $block->weight,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('submit'),
  );
  return $form;
}

/**
 * Implements hook_form_submit().
 */
function administertooltip_block_form_submit($form, &$form_state) {
  if ($form_state['values']['hide'] == 1) {
    // Use "<front>" when the current page is the front page.
    if (drupal_is_front_page() && strstr('<front>', $_GET['q']) === FALSE) {
      $form_state['values']['pages'] .= PHP_EOL .'<front>';
    }
    elseif (strstr($form_state['values']['pages'], $_GET['q']) === FALSE) {
      $form_state['values']['pages'] .= PHP_EOL . $_GET['q'];
    }
    db_query("UPDATE {blocks} SET  pages = '%s' WHERE module = '%s' AND delta = '%s'", trim($form_state['values']['pages']), $form_state['values']['module'], $form_state['values']['delta']);
  }
  unset($form_state['values']['hide'], $form_state['values']['pages'], $form_state['values']['module'], $form_state['values']['delta']);
  module_load_include('inc', 'block', 'block.admin');
  block_admin_display_form_submit($form, $form_state);
}

/**
 * Define the weight block form.
 */
function administertooltip_block_weight_form($form_state, $block) {
  global $theme_key;

  $key = $block->module .'_'. $block->delta .'3';

  // Get all blocks in this region for this user.
  $blocks_in_region = block_list($block->region);

  // Find out if the current block is the last or first one in this region.
  $l_block = array_pop($blocks_in_region);
  $f_block = array_shift($blocks_in_region);
  $is_last = ($block->module . $block->delta == $l_block->module . $l_block->delta ? TRUE : FALSE);
  $is_first = ($block->module . $block->delta == $f_block->module . $f_block->delta ? TRUE : FALSE);

  // Start.
  $form = array(
    '#tree' => TRUE,
    '#submit' => array('administertooltip_block_weight_form_submit'),
    '#redirect' => drupal_get_path_alias($_GET['q']),
  );

  $form[$key]['bid'] = array(
    '#type' => 'value',
    '#value' => $block->bid,
  );

  $form[$key]['module'] = array(
    '#type' => 'value',
    '#value' => $block->module,
  );

  $form[$key]['delta'] = array(
    '#type' => 'value',
    '#value' => $block->delta,
  );

  $form[$key]['region'] = array(
    '#type' => 'value',
    '#value' => $block->region,
  );

  $form[$key]['theme'] = array(
    '#type' => 'value',
    '#value' => $theme_key,
  );

  $form[$key]['buttons'] = array(
    '#prefix' => '<div style="clear:both;">',
    '#suffix' => '</div>',
  );
  if (!$is_last) {
    $form[$key]['buttons']['submit_up'] = array(
      '#type' => 'submit',
      '#value' => t('Down'),
    );
  }
  if (!$is_first) {
    $form[$key]['buttons']['submit_down'] = array(
      '#type' => 'submit',
      '#value' => t('Up'),
    );
  }

  return $form;
}

/**
 * Submit function of administertooltip_block_weight_form_submit.
 */
function administertooltip_block_weight_form_submit($form, &$form_state) {
  $blocks = array();
  foreach ($form_state['values'] as $k => $data) {
    if (is_array($data) && !empty($data['bid'])) {
      $block_id = $data['bid'];

      // Get minimum weight id for the region.
      $max_wid = db_result(db_query("SELECT MIN(weight) AS max FROM {blocks}
        WHERE region='%s' AND theme='%s' ORDER BY weight ASC", $data['region'], $data['theme']));

      // Get all blocks for the region.
      $result = db_query("SELECT * FROM {blocks} WHERE region='%s' AND theme='%s' ORDER BY weight ASC", $data['region'], $data['theme']);
      while ($block = db_fetch_object($result)) {
        $blocks[$block->bid] = $max_wid;

        // Update blocks.
        db_query("UPDATE {blocks} SET weight ='%s' WHERE bid=%d", $max_wid, $block->bid);
        $max_wid++;
      }
    }
  }

  if ($form_state['values']['op'] == t('Up') || $form_state['values']['op'] == t('Down')) {
    $message_down = FALSE;
    $message_up = FALSE;
    $weight_up = $blocks[$block_id] - 1;
    $p = 0;
    foreach ($blocks as $bid => $val) {
      // Move the block to higher position.
      if ($form_state['values']['op'] == t('Up')) {
        if ($block_id == $bid) {
          $val -= 1;
        }
        elseif ($weight_up == $val) {
          $val += 1;
        }

        // Report about the layout change.
        if (!$message_up) {
          $message_up = TRUE;
          drupal_set_message(t('The block moved one position up.'), 'info');
        }
      }

      // Move the block to lower position.
      if ($form_state['values']['op'] == t('Down')) {
        if ($block_id == $bid) {
          $val += 1;
          $p = 1;
        }
        if ($p == 1 && $block_id != $bid) {
          $val -=1;
          $p = 0;
        }

        // Report about the layout change.
        if (!$message_down) {
          $message_down = TRUE;
          drupal_set_message(t('The block moved one position down.'), 'info');
        }
      }

      // Update the block.
      db_query("UPDATE {blocks} SET weight ='%s' WHERE bid=%d", $val, $bid);
    }
  }
  cache_clear_all();
}

/**
 * Ajax-call to update the weight and region of a block.
 */
function _administertooltip_update_block() {
  global $theme_key;
  if (!empty($_GET['blocks']) && !empty($_GET['region'])) {
    // Various modules may change the theme depending on request.
    init_theme();
    $blocks = explode(";", $_GET['blocks']);
    $region = check_plain($_GET['region']);

    // Get minimum weight id for the region.
    $max_wid = db_result(db_query("SELECT MIN(weight) AS max FROM {blocks}
      WHERE region='%s' AND theme='%s' ORDER BY weight ASC", $region, $theme_key));

    // There could be empty entries in the array, so we count in a different variable.
    $c = $max_wid;
    foreach ($blocks as $name) {
      if (!empty($name)) {
        // Update the block according to its new info.
        list($module, $delta) = explode(":", $name);
        $module = str_replace("attdrgr_", "", $module);
        $bid = db_result(db_query("SELECT bid FROM {blocks} WHERE module='%s' AND delta='%s' AND theme='%s'", $module, $delta, $theme_key));
        if ($bid) {
          db_query("UPDATE {blocks} SET weight=%d, region='%s' WHERE bid=%d", $c, $region, $bid);
        }
        else {
          return t("Unable to find block!");
        }
        $c++;
      }
    }
  }
  return "ok";
}
