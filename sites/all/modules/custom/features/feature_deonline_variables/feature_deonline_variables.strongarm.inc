<?php

/**
 * Implementation of hook_strongarm().
 */
function feature_deonline_variables_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_hover_active_links_block';
  $strongarm->value = array(
    'admin%2Fbuild%2Fblock%2Fconfigure%2F%25module%2F%25id' => 'admin%2Fbuild%2Fblock%2Fconfigure%2F%25module%2F%25id',
    'admin%2Fbuild%2Fblock%2Fadd' => 'admin%2Fbuild%2Fblock%2Fadd',
  );
  $export['admin_hover_active_links_block'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_hover_active_links_node';
  $strongarm->value = array(
    'node%2F%5Bnid%5D%2Fedit' => 'node%2F%5Bnid%5D%2Fedit',
    'node%2F%5Bnid%5D%2Fadmin_hover%2Fpublish' => 'node%2F%5Bnid%5D%2Fadmin_hover%2Fpublish',
    'node%2F%5Bnid%5D%2Fadmin_hover%2Funpublish' => 'node%2F%5Bnid%5D%2Fadmin_hover%2Funpublish',
    'node%2F%5Bnid%5D%2Fadmin_hover%2Fpromote' => 'node%2F%5Bnid%5D%2Fadmin_hover%2Fpromote',
    'node%2F%5Bnid%5D%2Fadmin_hover%2Funpromote' => 'node%2F%5Bnid%5D%2Fadmin_hover%2Funpromote',
    'node%2F%5Bnid%5D%2Fadmin_hover%2Fmake_sticky' => 'node%2F%5Bnid%5D%2Fadmin_hover%2Fmake_sticky',
    'node%2F%5Bnid%5D%2Fadmin_hover%2Fmake_unsticky' => 'node%2F%5Bnid%5D%2Fadmin_hover%2Fmake_unsticky',
    'node%2F%5Bnid%5D%2Fdelete' => 'node%2F%5Bnid%5D%2Fdelete',
    'node%2F%5Bnid%5D%2Fclone' => 'node%2F%5Bnid%5D%2Fclone',
    'node%2F%5Bnid%5D%2Fdevel%2Fload' => 'node%2F%5Bnid%5D%2Fdevel%2Fload',
    'user%2F%5Bauthor-uid%5D' => 'user%2F%5Bauthor-uid%5D',
    'user%2F%5Bauthor-uid%5D%2Fedit' => 'user%2F%5Bauthor-uid%5D%2Fedit',
    'node%2Fadd%2F%5Btype-path%5D' => 'node%2Fadd%2F%5Btype-path%5D',
  );
  $export['admin_hover_active_links_node'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme';
  $strongarm->value = '0';
  $export['admin_theme'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_toolbar';
  $strongarm->value = array(
    'layout' => 'vertical',
    'position' => 'nw',
    'behavior' => 'df',
    'blocks' => array(
      'admin_tools-clearcache' => -1,
      'admin-create' => -1,
      'admin-theme' => 1,
      'admin-account' => -1,
      'admin-menu' => 1,
      'admin-devel' => -1,
      'menu-menu-deonline-admin' => -1,
    ),
  );
  $export['admin_toolbar'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'anonymous';
  $strongarm->value = 'Guest';
  $export['anonymous'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_book';
  $strongarm->value = '0';
  $export['ant_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_course_request';
  $strongarm->value = '1';
  $export['ant_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_lesson';
  $strongarm->value = '0';
  $export['ant_lesson'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_level';
  $strongarm->value = '0';
  $export['ant_level'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_long_answer';
  $strongarm->value = '0';
  $export['ant_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_material_audio';
  $strongarm->value = '0';
  $export['ant_material_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_material_document';
  $strongarm->value = '0';
  $export['ant_material_document'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_material_video';
  $strongarm->value = '0';
  $export['ant_material_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_page';
  $strongarm->value = '0';
  $export['ant_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_book';
  $strongarm->value = '';
  $export['ant_pattern_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_course_request';
  $strongarm->value = 'request [author-name] [field_cr_course-title] [date]';
  $export['ant_pattern_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_lesson';
  $strongarm->value = '';
  $export['ant_pattern_lesson'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_level';
  $strongarm->value = '';
  $export['ant_pattern_level'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_long_answer';
  $strongarm->value = '';
  $export['ant_pattern_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_material_audio';
  $strongarm->value = '';
  $export['ant_pattern_material_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_material_document';
  $strongarm->value = '';
  $export['ant_pattern_material_document'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_material_video';
  $strongarm->value = '';
  $export['ant_pattern_material_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_page';
  $strongarm->value = '';
  $export['ant_pattern_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_profile';
  $strongarm->value = '[field_profile_name-formatted]';
  $export['ant_pattern_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_program_types';
  $strongarm->value = '';
  $export['ant_pattern_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_programm';
  $strongarm->value = '';
  $export['ant_pattern_programm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_teacher_profile';
  $strongarm->value = 'tp [field_profile_name-formatted] [field_profile_surname-formatted]';
  $export['ant_pattern_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_book';
  $strongarm->value = 0;
  $export['ant_php_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_course_request';
  $strongarm->value = 0;
  $export['ant_php_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_lesson';
  $strongarm->value = 0;
  $export['ant_php_lesson'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_level';
  $strongarm->value = 0;
  $export['ant_php_level'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_long_answer';
  $strongarm->value = 0;
  $export['ant_php_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_material_audio';
  $strongarm->value = 0;
  $export['ant_php_material_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_material_document';
  $strongarm->value = 0;
  $export['ant_php_material_document'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_material_video';
  $strongarm->value = 0;
  $export['ant_php_material_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_meta_quiz';
  $strongarm->value = 0;
  $export['ant_php_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_page';
  $strongarm->value = 0;
  $export['ant_php_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_profile';
  $strongarm->value = 0;
  $export['ant_php_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_program_types';
  $strongarm->value = 0;
  $export['ant_php_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_programm';
  $strongarm->value = 0;
  $export['ant_php_programm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_teacher_profile';
  $strongarm->value = 0;
  $export['ant_php_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_profile';
  $strongarm->value = '1';
  $export['ant_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_program_types';
  $strongarm->value = '0';
  $export['ant_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_programm';
  $strongarm->value = '0';
  $export['ant_programm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_teacher_profile';
  $strongarm->value = '1';
  $export['ant_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'audioconverter';
  $strongarm->value = '0';
  $export['audioconverter'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'audioconverter_all';
  $strongarm->value = '0';
  $export['audioconverter_all'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'audioconverter_field_m_audio_file';
  $strongarm->value = 1;
  $export['audioconverter_field_m_audio_file'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'audioconverter_on_save';
  $strongarm->value = '1';
  $export['audioconverter_on_save'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'audioconverter_wav_setting';
  $strongarm->value = '0';
  $export['audioconverter_wav_setting'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'audiofield_audioplayer';
  $strongarm->value = 'wpaudioplayer';
  $export['audiofield_audioplayer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'audiofield_players_dir';
  $strongarm->value = 'sites/all/libraries/player';
  $export['audiofield_players_dir'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_pattern';
  $strongarm->value = 'user-[uid]-[mail]';
  $export['aun_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_php';
  $strongarm->value = 0;
  $export['aun_php'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_ampersand';
  $strongarm->value = '0';
  $export['aun_punctuation_ampersand'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_asterisk';
  $strongarm->value = '0';
  $export['aun_punctuation_asterisk'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_at';
  $strongarm->value = '0';
  $export['aun_punctuation_at'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_back_slash';
  $strongarm->value = '0';
  $export['aun_punctuation_back_slash'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_backtick';
  $strongarm->value = '0';
  $export['aun_punctuation_backtick'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_caret';
  $strongarm->value = '0';
  $export['aun_punctuation_caret'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_colon';
  $strongarm->value = '0';
  $export['aun_punctuation_colon'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_comma';
  $strongarm->value = '0';
  $export['aun_punctuation_comma'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_dollar';
  $strongarm->value = '0';
  $export['aun_punctuation_dollar'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_double_quotes';
  $strongarm->value = '0';
  $export['aun_punctuation_double_quotes'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_equal';
  $strongarm->value = '0';
  $export['aun_punctuation_equal'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_exclamation';
  $strongarm->value = '0';
  $export['aun_punctuation_exclamation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_greater_than';
  $strongarm->value = '0';
  $export['aun_punctuation_greater_than'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_hash';
  $strongarm->value = '0';
  $export['aun_punctuation_hash'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_hyphen';
  $strongarm->value = '0';
  $export['aun_punctuation_hyphen'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_left_curly';
  $strongarm->value = '0';
  $export['aun_punctuation_left_curly'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_left_parenthesis';
  $strongarm->value = '0';
  $export['aun_punctuation_left_parenthesis'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_left_square';
  $strongarm->value = '0';
  $export['aun_punctuation_left_square'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_less_than';
  $strongarm->value = '0';
  $export['aun_punctuation_less_than'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_percent';
  $strongarm->value = '0';
  $export['aun_punctuation_percent'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_period';
  $strongarm->value = '0';
  $export['aun_punctuation_period'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_pipe';
  $strongarm->value = '0';
  $export['aun_punctuation_pipe'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_plus';
  $strongarm->value = '0';
  $export['aun_punctuation_plus'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_question_mark';
  $strongarm->value = '0';
  $export['aun_punctuation_question_mark'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_quotes';
  $strongarm->value = '0';
  $export['aun_punctuation_quotes'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_right_curly';
  $strongarm->value = '0';
  $export['aun_punctuation_right_curly'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_right_parenthesis';
  $strongarm->value = '0';
  $export['aun_punctuation_right_parenthesis'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_right_square';
  $strongarm->value = '0';
  $export['aun_punctuation_right_square'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_semicolon';
  $strongarm->value = '0';
  $export['aun_punctuation_semicolon'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_tilde';
  $strongarm->value = '0';
  $export['aun_punctuation_tilde'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_punctuation_underscore';
  $strongarm->value = '0';
  $export['aun_punctuation_underscore'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_reduce_ascii';
  $strongarm->value = 0;
  $export['aun_reduce_ascii'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_replace_whitespace';
  $strongarm->value = 1;
  $export['aun_replace_whitespace'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_separator';
  $strongarm->value = '-';
  $export['aun_separator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aun_update_on_edit';
  $strongarm->value = 1;
  $export['aun_update_on_edit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'backup_migrate_destination_id';
  $strongarm->value = 'manual';
  $export['backup_migrate_destination_id'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'backup_migrate_profile_id';
  $strongarm->value = 'e9405034093d121cac9aa074f4a51372';
  $export['backup_migrate_profile_id'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'backup_migrate_source_id';
  $strongarm->value = 'db';
  $export['backup_migrate_source_id'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_defaults';
  $strongarm->value = array(
    'cssStyles' => array(),
  );
  $export['beautytips_defaults'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'better_messages';
  $strongarm->value = array(
    'position' => 'tr',
    'vertical' => '0',
    'horizontal' => '10',
    'fixed' => 1,
    'width' => '400px',
    'autoclose' => '5',
    'opendelay' => '0.1',
    'disable_autoclose' => 1,
    'show_countdown' => 1,
    'hover_autoclose' => 1,
    'popin' => array(
      'effect' => 'fadeIn',
      'duration' => 'slow',
    ),
    'popout' => array(
      'effect' => 'fadeIn',
      'duration' => 'slow',
    ),
    'jquery_ui' => array(
      'draggable' => 0,
      'resizable' => NULL,
    ),
    'extra' => array(
      'pages' => '',
      'visibility' => '0',
    ),
  );
  $export['better_messages'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clean_url';
  $strongarm->value = '1';
  $export['clean_url'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'color_deonline_theme_files';
  $strongarm->value = array(
    0 => 'sites/default/files/color/deonline_theme-d11422fe/menu-collapsed.gif',
    1 => 'sites/default/files/color/deonline_theme-d11422fe/menu-collapsed-rtl.gif',
    2 => 'sites/default/files/color/deonline_theme-d11422fe/menu-expanded.gif',
    3 => 'sites/default/files/color/deonline_theme-d11422fe/menu-leaf.gif',
    4 => 'sites/default/files/color/deonline_theme-d11422fe/body.png',
    5 => 'sites/default/files/color/deonline_theme-d11422fe/bg-bar.png',
    6 => 'sites/default/files/color/deonline_theme-d11422fe/bg-bar-white.png',
    7 => 'sites/default/files/color/deonline_theme-d11422fe/bg-tab.png',
    8 => 'sites/default/files/color/deonline_theme-d11422fe/bg-navigation.png',
    9 => 'sites/default/files/color/deonline_theme-d11422fe/bg-content-left.png',
    10 => 'sites/default/files/color/deonline_theme-d11422fe/bg-content-right.png',
    11 => 'sites/default/files/color/deonline_theme-d11422fe/bg-content.png',
    12 => 'sites/default/files/color/deonline_theme-d11422fe/bg-navigation-item.png',
    13 => 'sites/default/files/color/deonline_theme-d11422fe/bg-navigation-item-hover.png',
    14 => 'sites/default/files/color/deonline_theme-d11422fe/gradient-inner.png',
    15 => 'sites/default/files/color/deonline_theme-d11422fe/logo.png',
    16 => 'sites/default/files/color/deonline_theme-d11422fe/screenshot.png',
  );
  $export['color_deonline_theme_files'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'color_deonline_theme_logo';
  $strongarm->value = 'sites/default/files/color/deonline_theme-d11422fe/logo.png';
  $export['color_deonline_theme_logo'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'color_deonline_theme_palette';
  $strongarm->value = array(
    'base' => '#b7a0ba',
    'link' => '#c70000',
    'top' => '#a1443a',
    'bottom' => '#f21107',
    'text' => '#515d52',
  );
  $export['color_deonline_theme_palette'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'color_deonline_theme_screenshot';
  $strongarm->value = 'sites/default/files/color/deonline_theme-d11422fe/screenshot.png';
  $export['color_deonline_theme_screenshot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'color_deonline_theme_stylesheets';
  $strongarm->value = array();
  $export['color_deonline_theme_stylesheets'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_quiz';
  $strongarm->value = '0';
  $export['comment_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'configurable_timezones';
  $strongarm->value = '1';
  $export['configurable_timezones'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_prices';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '3',
    'author' => '2',
    'options' => '4',
    'menu' => '1',
  );
  $export['content_extra_weights_prices'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_profile';
  $strongarm->value = array(
    'weight' => '0',
    'user_display' => 'full',
    'edit_link' => 0,
    'edit_tab' => 'top',
    'add_link' => 0,
    'registration_use' => 1,
    'admin_user_create_use' => 1,
    'registration_hide' => array(
      0 => 'field_profile_avatar',
      1 => 'other',
    ),
  );
  $export['content_profile_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_teacher_profile';
  $strongarm->value = array(
    'weight' => '0',
    'user_display' => 'full',
    'edit_link' => 0,
    'edit_tab' => 'sub',
    'add_link' => 1,
    'registration_use' => 0,
    'admin_user_create_use' => 0,
    'registration_hide' => array(),
  );
  $export['content_profile_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_book';
  $strongarm->value = 0;
  $export['content_profile_use_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_course_request';
  $strongarm->value = 0;
  $export['content_profile_use_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_lesson';
  $strongarm->value = 0;
  $export['content_profile_use_lesson'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_level';
  $strongarm->value = 0;
  $export['content_profile_use_level'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_long_answer';
  $strongarm->value = 0;
  $export['content_profile_use_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_material_audio';
  $strongarm->value = 0;
  $export['content_profile_use_material_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_material_document';
  $strongarm->value = 0;
  $export['content_profile_use_material_document'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_material_video';
  $strongarm->value = 0;
  $export['content_profile_use_material_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_meta_quiz';
  $strongarm->value = 0;
  $export['content_profile_use_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_page';
  $strongarm->value = 0;
  $export['content_profile_use_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_profile';
  $strongarm->value = 1;
  $export['content_profile_use_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_program_types';
  $strongarm->value = 0;
  $export['content_profile_use_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_programm';
  $strongarm->value = 0;
  $export['content_profile_use_programm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_teacher_profile';
  $strongarm->value = 1;
  $export['content_profile_use_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_api_use_iso8601';
  $strongarm->value = 0;
  $export['date_api_use_iso8601'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_api_version';
  $strongarm->value = '5.2';
  $export['date_api_version'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_default_timezone';
  $strongarm->value = 25200;
  $export['date_default_timezone'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_default_timezone_name';
  $strongarm->value = 'Asia/Omsk';
  $export['date_default_timezone_name'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_first_day';
  $strongarm->value = '0';
  $export['date_first_day'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_long';
  $strongarm->value = 'l, F j, Y - H:i';
  $export['date_format_long'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_medium';
  $strongarm->value = 'D, Y-m-d H:i';
  $export['date_format_medium'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_short';
  $strongarm->value = 'Y-m-d H:i';
  $export['date_format_short'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_page_manager_pages';
  $strongarm->value = array();
  $export['default_page_manager_pages'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dev_query';
  $strongarm->value = 1;
  $export['dev_query'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupal_http_request_fails';
  $strongarm->value = FALSE;
  $export['drupal_http_request_fails'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_ignored_orphans';
  $strongarm->value = array();
  $export['features_ignored_orphans'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffmpeg_executable_command';
  $strongarm->value = ' -i %audiofile %convertfile';
  $export['ffmpeg_executable_command'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffmpeg_executable_path';
  $strongarm->value = 'ffmpeg';
  $export['ffmpeg_executable_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_material_audio_field_m_audio_file';
  $strongarm->value = 0;
  $export['ffp_material_audio_field_m_audio_file'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fieldgroup_schema_version';
  $strongarm->value = 6000;
  $export['fieldgroup_schema_version'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_directory_path';
  $strongarm->value = 'sites/default/files';
  $export['file_directory_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_directory_temp';
  $strongarm->value = '/tmp';
  $export['file_directory_temp'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_downloads';
  $strongarm->value = '1';
  $export['file_downloads'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filefield_paths_schema_version';
  $strongarm->value = 6103;
  $export['filefield_paths_schema_version'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_html_1';
  $strongarm->value = 1;
  $export['filter_html_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_book';
  $strongarm->value = 'form-e8fc04c308d75f9250bcbfe2889d7074';
  $export['form_build_id_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_course_request';
  $strongarm->value = 'form-76fc2e2b166b775fe56f69aa4d6dc9fb';
  $export['form_build_id_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_lesson';
  $strongarm->value = 'form-d00d943d4aeab97a75d3f228de6e221a';
  $export['form_build_id_lesson'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_level';
  $strongarm->value = 'form-bb0348d5d394c09691abf64a6cdfc58b';
  $export['form_build_id_level'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_long_answer';
  $strongarm->value = 'form-849881294eac9de1baec97a9efeee67c';
  $export['form_build_id_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_material_audio';
  $strongarm->value = 'form-42d71dae9a63b2fb75e7574d85de621d';
  $export['form_build_id_material_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_material_document';
  $strongarm->value = 'form-84e62eec7f3f0fb83076b04d1cb7151d';
  $export['form_build_id_material_document'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_material_video';
  $strongarm->value = 'form-daa4dca2d3b580375bf258dcec52095a';
  $export['form_build_id_material_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_meta_quiz';
  $strongarm->value = 'form-7964b5910f7435491e5716c8a5932941';
  $export['form_build_id_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_page';
  $strongarm->value = 'form-52d4b8331f1d44f4148f6a7916d8c0a5';
  $export['form_build_id_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_prices';
  $strongarm->value = 'form-2aaa29c1b9ab55918310ccbe0db300d2';
  $export['form_build_id_prices'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_profile';
  $strongarm->value = 'form-75c559e72e1decb37cf9e62a539b8147';
  $export['form_build_id_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_program_types';
  $strongarm->value = 'form-961298ac44d2a48c08564603de50f695';
  $export['form_build_id_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_programm';
  $strongarm->value = 'form-6562c935664c9a3e38e410d9da7d2baa';
  $export['form_build_id_programm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_teacher_profile';
  $strongarm->value = 'form-3886a22a6ca85dcf32751c6ed8170a85';
  $export['form_build_id_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'gradebook_empty_grade';
  $strongarm->value = '--';
  $export['gradebook_empty_grade'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'gradebook_student_rids';
  $strongarm->value = array(
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $export['gradebook_student_rids'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'gradebook_teacher_rids';
  $strongarm->value = array(
    5 => 5,
    3 => 0,
    4 => 0,
  );
  $export['gradebook_teacher_rids'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'gradebooks_per_page';
  $strongarm->value = '25';
  $export['gradebooks_per_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_content-taxonomy-field_level_compexity';
  $strongarm->value = array(
    'config_id' => 'content-taxonomy-field_level_compexity',
    'save_lineage' => '0',
    'enforce_deepest' => '1',
    'entity_count' => '0',
    'require_entity' => '0',
    'resizable' => '1',
    'level_labels' => array(
      'status' => 0,
      'labels' => array(
        0 => '',
        1 => '',
      ),
    ),
    'dropbox' => array(
      'status' => 0,
      'title' => 'All selections',
      'limit' => '0',
      'reset_hs' => '1',
    ),
    'editability' => array(
      'status' => 0,
      'item_types' => array(
        0 => '',
        1 => '',
      ),
      'allowed_levels' => array(
        0 => 1,
        1 => 1,
      ),
      'allow_new_levels' => 0,
      'max_levels' => '0',
    ),
  );
  $export['hs_config_content-taxonomy-field_level_compexity'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_content-taxonomy-field_pt_price_type';
  $strongarm->value = array(
    'config_id' => 'content-taxonomy-field_pt_price_type',
    'save_lineage' => '0',
    'enforce_deepest' => '1',
    'entity_count' => '0',
    'require_entity' => '0',
    'resizable' => '0',
    'level_labels' => array(
      'status' => 0,
      'labels' => array(
        0 => '',
      ),
    ),
    'dropbox' => array(
      'status' => 0,
      'title' => 'All selections',
      'limit' => '0',
      'reset_hs' => '1',
    ),
    'editability' => array(
      'status' => 0,
      'item_types' => array(
        0 => '',
      ),
      'allowed_levels' => array(
        0 => 1,
      ),
      'allow_new_levels' => 0,
      'max_levels' => '0',
    ),
  );
  $export['hs_config_content-taxonomy-field_pt_price_type'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_taxonomy-5';
  $strongarm->value = array(
    'config_id' => 'taxonomy-5',
    'save_lineage' => '0',
    'enforce_deepest' => '0',
    'entity_count' => '0',
    'require_entity' => '0',
    'resizable' => '1',
    'level_labels' => array(
      'status' => 0,
    ),
    'dropbox' => array(
      'status' => 0,
      'title' => 'All selections',
      'limit' => '0',
      'reset_hs' => '1',
    ),
    'editability' => array(
      'status' => 0,
      'allow_new_levels' => 0,
      'max_levels' => '0',
    ),
  );
  $export['hs_config_taxonomy-5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_toolkit';
  $strongarm->value = 'gd';
  $export['image_toolkit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_crop_query_string';
  $strongarm->value = 1315144530;
  $export['imagefield_crop_query_string'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'install_profile';
  $strongarm->value = 'default';
  $export['install_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'install_task';
  $strongarm->value = 'done';
  $export['install_task'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'install_time';
  $strongarm->value = 1307500015;
  $export['install_time'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'javascript_parsed';
  $strongarm->value = array();
  $export['javascript_parsed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_replace';
  $strongarm->value = TRUE;
  $export['jquery_update_replace'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_confirm_email_at_registration';
  $strongarm->value = '0';
  $export['logintoboggan_confirm_email_at_registration'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_immediate_login_on_register';
  $strongarm->value = 1;
  $export['logintoboggan_immediate_login_on_register'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_login_successful_message';
  $strongarm->value = '0';
  $export['logintoboggan_login_successful_message'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_login_with_email';
  $strongarm->value = '1';
  $export['logintoboggan_login_with_email'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_minimum_password_length';
  $strongarm->value = '0';
  $export['logintoboggan_minimum_password_length'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_override_destination_parameter';
  $strongarm->value = 0;
  $export['logintoboggan_override_destination_parameter'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_pre_auth_role';
  $strongarm->value = '2';
  $export['logintoboggan_pre_auth_role'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_purge_unvalidated_user_interval';
  $strongarm->value = '0';
  $export['logintoboggan_purge_unvalidated_user_interval'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_redirect_on_confirm';
  $strongarm->value = '';
  $export['logintoboggan_redirect_on_confirm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_redirect_on_register';
  $strongarm->value = 'user';
  $export['logintoboggan_redirect_on_register'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_default_node_menu';
  $strongarm->value = 'primary-links';
  $export['menu_default_node_menu'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_expanded';
  $strongarm->value = array();
  $export['menu_expanded'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_masks';
  $strongarm->value = array(
    0 => 127,
    1 => 125,
    2 => 117,
    3 => 116,
    4 => 63,
    5 => 62,
    6 => 61,
    7 => 60,
    8 => 59,
    9 => 58,
    10 => 57,
    11 => 56,
    12 => 44,
    13 => 31,
    14 => 30,
    15 => 29,
    16 => 28,
    17 => 24,
    18 => 23,
    19 => 21,
    20 => 15,
    21 => 14,
    22 => 13,
    23 => 11,
    24 => 10,
    25 => 9,
    26 => 7,
    27 => 6,
    28 => 5,
    29 => 3,
    30 => 2,
    31 => 1,
  );
  $export['menu_masks'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_primary_links_source';
  $strongarm->value = 'primary-links';
  $export['menu_primary_links_source'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_secondary_links_source';
  $strongarm->value = 'primary-links';
  $export['menu_secondary_links_source'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'meta_quiz_field_meta_quiz';
  $strongarm->value = 'field_meta_quiz_quiz';
  $export['meta_quiz_field_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'meta_quiz_field_meta_quiz_meta_quiz';
  $strongarm->value = 'field_meta_quiz_quiz';
  $export['meta_quiz_field_meta_quiz_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_book';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_course_request';
  $strongarm->value = '0';
  $export['more_node_buttons_cancel_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_lesson';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_lesson'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_level';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_level'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_long_answer';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_matching';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_matching'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_material_audio';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_material_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_material_document';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_material_document'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_material_video';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_material_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_meta_quiz';
  $strongarm->value = '0';
  $export['more_node_buttons_cancel_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_multichoice';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_multichoice'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_page';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_profile';
  $strongarm->value = '0';
  $export['more_node_buttons_cancel_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_program_types';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_programm';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_programm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_quiz';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_quiz_directions';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_quiz_directions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_book';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_course_request';
  $strongarm->value = 0;
  $export['more_node_buttons_cancel_referer_redirect_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_lesson';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_lesson'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_level';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_level'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_long_answer';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_matching';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_matching'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_material_audio';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_material_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_material_document';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_material_document'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_material_video';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_material_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_meta_quiz';
  $strongarm->value = 0;
  $export['more_node_buttons_cancel_referer_redirect_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_multichoice';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_multichoice'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_page';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_profile';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_program_types';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_programm';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_programm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_quiz';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_quiz_directions';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_quiz_directions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_scale';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_scale'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_short_answer';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_short_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_story';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_story'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_teacher_profile';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_referer_redirect_truefalse';
  $strongarm->value = 1;
  $export['more_node_buttons_cancel_referer_redirect_truefalse'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_scale';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_scale'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_short_answer';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_short_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_story';
  $strongarm->value = '0';
  $export['more_node_buttons_cancel_story'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_teacher_profile';
  $strongarm->value = '0';
  $export['more_node_buttons_cancel_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_cancel_truefalse';
  $strongarm->value = '2';
  $export['more_node_buttons_cancel_truefalse'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_book';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_course_request';
  $strongarm->value = '0';
  $export['more_node_buttons_sac_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_lesson';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_lesson'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_level';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_level'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_long_answer';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_matching';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_matching'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_material_audio';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_material_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_material_document';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_material_document'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_material_video';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_material_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_meta_quiz';
  $strongarm->value = '0';
  $export['more_node_buttons_sac_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_multichoice';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_multichoice'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_page';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_profile';
  $strongarm->value = '0';
  $export['more_node_buttons_sac_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_program_types';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_programm';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_programm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_quiz';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_quiz_directions';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_quiz_directions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_scale';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_scale'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_short_answer';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_short_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_story';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_story'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_teacher_profile';
  $strongarm->value = '0';
  $export['more_node_buttons_sac_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sac_truefalse';
  $strongarm->value = '3';
  $export['more_node_buttons_sac_truefalse'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_book';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_course_request';
  $strongarm->value = '0';
  $export['more_node_buttons_sacn_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_lesson';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_lesson'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_level';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_level'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_long_answer';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_matching';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_matching'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_material_audio';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_material_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_material_document';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_material_document'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_material_video';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_material_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_meta_quiz';
  $strongarm->value = '0';
  $export['more_node_buttons_sacn_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_multichoice';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_multichoice'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_page';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_profile';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_program_types';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_programm';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_programm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_quiz';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_quiz_directions';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_quiz_directions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_scale';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_scale'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_short_answer';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_short_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_story';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_story'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_teacher_profile';
  $strongarm->value = '0';
  $export['more_node_buttons_sacn_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_sacn_truefalse';
  $strongarm->value = '4';
  $export['more_node_buttons_sacn_truefalse'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_book';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_course_request';
  $strongarm->value = 0;
  $export['more_node_buttons_tabcn_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_lesson';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_lesson'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_level';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_level'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_long_answer';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_matching';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_matching'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_material_audio';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_material_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_material_document';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_material_document'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_material_video';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_material_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_meta_quiz';
  $strongarm->value = 0;
  $export['more_node_buttons_tabcn_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_multichoice';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_multichoice'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_page';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_profile';
  $strongarm->value = 0;
  $export['more_node_buttons_tabcn_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_program_types';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_programm';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_programm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_quiz';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_quiz_directions';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_quiz_directions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_scale';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_scale'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_short_answer';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_short_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_story';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_story'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_teacher_profile';
  $strongarm->value = 0;
  $export['more_node_buttons_tabcn_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_tabcn_truefalse';
  $strongarm->value = 1;
  $export['more_node_buttons_tabcn_truefalse'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'more_node_buttons_values';
  $strongarm->value = array(
    'cancel' => 'Cancel',
    'sac' => 'Save and continue',
    'sacn' => 'Save and create new',
    'tabcn' => 'Create new',
  );
  $export['more_node_buttons_values'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_admin_theme';
  $strongarm->value = 1;
  $export['node_admin_theme'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_forum';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_forum'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_long_answer';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_matching';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_matching'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_multichoice';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_multichoice'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_prices';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_prices'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_scale';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_scale'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_short_answer';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_short_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_truefalse';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_truefalse'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_button_preview_show_course_request';
  $strongarm->value = 0;
  $export['node_wizard_button_preview_show_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_button_preview_show_meta_quiz';
  $strongarm->value = 0;
  $export['node_wizard_button_preview_show_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_button_preview_show_profile';
  $strongarm->value = 0;
  $export['node_wizard_button_preview_show_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_extra_body_field_course_request';
  $strongarm->value = '1';
  $export['node_wizard_extra_body_field_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_extra_title_course_request';
  $strongarm->value = '1';
  $export['node_wizard_extra_title_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_extra_title_meta_quiz';
  $strongarm->value = '1';
  $export['node_wizard_extra_title_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_show_steps_numbers_course_request';
  $strongarm->value = 0;
  $export['node_wizard_show_steps_numbers_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_show_steps_numbers_meta_quiz';
  $strongarm->value = 1;
  $export['node_wizard_show_steps_numbers_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_show_steps_numbers_profile';
  $strongarm->value = 1;
  $export['node_wizard_show_steps_numbers_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_steps_course_request';
  $strongarm->value = '2';
  $export['node_wizard_steps_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_steps_meta_quiz';
  $strongarm->value = '1';
  $export['node_wizard_steps_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_steps_profile';
  $strongarm->value = '1';
  $export['node_wizard_steps_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_use_fieldset_labels_course_request';
  $strongarm->value = 1;
  $export['node_wizard_use_fieldset_labels_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_use_fieldset_labels_meta_quiz';
  $strongarm->value = 0;
  $export['node_wizard_use_fieldset_labels_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_wizard_use_fieldset_labels_profile';
  $strongarm->value = 0;
  $export['node_wizard_use_fieldset_labels_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess-grants';
  $strongarm->value = array(
    'view' => 0,
    'edit' => 0,
    'delete' => 0,
  );
  $export['nodeaccess-grants'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess-preserve';
  $strongarm->value = 1;
  $export['nodeaccess-preserve'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess-priority';
  $strongarm->value = 0;
  $export['nodeaccess-priority'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess-roles';
  $strongarm->value = array(
    3 => 0,
    1 => 0,
    2 => 0,
    4 => 0,
    5 => 0,
  );
  $export['nodeaccess-roles'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess-types';
  $strongarm->value = array(
    'panel' => 0,
    'lesson' => 0,
    'material_audio' => 0,
    'material_document' => 0,
    'material_video' => 0,
    'page' => 0,
    'profile' => 0,
    'programm' => 0,
    'story' => 0,
    'teacher_profile' => 0,
  );
  $export['nodeaccess-types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_authors';
  $strongarm->value = array(
    'lesson' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    'material_audio' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    'material_document' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    'material_video' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    'page' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    'profile' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    'programm' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    'story' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    'teacher_profile' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    'level' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
    'program_types' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
    'book' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
    'quiz' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
    'long_answer' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
    'matching' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
    'multichoice' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
    'quiz_directions' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
    'scale' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
    'short_answer' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
    'truefalse' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
    'course_request' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
    'meta_quiz' => array(
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
    ),
  );
  $export['nodeaccess_authors'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_book';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_course_request';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_lesson';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    2 => array(
      'gid' => 3,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    3 => array(
      'gid' => 4,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    4 => array(
      'gid' => 5,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_lesson'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_level';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_level'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_long_answer';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_matching';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_matching'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_material_audio';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    2 => array(
      'gid' => 3,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    3 => array(
      'gid' => 4,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    4 => array(
      'gid' => 5,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_material_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_material_document';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    2 => array(
      'gid' => 3,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    3 => array(
      'gid' => 4,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    4 => array(
      'gid' => 5,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_material_document'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_material_video';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    2 => array(
      'gid' => 3,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    3 => array(
      'gid' => 4,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    4 => array(
      'gid' => 5,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_material_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_meta_quiz';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_multichoice';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_multichoice'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_page';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    2 => array(
      'gid' => 3,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    3 => array(
      'gid' => 4,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    4 => array(
      'gid' => 5,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_profile';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    2 => array(
      'gid' => 3,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    3 => array(
      'gid' => 4,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    4 => array(
      'gid' => 5,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_program_types';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_programm';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    2 => array(
      'gid' => 3,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    3 => array(
      'gid' => 4,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    4 => array(
      'gid' => 5,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_programm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_quiz';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_quiz_directions';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_quiz_directions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_scale';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_scale'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_short_answer';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_short_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_story';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    2 => array(
      'gid' => 3,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    3 => array(
      'gid' => 4,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    4 => array(
      'gid' => 5,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_story'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_teacher_profile';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    2 => array(
      'gid' => 3,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    3 => array(
      'gid' => 4,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
    ),
    4 => array(
      'gid' => 5,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_truefalse';
  $strongarm->value = array(
    0 => array(
      'gid' => 1,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
    1 => array(
      'gid' => 2,
      'realm' => 'nodeaccess_rid',
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
    ),
  );
  $export['nodeaccess_truefalse'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodequeue_links';
  $strongarm->value = FALSE;
  $export['nodequeue_links'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodes';
  $strongarm->value = array(
    'page' => 'page',
    'profile' => 0,
    'story' => 0,
    'teacher_profile' => 0,
    'material_audio' => 0,
    'material_document' => 0,
    'programm' => 0,
    'lesson' => 0,
  );
  $export['nodes'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_manager_node_view_disabled';
  $strongarm->value = FALSE;
  $export['page_manager_node_view_disabled'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_legacy_rendering_mode';
  $strongarm->value = FALSE;
  $export['panels_legacy_rendering_mode'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_auto_revisioning';
  $strongarm->value = 1;
  $export['quiz_auto_revisioning'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_autotitle_length';
  $strongarm->value = '50';
  $export['quiz_autotitle_length'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_def_uid';
  $strongarm->value = '10';
  $export['quiz_def_uid'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_default_close';
  $strongarm->value = '30';
  $export['quiz_default_close'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_durod';
  $strongarm->value = 0;
  $export['quiz_durod'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_email_results';
  $strongarm->value = 0;
  $export['quiz_email_results'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_email_results_body';
  $strongarm->value = 'Dear !author

!taker attended the quiz !title on !date
Test Description : !desc
!taker got !correct out of !total points in !minutes minutes. Score given in percentage is !percentage
You can access the result here !url
';
  $export['quiz_email_results_body'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_email_results_body_taker';
  $strongarm->value = 'Dear !taker

You attended the quiz !title on !date
Test Description : !desc
You got !correct out of !total points in !minutes minutes. Score given in percentage is !percentage
You can access the result here !url
';
  $export['quiz_email_results_body_taker'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_email_results_subject';
  $strongarm->value = '!title Results Notice from !sitename';
  $export['quiz_email_results_subject'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_email_results_subject_taker';
  $strongarm->value = '!title Results Notice from !sitename';
  $export['quiz_email_results_subject_taker'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_has_timer';
  $strongarm->value = 0;
  $export['quiz_has_timer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_has_userpoints';
  $strongarm->value = 0;
  $export['quiz_has_userpoints'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_index_questions';
  $strongarm->value = 0;
  $export['quiz_index_questions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_max_result_options';
  $strongarm->value = '5';
  $export['quiz_max_result_options'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_name';
  $strongarm->value = 'Тест';
  $export['quiz_name'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_remove_partial_quiz_record';
  $strongarm->value = '0';
  $export['quiz_remove_partial_quiz_record'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_results_to_quiz_author';
  $strongarm->value = 0;
  $export['quiz_results_to_quiz_author'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_use_passfail';
  $strongarm->value = 1;
  $export['quiz_use_passfail'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_meta_quiz';
  $strongarm->value = 0;
  $export['show_diff_inline_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_profile';
  $strongarm->value = 0;
  $export['show_diff_inline_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_meta_quiz';
  $strongarm->value = 1;
  $export['show_preview_changes_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_profile';
  $strongarm->value = 1;
  $export['show_preview_changes_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_403';
  $strongarm->value = '';
  $export['site_403'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_footer';
  $strongarm->value = '';
  $export['site_footer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'programms';
  $export['site_frontpage'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_mail';
  $strongarm->value = 'goruha@gmail.com';
  $export['site_mail'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_mission';
  $strongarm->value = '';
  $export['site_mission'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'Центр дистанционного обучения';
  $export['site_name'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_offline';
  $strongarm->value = 0;
  $export['site_offline'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_slogan';
  $strongarm->value = '';
  $export['site_slogan'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_acquia_marina';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
      'display-1-region-middle' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
        'marina-general-styles' => array(),
        'marina-list-styles' => '',
        'marina-block-title-styles' => '',
        'marina-block-title-icon-styles' => '',
      ),
      'view-levels-display-default' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
        'marina-general-styles' => array(),
        'marina-list-styles' => '',
        'marina-block-title-styles' => '',
        'marina-block-title-icon-styles' => '',
      ),
      'view-prices-display-default' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
        'marina-general-styles' => array(),
        'marina-list-styles' => '',
        'marina-block-title-styles' => '',
        'marina-block-title-icon-styles' => '',
      ),
    ),
  );
  $export['skinr_acquia_marina'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_acquia_prosper';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
      'display-1-region-middle' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
        'prosper-general-styles' => '',
        'prosper-common-styles' => array(),
      ),
      'view-levels-display-default' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
        'prosper-general-styles' => '',
        'prosper-common-styles' => array(),
      ),
      'view-prices-display-default' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
        'prosper-general-styles' => '',
        'prosper-common-styles' => array(),
      ),
    ),
  );
  $export['skinr_acquia_prosper'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_ad_novus';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
    ),
  );
  $export['skinr_ad_novus'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_ad_novus-fluid';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
    ),
  );
  $export['skinr_ad_novus-fluid'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_bluemarine';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
    ),
  );
  $export['skinr_bluemarine'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_chameleon';
  $strongarm->value = array(
    'block' => array(
      'user-1' => array(),
      'menu-primary-links' => array(),
      'user-0' => array(),
      'modalframe_register-0' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'page' => array(),
      'program_types' => array(),
      'course_request' => array(),
      'profile' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
      'view-book_pages_formatter-display-default' => array(),
      'view-teacher_widget-display-default' => array(),
    ),
  );
  $export['skinr_chameleon'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_cube';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
    ),
  );
  $export['skinr_cube'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_deonline_theme';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(
        'title-color' => 'white-title',
        'link-color' => 'block-white-links',
        'fusion-login' => 'fusion-horiz-login',
      ),
      'menu-primary-links' => array(
        'background-color' => 'red-background',
        'link-color' => 'block-black-links',
        'fusion-general-styles' => array(
          'fusion-bold-links' => 'fusion-bold-links',
          'fusion-padding' => 'fusion-padding',
          'fusion-border' => 'fusion-border',
        ),
        'fusion-list-styles' => array(
          'fusion-list-bottom-border' => 'fusion-list-bottom-border',
          'fusion-list-vertical-spacing' => 'fusion-list-vertical-spacing',
        ),
      ),
      'user-1' => array(),
      'modalframe_register-0' => array(
        'fusion-login' => 'fusion-horiz-login',
      ),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'page' => array(),
      'program_types' => array(),
      'course_request' => array(),
      'profile' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(
        'options' => array(),
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        '_additional' => 'marina-rounded-corners marina-title-blue',
      ),
      'display-1-region-middle' => array(
        'options' => array(),
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        '_additional' => 'marina-rounded-corners marina-title-blue',
      ),
      'display-7-region-left' => array(
        'options' => array(),
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
      'display-7-region-right' => array(
        'options' => array(),
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
      'display-7-region-center' => array(
        'options' => array(),
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
      'display-7-pane-15' => array(
        'options' => array(),
        'background-color' => '',
        'header-background' => '',
        'title-color' => '',
        'link-color' => '',
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-general-styles' => array(),
        'fusion-equal-heights' => array(),
        'fusion-multicol' => '',
        'fusion-menu' => '',
        'fusion-list-styles' => array(),
        'fusion-login' => '',
        '_additional' => 'grid16-4 nested row',
      ),
      'display-7-pane-14' => array(
        'options' => array(),
        'background-color' => '',
        'header-background' => '',
        'title-color' => '',
        'link-color' => '',
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-general-styles' => array(),
        'fusion-equal-heights' => array(
          'equal-heights' => 'equal-heights',
        ),
        'fusion-multicol' => '',
        'fusion-menu' => '',
        'fusion-list-styles' => array(),
        'fusion-login' => '',
        '_additional' => 'grid16-4 nested row',
      ),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(
        'options' => array(),
        'marina-general-styles' => array(),
        'marina-list-styles' => '',
        'marina-block-title-styles' => '',
        'marina-block-title-icon-styles' => '',
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
      'view-levels-display-default' => array(
        'options' => array(),
        'marina-general-styles' => array(),
        'marina-list-styles' => '',
        'marina-block-title-styles' => '',
        'marina-block-title-icon-styles' => '',
        'grid-width' => array(),
        'fusion-content-alignment' => 'fusion-center-content',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
      'view-prices-display-default' => array(
        'options' => array(),
        'marina-general-styles' => array(),
        'marina-list-styles' => '',
        'marina-block-title-styles' => '',
        'marina-block-title-icon-styles' => '',
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
      'view-programms-display-default' => array(
        'options' => array(),
        'background-color' => 'gray-background',
        'header-background' => '',
        'title-color' => '',
        'link-color' => '',
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
      'view-program_types-display-default' => array(
        'options' => array(),
        'background-color' => 'gray-background',
        'header-background' => '',
        'title-color' => '',
        'link-color' => '',
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => 'fusion-float-imagefield-left',
      ),
      'view-book_pages_formatter-display-default' => array(
        'options' => array(),
        'background-color' => '',
        'header-background' => '',
        'title-color' => '',
        'link-color' => '',
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
      'view-teacher_widget-display-default' => array(
        'options' => array(),
        'background-color' => '',
        'header-background' => '',
        'title-color' => '',
        'link-color' => '',
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
      'view-node_program_type_teacher-display-default' => array(
        'options' => array(),
        'background-color' => '',
        'header-background' => '',
        'title-color' => '',
        'link-color' => '',
        'grid-width' => array(),
        'fusion-content-alignment' => 'fusion-center-content',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
      'view-meta_quiz_steps-display-default' => array(
        'options' => array(),
        'background-color' => '',
        'header-background' => '',
        'title-color' => '',
        'link-color' => '',
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
    ),
  );
  $export['skinr_deonline_theme'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_fusion_core';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
      'display-1-region-middle' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
      'view-levels-display-default' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
      'view-prices-display-default' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
    ),
  );
  $export['skinr_fusion_core'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_fusion_starter';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(
        'grid12-width' => array(),
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
      'display-1-region-middle' => array(
        'grid12-width' => array(),
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(
        'grid12-width' => array(),
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
      'view-levels-display-default' => array(
        'grid12-width' => array(),
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
      'view-prices-display-default' => array(
        'grid12-width' => array(),
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
      ),
    ),
  );
  $export['skinr_fusion_starter'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_fusion_starter_lite';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(
        'grid-width' => array(),
      ),
      'display-1-region-middle' => array(
        'grid-width' => array(),
      ),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(
        'grid-width' => array(),
      ),
      'view-levels-display-default' => array(
        'grid-width' => array(),
      ),
      'view-prices-display-default' => array(
        'grid-width' => array(),
      ),
    ),
  );
  $export['skinr_fusion_starter_lite'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_garland';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
    ),
  );
  $export['skinr_garland'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_marvin';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
    ),
  );
  $export['skinr_marvin'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_minnelli';
  $strongarm->value = array(
    'block' => array(
      'user-1' => array(),
      'menu-primary-links' => array(),
      'user-0' => array(),
      'modalframe_register-0' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'page' => array(),
      'program_types' => array(),
      'course_request' => array(),
      'profile' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
      'display-7-region-center' => array(),
      'display-7-pane-14' => array(),
      'display-7-region-left' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
      'view-book_pages_formatter-display-default' => array(),
      'view-teacher_widget-display-default' => array(),
    ),
  );
  $export['skinr_minnelli'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_mix_and_match';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(
        'fusion-general-styles' => array(
          'fusion-border' => 'fusion-border',
        ),
        'fusion-list-styles' => array(
          'fusion-list-bottom-border' => 'fusion-list-bottom-border',
          'fusion-list-vertical-spacing' => 'fusion-list-vertical-spacing',
        ),
        'background-color' => 'gray-background',
        'header-background' => 'gray-header',
      ),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
      'display-1-region-middle' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
      ),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
        'background-color' => '',
        'header-background' => '',
        'title-color' => '',
        'link-color' => '',
      ),
      'view-levels-display-default' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
        'background-color' => '',
        'header-background' => '',
        'title-color' => '',
        'link-color' => '',
      ),
      'view-prices-display-default' => array(
        'grid-width' => array(),
        'fusion-content-alignment' => '',
        'fusion-multicol' => '',
        'fusion-list-styles' => array(),
        'fusion-float-imagefield' => '',
        'background-color' => '',
        'header-background' => '',
        'title-color' => '',
        'link-color' => '',
      ),
    ),
  );
  $export['skinr_mix_and_match'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_pushbutton';
  $strongarm->value = array(
    'block' => array(
      'user-1' => array(),
      'menu-primary-links' => array(),
      'user-0' => array(),
      'modalframe_register-0' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'page' => array(),
      'program_types' => array(),
      'course_request' => array(),
      'profile' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
      'display-7-region-center' => array(),
      'display-7-pane-14' => array(),
      'display-7-region-left' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
      'view-book_pages_formatter-display-default' => array(),
      'view-teacher_widget-display-default' => array(),
    ),
  );
  $export['skinr_pushbutton'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_rootcandy';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
    ),
  );
  $export['skinr_rootcandy'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_rootcandy_dark';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
    ),
  );
  $export['skinr_rootcandy_dark'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_rootcandy_fixed';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
    ),
  );
  $export['skinr_rootcandy_fixed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_rubik';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
    ),
  );
  $export['skinr_rubik'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_book';
  $strongarm->value = array(
    0 => 'node_group',
  );
  $export['skinr_settings_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_course_request';
  $strongarm->value = array(
    0 => 'node_group',
  );
  $export['skinr_settings_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_lesson';
  $strongarm->value = array(
    0 => 'comment_group',
    1 => 'node_group',
  );
  $export['skinr_settings_lesson'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_level';
  $strongarm->value = array(
    0 => 'node_group',
  );
  $export['skinr_settings_level'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_long_answer';
  $strongarm->value = array(
    0 => 'node_group',
  );
  $export['skinr_settings_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_material_audio';
  $strongarm->value = array(
    0 => 'node_group',
  );
  $export['skinr_settings_material_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_material_document';
  $strongarm->value = array(
    0 => 'node_group',
  );
  $export['skinr_settings_material_document'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_material_video';
  $strongarm->value = array(
    0 => 'node_group',
  );
  $export['skinr_settings_material_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_meta_quiz';
  $strongarm->value = array(
    0 => 'node_group',
  );
  $export['skinr_settings_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_page';
  $strongarm->value = array(
    0 => 'node_group',
  );
  $export['skinr_settings_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_prices';
  $strongarm->value = array(
    0 => 'node_group',
  );
  $export['skinr_settings_prices'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_profile';
  $strongarm->value = array(
    0 => 'node_group',
  );
  $export['skinr_settings_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_program_types';
  $strongarm->value = array(
    0 => 'node_group',
  );
  $export['skinr_settings_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_programm';
  $strongarm->value = array(
    0 => 'comment_group',
    1 => 'node_group',
  );
  $export['skinr_settings_programm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_teacher_profile';
  $strongarm->value = array(
    0 => 'comment_group',
    1 => 'node_group',
  );
  $export['skinr_settings_teacher_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_tao';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
      'menu-primary-links' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
    ),
  );
  $export['skinr_tao'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_waffles';
  $strongarm->value = array(
    'block' => array(
      'user-0' => array(),
      'user-1' => array(),
    ),
    'comment' => array(
      'material_document' => array(),
      'programm' => array(),
    ),
    'node' => array(
      'programm' => array(),
      'material_audio' => array(),
      'material_video' => array(),
      'prices' => array(),
      'page' => array(),
    ),
    'panels' => array(
      'display-1-region-left' => array(),
      'display-1-region-middle' => array(),
    ),
    'views' => array(
      'view-user_materials-display-block_1' => array(),
    ),
  );
  $export['skinr_waffles'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sox_executable_command';
  $strongarm->value = '';
  $export['sox_executable_command'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sox_executable_path';
  $strongarm->value = '/usr/bin/sox';
  $export['sox_executable_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_actions';
  $strongarm->value = array(
    'swf' => 'swf',
    'flv' => 'video',
    'f4v' => 'video',
    'mp3' => 'audio',
    'jpg' => 'image',
    'jpeg' => 'image',
    'jpe' => 'image',
    'png' => 'image',
    'gif' => 'image',
  );
  $export['swftools_actions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_always_add_js';
  $strongarm->value = '1';
  $export['swftools_always_add_js'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_cache';
  $strongarm->value = '1';
  $export['swftools_cache'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_check_media';
  $strongarm->value = '1';
  $export['swftools_check_media'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_embed_method';
  $strongarm->value = 'swftools_swfobject2';
  $export['swftools_embed_method'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_error_output';
  $strongarm->value = '3';
  $export['swftools_error_output'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_extensions';
  $strongarm->value = array(
    'swf' => array(
      0 => 'swf',
    ),
    'video' => array(
      0 => 'flv',
      1 => 'f4v',
    ),
    'audio' => array(
      0 => 'mp3',
    ),
    'image' => array(
      0 => 'jpg',
      1 => 'jpeg',
      2 => 'jpe',
      3 => 'png',
      4 => 'gif',
    ),
  );
  $export['swftools_extensions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_flowplayer';
  $strongarm->value = array(
    'player' => 'flowplayer/FlowPlayerLP.swf',
    'usePlayOverlay' => 'true',
    'hideControls' => 'default',
    'controlBarGloss' => 'default',
    'showFullScreenButton' => 'default',
    'showPlayListButtons' => 'default',
    'autoPlay' => 'default',
    'loop' => 'default',
    'initialVolumePercentage' => '',
  );
  $export['swftools_flowplayer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_flv_display';
  $strongarm->value = 'flowplayer3_mediaplayer';
  $export['swftools_flv_display'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_flv_display_list';
  $strongarm->value = '0';
  $export['swftools_flv_display_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_grant_access_extensions';
  $strongarm->value = 'swf flv xml mp3 jpg jpeg png';
  $export['swftools_grant_access_extensions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_grant_access_to_cache';
  $strongarm->value = '0';
  $export['swftools_grant_access_to_cache'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_grant_access_to_private_files';
  $strongarm->value = '0';
  $export['swftools_grant_access_to_private_files'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_handlers';
  $strongarm->value = array(
    'swf' => 0,
    'video' => 'flowplayer',
    'video_list' => 'flowplayer',
    'audio' => '0',
    'audio_list' => '0',
    'image_list' => '0',
    'media_list' => 'flowplayer',
  );
  $export['swftools_handlers'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_html_alt';
  $strongarm->value = '<p>You are missing some Flash content that should appear here! Perhaps your browser cannot display it, or maybe it did not initialize correctly.</p>';
  $export['swftools_html_alt'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_html_alt_format';
  $strongarm->value = '1';
  $export['swftools_html_alt_format'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_image_display_list';
  $strongarm->value = '0';
  $export['swftools_image_display_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_javascript_location';
  $strongarm->value = '1';
  $export['swftools_javascript_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_media_display_list';
  $strongarm->value = '0';
  $export['swftools_media_display_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_media_url_dummy';
  $strongarm->value = '';
  $export['swftools_media_url_dummy'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_mime_types';
  $strongarm->value = array(
    'swf' => 'application/x-shockwave-flash',
    'flv' => 'video/x-flv',
    'mp3' => 'audio/mpeg',
    'jpg' => 'image/jpeg',
    'jpeg' => 'image/jpeg',
    'jpe' => 'image/jpeg',
    'png' => 'image/png',
    'gif' => 'image/gif',
  );
  $export['swftools_mime_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_mime_types_input';
  $strongarm->value = 'swf application/x-shockwave-flash
flv video/x-flv
mp3 audio/mpeg
jpg image/jpeg
jpeg image/jpeg
jpe image/jpeg
png image/png
gif image/gif';
  $export['swftools_mime_types_input'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_mp3_display';
  $strongarm->value = '0';
  $export['swftools_mp3_display'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_mp3_display_list';
  $strongarm->value = '0';
  $export['swftools_mp3_display_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_override_html_alt';
  $strongarm->value = '0';
  $export['swftools_override_html_alt'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_params';
  $strongarm->value = array(
    'version' => '7',
    'play' => 'true',
    'loop' => 'true',
    'menu' => 'false',
    'allowfullscreen' => 'true',
    'swliveconnect' => 'false',
    'bgcolor' => '',
    'quality' => 'autohigh',
    'scale' => 'showall',
    'wmode' => 'opaque',
    'align' => 'l',
    'salign' => 'tl',
    'allowscriptaccess' => 'sameDomain',
  );
  $export['swftools_params'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_player_path';
  $strongarm->value = '';
  $export['swftools_player_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_playlist_caching';
  $strongarm->value = 'here';
  $export['swftools_playlist_caching'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'swftools_playlist_path';
  $strongarm->value = 'playlists';
  $export['swftools_playlist_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sync';
  $strongarm->value = 'Create missing UUIDs';
  $export['sync'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_hierarchical_select_5';
  $strongarm->value = 0;
  $export['taxonomy_hierarchical_select_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_override_selector';
  $strongarm->value = TRUE;
  $export['taxonomy_override_selector'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_acquia_marina_settings';
  $strongarm->value = array(
    'user_notverified_display' => 1,
    'breadcrumb_display' => 1,
    'search_snippet' => 1,
    'search_info_type' => 1,
    'search_info_user' => 1,
    'search_info_date' => 1,
    'search_info_comment' => 1,
    'search_info_upload' => 1,
    'rebuild_registry' => 0,
    'fix_css_limit' => 0,
    'block_config_link' => 1,
    'grid_mask' => 0,
    'theme_grid' => 'grid16-960',
    'fluid_grid_width' => 'fluid-100',
    'sidebar_layout' => 'sidebars-split',
    'sidebar_first_width' => '3',
    'sidebar_last_width' => '3',
    'theme_font' => 'none',
    'theme_font_size' => 'font-size-12',
    'primary_menu_dropdown' => 1,
    'mission' => '',
    'default_logo' => 1,
    'logo_path' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'primary_links' => 1,
    'secondary_links' => 1,
    'toggle_logo' => 1,
    'toggle_favicon' => 1,
    'toggle_name' => 1,
    'toggle_search' => 0,
    'toggle_slogan' => 0,
    'toggle_mission' => 1,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_primary_links' => 1,
    'toggle_secondary_links' => 1,
    'toggle_node_info_page' => FALSE,
    'toggle_node_info_story' => 1,
    'theme_grid_options' => array(
      0 => 'grid16-960',
      1 => 'grid16-fluid',
    ),
  );
  $export['theme_acquia_marina_settings'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_acquia_prosper_settings';
  $strongarm->value = array(
    'user_notverified_display' => 1,
    'breadcrumb_display' => 1,
    'search_snippet' => 1,
    'search_info_type' => 1,
    'search_info_user' => 1,
    'search_info_date' => 1,
    'search_info_comment' => 1,
    'search_info_upload' => 1,
    'rebuild_registry' => 0,
    'fix_css_limit' => 0,
    'block_config_link' => 1,
    'grid_mask' => 0,
    'theme_grid' => 'grid16-960',
    'fluid_grid_width' => 'fluid-95',
    'sidebar_layout' => 'sidebars-split',
    'sidebar_first_width' => '3',
    'sidebar_last_width' => '3',
    'theme_font' => 'none',
    'theme_font_size' => 'font-size-12',
    'primary_menu_dropdown' => 1,
    'mission' => '',
    'default_logo' => 1,
    'logo_path' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'primary_links' => 1,
    'secondary_links' => 1,
    'toggle_logo' => 1,
    'toggle_favicon' => 1,
    'toggle_name' => 1,
    'toggle_search' => 0,
    'toggle_slogan' => 0,
    'toggle_mission' => 1,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_primary_links' => 1,
    'toggle_secondary_links' => 1,
    'toggle_node_info_page' => FALSE,
    'toggle_node_info_story' => 1,
    'theme_grid_options' => array(
      0 => 'grid16-960',
      1 => 'grid16-fluid',
    ),
  );
  $export['theme_acquia_prosper_settings'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'deonline_theme';
  $export['theme_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_deonline_theme_settings';
  $strongarm->value = array(
    'toggle_logo' => 0,
    'toggle_name' => 1,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_search' => 0,
    'toggle_favicon' => 1,
    'toggle_primary_links' => 1,
    'toggle_secondary_links' => 0,
    'default_logo' => 1,
    'logo_path' => 'sites/default/files/deonline_theme_logo.gif',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'theme_grid' => 'grid16-960',
    'fluid_grid_width' => 'fluid-100',
    'sidebar_layout' => 'sidebars-split',
    'sidebar_first_width' => '4',
    'sidebar_last_width' => '1',
    'theme_font' => 'none',
    'theme_font_size' => 'font-size-12',
    'primary_menu_dropdown' => 1,
    'breadcrumb_display' => 1,
    'user_notverified_display' => 1,
    'block_config_link' => 1,
    'grid_mask' => 1,
    'rebuild_registry' => 0,
    'fix_css_limit' => 0,
    'mix_and_match_body_bg' => 'black',
    'mix_and_match_page_bg' => 'white-page-bg',
    'mix_and_match_accent_color' => 'red-accents',
    'mix_and_match_footer_color' => 'lt-gray-footer',
    'mix_and_match_header_color' => 'black-headers',
    'mix_and_match_link_color' => 'gray-links',
    'mix_and_match_corners' => 'round-corners-11',
    'scheme' => '#b7a0ba,#c70000,#a1443a,#f21107,#515d52',
    'palette' => array(
      'base' => '#b7a0ba',
      'link' => '#c70000',
      'top' => '#a1443a',
      'bottom' => '#f21107',
      'text' => '#515d52',
    ),
    'theme' => 'deonline_theme',
    'info' => array(
      'schemes' => array(
        '#0072b9,#027ac6,#2385c2,#5ab5ee,#494949' => 'Blue Lagoon (Default)',
        '#464849,#2f416f,#2a2b2d,#5d6779,#494949' => 'Ash',
        '#55c0e2,#000000,#085360,#007e94,#696969' => 'Aquamarine',
        '#d5b048,#6c420e,#331900,#971702,#494949' => 'Belgian Chocolate',
        '#3f3f3f,#336699,#6598cb,#6598cb,#000000' => 'Bluemarine',
        '#d0cb9a,#917803,#efde01,#e6fb2d,#494949' => 'Citrus Blast',
        '#0f005c,#434f8c,#4d91ff,#1a1575,#000000' => 'Cold Day',
        '#c9c497,#0c7a00,#03961e,#7be000,#494949' => 'Greenbeam',
        '#ffe23d,#a9290a,#fc6d1d,#a30f42,#494949' => 'Mediterrano',
        '#788597,#3f728d,#a9adbc,#d4d4d4,#707070' => 'Mercury',
        '#5b5fa9,#5b5faa,#0a2352,#9fa8d5,#494949' => 'Nocturnal',
        '#7db323,#6a9915,#b5d52a,#7db323,#191a19' => 'Olivia',
        '#12020b,#1b1a13,#f391c6,#f41063,#898080' => 'Pink Plastic',
        '#b7a0ba,#c70000,#a1443a,#f21107,#515d52' => 'Shiny Tomato',
        '#18583d,#1b5f42,#34775a,#52bf90,#2d2d2d' => 'Teal Top',
        '' => 'Custom',
      ),
      'copy' => array(
        0 => 'images/menu-collapsed.gif',
        1 => 'images/menu-collapsed-rtl.gif',
        2 => 'images/menu-expanded.gif',
        3 => 'images/menu-leaf.gif',
      ),
      'css' => array(
        0 => 'style.css',
      ),
      'gradient' => array(
        0 => 0,
        1 => 37,
        2 => 760,
        3 => 121,
      ),
      'fill' => array(
        'base' => array(
          0 => 0,
          1 => 0,
          2 => 760,
          3 => 568,
        ),
        'link' => array(
          0 => 107,
          1 => 533,
          2 => 41,
          3 => 23,
        ),
      ),
      'slices' => array(
        'images/body.png' => array(
          0 => 0,
          1 => 37,
          2 => 1,
          3 => 280,
        ),
        'images/bg-bar.png' => array(
          0 => 202,
          1 => 530,
          2 => 76,
          3 => 14,
        ),
        'images/bg-bar-white.png' => array(
          0 => 202,
          1 => 506,
          2 => 76,
          3 => 14,
        ),
        'images/bg-tab.png' => array(
          0 => 107,
          1 => 533,
          2 => 41,
          3 => 23,
        ),
        'images/bg-navigation.png' => array(
          0 => 0,
          1 => 0,
          2 => 7,
          3 => 37,
        ),
        'images/bg-content-left.png' => array(
          0 => 40,
          1 => 117,
          2 => 50,
          3 => 352,
        ),
        'images/bg-content-right.png' => array(
          0 => 510,
          1 => 117,
          2 => 50,
          3 => 352,
        ),
        'images/bg-content.png' => array(
          0 => 299,
          1 => 117,
          2 => 7,
          3 => 200,
        ),
        'images/bg-navigation-item.png' => array(
          0 => 32,
          1 => 37,
          2 => 17,
          3 => 12,
        ),
        'images/bg-navigation-item-hover.png' => array(
          0 => 54,
          1 => 37,
          2 => 17,
          3 => 12,
        ),
        'images/gradient-inner.png' => array(
          0 => 646,
          1 => 307,
          2 => 112,
          3 => 42,
        ),
        'logo.png' => array(
          0 => 622,
          1 => 51,
          2 => 64,
          3 => 73,
        ),
        'screenshot.png' => array(
          0 => 0,
          1 => 37,
          2 => 400,
          3 => 240,
        ),
      ),
      'blend_target' => '#ffffff',
      'preview_image' => 'color/preview.png',
      'preview_css' => 'color/preview.css',
      'base_image' => 'color/base.png',
    ),
  );
  $export['theme_deonline_theme_settings'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_mix_and_match_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_search' => 0,
    'toggle_favicon' => 1,
    'toggle_primary_links' => 1,
    'toggle_secondary_links' => 1,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'theme_grid' => 'grid16-960',
    'fluid_grid_width' => 'fluid-100',
    'sidebar_layout' => 'sidebars-split',
    'sidebar_first_width' => '3',
    'sidebar_last_width' => '3',
    'theme_font' => 'none',
    'theme_font_size' => 'font-size-13',
    'primary_menu_dropdown' => 1,
    'breadcrumb_display' => 1,
    'user_notverified_display' => 1,
    'block_config_link' => 1,
    'grid_mask' => 0,
    'rebuild_registry' => 0,
    'fix_css_limit' => 0,
    'mix_and_match_body_bg' => 'gray',
    'mix_and_match_page_bg' => 'white-page-bg',
    'mix_and_match_accent_color' => 'gray-accents',
    'mix_and_match_footer_color' => 'default-footer',
    'mix_and_match_header_color' => 'default-headers',
    'mix_and_match_link_color' => 'default-links',
    'mix_and_match_corners' => 'round-corners-11',
  );
  $export['theme_mix_and_match_settings'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_settings';
  $strongarm->value = array(
    'toggle_node_info_page' => FALSE,
    'toggle_node_info_quiz' => 0,
  );
  $export['theme_settings'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_waffles_settings';
  $strongarm->value = array(
    'user_notverified_display' => 1,
    'breadcrumb_display' => 0,
    'search_snippet' => 1,
    'search_info_type' => 1,
    'search_info_user' => 1,
    'search_info_date' => 1,
    'search_info_comment' => 1,
    'search_info_upload' => 1,
    'mission_statement_pages' => 'home',
    'front_page_title_display' => 'title_slogan',
    'page_title_display_custom' => '',
    'other_page_title_display' => 'ptitle_slogan',
    'other_page_title_display_custom' => '',
    'configurable_separator' => ' | ',
    'meta_keywords' => '',
    'meta_description' => '',
    'taxonomy_display_default' => 'only',
    'taxonomy_format_default' => 'vocab',
    'taxonomy_enable_content_type' => 0,
    'submitted_by_author_default' => 1,
    'submitted_by_date_default' => 1,
    'submitted_by_enable_content_type' => 0,
    'readmore_default' => 'Read more',
    'readmore_title_default' => 'Read the rest of this posting.',
    'readmore_prefix_default' => '',
    'readmore_suffix_default' => '',
    'readmore_enable_content_type' => 0,
    'comment_singular_default' => '1 comment',
    'comment_plural_default' => '@count comments',
    'comment_title_default' => 'Jump to the first comment of this posting.',
    'comment_prefix_default' => '',
    'comment_suffix_default' => '',
    'comment_new_singular_default' => '1 new comment',
    'comment_new_plural_default' => '@count new comments',
    'comment_new_title_default' => 'Jump to the first new comment of this posting.',
    'comment_new_prefix_default' => '',
    'comment_new_suffix_default' => '',
    'comment_add_default' => 'Add new comment',
    'comment_add_title_default' => 'Add a new comment to this page.',
    'comment_add_prefix_default' => '',
    'comment_add_suffix_default' => '',
    'comment_node_default' => 'Add new comment',
    'comment_node_title_default' => 'Share your thoughts and opinions related to this posting.',
    'comment_node_prefix_default' => '',
    'comment_node_suffix_default' => '',
    'comment_enable_content_type' => 0,
    'mission' => '',
    'default_logo' => 1,
    'logo_path' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'primary_links' => 1,
    'secondary_links' => 1,
    'toggle_logo' => 1,
    'toggle_favicon' => 1,
    'toggle_name' => 1,
    'toggle_search' => 0,
    'toggle_slogan' => 0,
    'toggle_mission' => 1,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_primary_links' => 1,
    'toggle_secondary_links' => 1,
    'toggle_node_info_page' => FALSE,
    'toggle_node_info_story' => 1,
    'taxonomy_display_page' => 'only',
    'taxonomy_format_page' => 'vocab',
    'submitted_by_author_page' => 1,
    'submitted_by_date_page' => 1,
    'readmore_page' => NULL,
    'readmore_title_page' => NULL,
    'readmore_prefix_page' => NULL,
    'readmore_suffix_page' => NULL,
    'comment_singular_page' => '1 comment',
    'comment_plural_page' => '@count comments',
    'comment_title_page' => 'Jump to the first comment of this posting.',
    'comment_prefix_page' => '',
    'comment_suffix_page' => '',
    'comment_new_singular_page' => '1 new comment',
    'comment_new_plural_page' => '@count new comments',
    'comment_new_title_page' => 'Jump to the first new comment of this posting.',
    'comment_new_prefix_page' => '',
    'comment_new_suffix_page' => '',
    'comment_add_page' => 'Add new comment',
    'comment_add_title_page' => 'Add a new comment to this page.',
    'comment_add_prefix_page' => '',
    'comment_add_suffix_page' => '',
    'comment_node_page' => 'Add new comment',
    'comment_node_title_page' => 'Share your thoughts and opinions related to this posting.',
    'comment_node_prefix_page' => '',
    'comment_node_suffix_page' => '',
    'taxonomy_display_story' => 'only',
    'taxonomy_format_story' => 'vocab',
    'submitted_by_author_story' => 1,
    'submitted_by_date_story' => 1,
    'readmore_story' => NULL,
    'readmore_title_story' => NULL,
    'readmore_prefix_story' => NULL,
    'readmore_suffix_story' => NULL,
    'comment_singular_story' => '1 comment',
    'comment_plural_story' => '@count comments',
    'comment_title_story' => 'Jump to the first comment of this posting.',
    'comment_prefix_story' => '',
    'comment_suffix_story' => '',
    'comment_new_singular_story' => '1 new comment',
    'comment_new_plural_story' => '@count new comments',
    'comment_new_title_story' => 'Jump to the first new comment of this posting.',
    'comment_new_prefix_story' => '',
    'comment_new_suffix_story' => '',
    'comment_add_story' => 'Add new comment',
    'comment_add_title_story' => 'Add a new comment to this page.',
    'comment_add_prefix_story' => '',
    'comment_add_suffix_story' => '',
    'comment_node_story' => 'Add new comment',
    'comment_node_title_story' => 'Share your thoughts and opinions related to this posting.',
    'comment_node_prefix_story' => '',
    'comment_node_suffix_story' => '',
  );
  $export['theme_waffles_settings'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'transliteration_file_lowercase';
  $strongarm->value = 1;
  $export['transliteration_file_lowercase'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'transliteration_file_uploads';
  $strongarm->value = 1;
  $export['transliteration_file_uploads'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_comp_book';
  $strongarm->value = 'each';
  $export['unique_field_comp_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_comp_course_request';
  $strongarm->value = 'each';
  $export['unique_field_comp_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_comp_long_answer';
  $strongarm->value = 'each';
  $export['unique_field_comp_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_comp_meta_quiz';
  $strongarm->value = 'each';
  $export['unique_field_comp_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_comp_profile';
  $strongarm->value = 'each';
  $export['unique_field_comp_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_comp_program_types';
  $strongarm->value = 'each';
  $export['unique_field_comp_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_book';
  $strongarm->value = array();
  $export['unique_field_fields_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_course_request';
  $strongarm->value = array();
  $export['unique_field_fields_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_long_answer';
  $strongarm->value = array();
  $export['unique_field_fields_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_meta_quiz';
  $strongarm->value = array();
  $export['unique_field_fields_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_profile';
  $strongarm->value = array();
  $export['unique_field_fields_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_program_types';
  $strongarm->value = array(
    0 => 'field_pt_price_type',
  );
  $export['unique_field_fields_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_scope_book';
  $strongarm->value = 'type';
  $export['unique_field_scope_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_scope_course_request';
  $strongarm->value = 'type';
  $export['unique_field_scope_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_scope_long_answer';
  $strongarm->value = 'type';
  $export['unique_field_scope_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_scope_meta_quiz';
  $strongarm->value = 'type';
  $export['unique_field_scope_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_scope_profile';
  $strongarm->value = 'type';
  $export['unique_field_scope_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_scope_program_types';
  $strongarm->value = 'node';
  $export['unique_field_scope_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_show_matches_book';
  $strongarm->value = array();
  $export['unique_field_show_matches_book'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_show_matches_course_request';
  $strongarm->value = array();
  $export['unique_field_show_matches_course_request'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_show_matches_long_answer';
  $strongarm->value = array();
  $export['unique_field_show_matches_long_answer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_show_matches_meta_quiz';
  $strongarm->value = array();
  $export['unique_field_show_matches_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_show_matches_profile';
  $strongarm->value = array();
  $export['unique_field_show_matches_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_show_matches_program_types';
  $strongarm->value = array();
  $export['unique_field_show_matches_program_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_email_verification';
  $strongarm->value = TRUE;
  $export['user_email_verification'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_password_reset_body';
  $strongarm->value = '!username,

A request to reset the password for your account has been made at !site.

You may now log in to !uri_brief by clicking on this link or copying and pasting it in your browser:

!login_url

This is a one-time login, so it can be used only once. It expires after one day and nothing will happen if it\'s not used.

After logging in, you will be redirected to !edit_uri so you can change your password.';
  $export['user_mail_password_reset_body'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_password_reset_subject';
  $strongarm->value = 'Replacement login information for !username at !site';
  $export['user_mail_password_reset_subject'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_body';
  $strongarm->value = '!username,

A site administrator at !site has created an account for you. You may now log in to !login_uri using the following username and password:

username: !username
password: !password

You may also log in by clicking on this link or copying and pasting it in your browser:

!login_url

This is a one-time login, so it can be used only once.

After logging in, you will be redirected to !edit_uri so you can change your password.


--  !site team';
  $export['user_mail_register_admin_created_body'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_subject';
  $strongarm->value = 'An administrator created an account for you at !site';
  $export['user_mail_register_admin_created_subject'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_no_approval_required_body';
  $strongarm->value = '!username,

Thank you for registering at !site. You may now log in to !login_uri using the following username and password:

username: !username
password: !password

You may also log in by clicking on this link or copying and pasting it in your browser:

!login_url

This is a one-time login, so it can be used only once.

After logging in, you will be redirected to !edit_uri so you can change your password.


--  !site team';
  $export['user_mail_register_no_approval_required_body'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_no_approval_required_subject';
  $strongarm->value = 'Account details for !username at !site';
  $export['user_mail_register_no_approval_required_subject'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_pending_approval_body';
  $strongarm->value = '!username,

Thank you for registering at !site. Your application for an account is currently pending approval. Once it has been approved, you will receive another e-mail containing information about how to log in, set your password, and other details.


--  !site team';
  $export['user_mail_register_pending_approval_body'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_pending_approval_subject';
  $strongarm->value = 'Account details for !username at !site (pending admin approval)';
  $export['user_mail_register_pending_approval_subject'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_body';
  $strongarm->value = '!username,

Your account at !site has been activated.

You may now log in by clicking on this link or copying and pasting it in your browser:

!login_url

This is a one-time login, so it can be used only once.

After logging in, you will be redirected to !edit_uri so you can change your password.

Once you have set your own password, you will be able to log in to !login_uri in the future using:

username: !username
';
  $export['user_mail_status_activated_body'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_notify';
  $strongarm->value = 1;
  $export['user_mail_status_activated_notify'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_subject';
  $strongarm->value = 'Account details for !username at !site (approved)';
  $export['user_mail_status_activated_subject'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_body';
  $strongarm->value = '!username,

Your account on !site has been blocked.';
  $export['user_mail_status_blocked_body'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_notify';
  $strongarm->value = 0;
  $export['user_mail_status_blocked_notify'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_subject';
  $strongarm->value = 'Account details for !username at !site (blocked)';
  $export['user_mail_status_blocked_subject'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_deleted_body';
  $strongarm->value = '!username,

Your account on !site has been deleted.';
  $export['user_mail_status_deleted_body'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_deleted_notify';
  $strongarm->value = 0;
  $export['user_mail_status_deleted_notify'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_deleted_subject';
  $strongarm->value = 'Account details for !username at !site (deleted)';
  $export['user_mail_status_deleted_subject'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_default';
  $strongarm->value = '';
  $export['user_picture_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_dimensions';
  $strongarm->value = '85x85';
  $export['user_picture_dimensions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_file_size';
  $strongarm->value = '30';
  $export['user_picture_file_size'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_guidelines';
  $strongarm->value = '';
  $export['user_picture_guidelines'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_path';
  $strongarm->value = 'pictures';
  $export['user_picture_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_pictures';
  $strongarm->value = '0';
  $export['user_pictures'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_register';
  $strongarm->value = '1';
  $export['user_register'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_registration_help';
  $strongarm->value = '';
  $export['user_registration_help'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_signatures';
  $strongarm->value = '0';
  $export['user_signatures'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_automatic_for_comments';
  $strongarm->value = FALSE;
  $export['uuid_automatic_for_comments'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_automatic_for_nodes';
  $strongarm->value = array(
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
    'program_types' => 0,
    'level' => 0,
    'lesson' => 0,
    'book' => 0,
  );
  $export['uuid_automatic_for_nodes'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_automatic_for_taxonomy';
  $strongarm->value = array(
    3 => 3,
    1 => 1,
    4 => 4,
    5 => 5,
    6 => 6,
    7 => 7,
  );
  $export['uuid_automatic_for_taxonomy'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_automatic_for_users';
  $strongarm->value = FALSE;
  $export['uuid_automatic_for_users'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vid_convertor';
  $strongarm->value = 'video_ffmpeg';
  $export['vid_convertor'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vid_preset';
  $strongarm->value = array(
    'hq_flash' => 'hq_flash',
    'html5_webm' => 0,
    'iphone_mov' => 0,
    'html5_mp4' => 0,
    'html5_ogv' => 0,
  );
  $export['vid_preset'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_autobuffering';
  $strongarm->value = 1;
  $export['video_autobuffering'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_autoplay';
  $strongarm->value = 0;
  $export['video_autoplay'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_bypass_conversion';
  $strongarm->value = 0;
  $export['video_bypass_conversion'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_convert_on_save';
  $strongarm->value = 1;
  $export['video_convert_on_save'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_cron';
  $strongarm->value = 1;
  $export['video_cron'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_3g2';
  $strongarm->value = 'video_play_quicktime';
  $export['video_extension_3g2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_3g2_flash_player';
  $strongarm->value = '';
  $export['video_extension_3g2_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_3g2_html5_player';
  $strongarm->value = '';
  $export['video_extension_3g2_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_3gp';
  $strongarm->value = 'video_play_quicktime';
  $export['video_extension_3gp'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_3gp_flash_player';
  $strongarm->value = '';
  $export['video_extension_3gp_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_3gp_html5_player';
  $strongarm->value = '';
  $export['video_extension_3gp_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_asf';
  $strongarm->value = 'video_play_windowsmedia';
  $export['video_extension_asf'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_asf_flash_player';
  $strongarm->value = '';
  $export['video_extension_asf_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_asf_html5_player';
  $strongarm->value = '';
  $export['video_extension_asf_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_avi';
  $strongarm->value = 'video_play_windowsmedia';
  $export['video_extension_avi'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_avi_flash_player';
  $strongarm->value = '';
  $export['video_extension_avi_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_avi_html5_player';
  $strongarm->value = '';
  $export['video_extension_avi_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_dcr';
  $strongarm->value = 'video_play_dcr';
  $export['video_extension_dcr'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_dcr_flash_player';
  $strongarm->value = '';
  $export['video_extension_dcr_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_dcr_html5_player';
  $strongarm->value = '';
  $export['video_extension_dcr_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_dir';
  $strongarm->value = 'video_play_dcr';
  $export['video_extension_dir'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_dir_flash_player';
  $strongarm->value = '';
  $export['video_extension_dir_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_dir_html5_player';
  $strongarm->value = '';
  $export['video_extension_dir_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_divx';
  $strongarm->value = 'video_play_divx';
  $export['video_extension_divx'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_divx_flash_player';
  $strongarm->value = '';
  $export['video_extension_divx_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_divx_html5_player';
  $strongarm->value = '';
  $export['video_extension_divx_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_f4v';
  $strongarm->value = 'video_play_flv';
  $export['video_extension_f4v'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_f4v_flash_player';
  $strongarm->value = 'swftools';
  $export['video_extension_f4v_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_f4v_html5_player';
  $strongarm->value = '';
  $export['video_extension_f4v_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_flv';
  $strongarm->value = 'video_play_flv';
  $export['video_extension_flv'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_flv_flash_player';
  $strongarm->value = 'swftools';
  $export['video_extension_flv_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_flv_html5_player';
  $strongarm->value = '';
  $export['video_extension_flv_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mkv';
  $strongarm->value = 'video_play_divx';
  $export['video_extension_mkv'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mkv_flash_player';
  $strongarm->value = '';
  $export['video_extension_mkv_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mkv_html5_player';
  $strongarm->value = '';
  $export['video_extension_mkv_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mov';
  $strongarm->value = 'video_play_quicktime';
  $export['video_extension_mov'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mov_flash_player';
  $strongarm->value = '';
  $export['video_extension_mov_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mov_html5_player';
  $strongarm->value = '';
  $export['video_extension_mov_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mp4';
  $strongarm->value = 'video_play_quicktime';
  $export['video_extension_mp4'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mp4_flash_player';
  $strongarm->value = '';
  $export['video_extension_mp4_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mp4_html5_player';
  $strongarm->value = '';
  $export['video_extension_mp4_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mpeg';
  $strongarm->value = 'video_play_windowsmedia';
  $export['video_extension_mpeg'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mpeg_flash_player';
  $strongarm->value = '';
  $export['video_extension_mpeg_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mpeg_html5_player';
  $strongarm->value = '';
  $export['video_extension_mpeg_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mpg';
  $strongarm->value = 'video_play_windowsmedia';
  $export['video_extension_mpg'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mpg_flash_player';
  $strongarm->value = '';
  $export['video_extension_mpg_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_mpg_html5_player';
  $strongarm->value = '';
  $export['video_extension_mpg_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_ogg';
  $strongarm->value = 'video_play_theora';
  $export['video_extension_ogg'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_ogg_flash_player';
  $strongarm->value = '';
  $export['video_extension_ogg_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_ogg_html5_player';
  $strongarm->value = '';
  $export['video_extension_ogg_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_ogv';
  $strongarm->value = 'video_play_theora';
  $export['video_extension_ogv'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_ogv_flash_player';
  $strongarm->value = '';
  $export['video_extension_ogv_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_ogv_html5_player';
  $strongarm->value = '';
  $export['video_extension_ogv_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_rm';
  $strongarm->value = 'video_play_realmedia';
  $export['video_extension_rm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_rm_flash_player';
  $strongarm->value = '';
  $export['video_extension_rm_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_rm_html5_player';
  $strongarm->value = '';
  $export['video_extension_rm_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_swf';
  $strongarm->value = 'video_play_flash';
  $export['video_extension_swf'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_swf_flash_player';
  $strongarm->value = '';
  $export['video_extension_swf_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_swf_html5_player';
  $strongarm->value = '';
  $export['video_extension_swf_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_webm';
  $strongarm->value = 'video_play_theora';
  $export['video_extension_webm'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_webm_flash_player';
  $strongarm->value = '';
  $export['video_extension_webm_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_webm_html5_player';
  $strongarm->value = '';
  $export['video_extension_webm_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_wmv';
  $strongarm->value = 'video_play_windowsmedia';
  $export['video_extension_wmv'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_wmv_flash_player';
  $strongarm->value = '';
  $export['video_extension_wmv_flash_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_extension_wmv_html5_player';
  $strongarm->value = '';
  $export['video_extension_wmv_html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_ffmpeg_enable_faststart';
  $strongarm->value = 0;
  $export['video_ffmpeg_enable_faststart'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_ffmpeg_faststart_cmd';
  $strongarm->value = '/usr/bin/qt-faststart';
  $export['video_ffmpeg_faststart_cmd'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_ffmpeg_instances';
  $strongarm->value = '5';
  $export['video_ffmpeg_instances'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_ffmpeg_nice_enable';
  $strongarm->value = 1;
  $export['video_ffmpeg_nice_enable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_ffmpeg_pad_method';
  $strongarm->value = '0';
  $export['video_ffmpeg_pad_method'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_ffmpeg_thumbnailer_options';
  $strongarm->value = '-i !videofile -an -y -f mjpeg -ss !seek -vframes 1 !thumbfile';
  $export['video_ffmpeg_thumbnailer_options'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_thumb_path';
  $strongarm->value = 'video_thumbs';
  $export['video_thumb_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_thumbs';
  $strongarm->value = '5';
  $export['video_thumbs'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_transcoder_path';
  $strongarm->value = '/usr/local/bin/ffmpeg';
  $export['video_transcoder_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'video_use_default_thumb';
  $strongarm->value = 0;
  $export['video_use_default_thumb'] = $strongarm;

  return $export;
}
