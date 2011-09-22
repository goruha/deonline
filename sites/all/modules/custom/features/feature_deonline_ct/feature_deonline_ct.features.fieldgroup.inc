<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function feature_deonline_ct_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_cr_additional_info
  $groups['course_request-group_cr_additional_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'course_request',
    'group_name' => 'group_cr_additional_info',
    'label' => 'Дополнительная информация',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
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
        'label' => 'above',
      ),
      'node_wizard' => array(
        'step' => '2',
        'button_label' => 1,
      ),
    ),
    'weight' => '34',
    'parent' => '',
    'fields' => array(
      '0' => 'field_cr_level',
      '1' => 'field_cr_comments',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_cr_info
  $groups['course_request-group_cr_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'course_request',
    'group_name' => 'group_cr_info',
    'label' => 'Заявка',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
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
        'label' => 'above',
      ),
      'node_wizard' => array(
        'step' => '1',
        'button_label' => 1,
      ),
    ),
    'weight' => '33',
    'parent' => '',
    'fields' => array(
      '0' => 'field_cr_date',
      '1' => 'field_cr_teacher',
      '2' => 'field_cr_course',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_profile_contacts
  $groups['profile-group_profile_contacts'] = array(
    'group_type' => 'standard',
    'type_name' => 'profile',
    'group_name' => 'group_profile_contacts',
    'label' => 'Контакты',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '35',
        'parent' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
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
    ),
    'weight' => '35',
    'parent' => '',
    'fields' => array(
      '0' => 'field_profile_contact_skype',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_program_type_prices
  $groups['program_types-group_program_type_prices'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'program_types',
    'group_name' => 'group_program_type_prices',
    'label' => 'Цены',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '0',
        'parent' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'simple',
          'exclude' => 1,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 1,
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
            'format' => 'table-multiple',
            'exclude' => 0,
          ),
          'full' => array(
            'format' => 'table-multiple',
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
    'weight' => '0',
    'parent' => '',
    'fields' => array(
      '0' => 'field_pt_price_type',
      '1' => 'field_price_60_common',
      '2' => 'field_price_90_common',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_tp_portfolio
  $groups['teacher_profile-group_tp_portfolio'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'teacher_profile',
    'group_name' => 'group_tp_portfolio',
    'label' => 'Резюме',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
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
        'label' => NULL,
      ),
      'multigroup' => array(
        'multiple-columns' => 0,
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
      ),
    ),
    'weight' => '35',
    'parent' => '',
    'fields' => array(
      '0' => 'field_tp_portfolio_period',
      '1' => 'field_tp_portfolio_case',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Дополнительная информация');
  t('Заявка');
  t('Контакты');
  t('Резюме');
  t('Цены');

  return $groups;
}
