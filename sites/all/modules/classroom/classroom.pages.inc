<?php
// $Id: classroom.pages.inc,v 1.36 2010/06/27 16:45:57 osoh Exp $

/**
 * Returns a list of courses which aren't finished yet.
 * TODO: refactor query into a function classroom_get_courses.
 * TODO: allow filtering by date capabilities.
 */
function classroom_courses_page() {
  global $user;
  $course = node_load($course_nid);

  $headers = array(
    'title' => array('data' => t('Name'), 'field' => 'title'),
    'start_t' => array('data' => t('Start'), 'field' => 'start_t'),
    'end_t' => array('data' => t('End'), 'field' => 'end_t'),
    'links' => array('data' => NULL),
  );

  // Query
  $order_sql = tablesort_sql($headers);
  $types = array();
  foreach (_classroom_get_types_for('course') as $name => $type) {
    $types[] = $name;
  }
  $types_sql = "'" . implode("','", $types) . "'";

  $qry = "SELECT * FROM {classroom_course} LEFT JOIN {node} USING (nid) WHERE type in ($types_sql) AND (end_t > %d OR end_t IS NULL) $order_sql";
  $pager_limit = variable_get('classroom_pager_limit', CLASSROOM_PAGER_LIMIT_DEFAULT);
  $result = pager_query($qry, $pager_limit, 0, NULL, time());

  // Display courses in a table
  $rows = array();
  while ($row = db_fetch_object($result)) {
    $course = node_load($row->nid);
    $row = array();
    $row['title'] = l($course->title, "node/$course->nid");
    $row['start_t'] = _classroom_format_date($course->classroom_course['start_t']);
    $row['end_t'] = _classroom_format_date($course->classroom_course['end_t']);

    $actions = array();
    if (classroom_check_access($course->nid)) {
      array_push($actions,
        l(t('Go classroom'), "classroom/course/$course->nid"));
    }

    // Additional links provided by other modules
    $links = module_invoke_all('classroom_course_links', $course);
    foreach ($links as $module => $module_links) {
      if ($module_links) {
        foreach ($module_links as $link) {
          $actions[] = l($link['title'], $link['href']);
        }
      }
    }
    $row['links'] = implode(' ', $actions);
    $rows[] = $row;
  }

  if (empty($rows)) {
    $output = "<p>" . t("There are no planned or running courses.") . "</p>";
  } else {
    $output = theme('table', $headers, $rows);
    $output .= theme('pager');
  }

  return $output;
}

function classroom_course_page($course_nid) {
  global $user;
  $course = node_load($course_nid);
  $topics = classroom_get_topics($course);

  $output = $course->body;
  if (classroom_is_teacher($user, $course)) {
    $output .= "<p>" . l(t("Administer topics"), "classroom/course/{$course->nid}/topics")
      . "</p>";
  }

  if (!empty($topics)) {
    $output .= "<h2>" . t("Topics") . "</h2>";
    foreach ($topics as $topic) {
      $output .= "<h3 class=\"classroom-topic-title\">" . classroom_topic_link($topic) . "</h3>";
      $output .= "<p class=\"classroom-topic-description\">{$topic->description}</p>";
    }
  }

  return $output;
}

function classroom_course_news_page($course_nid) {
  $course = node_load($course_nid);
  $output .= "<h3>" . t('Lastest resources') . "</h3>";
  $output .= _classroom_recent_resources_table($course_nid);
  $output .= "<h3>" . t('Lastest assignments') . "</h3>";
  $output .= _classroom_recent_assignments_table($course_nid);
  $summaries = module_invoke_all('classroom_course_summary', $course);
  foreach ($summaries as $module => $summary) {
    if ($summary) {
      $output .= "<h3>" . $summary['title'] . "</h3>";
      $output .= $summary['content'];
    }
  }
  return $output;
}

/**
 * Display a list of assignments grouped by topic.
 *
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_assignments_page($course_nid) {
  global $user;
  $course = node_load($course_nid);
  $is_teacher = classroom_is_active_as_teacher($user, $course);
  $is_student = classroom_is_active_as_student($user, $course);
  $output = "";

  // Add a column for percentages
  if ($course->classroom_course['use_grade_percentages']) {
    $headers['percentage'] = array(
      'data' => t('Percentage'), 'field' => 'grade_percentage');
  }

  // Final grade
  if ($is_student) {
    $final_grade = classroom_course_calculate_finalgrade($course, $user);
    if ($final_grade) {
      $output .= "<p>" . t("Final grade: ") . "$final_grade</p>";
    }
  }

  // Assignments grouped by topics.
  $topics = classroom_get_topics($course);
  foreach ($topics as $topic) {
    $output .= "<h2 class=\"topic-title\">{$topic->number}. $topic->name</h2>";
    $assignments = classroom_get_assignments($course, $topic);
    $output .= _classroom_assignments_table($assignments, $is_student);
  }

  // Assignments with no topic.
  $assignments = classroom_get_assignments($course, FALSE);
  if (!empty($assignments)) {
    $output .= "<h2 class=\"topic-title\">" . t("Global") . "</h2>";
    $output .= _classroom_assignments_table($assignments, $is_student);
  }

  if ($is_teacher) {
    $output .= '<p>' . t('Add assignment:') . '</p>';
    $links = array();
    $types = _classroom_get_types_for('assignment');
    foreach ($types as $type) {
      $links[] = l($type->name, classroom_node_add_url($type), array('query' => "course_nid=$course_nid"));
    }
    $output .= theme('item_list', $links);
  }

  return $output;
}

/**
 * Display a list of managers.
 *
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_managers_page($course_nid) {
  return _classroom_course_users_page($course_nid, CLASSROOM_MANAGER);
}

/**
 * Form to add managers to a course.
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $course_nid
 *   Course ID.
 *
 * FIXME: this functions is almost identical to classroom_course_add_teachers_form().
 */
