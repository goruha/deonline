<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function feature_deonline_ct_meta_quiz_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_meta_quiz_quiz
  $groups['meta_quiz-group_meta_quiz_quiz'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'meta_quiz',
    'group_name' => 'group_meta_quiz_quiz',
    'label' => 'Quiz',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-4',
        'parent' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        'settings' => array(),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
      'multigroup' => array(
        'multiple-columns' => 1,
        'required' => 1,
        'multiple' => '1',
        'labels' => array(
          '0' => '',
          '1' => '',
          '2' => '',
          '3' => '',
          '4' => '',
          '5' => '',
          '6' => '',
          '7' => '',
          '8' => '',
          '9' => '',
        ),
        'subgroup' => array(
          'weight' => -20,
          'label' => 'above',
          'teaser' => array(
            'format' => 'fieldset',
            'exclude' => 0,
          ),
          'full' => array(
            'format' => 'hr',
            'exclude' => 0,
          ),
          '4' => array(
            'format' => 'fieldset',
            'exclude' => 0,
          ),
          'token' => array(
            'format' => 'fieldset',
            'exclude' => 0,
          ),
        ),
      ),
    ),
    'weight' => '-4',
    'parent' => '',
    'fields' => array(
      '0' => 'field_meta_quiz_quiz',
      '1' => 'field_meta_quiz_image',
      '2' => 'field_meta_quiz_image_passed',
      '3' => 'field_meta_quiz_text',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Quiz');

  return $groups;
}
