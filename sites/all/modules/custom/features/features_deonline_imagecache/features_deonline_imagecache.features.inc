<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function features_deonline_imagecache_imagecache_default_presets() {
  $items = array(
    '135x135' => array(
      'presetname' => '135x135',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '135',
            'height' => '135',
          ),
        ),
      ),
    ),
    '135x222' => array(
      'presetname' => '135x222',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '135',
            'height' => '222',
          ),
        ),
      ),
    ),
    'grid16-4' => array(
      'presetname' => 'grid16-4',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '240',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}
