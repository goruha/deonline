<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function features_deonline_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: Edit global presets
  $permissions['Edit global presets'] = array(
    'name' => 'Edit global presets',
    'roles' => array(),
  );

  // Exported permission: Use PHP input for field settings (dangerous - grant with care)
  $permissions['Use PHP input for field settings (dangerous - grant with care)'] = array(
    'name' => 'Use PHP input for field settings (dangerous - grant with care)',
    'roles' => array(),
  );

  // Exported permission: access administration pages
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(),
  );

  // Exported permission: access ajax quiz
  $permissions['access ajax quiz'] = array(
    'name' => 'access ajax quiz',
    'roles' => array(),
  );

  // Exported permission: access all views
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
  );

  // Exported permission: access backup and migrate
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(),
  );

  // Exported permission: access backup files
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(),
  );

  // Exported permission: access better messages
  $permissions['access better messages'] = array(
    'name' => 'access better messages',
    'roles' => array(),
  );

  // Exported permission: access content
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: access devel information
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(),
  );

  // Exported permission: access quiz
  $permissions['access quiz'] = array(
    'name' => 'access quiz',
    'roles' => array(),
  );

  // Exported permission: access site reports
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
  );

  // Exported permission: access skinr
  $permissions['access skinr'] = array(
    'name' => 'access skinr',
    'roles' => array(),
  );

  // Exported permission: access skinr classes
  $permissions['access skinr classes'] = array(
    'name' => 'access skinr classes',
    'roles' => array(),
  );

  // Exported permission: access user profiles
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(),
  );

  // Exported permission: administer actions
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
  );

  // Exported permission: administer backup and migrate
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(),
  );

  // Exported permission: administer better messages
  $permissions['administer better messages'] = array(
    'name' => 'administer better messages',
    'roles' => array(),
  );

  // Exported permission: administer blocks
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(),
  );

  // Exported permission: administer content types
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
  );

  // Exported permission: administer css3pie
  $permissions['administer css3pie'] = array(
    'name' => 'administer css3pie',
    'roles' => array(),
  );

  // Exported permission: administer features
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
  );

  // Exported permission: administer files
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(),
  );

  // Exported permission: administer filters
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
  );

  // Exported permission: administer flash
  $permissions['administer flash'] = array(
    'name' => 'administer flash',
    'roles' => array(),
  );

  // Exported permission: administer formatters
  $permissions['administer formatters'] = array(
    'name' => 'administer formatters',
    'roles' => array(),
  );

  // Exported permission: administer imageapi
  $permissions['administer imageapi'] = array(
    'name' => 'administer imageapi',
    'roles' => array(),
  );

  // Exported permission: administer imagecache
  $permissions['administer imagecache'] = array(
    'name' => 'administer imagecache',
    'roles' => array(),
  );

  // Exported permission: administer menu
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(),
  );

  // Exported permission: administer node wizard
  $permissions['administer node wizard'] = array(
    'name' => 'administer node wizard',
    'roles' => array(),
  );

  // Exported permission: administer nodeaccess
  $permissions['administer nodeaccess'] = array(
    'name' => 'administer nodeaccess',
    'roles' => array(),
  );

  // Exported permission: administer nodequeue
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(),
  );

  // Exported permission: administer nodes
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(),
  );

  // Exported permission: administer pageroutes
  $permissions['administer pageroutes'] = array(
    'name' => 'administer pageroutes',
    'roles' => array(),
  );

  // Exported permission: administer permissions
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(),
  );

  // Exported permission: administer quiz configuration
  $permissions['administer quiz configuration'] = array(
    'name' => 'administer quiz configuration',
    'roles' => array(),
  );

  // Exported permission: administer site configuration
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
  );

  // Exported permission: administer skinr
  $permissions['administer skinr'] = array(
    'name' => 'administer skinr',
    'roles' => array(),
  );

  // Exported permission: administer stylizer
  $permissions['administer stylizer'] = array(
    'name' => 'administer stylizer',
    'roles' => array(),
  );

  // Exported permission: administer taxonomy
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
  );

  // Exported permission: administer url aliases
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(),
  );

  // Exported permission: administer users
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(),
  );

  // Exported permission: administer views
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
  );

  // Exported permission: assign any action to quiz events
  $permissions['assign any action to quiz events'] = array(
    'name' => 'assign any action to quiz events',
    'roles' => array(),
  );

  // Exported permission: bypass conversion video
  $permissions['bypass conversion video'] = array(
    'name' => 'bypass conversion video',
    'roles' => array(),
  );

  // Exported permission: bypass requirement that fields are unique
  $permissions['bypass requirement that fields are unique'] = array(
    'name' => 'bypass requirement that fields are unique',
    'roles' => array(),
  );

  // Exported permission: change own username
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
  );

  // Exported permission: configure username patterns
  $permissions['configure username patterns'] = array(
    'name' => 'configure username patterns',
    'roles' => array(),
  );

  // Exported permission: convert on submission
  $permissions['convert on submission'] = array(
    'name' => 'convert on submission',
    'roles' => array(),
  );

  // Exported permission: create book content
  $permissions['create book content'] = array(
    'name' => 'create book content',
    'roles' => array(),
  );

  // Exported permission: create course_request content
  $permissions['create course_request content'] = array(
    'name' => 'create course_request content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: create lesson content
  $permissions['create lesson content'] = array(
    'name' => 'create lesson content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: create level content
  $permissions['create level content'] = array(
    'name' => 'create level content',
    'roles' => array(),
  );

  // Exported permission: create material_audio content
  $permissions['create material_audio content'] = array(
    'name' => 'create material_audio content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: create material_document content
  $permissions['create material_document content'] = array(
    'name' => 'create material_document content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: create material_video content
  $permissions['create material_video content'] = array(
    'name' => 'create material_video content',
    'roles' => array(),
  );

  // Exported permission: create page content
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(),
  );

  // Exported permission: create profile content
  $permissions['create profile content'] = array(
    'name' => 'create profile content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: create program_types content
  $permissions['create program_types content'] = array(
    'name' => 'create program_types content',
    'roles' => array(),
  );

  // Exported permission: create programm content
  $permissions['create programm content'] = array(
    'name' => 'create programm content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: create quiz
  $permissions['create quiz'] = array(
    'name' => 'create quiz',
    'roles' => array(),
  );

  // Exported permission: create story content
  $permissions['create story content'] = array(
    'name' => 'create story content',
    'roles' => array(),
  );

  // Exported permission: create teacher_profile content
  $permissions['create teacher_profile content'] = array(
    'name' => 'create teacher_profile content',
    'roles' => array(
      '0' => 'teacher',
    ),
  );

  // Exported permission: create url aliases
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(),
  );

  // Exported permission: delete any book content
  $permissions['delete any book content'] = array(
    'name' => 'delete any book content',
    'roles' => array(),
  );

  // Exported permission: delete any course_request content
  $permissions['delete any course_request content'] = array(
    'name' => 'delete any course_request content',
    'roles' => array(),
  );

  // Exported permission: delete any lesson content
  $permissions['delete any lesson content'] = array(
    'name' => 'delete any lesson content',
    'roles' => array(),
  );

  // Exported permission: delete any level content
  $permissions['delete any level content'] = array(
    'name' => 'delete any level content',
    'roles' => array(),
  );

  // Exported permission: delete any material_audio content
  $permissions['delete any material_audio content'] = array(
    'name' => 'delete any material_audio content',
    'roles' => array(),
  );

  // Exported permission: delete any material_document content
  $permissions['delete any material_document content'] = array(
    'name' => 'delete any material_document content',
    'roles' => array(),
  );

  // Exported permission: delete any material_video content
  $permissions['delete any material_video content'] = array(
    'name' => 'delete any material_video content',
    'roles' => array(),
  );

  // Exported permission: delete any page content
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(),
  );

  // Exported permission: delete any profile content
  $permissions['delete any profile content'] = array(
    'name' => 'delete any profile content',
    'roles' => array(),
  );

  // Exported permission: delete any program_types content
  $permissions['delete any program_types content'] = array(
    'name' => 'delete any program_types content',
    'roles' => array(),
  );

  // Exported permission: delete any programm content
  $permissions['delete any programm content'] = array(
    'name' => 'delete any programm content',
    'roles' => array(),
  );

  // Exported permission: delete any quiz
  $permissions['delete any quiz'] = array(
    'name' => 'delete any quiz',
    'roles' => array(),
  );

  // Exported permission: delete any quiz results
  $permissions['delete any quiz results'] = array(
    'name' => 'delete any quiz results',
    'roles' => array(),
  );

  // Exported permission: delete any story content
  $permissions['delete any story content'] = array(
    'name' => 'delete any story content',
    'roles' => array(),
  );

  // Exported permission: delete any teacher_profile content
  $permissions['delete any teacher_profile content'] = array(
    'name' => 'delete any teacher_profile content',
    'roles' => array(),
  );

  // Exported permission: delete backup files
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(),
  );

  // Exported permission: delete own book content
  $permissions['delete own book content'] = array(
    'name' => 'delete own book content',
    'roles' => array(),
  );

  // Exported permission: delete own course_request content
  $permissions['delete own course_request content'] = array(
    'name' => 'delete own course_request content',
    'roles' => array(),
  );

  // Exported permission: delete own lesson content
  $permissions['delete own lesson content'] = array(
    'name' => 'delete own lesson content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: delete own level content
  $permissions['delete own level content'] = array(
    'name' => 'delete own level content',
    'roles' => array(),
  );

  // Exported permission: delete own material_audio content
  $permissions['delete own material_audio content'] = array(
    'name' => 'delete own material_audio content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: delete own material_document content
  $permissions['delete own material_document content'] = array(
    'name' => 'delete own material_document content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: delete own material_video content
  $permissions['delete own material_video content'] = array(
    'name' => 'delete own material_video content',
    'roles' => array(),
  );

  // Exported permission: delete own page content
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(),
  );

  // Exported permission: delete own profile content
  $permissions['delete own profile content'] = array(
    'name' => 'delete own profile content',
    'roles' => array(),
  );

  // Exported permission: delete own program_types content
  $permissions['delete own program_types content'] = array(
    'name' => 'delete own program_types content',
    'roles' => array(),
  );

  // Exported permission: delete own programm content
  $permissions['delete own programm content'] = array(
    'name' => 'delete own programm content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: delete own quiz
  $permissions['delete own quiz'] = array(
    'name' => 'delete own quiz',
    'roles' => array(),
  );

  // Exported permission: delete own story content
  $permissions['delete own story content'] = array(
    'name' => 'delete own story content',
    'roles' => array(),
  );

  // Exported permission: delete own teacher_profile content
  $permissions['delete own teacher_profile content'] = array(
    'name' => 'delete own teacher_profile content',
    'roles' => array(),
  );

  // Exported permission: delete results for own quiz
  $permissions['delete results for own quiz'] = array(
    'name' => 'delete results for own quiz',
    'roles' => array(),
  );

  // Exported permission: delete revisions
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
  );

  // Exported permission: designate fields as unique
  $permissions['designate fields as unique'] = array(
    'name' => 'designate fields as unique',
    'roles' => array(),
  );

  // Exported permission: display source code
  $permissions['display source code'] = array(
    'name' => 'display source code',
    'roles' => array(),
  );

  // Exported permission: download all audio files
  $permissions['download all audio files'] = array(
    'name' => 'download all audio files',
    'roles' => array(),
  );

  // Exported permission: download own audio files
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(),
  );

  // Exported permission: edit any book content
  $permissions['edit any book content'] = array(
    'name' => 'edit any book content',
    'roles' => array(),
  );

  // Exported permission: edit any course_request content
  $permissions['edit any course_request content'] = array(
    'name' => 'edit any course_request content',
    'roles' => array(),
  );

  // Exported permission: edit any lesson content
  $permissions['edit any lesson content'] = array(
    'name' => 'edit any lesson content',
    'roles' => array(),
  );

  // Exported permission: edit any level content
  $permissions['edit any level content'] = array(
    'name' => 'edit any level content',
    'roles' => array(),
  );

  // Exported permission: edit any material_audio content
  $permissions['edit any material_audio content'] = array(
    'name' => 'edit any material_audio content',
    'roles' => array(),
  );

  // Exported permission: edit any material_document content
  $permissions['edit any material_document content'] = array(
    'name' => 'edit any material_document content',
    'roles' => array(),
  );

  // Exported permission: edit any material_video content
  $permissions['edit any material_video content'] = array(
    'name' => 'edit any material_video content',
    'roles' => array(),
  );

  // Exported permission: edit any page content
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(),
  );

  // Exported permission: edit any profile content
  $permissions['edit any profile content'] = array(
    'name' => 'edit any profile content',
    'roles' => array(),
  );

  // Exported permission: edit any program_types content
  $permissions['edit any program_types content'] = array(
    'name' => 'edit any program_types content',
    'roles' => array(),
  );

  // Exported permission: edit any programm content
  $permissions['edit any programm content'] = array(
    'name' => 'edit any programm content',
    'roles' => array(),
  );

  // Exported permission: edit any quiz
  $permissions['edit any quiz'] = array(
    'name' => 'edit any quiz',
    'roles' => array(),
  );

  // Exported permission: edit any story content
  $permissions['edit any story content'] = array(
    'name' => 'edit any story content',
    'roles' => array(),
  );

  // Exported permission: edit any teacher_profile content
  $permissions['edit any teacher_profile content'] = array(
    'name' => 'edit any teacher_profile content',
    'roles' => array(),
  );

  // Exported permission: edit own book content
  $permissions['edit own book content'] = array(
    'name' => 'edit own book content',
    'roles' => array(),
  );

  // Exported permission: edit own course_request content
  $permissions['edit own course_request content'] = array(
    'name' => 'edit own course_request content',
    'roles' => array(),
  );

  // Exported permission: edit own lesson content
  $permissions['edit own lesson content'] = array(
    'name' => 'edit own lesson content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: edit own level content
  $permissions['edit own level content'] = array(
    'name' => 'edit own level content',
    'roles' => array(),
  );

  // Exported permission: edit own material_audio content
  $permissions['edit own material_audio content'] = array(
    'name' => 'edit own material_audio content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: edit own material_document content
  $permissions['edit own material_document content'] = array(
    'name' => 'edit own material_document content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: edit own material_video content
  $permissions['edit own material_video content'] = array(
    'name' => 'edit own material_video content',
    'roles' => array(),
  );

  // Exported permission: edit own page content
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(),
  );

  // Exported permission: edit own profile content
  $permissions['edit own profile content'] = array(
    'name' => 'edit own profile content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own program_types content
  $permissions['edit own program_types content'] = array(
    'name' => 'edit own program_types content',
    'roles' => array(),
  );

  // Exported permission: edit own programm content
  $permissions['edit own programm content'] = array(
    'name' => 'edit own programm content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'sudo',
      '2' => 'teacher',
    ),
  );

  // Exported permission: edit own quiz
  $permissions['edit own quiz'] = array(
    'name' => 'edit own quiz',
    'roles' => array(),
  );

  // Exported permission: edit own story content
  $permissions['edit own story content'] = array(
    'name' => 'edit own story content',
    'roles' => array(),
  );

  // Exported permission: edit own teacher_profile content
  $permissions['edit own teacher_profile content'] = array(
    'name' => 'edit own teacher_profile content',
    'roles' => array(
      '0' => 'teacher',
    ),
  );

  // Exported permission: edit question titles
  $permissions['edit question titles'] = array(
    'name' => 'edit question titles',
    'roles' => array(),
  );

  // Exported permission: execute php code
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(),
  );

  // Exported permission: flush imagecache
  $permissions['flush imagecache'] = array(
    'name' => 'flush imagecache',
    'roles' => array(),
  );

  // Exported permission: grant deletable node permissions
  $permissions['grant deletable node permissions'] = array(
    'name' => 'grant deletable node permissions',
    'roles' => array(),
  );

  // Exported permission: grant editable node permissions
  $permissions['grant editable node permissions'] = array(
    'name' => 'grant editable node permissions',
    'roles' => array(),
  );

  // Exported permission: grant node permissions
  $permissions['grant node permissions'] = array(
    'name' => 'grant node permissions',
    'roles' => array(),
  );

  // Exported permission: grant own node permissions
  $permissions['grant own node permissions'] = array(
    'name' => 'grant own node permissions',
    'roles' => array(),
  );

  // Exported permission: import quiz questions
  $permissions['import quiz questions'] = array(
    'name' => 'import quiz questions',
    'roles' => array(),
  );

  // Exported permission: manage features
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
  );

  // Exported permission: manipulate all queues
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(),
  );

  // Exported permission: manipulate queues
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(),
  );

  // Exported permission: manual quiz revisioning
  $permissions['manual quiz revisioning'] = array(
    'name' => 'manual quiz revisioning',
    'roles' => array(),
  );

  // Exported permission: override player dimensions
  $permissions['override player dimensions'] = array(
    'name' => 'override player dimensions',
    'roles' => array(),
  );

  // Exported permission: perform backup
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(),
  );

  // Exported permission: restore from backup
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(),
  );

  // Exported permission: revert revisions
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(),
  );

  // Exported permission: score any quiz
  $permissions['score any quiz'] = array(
    'name' => 'score any quiz',
    'roles' => array(),
  );

  // Exported permission: score own quiz
  $permissions['score own quiz'] = array(
    'name' => 'score own quiz',
    'roles' => array(),
  );

  // Exported permission: select different theme
  $permissions['select different theme'] = array(
    'name' => 'select different theme',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: switch users
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(),
  );

  // Exported permission: toggle node wizard
  $permissions['toggle node wizard'] = array(
    'name' => 'toggle node wizard',
    'roles' => array(),
  );

  // Exported permission: use PHP for block visibility
  $permissions['use PHP for block visibility'] = array(
    'name' => 'use PHP for block visibility',
    'roles' => array(),
  );

  // Exported permission: use PHP for title patterns
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(),
  );

  // Exported permission: use admin toolbar
  $permissions['use admin toolbar'] = array(
    'name' => 'use admin toolbar',
    'roles' => array(),
  );

  // Exported permission: use default thumb
  $permissions['use default thumb'] = array(
    'name' => 'use default thumb',
    'roles' => array(),
  );

  // Exported permission: use default thumbnail
  $permissions['use default thumbnail'] = array(
    'name' => 'use default thumbnail',
    'roles' => array(),
  );

  // Exported permission: use regex for short answer
  $permissions['use regex for short answer'] = array(
    'name' => 'use regex for short answer',
    'roles' => array(),
  );

  // Exported permission: view any quiz question correct response
  $permissions['view any quiz question correct response'] = array(
    'name' => 'view any quiz question correct response',
    'roles' => array(),
  );

  // Exported permission: view any quiz results
  $permissions['view any quiz results'] = array(
    'name' => 'view any quiz results',
    'roles' => array(),
  );

  // Exported permission: view date repeats
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(),
  );

  // Exported permission: view imagecache 135x135
  $permissions['view imagecache 135x135'] = array(
    'name' => 'view imagecache 135x135',
    'roles' => array(),
  );

  // Exported permission: view imagecache 135x222
  $permissions['view imagecache 135x222'] = array(
    'name' => 'view imagecache 135x222',
    'roles' => array(),
  );

  // Exported permission: view imagecache grid16-4
  $permissions['view imagecache grid16-4'] = array(
    'name' => 'view imagecache grid16-4',
    'roles' => array(),
  );

  // Exported permission: view own quiz results
  $permissions['view own quiz results'] = array(
    'name' => 'view own quiz results',
    'roles' => array(),
  );

  // Exported permission: view quiz question outside of a quiz
  $permissions['view quiz question outside of a quiz'] = array(
    'name' => 'view quiz question outside of a quiz',
    'roles' => array(),
  );

  // Exported permission: view results for own quiz
  $permissions['view results for own quiz'] = array(
    'name' => 'view results for own quiz',
    'roles' => array(),
  );

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(),
  );

  // Exported permission: zencoder postback
  $permissions['zencoder postback'] = array(
    'name' => 'zencoder postback',
    'roles' => array(),
  );

  return $permissions;
}
