<?php
// $Id: classroom.assignments.inc,v 1.28 2010/03/18 21:09:53 osoh Exp $

function _classroom_assignment_form_delete_fields($form, $form_state, $form_id) {
  $node = node_load($form['nid']['#value']);
  $course_node = node_load($node->classroom_assignment['course_nid']);

  classroom_set_breadcrumb($node, TRUE);

  $fields = array();
  $fields['#redirect'] = 'classroom/course/'.$course_node->nid."/assignments";

  return $fields;
}

function _classroom_assignment_form_fields($form, $form_state, $form_id) {

 //cid contains the course id that assignment belongs to
  $node = $form['#node'];

  $fields = array();

  //Check that is a user of the course
  if (classroom_assignment_access_granted($node) == false)
    return $fields;

  $course_nid = null;

  if ( isset($_GET['course_nid']) )
    $course_nid = $_GET['course_nid'];

  if ( isset($node->classroom_assignment['course_nid']) )
    $course_nid = $node->classroom_assignment['course_nid'];

  if ( isset($course_nid) ) {

    $course_node = node_load($course_nid);
    classroom_set_breadcrumb($node);

    $fields['classroom_assignment'] = array(
      '#type' => 'fieldset',
      '#title' => t('Assignment'),
      '#tree' => true,
    );


    $fields['classroom_assignment']['end_date'] = array(
      '#type' => 'fieldset',
      '#title' => t('Ending date'),
      '#tree' => true,
    );

    if ($node->classroom_assignment['end_date']['type'] == null)
      $node->classroom_assignment['end_date']['type'] = 0;

    $fields['classroom_assignment']['end_date']['type'] = array(
      '#type' => 'radios',
      '#title' => t('Ending date type'),
      '#default_value' => $node->classroom_assignment['end_date']['type'],
      '#tree' => true,
      '#options' => array(t('Fixed date'),t('Relative date'),t('Without date')),
      '#weight' => 0,
      '#attributes' => array('onClick' => 'update_end_date()'),
    );


    $fields['classroom_assignment']['end_date']['date'] = array(
      '#type' => 'date',
      '#title' => t('Ending date'),
      '#default_value' => $node->classroom_assignment['end_date']['date'],
      '#tree' => true,
    );

    $fields['classroom_assignment']['end_date']['relative_end'] = array(
      '#type' => 'textfield',
      '#title' => t('Days from registration'),
      '#default_value' => $node->classroom_assignment['end_date']['relative_end'],
      '#size' => 3,
      '#maxlength' => 3,
      '#tree' => true,
      );

    //TODO: Something that fills the percentage as sum of the other percentage
    //TODO: size don't affect to textfields

    if ($course_node->classroom_course["use_grade_percentages"] == 1) {

      $fields['classroom_assignment']['grade_percentage'] = array(
        '#type' => 'textfield',
        '#title' => t('Percentage'),
        '#default_value' => $node->classroom_assignment['grade_percentage'],
        '#required' => true,
        '#tree' => true,
      );

    }

    $fields['classroom_assignment']['max_grade'] = array(
      '#type' => 'textfield',
      '#title' => t('Maximum grade'),
      '#default_value' => $node->classroom_assignment['max_grade'],
      '#required' => true,
      '#tree' => true,
    );

    $topics_map = classroom_get_topics_for_select($course_node);
    if (!empty($topics_map)) {
      $fields['classroom_assignment']['topic_tid'] = array(
        '#type' => 'select',
        '#title' => t('Topic'),
        '#description' => t('Related topic.'),
        '#default_value' => $node->classroom_assignment['topic']->tid,
        '#options' => $topics_map,
      );
    }

    $fields['classroom_assignment']['course_nid'] = array(
      '#type' => 'value',
      '#value' => $course_nid,
      '#tree' => true,
    ); 

    //Only redirects if is creating a new assignment
    if (! isset($node->nid)) {
      $fields['#redirect'] = 'classroom/course/'.$course_nid.'/assignments';
    }
  }
  return $fields;
}

/**
 *  Implementation fo hook nodeapi
 */
