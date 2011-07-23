<?php
// $Id: classroom.courses.inc,v 1.21 2010/03/18 21:09:53 osoh Exp $

function classroom_course_is_open($course, $date = NULL) {
  if ($date === NULL) {
    $date = time();
  }

  $classroom_course = $course->classroom_course;
  if (is_null($classroom_course['registration_start']) and (is_null($classroom_course['registration_end']))) {
    return TRUE;
  } elseif (is_null($classroom_course['registration_start']) and ($classroom_course['registration_end'])) {
    return ($date <= $classroom_course['registration_end']);
  } elseif (is_null($classroom_course['registration_end']) and ($classroom_course['registration_start'])) {
     return ($date >= $classroom_course['registration_start']);
  } else {
    return (($date >= $classroom_course['registration_start']) and ($date <= $classroom_course['registration_end']));
  }
}

/**
 * Retrieve all courses from the database.
 *
 * @return
 *   An array containing all the courses.
 */
function classroom_get_courses() {
  // FIXME: refactor
  $types = array();
  foreach (_classroom_get_types_for('course') as $name => $type) {
    $types[] = $name;
  }
  $types_sql = "'" . implode("','", $types) . "'";
  $qry = "SELECT * FROM {classroom_course} LEFT JOIN {node} USING (nid) WHERE type in ($types_sql)";
  $result = db_query($qry, $uid);
  $courses = array();
  while ($row = db_fetch_array($result)) {
    $courses[] = node_load(array('nid' => $row['nid']));
  }
  return $courses;
}

/**
 * Retrieve open courses from the database.
 *
 * @return
 *   An array containing the open courses.
 */
function classroom_get_open_courses() {
  $courses = classroom_get_courses();
  $open_courses = array();
  foreach ($courses as $course) {
    if (classroom_course_is_open($course)) {
      $open_courses[] = $course;
    }
  }
  return $courses;
}

/**
 * Get the students registered in a course.
 *
 * @param $course
 *   Course to get the students for.
 * @return
 *   An array containing the users registered in the $course.
 */
function classroom_get_students($course) {
  return classroom_get_users($course, CLASSROOM_STUDENT);
}

/**
 * Get the teachers of a given course.
 *
 * @param $course
 *   Course to get the managers for.
 * @return
 *   An array containing the teachers registered in the $course.
 */
function classroom_get_teachers_for($course) {
  return classroom_get_users($course, CLASSROOM_TEACHER);
}

/**
 * Get the managers of a given course.
 *
 * @param $course
 *   Course to get the managers for.
 * @return
 *   An array containing the mangers registered in the $course.
 */
function classroom_get_managers_for($course) {
  return classroom_get_users($course, CLASSROOM_MANAGER);
}

/**
 * Get the students of a given course.
 *
 * @param $course
 *   Course to get the managers for.
 * @return
 *   An array containing the students registered in the $course.
 */
function classroom_get_students_for($course) {
  return classroom_get_users($course, CLASSROOM_STUDENT);
}

/**
 * Get the users of a given course.
 *
 * @param $course
 *   Course to get the managers for.
 * @param $role
 *   Users' role (CLASSROOM_STUDENT, CLASSROOM_TEACHER or CLASSROOM_MANAGER).
 * @return
 *   An array containing the users registered in the $course.
 * TODO: discuss about using retrieving all users using a single SQL query.
 */
function classroom_get_users($course, $role) {
  $qry = "SELECT uid FROM {classroom_registration} WHERE course_nid = %d AND role = %d";
  $result = db_query($qry, $course->nid, $role);
  $students = array();
  while ($row = db_fetch_array($result)) {
    $students[] = user_load($row['uid']);
  }
  return $students;
}

/**
 * Get the assignments related to a course.
 *
 * @param $course
 *   Course to get the assignments for.
 * @param $topic
 *   Topic which the assignment belongs to. It could be: a topic, null (all assignments),
 *   or false (only assignments without associated topic).
 * @return
 *   An array containing the assignments realted to the $course.
 * TODO: discuss about using retrieving all assignments using a single SQL query.
 */
