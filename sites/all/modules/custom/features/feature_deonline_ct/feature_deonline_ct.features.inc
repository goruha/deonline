<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function feature_deonline_ct_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function feature_deonline_ct_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Учебник'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'course_request' => array(
      'name' => t('Записаться на курс'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'lesson' => array(
      'name' => t('Урок'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'level' => array(
      'name' => t('Уровень'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'has_body' => '1',
      'body_label' => t('Описание'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'material_audio' => array(
      'name' => t('Aудио'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'material_document' => array(
      'name' => t('Документ'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'material_video' => array(
      'name' => t('Видео'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page'),
      'module' => 'features',
      'description' => t('A <em>page</em>, similar in form to a <em>story</em>, is a simple method for creating and displaying information that rarely changes, such as an "About us" section of a website. By default, a <em>page</em> entry does not allow visitor comments and is not featured on the site\'s initial home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'profile' => array(
      'name' => t('Profile'),
      'module' => 'features',
      'description' => t('A user profile built as content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'program_types' => array(
      'name' => t('Типы программ'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'has_body' => '1',
      'body_label' => t('Описание'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'programm' => array(
      'name' => t('Программа'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'story' => array(
      'name' => t('Story'),
      'module' => 'features',
      'description' => t('A <em>story</em>, similar in form to a <em>page</em>, is ideal for creating and displaying content that informs or engages website visitors. Press releases, site announcements, and informal blog-like entries may all be created with a <em>story</em> entry. By default, a <em>story</em> entry is automatically featured on the site\'s initial home page, and provides the ability to post comments.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'teacher_profile' => array(
      'name' => t('Teacher profile'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('О себе'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
