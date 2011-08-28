<?php
/**
 * @file
 * Default views for ClosedQuestion module.
 */

/**
 * Implements hook_views_data().
 */
function closedquestion_views_data() {
  $data = array();
  $data['cq_user_answer'] = array(
    'table' => array(
      'group' => 'ClosedQuestionAnswers',
      'join' => array(
        'node' => array(
          'left_field' => 'nid',
          'field' => 'nid',
        ),
        'users' => array(
          'left_field' => 'uid',
          'field' => 'uid',
        ),
      )
    ),
    'unixtime' => array(
      'title' => t('Log Time'),
      'help' => t('The time/date for this attempt?'), // The help that appears on the UI,
      // Information for displaying the nid
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      // Information for accepting it as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_date',
        'name field' => 'Once Correct', // the field to display in the summary.
        'numeric' => TRUE,
      ),
      // Information for accepting it as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
      // Information for sorting on it.
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'once_correct' => array(
      'title' => t('Once Correct'),
      'help' => t('Has the user completed this question?'), // The help that appears on the UI,
      // Information for displaying the nid
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      // Information for accepting a nid as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'Once Correct', // the field to display in the summary.
        'numeric' => TRUE,
      ),
      // Information for accepting a nid as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      // Information for sorting on a nid.
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'tries' => array(
      'title' => t('Tries'),
      'help' => t('Number of times the user gave an answer.'), // The help that appears on the UI,
      // Information for displaying the nid
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      // Information for accepting a nid as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'Once Correct', // the field to display in the summary.
        'numeric' => TRUE,
      ),
      // Information for accepting a nid as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      // Information for sorting on a nid.
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'nid' => array(
      'title' => t('Node Id'),
      'help' => t('A reference to the node of the question.'),
      // Because this is a foreign key to the {node} table. This allows us to
      // have, when the view is configured with this relationship, all the fields
      // for the related node available.
      'relationship' => array(
        'base' => 'node',
        'field' => 'nid',
        'handler' => 'views_handler_relationship',
        'label' => t('CqAnswer - Node relation'),
      ),
    ),
    'uid' => array(
      'title' => t('User Id'),
      'help' => t('A reference to the User.'),
      // Because this is a foreign key to the {node} table. This allows us to
      // have, when the view is configured with this relationship, all the fields
      // for the related node available.
      'relationship' => array(
        'base' => 'users',
        'field' => 'uid',
        'handler' => 'views_handler_relationship',
        'label' => t('CqAnswer - User relation'),
      ),
    ),
  );

  $data['cq_user_answer_log'] = array(
    'table' => array(
      'group' => 'ClosedQuestionLog',
      'join' => array(
        'node' => array(
          'left_field' => 'nid',
          'field' => 'nid',
        ),
        'users' => array(
          'left_field' => 'uid',
          'field' => 'uid',
        ),
      ),
    ),
    'log_id' => array(
      'title' => t('Log Entry ID'),
      'help' => t('The sequence number of this log entry.'),
      // Information for displaying it
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      // Information for accepting it as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'Log Id', // the field to display in the summary.
        'numeric' => TRUE,
      ),
      // Information for accepting it as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      // Information for sorting on it.
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'unixtime' => array(
      'title' => t('Log Time'),
      'help' => t('The time/date for this attempt?'), // The help that appears on the UI,
      // Information for displaying the nid
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      // Information for accepting it as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_date',
        'name field' => 'Once Correct', // the field to display in the summary.
        'numeric' => TRUE,
      ),
      // Information for accepting it as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
      // Information for sorting on it.
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'once_correct' => array(
      'title' => t('Log Once Correct'),
      'help' => t('Has the user completed this question?'), // The help that appears on the UI,
      // Information for displaying it
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      // Information for accepting it as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'Once Correct', // the field to display in the summary.
        'numeric' => TRUE,
      ),
      // Information for accepting it as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      // Information for sorting on it.
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'tries' => array(
      'title' => t('Log Tries'),
      'help' => t('Number of times the user gave an answer.'), // The help that appears on the UI,
      // Information for displaying it
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      // Information for accepting it as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'Once Correct', // the field to display in the summary.
        'numeric' => TRUE,
      ),
      // Information for accepting it as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      // Information for sorting on it.
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'answer' => array(
      'title' => t('Logged Answer'),
      'help' => t('The answer the user gave for this attempt'), // The help that appears on the UI,
      // Information for displaying the nid
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      // Information for accepting a nid as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_string',
        'name field' => 'Once Correct', // the field to display in the summary.
        'numeric' => TRUE,
      ),
      // Information for accepting a nid as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      // Information for sorting on a nid.
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'nid' => array(
      'title' => t('Log Node Id'),
      'help' => t('A reference to the node of the question.'),
      // Because this is a foreign key to the {node} table. This allows us to
      // have, when the view is configured with this relationship, all the fields
      // for the related node available.
      'relationship' => array(
        'base' => 'node',
        'field' => 'nid',
        'handler' => 'views_handler_relationship',
        'label' => t('CqLog - Node relation'),
      ),
    ),
    'uid' => array(
      'title' => t('Log User Id'),
      'help' => t('A reference to the User.'),
      // Because this is a foreign key to the {node} table. This allows us to
      // have, when the view is configured with this relationship, all the fields
      // for the related node available.
      'relationship' => array(
        'base' => 'users',
        'field' => 'uid',
        'handler' => 'views_handler_relationship',
        'label' => t('CqLog - User relation'),
      ),
    ),
  );

  return $data;
}