function _classroom_assignment_nodeapi(&$node, $op, $a3 = NULL, $a4 = NULL) {
  drupal_add_js(drupal_get_path('module', 'classroom') .'/classroom.assignments.js', 'module');

  switch ($op) {
  case 'insert':
    return _classroom_assignment_nodeapi_insert($node, $op, $a3, $a4);
  case 'update':
    return _classroom_assignment_nodeapi_update($node, $op, $a3, $a4);
  case 'delete':
    return _classroom_assignment_nodeapi_delete($node, $op, $a3, $a4);
  case 'load':
    return _classroom_assignment_nodeapi_load($node, $op, $a3, $a4);
  case 'presave':
    return _classroom_assignment_nodeapi_presave($node, $op, $a3, $a4);
  case 'validate':
    return _classroom_assignment_nodeapi_validate($node, $op, $a3, $a4);
  case 'view':
    return _classroom_assignment_nodeapi_view($node, $op, $a3, $a4);
  }
}

/**
 * Method called to view the node
 */
function _classroom_assignment_nodeapi_view(&$node, $op, $a3, $a4)
{
  if (classroom_assignment_access_granted($node) == false )
    return;

  global $user;

  $course_node = node_load($node->classroom_assignment['course_nid']);

  if (!$a3) { // Full
    classroom_set_breadcrumb($node);
  }

  $node->content['classroom_assignment'] = array(
    '#type' => 'fieldset',
    '#title' => t('Assignment details'),
    '#tree' => true,
    '#collapsible' => true,
    '#collapsed' => true,
    '#weight' => 1
  );

  switch ($node->classroom_assignment['end_date']['type']) {
  case 0:
    $node->content['classroom_assignment']['end_date']['date'] = array(
      '#type' => 'item',
      '#title' => t('Ending date'),
      '#value' => _classroom_format_date($node->classroom_assignment['end_date']['end_t']),
      '#tree' => true,
      '#weight' => 0,
    );
    break;

  case 1:
    $node->content['classroom_assignment']['end_date']['relative_end'] =array(
      '#type' => 'item',
      '#title' => t('Ending date (days from registration)'),
      '#value' => $node->classroom_assignment['end_date']['relative_end'],
      '#weight' => 1,
      '#tree' => true,
    );
    break;

  case 2:
    $node->content['classroom_assignment']['end_date']['noend'] = array(
      '#type' => 'item',
      '#title' => t('Ending date'),
      '#value' => t('Unlimited'),
      '#weight' => 1,
      '#tree' => true,
    );
    break;

  }

  $node->content['classroom_assignment']['max_grade'] = array(
    '#type' => 'item',
    '#title' => t('Maximum grade'),
    '#value' => $node->classroom_assignment['max_grade'],
    '#weight' => 1,
    '#tree' => true,
  );


  if ($course_node->classroom_course["use_grade_percentages"] == 1) {

    $node->content['classroom_assignment']['grade_percentage'] = array(
      '#type' => 'item',
      '#title' => t('Percentage'),
      '#value' => $node->classroom_assignment['grade_percentage']." %",
      '#tree' => true,
      '#weight' => 2,
    );

  }
}

/**
 * Method called to insert the assignment information
 */
function _classroom_assignment_nodeapi_insert($node, $op, $a3 = NULL, $a4 = NULL) {
  //If is not an assignment don't insert anything
  if (! isset($node->classroom_assignment) ) return;

  //To create nodes that are not assignments
  if ( isset($node->classroom_assignment['course_nid']) == FALSE ) return;

  $fields = array();
  array_push($fields, $node->nid);
  array_push($fields, $node->classroom_assignment['course_nid']);
  array_push($fields, $node->classroom_assignment['max_grade']);
  array_push($fields, $node->classroom_assignment['grade_percentage']);
  
  $query = "INSERT INTO {classroom_assignment} (nid, course_nid, max_grade, grade_percentage, topic_tid, end_t, relative_end) VALUES (%d, %d, %d, %d, ";

  if ($node->classroom_assignment['topic_tid']) {
    array_push($fields, $node->classroom_assignment['topic_tid']);
    $query .= " %d,";
  } else {
    $query .= " NULL,";
  }

  if ($node->classroom_assignment['end_date']['type'] == 0) {
    array_push($fields, $node->classroom_assignment['end_date']['end_t']);
    $query .= " %d,";
  }
  else {
    $query .= " NULL,";
  }

  if ($node->classroom_assignment['end_date']['type'] == 1) {
    array_push($fields, $node->classroom_assignment['relative_end']);
    $query .= " %d)";
  }
  else {
    $query .= " NULL)";
  }

  db_query($query, $fields);
}

