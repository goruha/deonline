<?php

/**
 * Implementation of hook_views_default_views().
 */
function feature_deonline_ct_meta_quiz_views_default_views() {
  $views = array();

  // Exported view: meta_quiz_steps
  $view = new view;
  $view->name = 'meta_quiz_steps';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 3.0-alpha1;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Icon (field_meta_quiz_image) */
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['id'] = 'field_meta_quiz_image_fid';
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['table'] = 'node_data_field_meta_quiz_image';
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['field'] = 'field_meta_quiz_image_fid';
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['format'] = '135x135_default';
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['multiple']['group'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Field: Content: Icon passed (field_meta_quiz_image_passed) */
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['id'] = 'field_meta_quiz_image_passed_fid';
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['table'] = 'node_data_field_meta_quiz_image_passed';
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['field'] = 'field_meta_quiz_image_passed_fid';
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['format'] = '135x135_default';
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['multiple']['group'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_image_passed_fid']['multiple']['multiple_reversed'] = 0;
  /* Field: Content: Quiz (field_meta_quiz_quiz) */
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['id'] = 'field_meta_quiz_quiz_nid';
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['table'] = 'node_data_field_meta_quiz_quiz';
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['field'] = 'field_meta_quiz_quiz_nid';
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['format'] = 'plain';
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['multiple']['group'] = 0;
  $handler->display->display_options['fields']['field_meta_quiz_quiz_nid']['multiple']['multiple_reversed'] = 0;
  /* Sort criterion: Content: Quiz (field_meta_quiz_quiz) - delta */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'node_data_field_meta_quiz_quiz';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'meta_quiz' => 'meta_quiz',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter: Content multigroup: Quiz multigroup in Meta quiz */
  $handler->display->display_options['filters']['multigroup_meta_quiz_group_meta_quiz_quiz']['id'] = 'multigroup_meta_quiz_group_meta_quiz_quiz';
  $handler->display->display_options['filters']['multigroup_meta_quiz_group_meta_quiz_quiz']['table'] = 'node';
  $handler->display->display_options['filters']['multigroup_meta_quiz_group_meta_quiz_quiz']['field'] = 'multigroup_meta_quiz_group_meta_quiz_quiz';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'meta_quiz' => 'meta_quiz',
  );

  $views[$view->name] = $view;

  return $views;
}