function classroom_get_assignments($course, $topic = NULL) {
  $qry = "SELECT nid FROM {classroom_assignment} WHERE course_nid = %d";
  $conds = array($course->nid);
  if ($topic) {
    $qry .= " AND topic_tid = %d";
    $conds[] = $topic->tid;
  } elseif ($topic === FALSE) {
    $qry .= " AND topic_tid IS NULL";
  }
  $result = db_query($qry, $conds);
  $assignments = array();
  while ($row = db_fetch_array($result)) {
    $assignments[] = node_load($row['nid']);
  }
  return $assignments;
}


function _classroom_course_form_delete_fields($form, $form_state, $form_id) {
  $fields = array();
  $fields['classroom_course'] = array (
    '#type' => 'fieldset',
    '#weight' => -2,
    '#title' => t('Course'),
    '#tree' => true,
  );

  $options = array();
  $options['resources'] = t('Resources');
/* TODO: MOVE THIS TO FORUMS INTEGRATION MODULE
  if (module_exists('classroom_forum'))
    $options['forums'] = t('Forums');
 */
  $fields['classroom_course']['delete'] = array (
    '#type' => 'checkboxes',
    '#title' => t('Delete associated information'),
    '#weight' => -2,
    '#options' => $options,
    '#description' => t('The following information is associated to the course and will be erased if you check them.'),
    '#tree' => true,
  );

  if(is_array($fields['#submit']))
    array_unshift($fields['#submit'], '_classroom_course_delete_form_handler');
  $fields['#submit'][] = '_classroom_course_delete_form_handler';

  $fields['#redirect'] = '/classroom';

  return $fields;
}

function _classroom_course_form_fields($form, $form_state, $form_id) {
  drupal_add_js(drupal_get_path('module', 'classroom') .'/classroom.courses.js', 'module');
  $node = $form['#node'];

  $fields = array();
  $fields['classroom_course'] = array(
    '#type' => 'fieldset',
    '#title' => t('Course'),
    '#tree' => true,
  );

  $fields['classroom_course']['unlimitedend'] = array(
    '#type' => 'checkbox',
    '#title' => t('Unlimited end date'),
    '#default_value' => (is_null($node->classroom_course['end_date'])&&(isset($node->nid))),
    '#tree' => true,
  );

  $fields['classroom_course']['start_date'] = array(
    '#type' => 'date',
    '#title' => t('Starting date'),
    '#default_value' => $node->classroom_course['start_date'],
    '#tree' => true,
  );

  $fields['classroom_course']['end_date'] = array(
    '#type' => 'date',
    '#title' => t('End date'),
    '#default_value' => $node->classroom_course['end_date'],
    '#tree' => true,
  );

  $fields['classroom_course']['open_end_inscription'] = array(
    '#type' => 'checkbox',
    '#title' => t('Unlimited end inscription'),
    '#default_value' => (is_null($node->classroom_course['registration_end_date'])&&(isset($node->nid))),
    '#tree' => true,
  );

  $fields['classroom_course']['registration_start_date'] = array(
    '#type' => 'date',
    '#title' => t('Signup start date'),
    '#default_value' => $node->classroom_course['registration_start_date'],
    '#tree' => true,
  );

  $fields['classroom_course']['registration_end_date'] = array(
    '#type' => 'date',
    '#title' => t('Signup end date'),
    '#default_value' => $node->classrooom_course['registration_end_date'],
    '#tree' => true,
  );

  $fields['classroom_course']['use_grade_percentages'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use grade percentages'),
    '#default_value' => $node->classroom_course['use_grade_percentages'],
    '#tree' => true,
  );

  $fields['classroom_course']['access_by_rid'] = array(
    '#type' => 'select',
    '#title' => t('Access by role'),
    '#default_value' => $node->classroom_course['access_by_rid'],
    '#options' => array(NULL => t("None")) + user_roles(TRUE),
  );

  return $fields;
}

