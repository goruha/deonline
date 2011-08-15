<?php
/**
 * @file
 * Provide administertooltip handling for comment.module
 */

/**
 * Implements hook_administertooltip_ENTITY_data().
 */
function administertooltip_administertooltip_comment_data($variables=array()) {
  return array(
    'handle' => array(
      'title' => t('edit comment')
    ),
    'header' => array(
      'title' => t('Comment'),
    ),
  );
}

/**
 * Implements hook_administertooltip_ENTITY().
 */
function administertooltip_administertooltip_comment($variables=array()) {
  $items = array();
  $items['info'][] = "comment";
  if (comment_access('edit', $variables['comment'])) {
    $items['links'][] = l(t('Delete comment'), 'comment/delete/'. $variables['comment']->cid, array('query' => drupal_get_destination()));
    $items['links'][] = l(t('Edit comment'), 'comment/edit/'. $variables['comment']->cid, array('query' => drupal_get_destination()));
  }
  if (user_access('post comments') || user_access('post comments without approval')) {
    $items['links'][] = l(t('Reply to this comment'), 'comment/reply/'. $variables['comment']->nid .'/'. $variables['comment']->cid, array('query' => drupal_get_destination()));
  }
  return $items;
}
