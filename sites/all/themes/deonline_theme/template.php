<?php
/**
 * Created by JetBrains PhpStorm.
 * User: goruha
 * Date: 7/28/11
 * Time: 10:21 PM
 * To change this template use File | Settings | File Templates.
 */

function deonline_theme_preprocess_views_view_table__levels(&$vars) {
  $vars['real_rows'] = array();
  $cols = array();
  foreach ($vars['rows'] as $item) {
    $temp = array();
    if ($add_first_col = !in_array($item['name'], $cols)) {
      $cols[] = $item['name'];
    }
    foreach ($item as $field_name => $field) {
      if ($field_name == 'name') {
        if ($add_first_col) {
          $temp[$field_name]['value'] = $field;
          $temp[$field_name]['attributes'] = array('rowspan' => 2);
        }
      }
      elseif($field_name != 'field_level_description_value') {
        $temp[$field_name]['value'] = $field;
        $temp[$field_name]['attributes'] = array('title' => $item['field_level_description_value'], );
      }
    }
    $vars['real_rows'][] = $temp;
  }
}

function deonline_theme_preprocess_views_view_unformatted__program_types__default(&$vars) {
  drupal_add_js($vars['directory'] .'/js/programms.js');
  $vars['image'] = theme_image($vars['directory'] .'/images/gruen_100.png', '', '', array('id' => 'gruen-image'));
  $count = count($vars['rows']);
  foreach($vars['rows'] as $id => $row) {
    $weight = 8 - $count + $id;
    $vars['classes'][$id] .=  " clear grid16-$weight ";
  }
}

/**
 * Override or insert PHPTemplate variables into the templates.
 */
function deonline_theme_preprocess_page(&$vars) {

}

/**
 * Override or insert PHPTemplate variables into the templates.
 */
function deonline_theme_preprocess_node(&$vars) {
  $template = array();
  $template[] = 'node';
  $template[] = $vars['type'];
  $template[] = $vars['page'] ? 'full' : 'teaser';
  $vars['template_files'][] = implode('-', $template);

  if ($vars['type'] == 'program_types') {
    if (user_is_logged_in()) {
      $nid = $vars['nid'];
      $vars['subscribe_link'] = l(t('Записаться'), 'node/add/course-request', array('query' => array('edit[group_cr_info][field_cr_course][nid][nid]' => $nid)));
    }
    else {
      $nid = $vars['nid'];
      $link = url('node/add/course-request', array('query' => array('edit[group_cr_info][field_cr_course][nid][nid]' => $nid)));
      $vars['subscribe_link'] = l(t('Записаться'), 'user/register', array('query' => array('destination' => $link)));
    }
  }
}

function deonline_theme_preprocess_user_profile(&$vars) {
  $account = $vars['account'];
  if (in_array('teacher', $account->roles)) {
    $vars['template_files'][] = 'user-profile-teacher';
  }
}

function deonline_theme_preprocess_views_view_fields__meta_quiz_steps__default(&$vars) {
  global $user;
  $nid = $vars['fields']['field_meta_quiz_quiz_nid']->raw;
  $quiz = node_load($nid);
  $quiz_passed = quiz_is_passed($user->uid, $quiz->nid, $quiz->vid);
  $vars['image'] = $quiz_passed ? $vars['fields']['field_meta_quiz_image_passed_fid']->content : $vars['fields']['field_meta_quiz_image_fid']->content;
}