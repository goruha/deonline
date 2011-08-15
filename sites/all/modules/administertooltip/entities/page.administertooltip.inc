<?php
/**
 * @file
 * Provide administertooltip handling for page.module
 */

/**
 * Implements hook_administertooltip_ENTITY().
 */
function administertooltip_administertooltip_mission($variables=array()) {
  $items = array();
  if (user_access('administer site configuration')) {
    $items['info'][] = l(t("Edit mission"), 'admin/settings/site-information', array('query' => drupal_get_destination()));
  }
  return $items;
}

/**
 * Implements hook_administertooltip_ENTITY().
 */
function administertooltip_administertooltip_breadcrumb($variables=array()) {
  $items = array();
  return $items;
}

/**
 * Implements hook_administertooltip_ENTITY().
 */
function administertooltip_administertooltip_header($variables=array()) {
  $items = array();
  return $items;
}

/**
 * Implements hook_administertooltip_ENTITY().
 */
function administertooltip_administertooltip_footer_message($variables=array()) {
  $items = array();
  if (user_access('administer site configuration')) {
    $items['info'][] = l(t("Edit footer message"), 'admin/settings/site-information', array('query' => drupal_get_destination()));
  }
  return $items;
}

/**
 * Implements hook_administertooltip_ENTITY().
 */
function administertooltip_administertooltip_search_box($variables=array()) {
  $items = array();
  return $items;
}