function classroom_course_add_managers_form($form, $course_nid) {
  $headers = array(
    'name' => array('data' => t('Name'), 'field' => 'name'),
  );
  $order_sql = tablesort_sql($headers);
  $qry = "SELECT * FROM {users} AS u WHERE u.uid != 0 AND NOT EXISTS (SELECT * FROM {classroom_registration} WHERE uid = u.uid AND course_nid = %d AND role <> %d) $order_sql";
  $pager_limit = variable_get('classroom_pager_limit', CLASSROOM_PAGER_LIMIT_DEFAULT);
  $result = pager_query($qry, $pager_limit, 0, NULL, $course_nid, CLASSROOM_TEACHER);
  return _classroom_course_users_form($course_nid, $result, t("Add selected"), 'managers', $headers);
}

/**
 * Form to add managers to a course. (hook_form_submit() implementation).
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $form_state
 *   Form state (Drupal style).
 */
function classroom_course_add_managers_form_submit($form, $form_state) {
  $course_nid = $form['#post']['course_nid'];
  $course = node_load($course_nid);
  foreach ($form['#post']['uids'] as $uid) {
    $user = user_load($uid);
    classroom_register_manager($user, $course);
  }
}

/**
 * Check if we select at least one manager. (hook_form_validate() implementation).
 *
 */
function classroom_course_add_managers_form_validate($form, &$form_state) {
  _classroom_validate_empty($form['#post']['uids']);
}

/**
 * Form to remove managers to a course.
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_remove_managers_form($form, $course_nid) {
  return _classroom_course_remove_users_form($form, $course_nid, CLASSROOM_MANAGER);
}

/**
 * Form to remove teachers from a course. (hook_form_submit() implementation).
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $form_state
 *   Form state (Drupal style).
 */
function classroom_course_remove_managers_form_submit($form, $form_state) {
  $course_nid = $form['#post']['course_nid'];
  $course = node_load($course_nid);
  foreach ($form['#post']['uids'] as $uid) {
    $user = user_load($uid);
    classroom_signoff_manager($user, $course);
  }
}

/**
 * Check if we select at least one manager. (hook_form_validate() implementation).
 *
 */

function classroom_course_remove_managers_form_validate($form, &$form_state) {
  _classroom_validate_empty($form['#post']['uids']);
}

/**
 * Display a list of teachers.
 *
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_teachers_page($course_nid) {
  return _classroom_course_users_page($course_nid, CLASSROOM_TEACHER);
}

/**
 * Form to add teachers to a course.
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_add_teachers_form($form, $course_nid) {
  $headers = array(
    'name' => array('data' => t('Name'), 'field' => 'name'),
  );
  $order_sql = tablesort_sql($headers);
  $qry = "SELECT * FROM {users} AS u WHERE u.uid != 0 AND NOT EXISTS (SELECT * FROM {classroom_registration} WHERE uid = u.uid AND course_nid = %d AND role <> %d) $order_sql";
  $pager_limit = variable_get('classroom_pager_limit', CLASSROOM_PAGER_LIMIT_DEFAULT);
  $result = pager_query($qry, $pager_limit, 0, NULL, $course_nid, CLASSROOM_MANAGER);
  return _classroom_course_users_form($course_nid, $result, t("Add selected"), 'teachers', $headers);
}

/**
 * Form to add teachers to a course. (hook_form_submit() implementation).
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $form_state
 *   Form state (Drupal style).
 */
function classroom_course_add_teachers_form_submit($form, $form_state) {
  $course_nid = $form['#post']['course_nid'];
  $course = node_load($course_nid);
  foreach ($form['#post']['uids'] as $uid) {
    $user = user_load($uid);
    classroom_register_teacher($user, $course);
  }
}

/**
 * Check if we select at least one teacher. (hook_form_validate() implementation).
 *
 */

function classroom_course_add_teachers_form_validate($form, &$form_state) {
  _classroom_validate_empty($form['#post']['uids']);
}

/**
 * Form to remove teachers to a course.
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_remove_teachers_form($form, $course_nid) {
  return _classroom_course_remove_users_form($form, $course_nid, CLASSROOM_TEACHER);
}

/**
 * Form to remove teachers from a course. (hook_form_submit() implementation).
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $form_state
 *   Form state (Drupal style).
 */
function classroom_course_remove_teachers_form_submit($form, $form_state) {
  $course_nid = $form['#post']['course_nid'];
  $course = node_load($course_nid);
  foreach ($form['#post']['uids'] as $uid) {
    $user = user_load($uid);
    classroom_signoff_teacher($user, $course);
  }
}

