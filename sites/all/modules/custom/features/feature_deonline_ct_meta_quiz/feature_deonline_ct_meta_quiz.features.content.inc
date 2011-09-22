<?php

/**
 * Implementation of hook_content_default_fields().
 */
function feature_deonline_ct_meta_quiz_content_default_fields() {
  $fields = array();

  // Exported field: field_meta_quiz_quiz
  $fields['meta_quiz-field_meta_quiz_quiz'] = array(
    'field_name' => 'field_meta_quiz_quiz',
    'type_name' => 'meta_quiz',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_meta_quiz_quiz][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Quiz',
      'weight' => '-4',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Quiz');

  return $fields;
}
