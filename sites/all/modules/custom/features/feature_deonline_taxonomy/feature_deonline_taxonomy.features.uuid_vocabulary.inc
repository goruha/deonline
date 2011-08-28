<?php

/**
 * Implementation of hook_uuid_features_default_vocabularies().
 */
function feature_deonline_taxonomy_uuid_features_default_vocabularies() {
  $vocabularies = array();

  $vocabularies[] = array(
    'uuid' => '471b552a-d16f-11e0-9495-001e33587f06',
    'name' => 'Programs categories',
    'description' => '',
    'help' => '',
    'relations' => '1',
    'multiple' => '0',
    'required' => '0',
    'tags' => '0',
    'module' => 'taxonomy',
    'weight' => '0',
    'nodes' => array(),
  );
  $vocabularies[] = array(
    'uuid' => '471b762c-d16f-11e0-9495-001e33587f06',
    'name' => 'levels',
    'description' => '',
    'help' => '',
    'relations' => '1',
    'multiple' => '0',
    'required' => '0',
    'tags' => '0',
    'module' => 'taxonomy',
    'weight' => '0',
    'nodes' => array(),
  );
  $vocabularies[] = array(
    'uuid' => '471b9224-d16f-11e0-9495-001e33587f06',
    'name' => 'program_types',
    'description' => '',
    'help' => '',
    'relations' => '1',
    'multiple' => '0',
    'required' => '0',
    'tags' => '0',
    'module' => 'taxonomy',
    'weight' => '0',
    'nodes' => array(),
  );
  $vocabularies[] = array(
    'uuid' => '471bac64-d16f-11e0-9495-001e33587f06',
    'name' => 'question_themes',
    'description' => '',
    'help' => '',
    'relations' => '1',
    'multiple' => '0',
    'required' => '1',
    'tags' => '1',
    'module' => 'taxonomy',
    'weight' => '0',
    'nodes' => array(
      'long_answer' => 'long_answer',
      'matching' => 'matching',
      'multichoice' => 'multichoice',
      'quiz_directions' => 'quiz_directions',
      'scale' => 'scale',
      'short_answer' => 'short_answer',
      'truefalse' => 'truefalse',
    ),
  );
  $vocabularies[] = array(
    'uuid' => '471bc672-d16f-11e0-9495-001e33587f06',
    'name' => 'user_age_categories',
    'description' => '',
    'help' => '',
    'relations' => '1',
    'multiple' => '0',
    'required' => '0',
    'tags' => '0',
    'module' => 'taxonomy',
    'weight' => '0',
    'nodes' => array(),
  );
  $vocabularies[] = array(
    'uuid' => '471be850-d16f-11e0-9495-001e33587f06',
    'name' => 'user_knowlege_level',
    'description' => '',
    'help' => '',
    'relations' => '1',
    'multiple' => '0',
    'required' => '0',
    'tags' => '0',
    'module' => 'taxonomy',
    'weight' => '0',
    'nodes' => array(),
  );
  return $vocabularies;
}
