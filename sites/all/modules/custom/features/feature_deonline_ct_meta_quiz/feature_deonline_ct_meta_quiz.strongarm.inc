<?php

/**
 * Implementation of hook_strongarm().
 */
function feature_deonline_ct_meta_quiz_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_meta_quiz';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '-1',
    'author' => '-2',
    'options' => '0',
    'menu' => '-3',
    'path' => '1',
  );
  $export['content_extra_weights_meta_quiz'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_meta_quiz';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_meta_quiz'] = $strongarm;

  return $export;
}
