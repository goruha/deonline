<?php

/**
 * Implementation of hook_views_default_views().
 */
function features_deonline_views_views_default_views() {
  $views = array();

  // Exported view: book_pages_formatter
  $view = new view;
  $view->name = 'book_pages_formatter';
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
  $handler->display->display_options['style_plugin'] = 'viewscarousel';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['style_options']['start'] = '1';
  $handler->display->display_options['style_options']['scroll'] = '1';
  $handler->display->display_options['style_options']['visible'] = 1;
  $handler->display->display_options['style_options']['animation'] = 'slow';
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['auto'] = '5';
  $handler->display->display_options['style_options']['auto_pause'] = 1;
  $handler->display->display_options['style_options']['wrap'] = 'both';
  $handler->display->display_options['style_options']['skin'] = 'tango';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Страницы (field_book_page) */
  $handler->display->display_options['fields']['field_book_page_fid']['id'] = 'field_book_page_fid';
  $handler->display->display_options['fields']['field_book_page_fid']['table'] = 'node_data_field_book_page';
  $handler->display->display_options['fields']['field_book_page_fid']['field'] = 'field_book_page_fid';
  $handler->display->display_options['fields']['field_book_page_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_book_page_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_book_page_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_book_page_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_book_page_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_book_page_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_book_page_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_book_page_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_book_page_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_book_page_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_book_page_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_book_page_fid']['format'] = '135x222_default';
  $handler->display->display_options['fields']['field_book_page_fid']['multiple']['group'] = 0;
  $handler->display->display_options['fields']['field_book_page_fid']['multiple']['multiple_reversed'] = 0;
  /* Sort criterion: Content: Страницы (field_book_page) - delta */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'node_data_field_book_page';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'book' => 'book',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  $views[$view->name] = $view;

  // Exported view: levels
  $view = new view;
  $view->name = 'levels';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 3.0-alpha1;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['css_class'] = 'levels-list';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'description_1' => 'description_1',
    'name' => 'name',
    'description' => 'description',
    'name_1' => 'name_1',
    'field_level_description_value' => 'field_level_description_value',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'description_1' => array(
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'description' => array(
      'separator' => '',
    ),
    'name_1' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'field_level_description_value' => array(
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Relationship: Taxonomy: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['required'] = 1;
  /* Field: Taxonomy: Term description */
  $handler->display->display_options['fields']['description_1']['id'] = 'description_1';
  $handler->display->display_options['fields']['description_1']['table'] = 'term_data';
  $handler->display->display_options['fields']['description_1']['field'] = 'description';
  $handler->display->display_options['fields']['description_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['description_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description_1']['empty_zero'] = 0;
  /* Field: Taxonomy: Term */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name]
[description_1]';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Field: Taxonomy: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  /* Field: Taxonomy: Term */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['text'] = '[name_1]
[description]';
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = 0;
  /* Field: Content: Описание (field_level_description) */
  $handler->display->display_options['fields']['field_level_description_value']['id'] = 'field_level_description_value';
  $handler->display->display_options['fields']['field_level_description_value']['table'] = 'node_data_field_level_description';
  $handler->display->display_options['fields']['field_level_description_value']['field'] = 'field_level_description_value';
  $handler->display->display_options['fields']['field_level_description_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_level_description_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_level_description_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_level_description_value']['format'] = 'list';
  $handler->display->display_options['fields']['field_level_description_value']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_level_description_value']['multiple']['multiple_reversed'] = 0;
  /* Sort criterion: Taxonomy: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'parent';
  /* Sort criterion: Taxonomy: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'term_data';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'level' => 'level',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  
/* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  $views[$view->name] = $view;

  // Exported view: levels_widget
  $view = new view;
  $view->name = 'levels_widget';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 3.0-alpha1;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['css_class'] = 'levels-list';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'description_1' => 'description_1',
    'name' => 'name',
    'description' => 'description',
    'name_1' => 'name_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'description_1' => array(
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'description' => array(
      'separator' => '',
    ),
    'name_1' => array(
      'sortable' => 0,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Relationship: Taxonomy: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['required'] = 1;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Node: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Sort criterion: Taxonomy: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'parent';
  /* Sort criterion: Taxonomy: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'term_data';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'level' => 'level',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;

  $views[$view->name] = $view;

  // Exported view: node_program_type_teacher
  $view = new view;
  $view->name = 'node_program_type_teacher';
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
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Node: Content Profile */
  $handler->display->display_options['relationships']['content_profile_rel']['id'] = 'content_profile_rel';
  $handler->display->display_options['relationships']['content_profile_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['content_profile_rel']['field'] = 'content_profile_rel';
  $handler->display->display_options['relationships']['content_profile_rel']['label'] = 'Profile';
  $handler->display->display_options['relationships']['content_profile_rel']['required'] = 1;
  $handler->display->display_options['relationships']['content_profile_rel']['type'] = 'profile';
  /* Field: Content: Avatar (field_profile_avatar) */
  $handler->display->display_options['fields']['field_profile_avatar_fid']['id'] = 'field_profile_avatar_fid';
  $handler->display->display_options['fields']['field_profile_avatar_fid']['table'] = 'node_data_field_profile_avatar';
  $handler->display->display_options['fields']['field_profile_avatar_fid']['field'] = 'field_profile_avatar_fid';
  $handler->display->display_options['fields']['field_profile_avatar_fid']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_profile_avatar_fid']['format'] = '135x135_default';
  /* Field: Content: Name (field_profile_name) */
  $handler->display->display_options['fields']['field_profile_name_value']['id'] = 'field_profile_name_value';
  $handler->display->display_options['fields']['field_profile_name_value']['table'] = 'node_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name_value']['field'] = 'field_profile_name_value';
  $handler->display->display_options['fields']['field_profile_name_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_profile_name_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['label_type'] = 'none';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[field_profile_name_value] [field_profile_surname_value]';
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: Content: Skype (field_profile_contact_skype) */
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['id'] = 'field_profile_contact_skype_value';
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['table'] = 'node_data_field_profile_contact_skype';
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['field'] = 'field_profile_contact_skype_value';
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_profile_contact_skype_value']['format'] = 'balloon';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Argument: Content: Program (field_tp_program) */
  $handler->display->display_options['arguments']['field_tp_program_nid']['id'] = 'field_tp_program_nid';
  $handler->display->display_options['arguments']['field_tp_program_nid']['table'] = 'node_data_field_tp_program';
  $handler->display->display_options['arguments']['field_tp_program_nid']['field'] = 'field_tp_program_nid';
  $handler->display->display_options['arguments']['field_tp_program_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_tp_program_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tp_program_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_tp_program_nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['field_tp_program_nid']['validate_options']['types'] = array(
    'program_types' => 'program_types',
  );
  $handler->display->display_options['arguments']['field_tp_program_nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['field_tp_program_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_tp_program_nid']['not'] = 0;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'teacher_profile' => 'teacher_profile',
  );
  
/* Display: Embed */
  $handler = $view->new_display('embed', 'Embed', 'node_program_type');

  $views[$view->name] = $view;

  // Exported view: prices
  $view = new view;
  $view->name = 'prices';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 3.0-alpha1;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Формы обучения и цены';
  $handler->display->display_options['css_class'] = 'prices-list';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_price_60_business_value' => 'field_price_60_business_value',
    'field_price_60_common_value' => 'field_price_60_common_value',
    'field_price_90_business_value' => 'field_price_90_business_value',
    'field_price_90_common_value' => 'field_price_90_common_value',
    'field_price_type_value' => 'field_price_type_value',
    'body' => 'body',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_price_60_business_value' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'field_price_60_common_value' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'field_price_90_business_value' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'field_price_90_common_value' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'field_price_type_value' => array(
      'separator' => '',
    ),
    'body' => array(
      'separator' => '',
    ),
    'nothing' => array(
      'separator' => '',
    ),
    'nothing_1' => array(
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 0;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Relationship: Nodequeue: Queue (qid) */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['qids'] = array(
    '1' => 1,
  );
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_price_60_business_value']['id'] = 'field_price_60_business_value';
  $handler->display->display_options['fields']['field_price_60_business_value']['table'] = 'node_data_field_price_60_business';
  $handler->display->display_options['fields']['field_price_60_business_value']['field'] = 'field_price_60_business_value';
  $handler->display->display_options['fields']['field_price_60_business_value']['label'] = '60 минут';
  $handler->display->display_options['fields']['field_price_60_business_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_price_60_business_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_price_60_business_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_price_60_business_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_price_60_business_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_price_60_business_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_price_60_business_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_price_60_business_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_price_60_business_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_price_60_business_value']['empty_zero'] = 0;
  /* Field: Content: 60 минут (field_price_60_common) */
  $handler->display->display_options['fields']['field_price_60_common_value']['id'] = 'field_price_60_common_value';
  $handler->display->display_options['fields']['field_price_60_common_value']['table'] = 'node_data_field_price_60_common';
  $handler->display->display_options['fields']['field_price_60_common_value']['field'] = 'field_price_60_common_value';
  $handler->display->display_options['fields']['field_price_60_common_value']['label'] = '60 минут';
  $handler->display->display_options['fields']['field_price_60_common_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_price_60_common_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_price_60_common_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_price_60_common_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_price_60_common_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_price_60_common_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_price_60_common_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_price_60_common_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_price_60_common_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_price_60_common_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_price_60_common_value']['link_to_node'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_price_90_business_value']['id'] = 'field_price_90_business_value';
  $handler->display->display_options['fields']['field_price_90_business_value']['table'] = 'node_data_field_price_90_business';
  $handler->display->display_options['fields']['field_price_90_business_value']['field'] = 'field_price_90_business_value';
  $handler->display->display_options['fields']['field_price_90_business_value']['label'] = '90 минут';
  $handler->display->display_options['fields']['field_price_90_business_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_price_90_business_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_price_90_business_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_price_90_business_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_price_90_business_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_price_90_business_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_price_90_business_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_price_90_business_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_price_90_business_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_price_90_business_value']['empty_zero'] = 0;
  /* Field: Content: 90 минут (field_price_90_common) */
  $handler->display->display_options['fields']['field_price_90_common_value']['id'] = 'field_price_90_common_value';
  $handler->display->display_options['fields']['field_price_90_common_value']['table'] = 'node_data_field_price_90_common';
  $handler->display->display_options['fields']['field_price_90_common_value']['field'] = 'field_price_90_common_value';
  $handler->display->display_options['fields']['field_price_90_common_value']['label'] = '90 минут';
  $handler->display->display_options['fields']['field_price_90_common_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_price_90_common_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_price_90_common_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_price_90_common_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_price_90_common_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_price_90_common_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_price_90_common_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_price_90_common_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_price_90_common_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_price_90_common_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_price_90_common_value']['link_to_node'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_price_type_value']['id'] = 'field_price_type_value';
  $handler->display->display_options['fields']['field_price_type_value']['table'] = 'node_data_field_price_type';
  $handler->display->display_options['fields']['field_price_type_value']['field'] = 'field_price_type_value';
  $handler->display->display_options['fields']['field_price_type_value']['label'] = '';
  $handler->display->display_options['fields']['field_price_type_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_price_type_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_price_type_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_price_type_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_price_type_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_price_type_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_price_type_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_price_type_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_price_type_value']['empty_zero'] = 0;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Общая программа';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '60 минут - [field_price_60_common_value]<br/>
90 минут - [field_price_90_common_value]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Подготовка к тестам';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '60 минут - [field_price_60_business_value]<br/>
90 минут - [field_price_90_business_value]';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_1']['empty_zero'] = 0;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'prices' => 'prices',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';
  $handler->display->display_options['filters']['in_queue']['expose']['operator'] = FALSE;
  
/* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'prices';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Формы обучения и цены';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'primary-links';

  $views[$view->name] = $view;

  // Exported view: program_types
  $view = new view;
  $view->name = 'program_types';
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
  $handler->display->display_options['style_plugin'] = 'views_showcase';
  $handler->display->display_options['style_options']['cycle'] = 'fade';
  $handler->display->display_options['style_options']['timeout'] = '6000';
  $handler->display->display_options['style_options']['pause'] = 'true';
  $handler->display->display_options['style_options']['listpause'] = 'true';
  $handler->display->display_options['style_options']['easing'] = 'easeInOutQuart';
  $handler->display->display_options['style_options']['skin'] = 'left';
  /* Relationship: Nodequeue: Queue (name) */
  $handler->display->display_options['relationships']['nodequeue_rel_queue_name']['id'] = 'nodequeue_rel_queue_name';
  $handler->display->display_options['relationships']['nodequeue_rel_queue_name']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel_queue_name']['field'] = 'nodequeue_rel_queue_name';
  $handler->display->display_options['relationships']['nodequeue_rel_queue_name']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel_queue_name']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel_queue_name']['names'] = array(
    'program_types' => 'program_types',
    'cases_prices' => 0,
  );
  /* Field: Content: Картинка (field_image) */
  $handler->display->display_options['fields']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['table'] = 'node_data_field_image';
  $handler->display->display_options['fields']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_image_fid']['format'] = 'grid16-4_default';
  /* Field: Node: Teaser */
  $handler->display->display_options['fields']['teaser']['id'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['teaser']['field'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['label'] = '';
  $handler->display->display_options['fields']['teaser']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['teaser']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['teaser']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['html'] = 0;
  $handler->display->display_options['fields']['teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['teaser']['empty_zero'] = 0;
  /* Field: Node: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['link_class'] = 'link-button';
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['text'] = 'Подробнее';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel_queue_name';
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program_types' => 'program_types',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel_queue_name';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';
  $handler->display->display_options['filters']['in_queue']['expose']['operator'] = FALSE;
  
/* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'programms';

  $views[$view->name] = $view;

  // Exported view: teacher_widget
  $view = new view;
  $view->name = 'teacher_widget';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'users';
  $view->is_cacheable = FALSE;
  $view->api_version = 3.0-alpha1;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_profile_avatar_fid' => 'field_profile_avatar_fid',
    'field_profile_name_value' => 'field_profile_name_value',
    'field_profile_surname_value' => 'field_profile_surname_value',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_profile_avatar_fid' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_profile_name_value' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
    'field_profile_surname_value' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Relationship: Node: Content Profile */
  $handler->display->display_options['relationships']['content_profile_rel']['id'] = 'content_profile_rel';
  $handler->display->display_options['relationships']['content_profile_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['content_profile_rel']['field'] = 'content_profile_rel';
  $handler->display->display_options['relationships']['content_profile_rel']['label'] = 'Profile';
  $handler->display->display_options['relationships']['content_profile_rel']['required'] = 1;
  $handler->display->display_options['relationships']['content_profile_rel']['type'] = 'profile';
  /* Relationship: Node: Content Profile */
  $handler->display->display_options['relationships']['content_profile_rel_1']['id'] = 'content_profile_rel_1';
  $handler->display->display_options['relationships']['content_profile_rel_1']['table'] = 'users';
  $handler->display->display_options['relationships']['content_profile_rel_1']['field'] = 'content_profile_rel';
  $handler->display->display_options['relationships']['content_profile_rel_1']['label'] = 'Teacher Profile';
  $handler->display->display_options['relationships']['content_profile_rel_1']['required'] = 1;
  $handler->display->display_options['relationships']['content_profile_rel_1']['type'] = 'teacher_profile';
  /* Field: Content: Avatar (field_profile_avatar) */
  $handler->display->display_options['fields']['field_profile_avatar_fid']['id'] = 'field_profile_avatar_fid';
  $handler->display->display_options['fields']['field_profile_avatar_fid']['table'] = 'node_data_field_profile_avatar';
  $handler->display->display_options['fields']['field_profile_avatar_fid']['field'] = 'field_profile_avatar_fid';
  $handler->display->display_options['fields']['field_profile_avatar_fid']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_profile_avatar_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_profile_avatar_fid']['format'] = '135x222_default';
  /* Field: Content: Name (field_profile_name) */
  $handler->display->display_options['fields']['field_profile_name_value']['id'] = 'field_profile_name_value';
  $handler->display->display_options['fields']['field_profile_name_value']['table'] = 'node_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name_value']['field'] = 'field_profile_name_value';
  $handler->display->display_options['fields']['field_profile_name_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_profile_name_value']['label_type'] = 'none';
  /* Argument: Content: Program (field_tp_program) */
  $handler->display->display_options['arguments']['field_tp_program_nid']['id'] = 'field_tp_program_nid';
  $handler->display->display_options['arguments']['field_tp_program_nid']['table'] = 'node_data_field_tp_program';
  $handler->display->display_options['arguments']['field_tp_program_nid']['field'] = 'field_tp_program_nid';
  $handler->display->display_options['arguments']['field_tp_program_nid']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['arguments']['field_tp_program_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tp_program_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tp_program_nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['field_tp_program_nid']['validate_options']['types'] = array(
    'program_types' => 'program_types',
  );
  $handler->display->display_options['arguments']['field_tp_program_nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['field_tp_program_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_tp_program_nid']['not'] = 0;
  /* Filter: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    '5' => '5',
  );
  
/* Display: Embed */
  $handler = $view->new_display('embed', 'Embed', 'embed_1');

  $views[$view->name] = $view;

  // Exported view: test
  $view = new view;
  $view->name = 'test';
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
  /* Field: Content: Описание (field_level_description) */
  $handler->display->display_options['fields']['field_level_description_value']['id'] = 'field_level_description_value';
  $handler->display->display_options['fields']['field_level_description_value']['table'] = 'node_data_field_level_description';
  $handler->display->display_options['fields']['field_level_description_value']['field'] = 'field_level_description_value';
  $handler->display->display_options['fields']['field_level_description_value']['label'] = 'Описание';
  $handler->display->display_options['fields']['field_level_description_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_level_description_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_level_description_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['multiple']['group'] = 0;
  $handler->display->display_options['fields']['field_level_description_value']['multiple']['multiple_number'] = '0';
  $handler->display->display_options['fields']['field_level_description_value']['multiple']['multiple_from'] = '2';
  $handler->display->display_options['fields']['field_level_description_value']['multiple']['multiple_reversed'] = 0;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'level' => 'level',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;

  $views[$view->name] = $view;

  // Exported view: user_materials
  $view = new view;
  $view->name = 'user_materials';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 3.0-alpha1;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Мои материалы';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    '3' => 3,
    '2' => 2,
    '4' => 4,
    '5' => 5,
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['build_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Argument: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter: Node: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'material_audio' => 'material_audio',
    'material_document' => 'material_document',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Node: Type';
  $handler->display->display_options['filters']['type']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['type']['expose']['single'] = TRUE;
  
/* Display: user_materials_block */
  $handler = $view->new_display('block', 'user_materials_block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['items_per_page'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_m_audio_file_fid' => 'field_m_audio_file_fid',
    'field_m_document_file_fid' => 'field_m_document_file_fid',
    'title' => 'title',
    'nothing' => 'nothing',
    'edit_node' => 'edit_node',
    'view_node' => 'view_node',
    'type' => 'type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_m_audio_file_fid' => array(
      'separator' => '',
    ),
    'field_m_document_file_fid' => array(
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'nothing' => array(
      'separator' => '',
    ),
    'edit_node' => array(
      'separator' => '',
    ),
    'view_node' => array(
      'separator' => '',
    ),
    'type' => array(
      'sortable' => 0,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 0;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['label'] = '';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'Материалы не найдены';
  $handler->display->display_options['empty']['text']['format'] = '1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Трек (field_m_audio_file) */
  $handler->display->display_options['fields']['field_m_audio_file_fid']['id'] = 'field_m_audio_file_fid';
  $handler->display->display_options['fields']['field_m_audio_file_fid']['table'] = 'node_data_field_m_audio_file';
  $handler->display->display_options['fields']['field_m_audio_file_fid']['field'] = 'field_m_audio_file_fid';
  $handler->display->display_options['fields']['field_m_audio_file_fid']['label'] = 'Трек';
  $handler->display->display_options['fields']['field_m_audio_file_fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_m_audio_file_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_m_audio_file_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_m_audio_file_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_m_audio_file_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_m_audio_file_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_m_audio_file_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_m_audio_file_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_m_audio_file_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_m_audio_file_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_m_audio_file_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_m_audio_file_fid']['format'] = 'audiofield_embedded';
  /* Field: Content: Файл (field_m_document_file) */
  $handler->display->display_options['fields']['field_m_document_file_fid']['id'] = 'field_m_document_file_fid';
  $handler->display->display_options['fields']['field_m_document_file_fid']['table'] = 'node_data_field_m_document_file';
  $handler->display->display_options['fields']['field_m_document_file_fid']['field'] = 'field_m_document_file_fid';
  $handler->display->display_options['fields']['field_m_document_file_fid']['label'] = 'Файл';
  $handler->display->display_options['fields']['field_m_document_file_fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_m_document_file_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_m_document_file_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_m_document_file_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_m_document_file_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_m_document_file_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_m_document_file_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_m_document_file_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_m_document_file_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_m_document_file_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_m_document_file_fid']['link_to_node'] = 0;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Файл';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_m_audio_file_fid] [field_m_document_file_fid]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  /* Field: Node: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  /* Field: Node: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  /* Field: Node: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Тип';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Node: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'material_audio' => 'material_audio',
    'material_document' => 'material_document',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Node: Type';
  $handler->display->display_options['filters']['type']['expose']['use_operator'] = 0;
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 1;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'material_audio' => 'material_audio',
    'material_document' => 'material_document',
  );
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = FALSE;

  $views[$view->name] = $view;

  // Exported view: user_programms
  $view = new view;
  $view->name = 'user_programms';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 3.0-alpha1;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Мои программы';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    '3' => 3,
    '2' => 2,
    '4' => 4,
    '5' => 5,
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['build_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Argument: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter: Node: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'programm' => 'programm',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  
/* Display: user_programms_block */
  $handler = $view->new_display('block', 'user_programms_block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Мои программы';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Тип (field_program_type) */
  $handler->display->display_options['fields']['field_program_type_value']['id'] = 'field_program_type_value';
  $handler->display->display_options['fields']['field_program_type_value']['table'] = 'node_data_field_program_type';
  $handler->display->display_options['fields']['field_program_type_value']['field'] = 'field_program_type_value';
  $handler->display->display_options['fields']['field_program_type_value']['label'] = 'Тип';
  $handler->display->display_options['fields']['field_program_type_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_program_type_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_program_type_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_program_type_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_program_type_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_program_type_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_program_type_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_program_type_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_program_type_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_program_type_value']['link_to_node'] = 0;
  /* Field: Node: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  /* Field: Node: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;

  $views[$view->name] = $view;

  return $views;
}