/**
 * Check if we select at least one teacher. (hook_form_validate() implementation).
 *
 */

function classroom_course_remove_teachers_form_validate($form, &$form_state) {
  _classroom_validate_empty($form['#post']['uids']);
}

/**
 * Display a list of students.
 *
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_students_page($course_nid) {
  return _classroom_course_users_page($course_nid, CLASSROOM_STUDENT);
}

/**
 * Form to add students to a course.
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_add_students_form($form, $course_nid) {
  return _classroom_course_add_users_form($form, $course_nid, CLASSROOM_STUDENT);
}

/**
 * Form to add students to a course. (hook_form_submit() implementation).
 * TODO: this functions is almost identical to
 * classroom_course_add_teachers_form_submit, so refactor them seems a good option.
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $form_state
 *   Form state (Drupal style).
 */
function classroom_course_add_students_form_submit($form, $form_state) {
  $course_nid = $form['#post']['course_nid'];
  $course = node_load($course_nid);
  foreach ($form['#post']['uids'] as $uid) {
    $user = user_load($uid);
    classroom_register_student($user, $course);
  }
}

/**
 * Check if we select at least one student. (hook_form_validate() implementation).
 *
 */
function classroom_course_add_students_form_validate($form, &$form_state) {
  _classroom_validate_empty($form['#post']['uids']);
}

/**
 * Form to remove students from a course.
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_remove_students_form($form, $course_nid) {
  return _classroom_course_remove_users_form($form, $course_nid, CLASSROOM_STUDENT);
}

/**
 * Form to remove students from a course. (hook_form_submit() implementation).
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $form_state
 *   Form state (Drupal style).
 */
function classroom_course_remove_students_form_submit($form, $form_state) {
  $course_nid = $form['#post']['course_nid'];
  $course = node_load($course_nid);
  foreach ($form['#post']['uids'] as $uid) {
    $user = user_load($uid);
    classroom_signoff_student($user, $course);
  }
}

/**
 * Check if we select at least one student. (hook_form_validate() implementation).
 *
 */
function classroom_course_remove_students_form_validate($form, &$form_state) {
  _classroom_validate_empty($form['#post']['uids']);
}

/**
 * Display a list of resources.
 *
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_resources_page($course_nid) {
  $course = node_load(array('nid' => $course_nid));

  // Resources grouped by topics.
  $topics = classroom_get_topics($course);
  $output = "";
  foreach ($topics as $topic) {
    $output .= "<h2 class=\"topic-title\">{$topic->number}. $topic->name</h2>";
    $resources = classroom_get_resources_for($course, $topic);
    $output .= _classroom_resources_table($resources);
  }

  // Resources with no topic.
  $resources = classroom_get_resources_for($course, FALSE);
  if (!empty($resources)) {
    $output .= "<h2 class=\"topic-title\">" . t("Global") . "</h2>";
    $output .= _classroom_resources_table($resources, $is_student);
  }

  return $output;
}

/**
 * Form to add resources to a course.
 *
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_add_resources_form($form, $course_nid) {
  $headers = array(
    'name' => array('data' => t('Title'), 'field' => 'title'),
  );
  $types = array();
  foreach (_classroom_get_types_for('resource') as $name => $type) {
    $types[] = $name;
  }
  $types_sql = "'" . implode("','", $types) . "'";
  $order_sql = tablesort_sql($headers);
  $qry = "SELECT * FROM {node} AS n WHERE type IN ($types_sql) AND NOT EXISTS (SELECT * FROM {classroom_course_resource} WHERE resource_nid = n.nid AND course_nid = %d) $order_sql";
  $pager_limit = variable_get('classroom_pager_limit', CLASSROOM_PAGER_LIMIT_DEFAULT);
  $result = pager_query($qry, $pager_limit, 0, NULL, $course_nid);

  $course = node_load(array('nid' => $course_nid));
  $topics_map = classroom_get_topics_for_select($course);
  $topic_form = array();
  if ($topics_map) {
    $topic_form['topic_tid'] = array(
      '#type' => 'select',
      '#title' => t('Topic'),
      '#description' => t('Related topic.'),
      '#options' => $topics_map,
    );
  }

  $common_form = _classroom_course_resources_form($course_nid, $result, t("Add selected"),
    $headers);
  return array_merge($topic_form, $common_form);
}

/**
 * Form to add resources to a course. (hook_form_submit() implementation).
 *
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_add_resources_form_submit($form, $form_state) {
  $course_nid = $form['#post']['course_nid'];
  $course = node_load($course_nid);
  $topic_tid = $form['#post']['topic_tid'];
  $topic = ($topic_tid) ? classroom_load_topic($topic_tid) : NULL;
  foreach ($form['#post']['nids'] as $nid) {
    $resource = node_load($nid);
    classroom_add_resource($course, $resource, $topic);
  }
}

/**
 * Check if we select at least one resource. (hook_form_validate() implementation).
 *
 */
function classroom_course_add_resources_form_validate($form, &$form_state) {
  _classroom_validate_empty($form['#post']['nids']);
}

