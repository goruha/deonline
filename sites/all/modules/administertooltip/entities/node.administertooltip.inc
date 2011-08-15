<?php
/**
 * @file
 * Provide administertooltip handling for node.module
 */

/**
 * Implements hook_administertooltip_ENTITY_data().
 */
function administertooltip_administertooltip_node_data($variables=array()) {
  return array(
    'handle' => array(
      'title' => t('edit node'),
    ),
    'header' => array(
      'title' => t('Node: @title', array('@title' => $variables['title'])),
    ),
  );
}

/**
 * Implements hook_administertooltip_ENTITY_AREA().
 */
function administertooltip_administertooltip_node_links($variables=array()) {
  global $user, $theme_key;
  $items = array();

  if (user_access('edit any '. $variables['type'] .' content') ||
    (user_access('edit own '. $variables['type'] .' content') && $variables['uid'] == $user->uid)) {
    $items[] = l(t('Edit node'),
      'node/'. $variables['nid'] .'/edit',
      array('query' => drupal_get_destination()));
  }
  if (user_access('administer content types')) {
    $node_type = node_get_types('type', $variables['type'], FALSE);

    $items[] = l(t('Edit content-type "@name"', array('@name' => drupal_ucfirst($node_type->name))),
      'admin/content/node-type/'. $variables['type'],
      array('query' => drupal_get_destination()));

    if (module_exists('content')) {
      $items[] = l(t('Manage fields "@name"', array('@name' => drupal_ucfirst($node_type->name))),
        'admin/content/node-type/'. $variables['type'] .'/fields',
        array('query' => drupal_get_destination()));
    }
  }
  if (user_access('administer site configuration')) {
    $items[] = l(t('Manage page elements'),
      'admin/build/themes/settings/'. $theme_key,
      array('query' => drupal_get_destination()));
  }
  if (module_exists('devel') && user_access('access devel information')) {
    $items[] = l(t('Dev load'), 'node/'. $variables['nid'] .'/devel/load');
    $items[] = l(t('Dev render'), 'node/'. $variables['nid'] .'/devel/render');
  }
  return $items;
}

/**
 * Implements hook_administertooltip_ENTITY_AREA().
 * @warning: Note the "administertooltip_get_form" function.
 */
function administertooltip_administertooltip_node_actions($variables=array()) {
  global $user;
  $items = array();

  if (user_access('edit any '. $variables['type'] .' content') ||
    (user_access('edit own '. $variables['type'] .' content') && $variables['uid'] == $user->uid)) {
    $items[] = administertooltip_get_form('administertooltip_node_form', $variables['nid']);
  }
  return $items;
}

/**
 * Simple single-button form to (un)publish a node within a administertooltip tip.
 */
function administertooltip_node_form($form_state, $nid) {
  $form = array();
  if ($node = node_load($nid)) {
    $form['setstatus'] = array(
      '#type' => 'submit',
      '#value' => ($node->status==1 ? t('Set unpublished') : t('Set published')),
    );
    $form['nid'] = array('#type' => 'hidden', '#value' => $nid);
    $form['status'] = array('#type' => 'hidden', '#value' => $node->status);
    $form['#redirect'] = drupal_get_path_alias($_GET['q']);
  }
  return $form;
}

/**
 * Submit handler for (un)publishing a node.
 */
function administertooltip_node_form_submit($form, &$form_state) {
  if ($node = node_load($form_state['values']['nid'])) {
    $node->status = ($form_state['values']['status'] == 1 ? 0 : 1);
    node_save($node);
    drupal_set_message(t('Your form has been saved.'));
  }
}