function _classroom_course_delete_form_handler($form, &$form_state) {
  $course = node_load($form['nid']['#value']);
  node_delete($course->nid);

  //Delete all the resources
  if (isset($form['nid']['#post']['classroom_course']['delete']['resources'])) {
    $resources_nids = db_query("SELECT resource_nid FROM {classroom_course_resource} WHERE course_nid = %d", $course->nid);  
    while ( $resources_nid = db_fetch_array($resources_nids) ) {
      delete_node($resource_nid);
    }
    $resources_nids = db_query("DELETE  FROM {classroom_course_resource} WHERE course_nid = %d", $course->nid);   
  }   
}

function _classroom_course_nodeapi(&$node, $op, $a3 = NULL, $a4 = NULL) {
  switch ($op) {
  case 'insert':
    return _classroom_course_nodeapi_insert($node, $op, $a3, $a4);
  case 'update':
    return _classroom_course_nodeapi_update($node, $op, $a3, $a4);
  case 'delete':
    return _classroom_course_nodeapi_delete($node, $op, $a3, $a4);
  case 'load':
    return _classroom_course_nodeapi_load($node, $op, $a3, $a4);
  case 'presave':
    return _classroom_course_nodeapi_presave($node, $op, $a3, $a4);
  case 'validate':
    return _classroom_course_nodeapi_validate($node, $op, $a3, $a4);
  case 'view':
    return _classroom_course_nodeapi_view($node, $op, $a3, $a4);

  }
}

function _classroom_course_nodeapi_presave(&$node, $op, $a3, $a4) {
  _classroom_course_sync_dates($node);
  _classroom_course_nodeapi_validate($node, $op, $a3, $a4);
}

function _classroom_course_nodeapi_insert($node, $op, $a3 = NULL, $a4 = NULL) {
  $fields = array(
    'nid' => $node->nid,
    'use_grade_percentages' => $node->classroom_course['use_grade_percentages'],
    'access_by_rid' => $node->classroom_course['access_by_rid'],
  );

  //Course date
  $fields['start_t'] = $node->classroom_course['start_t'];
  if ($node->classroom_course['unlimitedend']) {
    $fields['end_t'] = NULL;
  }
  else {
    $fields['end_t'] = $node->classroom_course['end_t'];
  }

  // Signup date
  $fields['registration_start'] = $node->classroom_course['registration_start'];
  if ($node->classroom_course['open_end_inscription']) {
    $fields['registration_end'] = NULL;
  }
  else {
    $fields['registration_end'] = $node->classroom_course['registration_end'];
  }

  drupal_write_record('classroom_course', $fields);
  classroom_register_manager($node->uid, $node->nid);
  classroom_register_teacher($node->uid, $node->nid);
  _classroom_update_course_access_by_rid($node);

  module_invoke_all('classroom_insert_course', $node);
}

function _classroom_course_nodeapi_update($node, $op, $a3 = NULL, $a4 = NULL) {
  $fields = array(
    'nid' => $node->nid,
    'use_grade_percentages' => $node->classroom_course['use_grade_percentages'],
    'access_by_rid' => $node->classroom_course['access_by_rid'],
  );

  //Course date 
  $fields['start_t'] = $node->classroom_course['start_t'];
  if ($node->classroom_course['unlimitedend']) {
    $fields['end_t'] = NULL;
  }
  else {
    $fields['end_t'] = $node->classroom_course['end_t'];
  }

  // Signup date
  $fields['registration_start'] = $node->classroom_course['registration_start'];
  if ($node->classroom_course['open_end_inscription']) {
    $fields['registration_end'] = NULL;
  }
  else {
    $fields['registration_end'] = $node->classroom_course['registration_end'];
  }

  $count = db_fetch_array(db_query("SELECT COUNT(*) AS courses FROM {classroom_course} WHERE nid = %d", $node->nid));
  $exists = (bool) $count['courses'];
  if ($exists) {
    drupal_write_record('classroom_course', $fields, 'nid');
    _classroom_update_course_access_by_rid($node);
  } else {
    _classroom_course_nodeapi_insert($node, $op, $a3, $a4);
  }
}