/**
 * Form to remove resources to a course.
 * TODO: this functions is almost identical to
 * classroom_course_add_resources_form, so refactor them seems a good option.
 *
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_remove_resources_form($form, $course_nid) {
  $headers = array(
    'name' => array('data' => t('Title'), 'field' => 'title'),
  );
  $types = array();
  foreach (_classroom_get_types_for('resource') as $name => $type) {
    $types[] = $name;
  }
  $order_sql = tablesort_sql($headers);
  $qry = "SELECT * FROM {classroom_course_resource} LEFT JOIN {node} ON {classroom_course_resource}.resource_nid = {node}.nid WHERE course_nid = %d $order_sql";
  $pager_limit = variable_get('classroom_pager_limit', CLASSROOM_PAGER_LIMIT_DEFAULT);
  $result = pager_query($qry, $pager_limit, 0, NULL, $course_nid);
  return _classroom_course_resources_form($course_nid, $result, t("Remove selected"), $headers);
}

/**
 * Form to remove resources to a course. (hook_form_submit() implementation).
 *
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_remove_resources_form_submit($form, $form_state) {
  $course_nid = $form['#post']['course_nid'];
  $course = node_load($course_nid);
  foreach ($form['#post']['nids'] as $nid) {
    $resource = node_load($nid);
    classroom_remove_resource_from($course, $resource);
  }
}

/**
 * Check if we select at least one resource. (hook_form_validate() implementation).
 *
 */
function classroom_course_remove_resources_form_validate($form, &$form_state) {
  _classroom_validate_empty($form['#post']['nids']);
}

/**
 * Display a list of topics
 *
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_topics_page($course_nid) {
  $course = node_load(array('nid' => $course_nid));
  $topics = classroom_get_topics($course);

  classroom_set_breadcrumb($course, TRUE);

  $headers = array(
    'number' => array('data' => t('Number')),
    'name' => array('data' => t('Name')),
    'description' => array('data' => t('Description')),
  );

  $rows = array();
  foreach ($topics as $topic) {
    $rows[] = array(
      'number' => l($topic->number, "classroom/course/{$topic->course->nid}/topics/$topic->tid/edit"),
      'name' => $topic->name,
      'description' => $topic->description,
    );
  }

  $html = theme('table', $headers, $rows);
  $html.= "<p>" . l(t("Add topic"), "classroom/course/{$course_nid}/topics/add")
    . "</p>";
  return $html;
}

/**
 * Form to add topics to a course.
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_add_topic_form($form, $course_nid) {
  $course = node_load(array('nid' => $course_nid));
  $topic = classroom_new_topic(array('course' => $course));
  $form = _classroom_course_topics_form($topic);
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Implementation of hook_form_validate(). 
 */
function classroom_course_add_topic_form_validate($form, &$form_state) {
  _classroom_course_topic_form_validate($form, $form_state);
}

/**
 * Implementation of hook_form_validate(). 
 */
function classroom_course_edit_topic_form_validate($form, &$form_state) {
  _classroom_course_topic_form_validate($form, $form_state);
}

/**
 * Checks if a topic with a given number yet exists.
 * This function is used by hook_form_validate() implementations.
 */
function _classroom_course_topic_form_validate($form, $form_state) {
  if ($form['#post']['op'] == t('Delete')) {
    return TRUE;
  }

  // Check if the number is duplicated yet.
  $qry = "SELECT COUNT(*) AS e FROM {classroom_topic} WHERE number = %d AND course_nid = %d";
  $conds = array($form['#post']['number'], $form['#post']['course_nid']);
  if ($form['#post']['tid']) {
    $qry .= " AND tid <> %d";
    $conds[] = $form['#post']['tid'];
  }
  $result = db_query($qry, $conds);
  $exists = db_fetch_array($result);
  if ($exists['e'] > 0) {
    form_set_error('number', t("The topic number can't be duplicated!"));
  }
}

/**
 * Form to edit topics.
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_edit_topic_form($form, $tid) {
  $topic = classroom_load_topic($tid);
  $form = _classroom_course_topics_form($topic);
  $form['tid'] = array(
    '#type' => 'hidden',
    '#value' => $tid,
  );

  $form['buttons']['update'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );
  $form['buttons']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#submit' => array('classroom_course_topic_delete_submit'),
  );
  return $form;
}

function classroom_course_add_topic_form_submit($form, $form_state) {
  $course_nid = $form['#post']['course_nid'];
  $course = node_load($course_nid);
  $data = $form['#post'];
  $topic = classroom_new_topic(
    array(
      'course' => $course,
      'name' => $data['name'],
      'description' => $data['description'],
      'number' => $data['number'],
    )
  );
  classroom_save_topic($topic);
}

function classroom_course_edit_topic_form_submit($form, $form_state) {
  $topic = classroom_load_topic($form['#post']['tid']);
  // FIXME: write a topic_update() function or something like that.
  $topic->name = $form['#post']['name'];
  $topic->description = $form['#post']['description'];
  $topic->number = $form['#post']['number'];
  classroom_save_topic($topic);
}

function classroom_course_topic_delete_submit($form, $form_state) {
  $topic = classroom_load_topic($form['#post']['tid']);
  classroom_delete_topic($topic);
}

/**
 * Form to give grades to responses.
 *
 * @param $assignment_nid
 *   Assignment ID.
 */
