<?php
/**
 * Created by JetBrains PhpStorm.
 * User: goruha
 * Date: 7/28/11
 * Time: 10:21 PM
 * To change this template use File | Settings | File Templates.
 */

function deonline_theme_preprocess_views_view_table__levels__page_1(&$vars) {
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