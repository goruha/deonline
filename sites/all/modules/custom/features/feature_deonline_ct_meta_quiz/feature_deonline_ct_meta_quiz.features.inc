<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function feature_deonline_ct_meta_quiz_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function feature_deonline_ct_meta_quiz_node_info() {
  $items = array(
    'meta_quiz' => array(
      'name' => t('Meta quiz'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
