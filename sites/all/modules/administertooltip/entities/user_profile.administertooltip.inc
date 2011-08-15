<?php
/**
 * @file
 * Provide administertooltip handling for user.module
 */

/**
 * Implements hook_administertooltip_ENTITY_data().
 */
function administertooltip_administertooltip_user_link_data($variables=array()) {
  return array(
    'handle' => array(
      'title' => t('edit user'),
    ),
    'header' => array(
      'title' => t('User'),
    ),
  );
}

/**
 * Implements hook_administertooltip_ENTITY().
 */
function administertooltip_administertooltip_user_profile($variables=array()) {
  $items = array();
  if (user_access('administer users')) {
    $items['links'][] = l(t("Edit user's profile"),
      'user/'. $variables['account']->uid .'/edit',
      array('query' => drupal_get_destination()));
  }
  return $items;
}

/**
 * Implements hook_administertooltip_ENTITY().
 */
function administertooltip_administertooltip_user_link($variables=array()) {
  $items = array();
  if (user_access('administer users')) {
    $items['links'][] = l(t("Edit user"),
      'user/'. $variables['node']->uid .'/edit',
      array('query' => drupal_get_destination()));
    $items['links'][] = l(t("Edit user's picture"),
      'user/'. $variables['node']->uid .'/edit',
      array('query' => drupal_get_destination()));
  }
  return $items;
}

/**
 * Implements hook_administertooltip_ENTITY().
 */
function administertooltip_administertooltip_user_picture($variables=array()) {
  $items = array();
  if (user_access('administer users')) {
    $items['links'][] = l(t("Edit user's picture"),
      'user/'. $variables['account']->uid .'/edit',
      array('query' => drupal_get_destination()));
  }
  return $items;
}