function classroom_assignment_responses_form($form, $assignment_nid) {
  $assignment = node_load($assignment_nid);
  classroom_set_breadcrumb($assignment);

  $form = array();
  $form['#headers'] = array(
    'name' => array('data' => t('Name'), 'field' => 'name'),
    'grade' => array('data' => t('Grade')),
    'response' => array('data' => ''),
  );

  // Response types (TODO: refactor)
  $types = array();
  foreach (_classroom_get_types_for('response') as $name => $type) {
    $types[] = $name;
  }
  $types_sql = "'" . implode("','", $types) . "'";

  // Query
  $order_sql = tablesort_sql($form['#headers']);
  $qry = "SELECT nid, uid, name, grade FROM {node} LEFT JOIN {classroom_response} "
    ."USING (nid) LEFT JOIN {users} USING (uid) "
    ."WHERE type IN ($types_sql) AND assignment_nid = %d $order_sql";
  $pager_limit = variable_get('classroom_pager_limit', CLASSROOM_PAGER_LIMIT_DEFAULT);
  $result = pager_query($qry, $pager_limit, 0, NULL, $assignment_nid);

  // Form
  $form['responses'] = array();
  while ($response = db_fetch_object($result)) {
    $row = array();
    $row['name'] = array('#value' => $response->name);
    $row['grade'] = array(
      '#type' => 'textfield',
      '#title' => '',
      '#name' => "grade_$response->nid",
      '#default_value' => $response->grade,
      '#size' => 3,
      '#maxlenght' => 3,
    );
    $row['view'] = array('#value' => l(t('View response'), "node/$response->nid"));
    $form['responses'][] = $row;
  }

  $form['assignment_nid'] = array(
    '#type' => 'hidden',
    '#value' => $course_nid,
  );
  $form['#redirect'] = array("node/$assignment_nid");
  $form['pager'] = array('#value' => theme('pager'));
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );
  return $form;
}

/**
 * Display a list of grades.
 *
 * @param $course_nid
 *   Course ID.
 */
function classroom_course_grades_page($course_nid) {
  global $user;

  $course = node_load($course_nid);
  $assignments = classroom_get_assignments($course);
  if (empty($assignments)) { // Nothing to see if there is no assignments.
    return "<p>" . t("There are no assignments for this course yet.") . "</p>";
  }

  $students = classroom_get_students($course);

  $rows = array();
  $headers = array(
    'student' => array('data' => t('Student')),
  );

  foreach ($assignments as $assignment) {
    $headers[$assignment->nid] = array('data' => $assignment->title);
  }

  $headers['finalgrade'] = array('data' => t('Final Grade'));

  // Add one header for each assignment
  foreach ($students as $student) {
    $row = array('student' => $student->name);
    foreach ($assignments as $assignment) {
      $response = classroom_get_response($assignment, $student);
      if ($response) {
        $grade = $response->classroom_response['grade'];
        if ($grade === NULL) {
          $grade = t('N/G');
        }
        $grade .= " (" . l(t('view'), "node/$response->nid") . ")";
      } else {
        $grade = t('N/A');
      }
      $row[$assignment->nid] = $grade;
    }

    $row['finalgrade'] =  classroom_course_calculate_finalgrade($course, $student);
    $rows[] = $row;
  }

  return theme('table', $headers, $rows);
}
/**
 * Form to give grades to responses. (hook_form_submit() implementation).
 *
 * @param $assignment_nid
 *   Assignment ID.
 */
function classroom_assignment_responses_form_submit($form, $form_state) {
  foreach ($form['#post'] as $name => $value) {
    if (preg_match('/^grade_(.+)/', $name, $matches)) {
      $response_nid = $matches[1];
      // TODO: maybe we must write a function to avoids loading
      // the response just to assign the grade.
      $response = node_load($response_nid);
      $response->classroom_response['grade'] = (float) $value;
      node_save($response);
    }
  }
}

function classroom_topic_page($course_nid, $topic_tid) {
  global $user;

  $course = node_load(array('nid' => $course_nid));
  $topic = classroom_load_topic($topic_tid);

  classroom_set_breadcrumb($course, TRUE);

  $is_teacher = classroom_is_active_as_teacher($user, $course);
  $is_student = classroom_is_active_as_student($user, $course);

  $output = "";
  $output .= "<p>{$topic->description}</p>\n";

  // Assignments
  $assignments = classroom_get_assignments($course, $topic);
  if (!empty($assignments)) {
    $output .= "<h3>" . t("Assignments") . "</h3>";
    $output .= _classroom_assignments_table($assignments, $is_student);
  }

  // Resources
  $resources = classroom_get_resources_for($course, $topic);
  if (!empty($resources)) {
    $output .= "<h3>" . t("Resources") . "</h3>";
    $output .= _classroom_resources_table($resources, $is_student);
  }

  return $output;
}

/**
 * 'Private' functions.
 */

/**
 * Builds the description of a form which contains a list
 * of users with a checkbox for each one of them.
 * It retrieve the data using a query result.
 *
 * @param $result
 *   Query $result.
 * @return
 *   An array describing the form.
 */