/**
 * Implements hook_views_default_views().
 */
function closedquestion_views_default_views() {
  /**
   * Default view to get the list users that answered a question.
   */
  $view = new view;
  $view->name = 'ClosedQuestionUsers';
  $view->description = t('Shows the list of users that tried answering this question, and the number of tries they needed.');
  $view->tag = 'closedquestion';
  $view->view_php = '';
  $view->base_table = 'users';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to TRUE to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'uid' => array(
      'label' => 'User relation',
      'required' => 1,
      'id' => 'uid',
      'table' => 'cq_user_answer',
      'field' => 'uid',
      'relationship' => 'none',
    ),
    'nid' => array(
      'label' => 'Node relation',
      'required' => 1,
      'id' => 'nid',
      'table' => 'cq_user_answer',
      'field' => 'nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'name' => array(
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
    ),
    'uid' => array(
      'id' => 'uid',
      'table' => 'users',
      'field' => 'uid',
    ),
    'once_correct' => array(
      'label' => 'Once Correct',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '0',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'once_correct',
      'table' => 'cq_user_answer',
      'field' => 'once_correct',
      'relationship' => 'none',
    ),
    'tries' => array(
      'label' => 'Tries',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '0',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'tries',
      'table' => 'cq_user_answer',
      'field' => 'tries',
      'relationship' => 'none',
    ),
    'unixtime' => array(
      'label' => 'Last Change',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'custom',
      'custom_date_format' => 'Y/m/d H:m',
      'exclude' => 0,
      'id' => 'unixtime',
      'table' => 'cq_user_answer',
      'field' => 'unixtime',
      'relationship' => 'none',
    ),
    'nothing' => array(
      'label' => 'Log',
      'alter' => array(
        'text' => 'Log',
        'make_link' => 1,
        'path' => 'node/!1/cq_users/[uid]',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'nothing',
      'table' => 'views',
      'field' => 'nothing',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => 'For Node %1',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'nid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
      ),
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_image_size' => '_original',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'webform' => 0,
        'poll' => 0,
        'closedquestion' => 0,
        'flashnode' => 0,
        'image' => 0,
        'linearcase' => 0,
        'proteusquiz' => 0,
        'book' => 0,
        'page' => 0,
        'story' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '2' => 0,
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'image_size' => array(
        '_original' => '_original',
        'thumbnail' => 'thumbnail',
        'preview' => 'preview',
        'thumbnail_200' => 'thumbnail_200',
        'thumbnail_300' => 'thumbnail_300',
      ),
      'validate_argument_php' => '',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'create closedquestion',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Users that answered this question');
  $handler->override_option('items_per_page', 100);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'once_correct' => 'once_correct',
      'tries' => 'tries',
      'name' => 'name',
      'uid' => 'uid',
      'unixtime' => 'unixtime',
      'nothing' => 'nothing',
    ),
    'info' => array(
      'once_correct' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'tries' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'uid' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'unixtime' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'nothing' => array(
        'separator' => '',
      ),
    ),
    'default' => 'name',
  ));
  $views['ClosedQuestionUsers'] = $view;


  /**
   * Default view to get the log of how a user answered a question.
   */
  $view = new view;
  $view->name = 'ClosedQuestionUserLog';
  $view->description = 'Shows the answers a user tried out for a certain question.';
  $view->tag = 'closedquestion';
  $view->view_php = '';
  $view->base_table = 'users';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to TRUE to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'nid_1' => array(
      'id' => 'nid_1',
      'table' => 'cq_user_answer_log',
      'field' => 'nid',
    ),
    'uid_1' => array(
      'id' => 'uid_1',
      'table' => 'cq_user_answer_log',
      'field' => 'uid',
    ),
  ));
  $handler->override_option('fields', array(
    'name' => array(
      'label' => 'Name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'overwrite_anonymous' => 0,
      'anonymous_text' => '',
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'uid' => array(
      'id' => 'uid',
      'table' => 'users',
      'field' => 'uid',
    ),
    'log_id' => array(
      'label' => 'Log Entry ID',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'log_id',
      'table' => 'cq_user_answer_log',
      'field' => 'log_id',
      'relationship' => 'none',
    ),
    'unixtime' => array(
      'label' => 'Log Time',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'custom',
      'custom_date_format' => 'Y/m/d H:i:s',
      'exclude' => 0,
      'id' => 'unixtime',
      'table' => 'cq_user_answer_log',
      'field' => 'unixtime',
      'relationship' => 'none',
    ),
    'once_correct_1' => array(
      'label' => 'Log Once Correct',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '0',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'once_correct_1',
      'table' => 'cq_user_answer_log',
      'field' => 'once_correct',
      'relationship' => 'none',
    ),
    'tries_1' => array(
      'label' => 'Log Tries',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '0',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'tries_1',
      'table' => 'cq_user_answer_log',
      'field' => 'tries',
      'relationship' => 'none',
    ),
    'answer' => array(
      'id' => 'answer',
      'table' => 'cq_user_answer_log',
      'field' => 'answer',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => 'For Node %1',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'nid_1',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
      ),
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_image_size' => '_original',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'webform' => 0,
        'poll' => 0,
        'closedquestion' => 0,
        'flashnode' => 0,
        'image' => 0,
        'linearcase' => 0,
        'proteusquiz' => 0,
        'book' => 0,
        'page' => 0,
        'story' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '2' => 0,
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'image_size' => array(
        '_original' => '_original',
        'thumbnail' => 'thumbnail',
        'preview' => 'preview',
        'thumbnail_200' => 'thumbnail_200',
        'thumbnail_300' => 'thumbnail_300',
      ),
      'validate_argument_php' => '',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'uid' => array(
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => 'Answers of user %2 for question %1',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'uid',
      'table' => 'users',
      'field' => 'uid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
      ),
      'relationship' => 'uid_1',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_image_size' => '_original',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'webform' => 0,
        'poll' => 0,
        'closedquestion' => 0,
        'flashnode' => 0,
        'image' => 0,
        'linearcase' => 0,
        'proteusquiz' => 0,
        'book' => 0,
        'page' => 0,
        'story' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '2' => 0,
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'image_size' => array(
        '_original' => '_original',
        'thumbnail' => 'thumbnail',
        'preview' => 'preview',
        'thumbnail_200' => 'thumbnail_200',
        'thumbnail_300' => 'thumbnail_300',
      ),
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'create closedquestion',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Users that answered this question');
  $handler->override_option('items_per_page', 50);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'name' => 'name',
      'uid' => 'uid',
      'log_id' => 'log_id',
      'unixtime' => 'unixtime',
      'once_correct_1' => 'once_correct_1',
      'tries_1' => 'tries_1',
      'answer' => 'answer',
    ),
    'info' => array(
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'uid' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'log_id' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'unixtime' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'once_correct_1' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'tries_1' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'answer' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => 'log_id',
  ));
  $views['ClosedQuestionUserLog'] = $view;

  return $views;
}