/**
 * Method called to load the assignment information
 */
function _classroom_assignment_nodeapi_load($node, $op, $a3 = NULL, $a4 = NULL) {
  // FIXME: return some kind of empty object when row isn't found.
  $data = db_fetch_array(db_query('SELECT end_t, relative_end, grade_percentage, course_nid, topic_tid, max_grade FROM {classroom_assignment} WHERE nid = %d',
    $node->nid));

  $data['end_date']['type'] = 2;

  // Load dates into 'end_date'.
  if ($data['end_t']) {
    $data['end_date']['date'] = _classroom_timestamp_to_form_date($data['end_t']);
    $data['end_date']['end_t'] = $data['end_t'];
    $data['end_date']['type'] = 0;
  }

  if ($data['relative_end']) {
    $data['end_date']['relative_end'] = $data['relative_end']/86400;
    $data['end_date']['type'] = 1;
  }

  if ($data['topic_tid']) {
    $data['topic'] = classroom_load_topic($data['topic_tid']);
  }
 
  unset($data['end_t']);
  unset($data['relative_end']);

  return array('classroom_assignment' => $data);
}

/**
 * Method called to update the assignment information
 */
function _classroom_assignment_nodeapi_update($node, $op, $a3 = NULL, $a4 = NULL) {
  //If is not an assignment don't update
  if (! isset($node->classroom_assignment) ) return;

  //To create nodes that are not assignments
  if ( isset($node->classroom_assignment['course_nid']) == FALSE ) return;

  $count = db_fetch_array(db_query("SELECT COUNT(*) AS assignments FROM {classroom_assignment} WHERE nid = %d", $node->nid));
  $exists = (bool) $count['assignments'];
  if ($exists) {
    $query = "UPDATE {classroom_assignment} SET course_nid = %d, max_grade = %d, grade_percentage = %d,";

    $fields = array();
    array_push($fields, $node->classroom_assignment['course_nid']);
    array_push($fields, $node->classroom_assignment['max_grade']);
    array_push($fields, $node->classroom_assignment['grade_percentage']);

    if ($node->classroom_assignment['topic_tid']) {
      array_push($fields, $node->classroom_assignment['topic_tid']);
      $query .= " topic_tid = %d,";
    }

    if ($node->classroom_assignment['end_date']['end_t']) {
      array_push($fields, $node->classroom_assignment['end_date']['end_t']);
      $query .= " end_t = %d,";
    }
    else {
      $query .= " end_t = NULL,";
    }

    if ($node->classroom_assignment['relative_end']) {
      array_push($fields, $node->classroom_assignment['relative_end']);
      $query .= " relative_end = %d";
    }
    else {
      $query .= " relative_end = NULL";
    }

    $query .= " WHERE nid = %d";
    array_push($fields, $node->nid);

    db_query($query, $fields);
  } else {
    _classroom_assignment_nodeapi_insert($node, $op, $a3, $a4);
  }
}

/**
 * Method called to delete the assignment information
 */
function _classroom_assignment_nodeapi_delete($node, $op, $a3 = NULL, $a4 = NULL) {
  //If is not an assignment do not delete
  if (! isset($node->classroom_assignment) ) return;

  $responses_nids = db_query("SELECT nid FROM {classroom_response} WHERE assignment_nid = %d", $node->nid);  

  while ( $response_nid = db_fetch_array($responses_nids) ) {
    node_delete($response_nid["nid"]);
  }

  db_query("DELETE FROM {classroom_assignment} WHERE nid = %d", $node->nid);
}

/**
 * Method called before save the node
 */