function _classroom_course_users_form($course_nid, $result, $button_value = "Submit", $target = 'teachers', $headers = NULL) {
  $form = array();
  if ($headers) {
    $form['#headers'] = $headers;
  }

  $form['users'] = array();
  while ($user = db_fetch_object($result)) {
    $row = array();
    $row['uid'] = array(
      '#type' => 'checkbox',
      '#name' => 'uids[]',
      '#title' => $user->name,
      '#return_value' => $user->uid,
      '#default_value' => FALSE,
    );
    $form['users'][] = $row;
  }
  $form['course_nid'] = array(
    '#type' => 'hidden',
    '#value' => $course_nid,
  );
  $form['#redirect'] = array("classroom/course/$course_nid/$target");
  $form['pager'] = array('#value' => theme('pager'));
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $button_value,
  );
  return $form;
}

/**
 * Builds the description of a form which contains a list
 * of resources with a checkbox for each one of them.
 * It retrieve the data using a query result.
 *
 * @param $result
 *   Query $result.
 * @return
 *   An array describing the form.
 */
function _classroom_course_resources_form($course_nid, $result, $button_value = "Submit", $headers = NULL) {
  $form = array();
  if ($headers) {
    $form['#headers'] = $headers;
  }

  $form['resources'] = array();
  while ($resource = db_fetch_object($result)) {
    $row = array(
      'nid' => array(
        '#type' => 'checkbox',
        '#name' => 'nids[]',
        '#title' => $resource->title,
        '#return_value' => $resource->nid,
        '#default_value' => FALSE,
      ),
    );
    $form['resources'][] = $row;
  }
  $form['course_nid'] = array(
    '#type' => 'hidden',
    '#value' => $course_nid,
  );

  $form['#redirect'] = array("classroom/course/$course_nid/resources");
  $form['pager'] = array('#value' => theme('pager'));
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $button_value,
  );
  return $form;
}

/**
 * Display a list of users related to a course.
 *
 * @param $course_nid
 *   Course ID
 * @param $users_role
 *   Filter using a 'role' (CLASSROOM_STUDENT, CLASSROOM_TEACHER or
 *   CLASSROOM_MANAGER). Other value disables this filter.
 * @return
 *   List formatted in HTML.
 */
function _classroom_course_users_page($course_nid, $users_role = NULL) {
  $headers = array(
    'name' => array('data' => t('Name'), 'field' => 'name'),
  );

  $conds = array($course_nid);

  // Set some values depending upon $users_role variable
  if ($users_role !== NULL) {
    $filter = " AND role = %d";
    $conds[] = $users_role;
  }
  $target = _classroom_target($users_role);

  // Query
  $order_sql = tablesort_sql($headers);
  $qry = "SELECT * FROM {classroom_registration} LEFT JOIN {users} USING (uid) WHERE course_nid = %d $filter $order_sql";
  $pager_limit = variable_get('classroom_pager_limit', CLASSROOM_PAGER_LIMIT_DEFAULT);
  $result = pager_query($qry, $pager_limit, 0, NULL, $conds);

  // Display users in a table
  $rows = array();
  while ($user = db_fetch_object($result)) {
    $row = array(
      'name' => l($user->name, "user/$user->uid"),
    );

    // Additional links provided by other modules
    $actions = array();
    $links = module_invoke_all('classroom_user_links', $user, "classroom/course/$course_nid/$users_role");
    foreach ($links as $module => $module_links) {
      foreach ($module_links as $link) {
        $actions[] = $link;
      }
    }
    $row['links'] = implode(' ', $actions);
    $rows[] = $row;
  }

  if (empty($rows)) {
    $output = "<p>" . t("There are no $target assigned to this course.") . "</p>";
  } else {
    $output = theme('table', $headers, $rows);
    $output .= theme('pager');
  }
  return $output;
}

/**
 * Form to add users to a course.
 *
 * @param $form
 *   Form definition.
 *
 * @param $course_nid
 *   Course ID.
 *
 * @param $role
 *   Classroom user role.
 *
 * FIXME: this functions is only used by classroom_course_add_students_form().
 */
function _classroom_course_add_users_form($form, $course_nid, $role) {
  $headers = array(
    'name' => array('data' => t('Name'), 'field' => 'name'),
  );
  $target = _classroom_target($role);
  $order_sql = tablesort_sql($headers);
  $qry = "SELECT * FROM {users} AS u WHERE u.uid != 0 AND NOT EXISTS (SELECT * FROM {classroom_registration} WHERE uid = u.uid AND course_nid = %d) $order_sql";
  $pager_limit = variable_get('classroom_pager_limit', CLASSROOM_PAGER_LIMIT_DEFAULT);
  $result = pager_query($qry, $pager_limit, 0, NULL, $course_nid);
  return _classroom_course_users_form($course_nid, $result, t("Add selected"), $target, $headers);
}

/**
 * Form to remove users from a course.
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $course_nid
 *   Course ID.
 * @param $role
 *   What kind of users will be taken into account.
 */