function _classroom_course_nodeapi_delete($node, $op, $a3 = NULL, $a4 = NULL) {
  //Remove user association to the course
  $users_nids = db_query("SELECT uid FROM {classroom_registration} WHERE course_nid = %d", $course->nid);  
  while ( $user_nid = db_fetch_array($users_nids) ) {
    $user = user_load($user_nid);
    classroom_signoff_user($user, $node);
  }

  //Remove assignments
  $assignments_nids = db_query("SELECT nid FROM {classroom_assignment} WHERE course_nid = %d", $node->nid);  
  while ( $assignment_nid = db_fetch_array($assignments_nids) ) {
    node_delete($assignment_nid["nid"]);
  }

  db_query("DELETE FROM {classroom_course} WHERE nid = %d", $node->nid);
}

function _classroom_course_nodeapi_load($node, $op, $a3 = NULL, $a4 = NULL) {
  // FIXME: return some kind of empty object when row isn't found.
  $data = db_fetch_array(db_query('SELECT start_t, end_t, registration_start, registration_end, use_grade_percentages, access_by_rid FROM {classroom_course} WHERE nid = %d', $node->nid));

  // Load dates into 'start_date' and 'end_date'.
  $data['start_date'] = _classroom_timestamp_to_form_date($data['start_t']);
  $data['end_date'] = _classroom_timestamp_to_form_date($data['end_t']);
  $data['registration_start_date'] = _classroom_timestamp_to_form_date($data['registration_start']);
  $data['registration_end_date'] = _classroom_timestamp_to_form_date($data['registration_end']);

  $data = array_merge($data, module_invoke_all('classroom_load_course', $node));
  return array('classroom_course' => $data);
}

function _classroom_course_nodeapi_validate(&$node, $op, $a3 = NULL, $a4 = NULL) {
  
  _classroom_course_sync_dates($node); // There's no prevalidate hook :(

  $start = $node->classroom_course['start_t'];
  $end = $node->classroom_course['end_t'];

  $registration_start = $node->classroom_course['registration_start'];
  $registration_end = $node->classroom_course['registration_end'];

  //Verification of start-end dates
  if ($node->classroom_course['unlimitedend'] == false)
  {
      if (isset($start) && isset($end) && ($start > $end)) {
      // FIXME: it must highlight the entire field ('classroom_course][end_date' doesnt't seems work).
      form_set_error('classroom_course][end_date][day', t('An event may not end before it starts.'));
    }
  }

  //Verification of registration_start and registration_end dates
  if ($node->classroom_course['open_end_inscription'] == false)
  {
    if (isset($registration_start) && isset($registration_end) && ($registration_start > $registration_end)) {
      form_set_error('classroom_course][registration_start_date][day', t('The registration period starting date must be prior to the ending date.'));
    }

    if ($node->classroom_course['unlimitedend'] == false) {
      if (isset($registration_start) && isset($end) && ($registration_start > $end)) {
        form_set_error('classroom_course][registration_start_date][day', t('The registration period may not start after the course ends.'));
      }
    }
  }
}

function _classroom_course_sync_dates(&$node) { 
  $node->classroom_course['start_t'] = _classroom_date_to_timestamp($node->classroom_course['start_date']);
  if ($node->classroom_course['unlimitedend']) {
    $node->classroom_course['end_t'] = null;
  }
  else {
    $node->classroom_course['end_t'] = _classroom_date_to_timestamp($node->classroom_course['end_date']);
  }

  $node->classroom_course['registration_start'] =
    _classroom_date_to_timestamp($node->classroom_course['registration_start_date']);
  if ($node->classroom_course['open_end_inscription']) {
    $node->classroom_course['registration_end'] = null;
  }
  else {
    $node->classroom_course['registration_end'] =
      _classroom_date_to_timestamp($node->classroom_course['registration_end_date']);
  }
}


/**
 * Method called to view the node
 */