function _classroom_assignment_nodeapi_presave(&$node, $op, $a3, $a4) {
  //If is not an assignment don't do anything
  if (! isset($node->classroom_assignment) ) return;

  _classroom_assignment_sync_dates($node);
  _classroom_assignment_nodeapi_validate($node, $op, $a3, $a4);
}

/**
 *Method to validate the assignment information
 */
function _classroom_assignment_nodeapi_validate(&$node, $op, $a3 = NULL, $a4 = NULL) {
  global $user;
 
  //If is not an assignment not validate anything
  if (! isset($node->classroom_assignment) ) return;
  
  _classroom_assignment_sync_dates($node); // There's no prevalidate hook :(

  $end = $node->classroom_assignment['end_date'];

  // Load the course
  $course = node_load(array('nid' => $node->classroom_assignment['course_nid']));

  //Check the user is a teacher of this course
  if (!classroom_is_teacher($user, $course)) {
    form_set_error('', t('You must be a teacher of this course'));
  } 

  //If no course is defined is not an assignment node
  if ( isset($node->classroom_assignment['course_nid']) == FALSE ) return;

  //Check the course
  if ($course == false){
    form_set_error('', t('The course for this assignment must exists'));
  }

  //Check the percentage not exceed 100%
  if ($course->classroom_course['use_grade_percentages'] == TRUE)
  {
    $query = "SELECT sum(grade_percentage) AS percentage FROM {classroom_assignment} WHERE course_nid = ".$node->classroom_assignment['course_nid'];

    if (isset($node->nid)) { // The node exists in the database yet.
      $query .= " AND nid != ".$node->nid;
    }

    $sum = db_fetch_array(db_query($query));
    $percentage = $sum['percentage'] + $node->classroom_assignment['grade_percentage'];

    if ($percentage > 100) {
      form_set_error('classroom_assignment][grade_percentage', t('The sum of the percentages of all assignments must not exceed 100%'));
    }
  }

  $actual_time = time();
  $today = gmmktime(0, 0, 0, (int)strftime('%m', $actual_time),
    (int)strftime('%d', $actual_time),
    (int)strftime('%Y', $actual_time));
  
  switch ($node->classroom_assignment['end_date']['type'])
  {
  case 0: //Fixed date
    $course_start_timestamp = gmmktime(0,0,0, $course->classroom_course['start_date']['month'],
      $course->classroom_course['start_date']['day'],
      $course->classroom_course['start_date']['year']);
    $course_end_timestamp =  gmmktime(23,59,59, $course->classroom_course['end_date']['month'],
      $course->classroom_course['end_date']['day'],
      $course->classroom_course['end_date']['year']);

    //Check that end date not overdue course end date

    if ( $course->classroom_course['end_date'] != NULL) {
      if ( $node->classroom_assignment['end_date']['end_t'] > $course_end_timestamp ) {
        form_set_error('', t('The assignment could not end after the course end'));
      }
    }

    if ($course->classroom_course['start_date'] != NULL) {
      if (($node->classroom_assignment['end_date'] != NULL) && ($node->classroom_assignment['end_date']['end_t'] != NULL))
        if ( $node->classroom_assignment['end_date']['end_t']< $course_start_timestamp ) {
          form_set_error('', t('The assignment could not end before the course begins'));
        }
    }
 
    //Check that end date is not before today
    if (($node->classroom_assignment['end_date'] != NULL) && ($node->classroom_assignment['end_date']['end_t'] != NULL))

      if ( $node->classroom_assignment['end_date']['end_t'] < $today ) {
        form_set_error('', t('The end date could not be before today'));
      }
    break;
  case 1: //Relative end
    if ($node->classroom_assignment['relative_end']<=0)
      form_set_error('',t('The end date could not be before today'));
    break;
  case 2: //No end
    break;
  }
}

/**
 * Method to convert date into timestamp
 */
