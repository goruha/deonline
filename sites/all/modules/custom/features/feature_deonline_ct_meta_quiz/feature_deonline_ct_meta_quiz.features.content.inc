<?php

/**
 * Implementation of hook_content_default_fields().
 */
function feature_deonline_ct_meta_quiz_content_default_fields() {
  $fields = array();

  // Exported field: field_meta_quiz_image
  $fields['meta_quiz-field_meta_quiz_image'] = array(
    'field_name' => 'field_meta_quiz_image',
    'type_name' => 'meta_quiz',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => 'group_meta_quiz_quiz',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => '135x135_default',
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
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'resolution' => '100x100',
      'enforce_ratio' => 1,
      'croparea' => '200x200',
      'enforce_minimum' => 1,
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
      'label' => 'Icon',
      'weight' => '-2',
      'description' => '',
      'type' => 'imagefield_crop_widget',
      'module' => 'imagefield_crop',
    ),
  );

  // Exported field: field_meta_quiz_image_passed
  $fields['meta_quiz-field_meta_quiz_image_passed'] = array(
    'field_name' => 'field_meta_quiz_image_passed',
    'type_name' => 'meta_quiz',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => 'group_meta_quiz_quiz',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => '135x135_default',
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
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'resolution' => '100x100',
      'enforce_ratio' => 1,
      'croparea' => '200x200',
      'enforce_minimum' => 1,
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
      'label' => 'Icon passed',
      'weight' => '-1',
      'description' => '',
      'type' => 'imagefield_crop_widget',
      'module' => 'imagefield_crop',
    ),
  );

  // Exported field: field_meta_quiz_quiz
  $fields['meta_quiz-field_meta_quiz_quiz'] = array(
    'field_name' => 'field_meta_quiz_quiz',
    'type_name' => 'meta_quiz',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => 'group_meta_quiz_quiz',
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
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'quiz' => 'quiz',
      'material_audio' => 0,
      'long_answer' => 0,
      'matching' => 0,
      'meta_quiz' => 0,
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
      'program_types' => 0,
      'level' => 0,
      'lesson' => 0,
      'book' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '20',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_meta_quiz_quiz][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Quiz',
      'weight' => '-3',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_meta_quiz_text
  $fields['meta_quiz-field_meta_quiz_text'] = array(
    'field_name' => 'field_meta_quiz_text',
    'type_name' => 'meta_quiz',
    'display_settings' => array(
      'weight' => 0,
      'parent' => 'group_meta_quiz_quiz',
      'label' => array(
        'format' => 'hidden',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '1',
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
          '_error_element' => 'default_value_widget][field_meta_quiz_text][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Description',
      'weight' => 0,
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('Icon');
  t('Icon passed');
  t('Quiz');

  return $fields;
}