function _classroom_course_nodeapi_view(&$node, $op, $a3, $a4)
{
  if (!$a3) {
    classroom_set_breadcrumb($node);
  }

  $node->content['classroom_course'] = array(
    '#type' => 'fieldset',
    '#title' => t('Course'),
    '#tree' => true,
  );

  if ($node->classroom_course['start_t']) {
    $node->content['classroom_course']['start_date'] = array(
      '#type' => 'item',
      '#title' => t('Starting date'),
      '#weight' => 1,
      '#value' => _classroom_format_date($node->classroom_course['start_t']),
      '#tree' => true,
    );
  }

  if ($node->classroom_course['end_t']) {
    $node->content['classroom_course']['end_date'] = array(
      '#type' => 'item',
      '#title' => t('End date'),
      '#weight' => 2,
      '#value' => _classroom_format_date($node->classroom_course['end_t']),
      '#tree' => true,
    );
  }

  if ($node->classroom_course['registration_start']) {
    $node->content['classroom_course']['registration_start_date'] = array(
      '#type' => 'item',
      '#title' => t('Registration starting date'),
      '#weight' => 3,
      '#value' => _classroom_format_date($node->classroom_course['registration_start']),
      '#tree' => true,
    );
  }

  if ($node->classroom_course['registration_end']) {
    $node->content['classroom_course']['registration_end_date'] = array(
      '#type' => 'item',
      '#title' => t('Registration ending date'),
      '#weight' => 4,
      '#value' => _classroom_format_date($node->classroom_course['registration_end']),
      '#tree' => true,
    );
  }

  $html_checkbox = '';

  if ($node->classroom_course['use_grade_percentages'])
    $html_checkbox = '<input type="checkbox" checked disabled=true>'.t('Use grade percentages').'</input>';
  else
    $html_checkbox = '<input type="checkbox" disabled=true>'.t('Use grade percentages').'</input>';

  $node->content['classroom_course']['use_grade_percentages'] = array(
    '#type' => 'markup',
    '#value' => $html_checkbox,
    '#tree' => true,
  );

}

/**
 * Check a timestamp against the time limits of a course
 * Return true if the timestamp is in the limits and false otherwise
 */
function classroom_course_check_timestamp($timestamp, $course) {
  $course_start_timestamp = gmmktime(0,0,0, $course->classroom_course['start_date']['month'],
    $course->classroom_course['start_date']['day'],
    $course->classroom_course['start_date']['year']);
  $course_end_timestamp =  gmmktime(23,59,59, $course->classroom_course['end_date']['month'],
    $course->classroom_course['end_date']['day'],
    $course->classroom_course['end_date']['year']);


  if ( $course->classroom_course['end_date'] != NULL) {
    if ( $timestamp > $course_end_timestamp ) {
      return false;
    }
  }

  if ($course->classroom_course['start_date'] != NULL) {
    if ( $timestamp< $course_start_timestamp ) {
      return false;
    }
  }

  return true;
}

/**
 * Calculate the course final grade 
 *
 * @param $course
 *   The course that will be used to calculate the final grade
 * @param $student
 *   The student, if the student is not present or is null will use the active user
 */
function classroom_course_calculate_finalgrade($course, $student = null){
  global $user;

  if (is_object($course)) {
    $course_nid = (int) $course->nid;
  } else {
    $course_nid = (int) $course;
    $course = node_load($course_nid);
  }

  if ($student == null) {
    $student = $user;
  }

  if (is_object($user)) {
    $uid = (int) $student->uid;
  } else {
    $uid = (int) $student;
  }

  if (!($uid AND $course_nid)) return FALSE;
  if (! classroom_is_user_registered($user, $course)) return FALSE;

  $final_grade = 0;
  $assignments = classroom_get_assignments($course);

  if (!empty($assignments)) {
    foreach ($assignments as $assignment) {
      $final_grade += classroom_assignment_calculate_finalgrade($assignment, $student);
    }
    return round($final_grade/count($assignments),2);
  } else {
    return NULL;
  }
}