function _classroom_course_remove_users_form($form, $course_nid, $role) {
  $headers = array(
    'name' => array('data' => t('Name'), 'field' => 'name'),
  );
  $target = _classroom_target($role);
  $qry = "SELECT * FROM {classroom_registration} LEFT JOIN {users} ON {classroom_registration}.uid = {users}.uid WHERE course_nid = %d AND role = %d";
  $order_sql = tablesort_sql($headers);
  $qry .= " $order_sql";
  $pager_limit = variable_get('classroom_pager_limit', CLASSROOM_PAGER_LIMIT_DEFAULT);
  $result = pager_query($qry, $pager_limit, 0, NULL, $course_nid, $role);
  return _classroom_course_users_form($course_nid, $result, t("Remove selected"), $target, $headers);
}

/**
 * Returns a title for the course page.
 *
 * @param course_nid
 *   Course ID.
 */
function _classroom_course_page_title($course_nid) {
  $course = node_load($course_nid);
  return $course->title;
}

/**
 * Returns a title for the topic page.
 *
 * @param topic_tid
 *   Topic ID.
 */
function _classroom_topic_page_title($topic_tid) {
  $topic = classroom_load_topic($topic_tid);
  return "{$topic->number}. {$topic->name}";
}


/**
 * Theme functions
 *
 * Some of the next functions (theme_*) are almost identical and
 * maybe they must implemented in other way.
 */
function theme_classroom_course_add_teachers_form($form) {
  return _classroom_theme_course_users_form($form);
}

function theme_classroom_course_add_students_form($form) {
  return _classroom_theme_course_users_form($form);
}

function theme_classroom_course_remove_teachers_form($form) {
  return _classroom_theme_course_users_form($form);
}

function theme_classroom_course_remove_students_form($form) {
  return _classroom_theme_course_users_form($form);
}

function theme_classroom_course_add_resources_form($form) {
  return _classroom_theme_course_resources_form($form);
}

function theme_classroom_course_remove_resources_form($form) {
  return _classroom_theme_course_resources_form($form);
}

function theme_classroom_assignment_responses_form($form) {
  $headers = $form['#headers'];
  unset($form['#headers']);

  $rows = array();
  foreach ($form['responses'] as $name => $element) {
    if (!isset($element['grade'])) { continue; }
    $rows[] = array(
      drupal_render($element['name']),
      drupal_render($element['grade']),
      drupal_render($element['view']),
    );
    unset($form['responses'][$name]);
  }

  $output = theme('table', $headers, $rows);
  $output .= drupal_render($form);
  return $output;

}

/**
 * Theme function to show the users' form (students or teachers)
 * in a table.
 *
 * @param $form
 *   Form definition.
 * @return
 *   Form in HTML.
 */
function _classroom_theme_course_users_form($form) {
  if (isset($form['#headers'])) {
    $headers = $form['#headers'];
    unset($form['#headers']);
  } else {
    $headers = array();
  }

  $rows = array();
  foreach ($form['users'] as $name => $element) {
    if (!isset($element['uid'])) { continue; }
    $rows[] = array(
      drupal_render($element['uid']),
    );
    unset($form['users'][$name]);
  }

  $form['pager'] = array('#value' => theme('pager'));
  $output = theme('table', $headers, $rows);
  $output .= drupal_render($form);
  return $output;
}

/**
 * Theme function to show the resources' form in a table.
 *
 * @param $form
 *   Form definition.
 * @return
 *   Form in HTML.
 */
function _classroom_theme_course_resources_form($form) {
  if (isset($form['#headers'])) {
    $headers = $form['#headers'];
    unset($form['#headers']);
  } else {
    $headers = array();
  }

  $rows = array();
  foreach ($form['resources'] as $name => $element) {
    if (!isset($element['nid'])) { continue; }
    $rows[] = array(
      drupal_render($element['nid']),
    );
    unset($form['resources'][$name]);
  }

  $output = theme('table', $headers, $rows);
  $output .= drupal_render($form);
  return $output;
}

/**
 * Builds a list of recent assignments.
 *
 * @param $course_nid
 *   Course ID.
 * @param $last
 *   How many assignments must be shown.
 */
function _classroom_recent_assignments_table($course_nid, $last = 5) {
  $headers = array(
    'title' => array('data' => t('Title')),
  );

  $qry = "SELECT * FROM {node} LEFT JOIN {classroom_assignment} USING (nid) "
    ."WHERE course_nid = %d ORDER BY created DESC LIMIT %d";
  $result = db_query($qry, $course_nid, $last);
  $rows = array();
  while ($assignment = db_fetch_object($result)) {
    // FIXME: this must be done in an unobstrusive way.
    if ($assignment->type == 'quiz') {
      $row = array(
        'title' => l($assignment->title, "classroomquiz/$assignment->nid")
      );
    } else {
      $row = array(
        'title' => l($assignment->title, "node/$assignment->nid")
      );
    }
    $row['title'] .= theme('mark', node_mark($assignment->nid, $assignment->changed));
    $rows[] = $row;
  }

  if (empty($rows)) {
    return "<p>" . t("There are no assignments for this course yet.") . "</p>";
  } else {
    return theme('table', $headers, $rows);
  }
}

/**
 * Builds a list of recent resources.
 *
 * @param $course_nid
 *   Course ID.
 * @param $last
 *   How many resources must be shown.
 */
