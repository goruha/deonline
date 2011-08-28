<?php

/**
 * @file
 * Features integration for "Multistep Nodeform".
 */

/**
 * Implementation of hook_features_export_options().
 */
function msnf_step_features_export_options() {
  // Load necessary functions for form steps.
  module_load_include('inc', 'msnf', 'includes/msnf.steps');

  $options = array();
  $steps = msnf_steps();
  $content_types = msnf_content_types();
  foreach ($steps as $type_name => $type) {
    if (isset($content_types[$type_name])) {
      foreach ($type as $step_name => $step) {
        $options[$type_name .'__'. $step_name] = $content_types[$type_name]['name'] .': '. $step['label'];
      }
    }
  }
  return $options;
}

/**
 * Implementation of hook_features_export().
 *
 * @param <array> $data
 *   Machine name for the component to export.
 * @param <array> $export
 *   Array of all components to be exported.
 * @param <string> $module_name
 *   The name of the feature module to be generated.
 * @return <array>
 *   Array of further processors that should be called.
 */
function msnf_step_features_export($data, &$export, $module_name) {
  $export['dependencies']['msnf'] = 'msnf';
  foreach ($data as $component) {
    $export['features']['msnf_step'][$component] = $component;
  }
  // No further processing needed.
  return array();
}

/**
 * Implementation of hook_features_export_render().
 *
 * Render one or more component objects to code.
 *
 * @param <string> $module_name
 *   The name of the feature module to be exported.
 * @param <array> $data
 *   An array of machine name identifiers for the objects to be rendered.
 * @param <array> $export
 *   The full export array of the current feature being exported. This is only
 *   passed when hook_features_export_render() is invoked for an actual feature
 *   update or recreate, not during state checks or other operations.
 * @return <array>
 *   An associative array of rendered PHP code where the key is the name of the
 *   hook that should wrap the PHP code. The hook should not include the name
 *   of the module, e.g. the key for `hook_example` should simply be `example`.
 */
function msnf_step_features_export_render($module_name, $data, $export = NULL) {
  // Load necessary functions for form steps.
  module_load_include('inc', 'msnf', 'includes/msnf.steps');

  $steps = msnf_steps();
  $content_types = msnf_content_types();
  $code = array();
  $code[] = '  $steps = array();';
  $code[] = '';
  foreach ($data as $sys_name) {
    // Get node type and step name from sys_name.
    list($type_name, $step_name) = explode('__', $sys_name);
    // Get the step we want to export.
    if (isset($steps[$type_name]) && isset($steps[$type_name][$step_name])) {
      $code[] = '  $steps[\''. $type_name ."']['". $step_name ."'] = ". features_var_export($steps[$type_name][$step_name], '  ') .';';
    }
  }
  $code[] = '  return $steps;';
  $code = implode("\n", $code);
  return array('msnf_step_default_steps' => $code);
}

/**
 * Implementation of hook_features_rebuild().
 */
function msnf_step_features_rebuild($module) {
  // Load necessary functions for form steps.
  module_load_include('inc', 'msnf', 'includes/msnf.steps');

  $default_steps = module_invoke($module, 'msnf_step_default_steps');
  // Loop over the items we need to recreate.
  foreach ($default_steps as $type_name => $type) {
    foreach ($type as $step_name => $step) {
      // Save step.
      $saved = msnf_save_step($type_name, $step);
    }
  }
  cache_clear_all('msnf_step_data:', 'cache', TRUE);
}

/**
 * Implementation of hook_features_revert().
 */
function msnf_step_features_revert($module) {
  msnf_step_features_rebuild($module);
}