function _classroom_assignment_sync_dates(&$node) {
  switch ($node->classroom_assignment['end_date']['type']) {
  case 0: //Fixed date
    $node->classroom_assignment['end_date']['end_t'] =
      _classroom_date_to_timestamp($node->classroom_assignment['end_date']['date']);
    $node->classroom_assignment['relative_end'] = NULL;
    $node->classroom_assignment['end_date']['relative_end'] = NULL;
    break;
  case 1: //Relative date
    $node->classroom_assignment['end_date']['end_t'] = NULL;
    $node->classroom_assignment['end_date']['date'] = NULL;
    $node->classroom_assignment['relative_end'] = ($node->classroom_assignment['end_date']['relative_end']*86400);
    break;
  case 2: //Without date
    $node->classroom_assignment['end_date']['end_t'] = NULL;
    $node->classroom_assignment['end_date']['date'] = NULL;
    $node->classroom_assignment['relative_end'] = NULL; 
    $node->classroom_assignment['end_date']['relative_end'] = NULL;
    break;
  }
}

/**
 * Method to control the access
 */

function classroom_assignment_access_granted($node) {
  global $user;

  $course_nid = null;

  if ( isset($_GET['course_nid']) )
    $course_nid = $_GET['course_nid'];

  if ( isset($node->classroom_assignment['course_nid']) )
    $course_nid = $node->classroom_assignment['course_nid'];

  if ($course_nid == null)
    return false;

  $course_node = node_load($course_nid);

  if (( classroom_is_teacher($user, $course_node) == false ) &&
    ( classroom_is_student($user, $course_node) == false )) {
      drupal_access_denied();
      return false;
    }   
  else
    return true;
}

/**
 * Check a timestamp against the time limits of an assignment
 * Return true if the timestamp is in the limits and false otherwise
 */
function classroom_assignment_check_timestamp($timestamp, $assignment) {
  global $user;

  _classroom_assignment_sync_dates($assignment);

  switch ($assignment->classroom_assignment['end_date']['type']) {
  case 0: //Fixed dates
    if ($timestamp < $assignment->classroom_assignment['end_date']['end_t'])
      return true;
    else
      return false;
    break;
  case 1: //Relative dates
    $date =  classroom_get_registration_date($user, $assignment->classroom_assignment['course_nid']); 
    $initial_date = gmmktime(0,0,0, $date['month'],
      $date['day'],
      $date['year']);

    if ($timestamp < ($initial_date + $assignment->classroom_assignment['relative_end']))
      return true;
    else 
      return false;
    break;
  case 2: //No end date
     return true;
    break;
  }
}


/**
 * Calculate the final grade for a response of an assignment
 *
 * @param $assignment
 *   Assignment itself
 * @param $response
 *   Response of the assignment
 * @param $student
 *   The student 
 * @return
 *   A float representing the final grade for a response of an assignment.
 */
function classroom_assignment_calculate_finalgrade($assignment, $student) {
  global $user;

  if ($assignment === NULL) {
    return FALSE;
  }

  $response = classroom_get_response($assignment, $student);
  if ($response === FALSE) {
    return 0;
  }

  $course = node_load($node->classroom_assignment['course_nid']);

  // NOTE: this '10' could be something like a course's 'max grade'.
  if ($assignment->classroom_assignment["max_grade"] != 0) {
    $grade = (10 * $response->classroom_response["grade"])
      / $assignment->classroom_assignment["max_grade"];
  } else {
    return 0;
  }

  if ($course->classroom_course['use_grade_percentages']) {
    $grade -= ($grade * ($assignment->classroom_assignment["grade_percentage"] / 100));
  }

  return $grade;
}

/**
 * Function to get the responses to an assignment
 *
 * FIXME: params should be documented.
 */
function classroom_assignment_get_responses($assignment, $user, $order = NULL, $limit = NULL) {
  $responses = array();
  $query =  "SELECT r.*, n.changed, n.title FROM {classroom_response} AS r, {node} AS n".
    " WHERE r.nid = n.nid AND n.uid = %d AND r.assignment_nid = %d $order";

  if ($limit == NULL) {
    $results =   db_query(
      $query,
      $user->uid , $assignment->nid);
  }
  else {
    $results = pager_query(
      $query,
      $limit,
      0, NULL,
      $user->uid, $assignment->nid);
  }

  while ($result = db_fetch_array($results)) {
    $responses = array_merge($responses, array( $result));
  }
  return $responses;
}
