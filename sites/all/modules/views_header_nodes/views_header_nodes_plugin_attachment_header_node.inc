<?php
// $Id: views_header_nodes_plugin_attachment_header_node.inc,v 1.1.2.4 2010/09/21 16:52:19 joachim Exp $

/**
 * The plugin that handles a header node attachment display.
 *
 * A header node attachment display outputs the content of the node found at the
 * path 'VIEWPATH/text'. This allows non-admins to easily edit the effective
 * header or footer text of the view.
 *
 * @todo:
 *  - add a setting for either the complete path, or the path suffix,
 *    or even a node autocomplete selection widget.
 *  - if basing the path on the view's path, send arguments.
 *  - consider using title rather than path??
 *  - pass arguments by validated value: reach into $this->view->argument and 
 *    pass values from that.
 *  - work with prepopulate module to give admins a 'create header for this view'
 *    that fills in the URL path setting automatically.
 */
class views_header_nodes_plugin_attachment_header_node extends views_plugin_display_attachment {
  /**
   * Provide the summary for attachment options in the views UI.
   *
   * This output is returned as an array.
   */
  function options_summary(&$categories, &$options) {
    // It is very important to call the parent function here:
    parent::options_summary($categories, $options);

    switch ($this->get_option('path_base_type')) {
      case 'display_path':
        $base_path_summary = t('Display path');
        break;
      case 'view_name':
        $base_path_summary = t('View name');
        break;
    }
    $options['path_base_type'] = array(
      'category' => 'attachment',
      'title' => t('Path base'),
      'value' => $base_path_summary,
    );
    $options['path_suffix'] = array(
      'category' => 'attachment',
      'title' => t('Path suffix'),
      'value' => $this->get_option('path_suffix'),
    );
  }

  function option_definition () {
    $options = parent::option_definition();

    $options['path_base_type'] = array('default' => 'display_path');
    $options['path_suffix'] = array('default' => 'header');

    return $options;
  }
  
  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_form($form, $form_state);

    switch ($form_state['section']) {
      case 'path_base_type':
        $form['#title'] .= t('Path base');
        $form['path_base_type'] = array(
          '#type' => 'radios',
          '#description' => t('The base to use to form the node path.'),
          '#default_value' => $this->get_option('path_base_type'),
          '#options' => array(
            'display_path'  => t('Display: The path of each display'),
            'view_name'     => t('View: The machine name of the view'),
            ),
        );
        break;
      case 'path_suffix':
        $form['#title'] .= t('Path suffix');
        $form['path_suffix'] = array(
          '#type' => 'textfield',
          '#description' => t('The suffix to add to the view path to form the node path.'),
          '#default_value' => $this->get_option('path_suffix'),
        );
        break;
    }
  }

  /**
   * Perform any necessary changes to the form values prior to storage.
   * There is no need for this function to actually store the data.
   */
  function options_submit(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_submit($form, $form_state);
    switch ($form_state['section']) {
      case 'path_base_type':
        $this->set_option($form_state['section'], $form_state['values'][$form_state['section']]);
        break;
      case 'path_suffix':
        $this->set_option($form_state['section'], $form_state['values'][$form_state['section']]);
        break;
    }
  }
  
  /**
   * Attach to another view.
   */
  function attach_to($display_id) {
    $displays = $this->get_option('displays');

    if (empty($displays[$display_id])) {
      return;
    }

    if (!$this->access()) {
      return;
    }

    $attachment = $this->get_header_content();

    switch ($this->get_option('attachment_position')) {
      case 'before':
        $this->view->attachment_before .= $attachment;
        break;
      case 'after':
        $this->view->attachment_after .= $attachment;
        break;
      case 'both':
        $this->view->attachment_before .= $attachment;
        $this->view->attachment_after .= $attachment;
        break;
    }
  }  

  /**
   * Helper function to get the path of the required node.
   */
  function build_node_path() {
    //dsm($this->view);
    switch ($this->get_option('path_base_type')) {
      case 'display_path':
        // Get the URL of the curent view, including arguments.
        $base_path = $this->view->get_url();
        break;
      case 'view_name':
        $base_path = $this->view->name;
        break;
    }
    //dsm($base_path);

    $node_path = $base_path . '/' . $this->get_option('path_suffix');
    
    return $node_path;
    
    // deletia... may have future use.
    
    // Pass just the base path of the view, not the complete current path with arguments.
    /*
    $pieces = array_slice(explode('/', $view_url), 0, count(explode('/', $view_path)));
    $view_basepath = implode('/', $pieces);
    $node_path = $view_basepath . '/' . $this->get_option('path_suffix');
    */
    
    // Add the validated argument values; eg this means we pass a tid rather than 
    // a term name.
    // @todo: make this optional per-argument.
    /*
    $argument_handlers = $this->view->argument;
    //$arguments = $this->view->args;
    foreach ($argument_handlers as $handler) {
      //$raw_arg = array_shift($arguments);
      if (isset($handler->argument)) {
        $argument_value_pieces[] = $handler->argument;
      }
    }
    dsm($argument_value_pieces);
    */    
  } 
  
  /**
   * Get the content to show as this view's header.
   */
  function get_header_content() {
    // Construct the path for the required node.
    $node_path = $this->build_node_path();
        
    // Retrieve the system path for whatever is at the constructed path.
    $path = drupal_get_normal_path($node_path);
    
    $nid = str_replace('node/', '', $path);
    
    // If we've found a node, display it.   
    if (is_numeric($nid)) {
      $textarea_node = node_load($nid);
      
      // Run the node through a limited portion of the node_view() chain.
      $textarea_node = node_build_content($textarea_node, FALSE, FALSE);
      $output = drupal_render($textarea_node->content);
      
      // Display an edit link for convenience if user may edit.
      if (node_access('update', $textarea_node)) {
        $output .= '<p class = "edit-link">';
        $output .= l(t('Edit header'), "node/$nid/edit", array(
          'query' => array(
            'destination' => $view_url,
          ),
        ));
        $output .= '</p>';
      }
      
      return $output;      
    }
    else {
      // No corresponding header node found. 
      // If prepopulate module is present, show a helper link to admins
      // to create one.
      if (module_exists('prepopulate') && user_access('create page content') && user_access('create url aliases')) {
        // @todo: allow other node types than page?
        $options = array(
          'query' => array(
            'edit[path][path]' => $node_path,
            'destination'      => $view_url,
          ),
        );
        if (module_exists('pathauto')) {
          // Prevent pathauto from setting the path.
          $options['query']['edit[path][pathauto_perform_alias]'] = 0;
        }
        $output = l(t('Add a header'), 'node/add/page', $options);
        
        return $output;
      }
    }
  }
}