function _classroom_recent_resources_table($course_nid, $last = 5) {
  $headers = array(
    'title' => array('data' => t('Title')),
  );

  // FIXME: it must be ordered using the date when it was added to the course.
  $qry = "SELECT * FROM {classroom_course_resource} LEFT JOIN {node} ON {classroom_course_resource}.resource_nid = {node}.nid WHERE course_nid = %d ORDER BY created LIMIT %d";
  $result = db_query($qry, $course_nid, $last);
  $rows = array();
  while ($resource = db_fetch_object($result)) {
    $rows[] = array(
      'title' => l($resource->title, "node/$resource->nid"),
    );
  }

  if (empty($rows)) {
    return "<p>" . t("There are no resources for this course yet.") . "</p>";
  } else {
    return theme('table', $headers, $rows);
  }
}

 /**
  * Checks if value empty and set form error
  *
  * @param $string
  * String to check
  */
function _classroom_validate_empty($string){
  if($string == '')
    form_set_error('', t('You must select at least one item for this group of options.'));
  }

/**
 * Form to add/edit topics to a course. This functions is a helper for
 * classroom_course_topic_add_form and classroom_course_topic_edit_form functions.
 *
 * @param $topic
 *   Topic object.
 * @return
 *   Form definition (Drupal style).
 */
function _classroom_course_topics_form($topic) {
  $form = array();
  $form['number'] = array(
    '#type' => 'textfield',
    '#title' => t('Number'),
    '#maxlength' => 3,
    '#size' => 3,
    '#value' => $topic->number,
  );
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#value' => $topic->name,
  );
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#value' => $topic->description,
  );
  $form['course_nid'] = array(
    '#type' => 'hidden',
    '#value' => $topic->course->nid,
  );
  $form['#redirect'] = array("classroom/course/{$topic->course->nid}/topics");
  return $form;
}

/**
 * Builds an assignments table.
 *
 * @param $assignments
 *   Resources that must be included in the table.
 * @return
 *   Table's HTML.
 */
function _classroom_resources_table($resources, $is_student = FALSE) {
  $headers = array(
    'title' => array('data' => t('Title')),
    'type' => array('data' => t('Type')),
  );

  // Display resources in a table
  $rows = array();
  $types = node_get_types('types');
  foreach ($resources as $resource) {
    $rows[] = array(
      'title' => l($resource->title, "node/$resource->nid"),
      'type' => t($types[$resource->type]->name),
    );
  }

  if (empty($rows)) {
    $output .= "<p>" . t("There are no resources for this topic yet.") . "</p>";
  } else {
    $output .= theme('table', $headers, $rows);
    $output .= theme('pager');
  }

  return $output;
}

/**
 * Builds an assignments table.
 *
 * @param $assignments
 *   Assignments that must be included in the table.
 * @return
 *   Table's HTML.
 */
function _classroom_assignments_table($assignments, $is_student = FALSE) {
  global $user; // FIXME: maybe this variable could be a parameter.

  // Headers
  $headers = array();
  $headers['title'] = array('data' => t('Title'), 'field' => 'title');

  // Add a column for grade
  if ($is_student) {
    $headers['grade'] = array('data' => t('Grade'), 'field' => 'grade');
  }

  $headers['due date'] = array('data' => t('Due date'), 'field' => 'end_t');
  $headers['type'] = array('data' => t('Type'));
  $headers['created'] = array('data' => t('Created at'), 'field' => 'created');

  // Display assignments in a table
  $rows = array();
  $types = node_get_types('types');
  foreach ($assignments as $assignment) {
    $type = $types[$assignment->type];

    // FIXME: This should be done in other way
    if ($assignment->type == 'quiz') {
      $row['title'] = l ($assignment->title, "classroomquiz/$assignment->nid");
    } else {
      $row['title'] = l($assignment->title, "node/$assignment->nid");
    }
    $row['title'] .= theme('mark', node_mark($assignment->nid, $assignment->changed));

    if ($is_student) {
      $response = classroom_get_response($assignment, $user);
      if (($response == NULL) || ($response == FALSE))
        $row['grade'] = theme('links', classroom_response_link($assignment));
      else {
        if ($response->classroom_response["grade"] == NULL)
          $row['grade'] = t('N/G');
        else
          $row['grade'] = $response->classroom_response["grade"];
      }
    }
    $row['due date'] = _classroom_format_date($assignment->classroom_assignment['end_date']['end_t']);
    $row['type'] = t($type->name);
    $row['created'] = t(format_interval(time() - $assignment->created));
    if ($course->classroom_course['use_grade_percentages']) {
      $row['percentage'] = $assignment->grade_percentage;
    }
    $rows[] = $row;
  }

  if (empty($rows)) {
    $output .= "<p>" . t("There are no assignments for this topic yet.") . "</p>";
  } else {
    $output .= theme('table', $headers, $rows);
    $output .= theme('pager');
  }

  return $output;
}

/**
 * Just a helper function for users related page.
 */
function _classroom_target($role) {
  if ($role === NULL) return "users";
  $targets = array(
    CLASSROOM_STUDENT => "students",
    CLASSROOM_MANAGER => "managers",
    CLASSROOM_TEACHER => "teachers",
  );
  return $targets[$role];
}

