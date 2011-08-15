<?php
/**
 * @file
 * Provide administertooltip handling for views.module
 */

/**
 * Implements hook_administertooltip_ENTITY_data().
 */
function administertooltip_administertooltip_views_view_data($variables=array()) {
  return array(
    'handle' => array(
      'title' => t('edit view'),
    ),
    'header' => array(
      'title' => t('View: @name', array('@name' => $variables['view']->name)),
    ),
  );
}

/**
 * Implements hook_administertooltip_ENTITY().
 */
function administertooltip_administertooltip_views_view($variables=array()) {
  $items = array();
  if (user_access('administer views')) {
    $items['links'][] = l(t("Edit view"),
      'admin/build/views/edit/'. $variables['view']->name,
      array('query' => drupal_get_destination()));
    $items['links'][] = l(t("Export view"),
      'admin/build/views/export/'. $variables['view']->name,
      array('query' => drupal_get_destination()));
    $items['links'][] = l(t("Clone view"),
      'admin/build/views/clone/'. $variables['view']->name,
      array('query' => drupal_get_destination()));
    $items['links'][] = l(t("Delete view"),
      'admin/build/views/delete/'. $variables['view']->name,
      array('query' => drupal_get_destination()));
  }
  return $items;
}