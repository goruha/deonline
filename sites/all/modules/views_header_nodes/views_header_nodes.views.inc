<?php
// $Id: views_header_nodes.views.inc,v 1.1.2.1 2010/06/11 08:19:15 joachim Exp $

/**
 * views_header_nodes
 */
/**
 * Implementation of hook_views_handlers().
 */
function views_header_nodes_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views_header_nodes'),
    ),
    'handlers' => array(
      'views_header_nodes_handler_plugin_page_header_nodes' => array(
        'parent' => 'views_handler_field_node',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_plugins().
 */
function views_header_nodes_views_plugins() {
  return array(
    'module' => 'views', // This just tells our themes are elsewhere.
    'display' => array(
      'attachment_header_node' => array(
        'parent' => 'attachment',
        'title' => t('Header node'),
        'admin' => t('Header node'),        
        'handler' => 'views_header_nodes_plugin_attachment_header_node',
        'path' => drupal_get_path('module', 'views_header_nodes'),
        'theme' => 'views_view',
        'use ajax' => TRUE,
      ),
    ),
  );
}

