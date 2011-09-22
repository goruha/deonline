<?php

/**
 * Implementation of hook_content_default_fields().
 */
function feature_deonline_ct_content_default_fields() {
  $fields = array();

  // Exported field: field_book_author
  $fields['book-field_book_author'] = array(
    'field_name' => 'field_book_author',
    'type_name' => 'book',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_book_author][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Автор',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_book_page
  $fields['book-field_book_page'] = array(
    'field_name' => 'field_book_page',
    'type_name' => 'book',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Страницы',
      'weight' => '-3',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_cr_comments
  $fields['course_request-field_cr_comments'] = array(
    'field_name' => 'field_cr_comments',
    'type_name' => 'course_request',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_cr_comments][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Комментарии',
      'weight' => '46',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_cr_course
  $fields['course_request-field_cr_course'] = array(
    'field_name' => 'field_cr_course',
    'type_name' => 'course_request',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'program_types' => 'program_types',
      'material_audio' => 0,
      'long_answer' => 0,
      'matching' => 0,
      'multichoice' => 0,
      'page' => 0,
      'profile' => 0,
      'quiz_directions' => 0,
      'scale' => 0,
      'short_answer' => 0,
      'story' => 0,
      'teacher_profile' => 0,
      'truefalse' => 0,
      'material_video' => 0,
      'material_document' => 0,
      'course_request' => 0,
      'programm' => 0,
      'quiz' => 0,
      'level' => 0,
      'lesson' => 0,
      'book' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Курс',
      'weight' => '44',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_cr_date
  $fields['course_request-field_cr_date'] = array(
    'field_name' => 'field_cr_date',
    'type_name' => 'course_request',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'user',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'm/d/Y - g:ia',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-0:+1',
      'label_position' => 'above',
      'label' => 'Дата',
      'weight' => '42',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_cr_level
  $fields['course_request-field_cr_level'] = array(
    'field_name' => 'field_cr_level',
    'type_name' => 'course_request',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'content_taxonomy',
    'required' => '1',
    'multiple' => '0',
    'module' => 'content_taxonomy',
    'active' => '1',
    'save_term_node' => 1,
    'vid' => '7',
    'parent' => '0',
    'parent_php_code' => '',
    'depth' => '',
    'widget' => array(
      'group_parent' => '0',
      'show_depth' => 1,
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Уровень',
      'weight' => '45',
      'description' => '',
      'type' => 'content_taxonomy_select',
      'module' => 'content_taxonomy_options',
    ),
  );

  // Exported field: field_cr_teacher
  $fields['course_request-field_cr_teacher'] = array(
    'field_name' => 'field_cr_teacher',
    'type_name' => 'course_request',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'userreference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'userreference',
    'active' => '1',
    'referenceable_roles' => array(
      '5' => 5,
      '2' => 0,
      '3' => 0,
      '4' => 0,
    ),
    'referenceable_status' => '1',
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'reverse_link' => 0,
      'default_value' => array(
        '0' => array(
          'uid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Преподаватель',
      'weight' => '43',
      'description' => '',
      'type' => 'userreference_select',
      'module' => 'userreference',
    ),
  );

  // Exported field: field_lesson_materials
  $fields['lesson-field_lesson_materials'] = array(
    'field_name' => 'field_lesson_materials',
    'type_name' => 'lesson',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'full',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'full',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'material_audio' => 'material_audio',
      'material_document' => 'material_document',
      'page' => 0,
      'profile' => 0,
      'story' => 0,
      'teacher_profile' => 0,
      'programm' => 0,
      'lesson' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_lesson_materials][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Материалы',
      'weight' => '-4',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_level_compexity
  $fields['level-field_level_compexity'] = array(
    'field_name' => 'field_level_compexity',
    'type_name' => 'level',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'content_taxonomy',
    'required' => '1',
    'multiple' => '0',
    'module' => 'content_taxonomy',
    'active' => '1',
    'save_term_node' => 1,
    'vid' => '3',
    'parent' => '0',
    'parent_php_code' => '',
    'depth' => '',
    'widget' => array(
      'group_parent' => '0',
      'show_depth' => 1,
      'default_value' => array(
        'field_level_compexity' => array(
          'tids' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Сложность',
      'weight' => '-4',
      'description' => '',
      'type' => 'content_taxonomy_hs',
      'module' => 'hs_content_taxonomy',
    ),
  );

  // Exported field: field_level_description
  $fields['level-field_level_description'] = array(
    'field_name' => 'field_level_description',
    'type_name' => 'level',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '1',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_level_description][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Описание',
      'weight' => '-1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_m_audio_file
  $fields['material_audio-field_m_audio_file'] = array(
    'field_name' => 'field_m_audio_file',
    'type_name' => 'material_audio',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3 wma wav',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Трек',
      'weight' => '-4',
      'description' => '',
      'type' => 'audiofield_widget',
      'module' => 'audiofield',
    ),
  );

  // Exported field: field_m_document_file
  $fields['material_document-field_m_document_file'] = array(
    'field_name' => 'field_m_document_file',
    'type_name' => 'material_document',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'doc docx',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Файл',
      'weight' => '31',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_m_video_file
  $fields['material_video-field_m_video_file'] = array(
    'field_name' => 'field_m_video_file',
    'type_name' => 'material_video',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp4 mpeg avi mpg wmv flv mov',
      'file_path' => 'videos',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'default_video_thumb' => NULL,
      'default_dimensions' => '640x480',
      'default_player_dimensions' => '640x480',
      'autoconversion' => 1,
      'autothumbnail' => 'auto',
      'label' => 'Файл',
      'weight' => '-4',
      'description' => '',
      'type' => 'uploadfield_widget',
      'module' => 'uploadfield',
    ),
  );

  // Exported field: field_page_footer
  $fields['page-field_page_footer'] = array(
    'field_name' => 'field_page_footer',
    'type_name' => 'page',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_page_footer][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Footer',
      'weight' => '-2',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_page_header
  $fields['page-field_page_header'] = array(
    'field_name' => 'field_page_header',
    'type_name' => 'page',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_page_header][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Header',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_view
  $fields['page-field_view'] = array(
    'field_name' => 'field_view',
    'type_name' => 'page',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'viewfield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'viewfield',
    'active' => '1',
    'allowed_views' => array(
      'programms' => 0,
      'noderelationships_noderef' => 0,
      'user_programms' => 0,
      'user_materials' => 0,
      'test' => 0,
      'levels' => 0,
      'prices' => 0,
      'frontpage' => 0,
      'glossary' => 0,
      'archive' => 0,
      'taxonomy_term' => 0,
      'nodequeue_1' => 0,
      'noderelationships_backref' => 0,
    ),
    'super_default' => 0,
    'token_enabled' => 0,
    'super_default_widget' => array(
      'vname' => '0',
      'vargs' => '',
    ),
    'widget' => array(
      'force_default' => 0,
      'label' => 'View',
      'weight' => '-3',
      'description' => '',
      'type' => 'viewfield_select',
      'module' => 'viewfield',
    ),
  );

  // Exported field: field_profile_age
  $fields['profile-field_profile_age'] = array(
    'field_name' => 'field_profile_age',
    'type_name' => 'profile',
    'display_settings' => array(
      'weight' => '34',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'content_taxonomy',
    'required' => '0',
    'multiple' => '0',
    'module' => 'content_taxonomy',
    'active' => '1',
    'save_term_node' => 1,
    'vid' => '6',
    'parent' => '0',
    'parent_php_code' => '',
    'depth' => '',
    'widget' => array(
      'group_parent' => '0',
      'show_depth' => 1,
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Возраст',
      'weight' => '34',
      'description' => '',
      'type' => 'content_taxonomy_select',
      'module' => 'content_taxonomy_options',
    ),
  );

  // Exported field: field_profile_avatar
  $fields['profile-field_profile_avatar'] = array(
    'field_name' => 'field_profile_avatar',
    'type_name' => 'profile',
    'display_settings' => array(
      'weight' => '32',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => '135x222_default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => array(
        'filename' => 'user_clip_art.png',
        'filepath' => 'sites/default/files/imagefield_default_images/user_clip_art.png',
        'filemime' => 'image/png',
        'source' => 'default_image_upload',
        'destination' => 'sites/default/files/imagefield_default_images/user_clip_art.png',
        'filesize' => 37446,
        'uid' => '1',
        'status' => 1,
        'timestamp' => 1314641569,
        'fid' => '69',
      ),
      'use_default_image' => 1,
      'resolution' => '',
      'enforce_ratio' => 0,
      'croparea' => '500x500',
      'enforce_minimum' => 0,
      'label' => 'Avatar',
      'weight' => '32',
      'description' => '',
      'type' => 'imagefield_crop_widget',
      'module' => 'imagefield_crop',
    ),
  );

  // Exported field: field_profile_contact_skype
  $fields['profile-field_profile_contact_skype'] = array(
    'field_name' => 'field_profile_contact_skype',
    'type_name' => 'profile',
    'display_settings' => array(
      'weight' => '42',
      'parent' => 'group_profile_contacts',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'smallicon',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'balloon',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'skype_status_cck',
    'required' => '0',
    'multiple' => '0',
    'module' => 'skype_status_cck',
    'active' => '1',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_contact_skype][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Skype',
      'weight' => '42',
      'description' => '',
      'type' => 'skype_status_field',
      'module' => 'skype_status_cck',
    ),
  );

  // Exported field: field_profile_name
  $fields['profile-field_profile_name'] = array(
    'field_name' => 'field_profile_name',
    'type_name' => 'profile',
    'display_settings' => array(
      'weight' => '33',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Name',
      'weight' => '33',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_image
  $fields['program_types-field_image'] = array(
    'field_name' => 'field_image',
    'type_name' => 'program_types',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 1,
      'title' => '',
      'custom_title' => 1,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'resolution' => '',
      'enforce_ratio' => 0,
      'croparea' => '500x500',
      'enforce_minimum' => 0,
      'label' => 'Картинка',
      'weight' => '-3',
      'description' => '',
      'type' => 'imagefield_crop_widget',
      'module' => 'imagefield_crop',
    ),
  );

  // Exported field: field_price_60_common
  $fields['program_types-field_price_60_common'] = array(
    'field_name' => 'field_price_60_common',
    'type_name' => 'program_types',
    'display_settings' => array(
      'weight' => '9',
      'parent' => 'group_program_type_prices',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '1',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => ' рублей',
    'min' => '0',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_price_60_common][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => '60 минут',
      'weight' => '9',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_price_90_common
  $fields['program_types-field_price_90_common'] = array(
    'field_name' => 'field_price_90_common',
    'type_name' => 'program_types',
    'display_settings' => array(
      'weight' => '10',
      'parent' => 'group_program_type_prices',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '1',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => ' рублей',
    'min' => '0',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_price_90_common][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => '90 минут',
      'weight' => '10',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_program_type_level
  $fields['program_types-field_program_type_level'] = array(
    'field_name' => 'field_program_type_level',
    'type_name' => 'program_types',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'material_audio' => 0,
      'page' => 0,
      'panel' => 0,
      'profile' => 0,
      'story' => 0,
      'teacher_profile' => 0,
      'material_video' => 0,
      'material_document' => 0,
      'programm' => 0,
      'prices' => 0,
      'program_types' => 0,
      'level' => 0,
      'lesson' => 0,
    ),
    'advanced_view' => 'levels_widget',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Категрия по европейской шкале',
      'weight' => '-1',
      'description' => '',
      'type' => 'nodereference_buttons',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_pt_book
  $fields['program_types-field_pt_book'] = array(
    'field_name' => 'field_pt_book',
    'type_name' => 'program_types',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'cck_formatter_view_1',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'book' => 'book',
      'material_audio' => 0,
      'page' => 0,
      'panel' => 0,
      'profile' => 0,
      'story' => 0,
      'teacher_profile' => 0,
      'material_video' => 0,
      'material_document' => 0,
      'programm' => 0,
      'program_types' => 0,
      'level' => 0,
      'lesson' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_pt_book][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Базовый учебник',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_pt_price_type
  $fields['program_types-field_pt_price_type'] = array(
    'field_name' => 'field_pt_price_type',
    'type_name' => 'program_types',
    'display_settings' => array(
      'weight' => '8',
      'parent' => 'group_program_type_prices',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'content_taxonomy',
    'required' => '1',
    'multiple' => '1',
    'module' => 'content_taxonomy',
    'active' => '1',
    'save_term_node' => 1,
    'vid' => '4',
    'parent' => '0',
    'parent_php_code' => '',
    'depth' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'group_parent' => '0',
      'show_depth' => 1,
      'label' => 'Тип',
      'weight' => '8',
      'description' => '',
      'type' => 'content_taxonomy_select',
      'module' => 'content_taxonomy_options',
    ),
  );

  // Exported field: field_program_type
  $fields['programm-field_program_type'] = array(
    'field_name' => 'field_program_type',
    'type_name' => 'programm',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'content_taxonomy',
    'required' => '1',
    'multiple' => '0',
    'module' => 'content_taxonomy',
    'active' => '1',
    'save_term_node' => 1,
    'vid' => '1',
    'parent' => '0',
    'parent_php_code' => '',
    'depth' => '',
    'widget' => array(
      'group_parent' => '0',
      'show_depth' => 1,
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Тип',
      'weight' => '-4',
      'description' => '',
      'type' => 'content_taxonomy_select',
      'module' => 'content_taxonomy_options',
    ),
  );

  // Exported field: field_programm_lesson
  $fields['programm-field_programm_lesson'] = array(
    'field_name' => 'field_programm_lesson',
    'type_name' => 'programm',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'full',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'lesson' => 'lesson',
      'page' => 0,
      'profile' => 0,
      'story' => 0,
      'teacher_profile' => 0,
      'material_audio' => 0,
      'material_document' => 0,
      'programm' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_programm_lesson][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Уроки',
      'weight' => '-3',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_tp_portfolio_case
  $fields['teacher_profile-field_tp_portfolio_case'] = array(
    'field_name' => 'field_tp_portfolio_case',
    'type_name' => 'teacher_profile',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '1',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_tp_portfolio_case][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Деятельность',
      'weight' => '46',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_tp_portfolio_period
  $fields['teacher_profile-field_tp_portfolio_period'] = array(
    'field_name' => 'field_tp_portfolio_period',
    'type_name' => 'teacher_profile',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '1',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => 'optional',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'blank',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-60:+0',
      'label_position' => 'above',
      'label' => 'Период',
      'weight' => '45',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_tp_program
  $fields['teacher_profile-field_tp_program'] = array(
    'field_name' => 'field_tp_program',
    'type_name' => 'teacher_profile',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'program_types' => 'program_types',
      'material_audio' => 0,
      'page' => 0,
      'panel' => 0,
      'profile' => 0,
      'story' => 0,
      'teacher_profile' => 0,
      'material_video' => 0,
      'material_document' => 0,
      'programm' => 0,
      'prices' => 0,
      'level' => 0,
      'lesson' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Program',
      'weight' => '36',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('60 минут');
  t('90 минут');
  t('Avatar');
  t('Footer');
  t('Header');
  t('Name');
  t('Program');
  t('Skype');
  t('View');
  t('Автор');
  t('Базовый учебник');
  t('Возраст');
  t('Дата');
  t('Деятельность');
  t('Картинка');
  t('Категрия по европейской шкале');
  t('Комментарии');
  t('Курс');
  t('Материалы');
  t('Описание');
  t('Период');
  t('Преподаватель');
  t('Сложность');
  t('Страницы');
  t('Тип');
  t('Трек');
  t('Уровень');
  t('Уроки');
  t('Файл');

  return $fields;
}
