<?php
// $Id: classroom.responses.inc,v 1.11 2010/07/03 01:32:27 osoh Exp $

function classroom_get_response($assignment, $student) {
  $qry = "SELECT {node}.nid FROM {classroom_response} LEFT JOIN {node} USING (nid) WHERE uid = $student->uid AND assignment_nid = $assignment->nid";
  $result = db_query($qry);
  $row = db_fetch_array($result);
  if ($row) {
    return node_load($row['nid']);
  } else {
    return FALSE;
  }
}

function _classroom_response_form_delete_fields($form, $form_state, $form_id) {
  $node = node_load($form['nid']['#value']);
  $assignment_nid = null;
  $fields = array();

  if ( isset($_GET['assignment_nid']) )
    $assignment_nid = $_GET['assignment_nid'];

  if ( isset($node->classroom_response['assignment_nid']) )
    $assignment_nid = $node->classroom_response['assignment_nid'];

 if (isset($assignment_nid)) {
    classroom_set_breadcrumb($node);
    $fields['#redirect'] = 'node/'.$assignment_nid;
  }

  return $fields;
}

function _classroom_response_form_fields($form, $form_state, $form_id) {
  global $user;

  $node = $form['#node'];
  $fields = array();
  //Check that is a user of the course
  if (classroom_response_access_granted($node) == false)
    return $fields;

  //Check is the user is the author or is a teacher
  if($node->uid != null)
  {
    if ( ($node->uid != $user->uid) && (classroom_is_teacher($user, classroom_response_course_node($node) ) == false)) {
      drupal_access_denied();
      return $fields;
    }
  }

  $assignment_nid = null;

  $fields = array();

  if ( isset($_GET['assignment_nid']) )
    $assignment_nid = $_GET['assignment_nid'];

  if ( isset($node->classroom_response['assignment_nid']) )
    $assignment_nid = $node->classroom_response['assignment_nid'];

  if ( isset($assignment_nid) ) {

    $assignment_node = node_load($assignment_nid);
    $course_node = node_load($assignment_node->classroom_assignment['course_nid']);
    classroom_set_breadcrumb($node);


    $fields['classroom_response'] = array(
      '#type' => 'fieldset',
      '#title' => t('Grade'),
      '#tree' => true,
    );


    $fields['classroom_response']['assignment_nid'] = array(
      '#type' => 'value',
      '#value' => $assignment_nid,
      '#tree' => true,
    ); 

    $course = node_load($assignment_node->classroom_assignment['course_nid']);
    if ( classroom_is_teacher($user, $course) ) {
      $fields['classroom_response']['grade'] = array (
        '#type' => 'textfield',
        '#default_value'=> $node->classroom_response['grade'],
        '#tree' => true,
      );
    }
    else {
      $fields['classroom_response']['grade'] = array (
        '#type' => 'markup',
        '#value'=> $node->classroom_response['grade'],
        '#tree' => true,
      );

    }
    
    //Only redirects if is creating a new assignment
    if (! isset($node->nid)) {
      $fields['#redirect'] = 'node/'.$assignment_nid;
    }
  }
  return $fields;
}

/**
 *  Implementation fo hook nodeapi
 */
function _classroom_response_nodeapi(&$node, $op, $a3 = NULL, $a4 = NULL) {
  switch ($op) {
  case 'insert':
    return _classroom_response_nodeapi_insert($node, $op, $a3, $a4);
  case 'update':
    return _classroom_response_nodeapi_update($node, $op, $a3, $a4);
  case 'delete':
    return _classroom_response_nodeapi_delete($node, $op, $a3, $a4);
  case 'load':
    return _classroom_response_nodeapi_load($node, $op, $a3, $a4);
  case 'presave':
  case 'validate':
    return _classroom_response_nodeapi_validate($node, $op, $a3, $a4);
  case 'view':
    return _classroom_response_nodeapi_view($node, $op, $a3, $a4);
  }
}

/**
 * Method called to view the node
 */
function _classroom_response_nodeapi_view(&$node, $op, $a3, $a4)
{
  global $user;

  if (!$a3) {
    classroom_set_breadcrumb($node);
  }

  //Check that is a user of the course
  if (classroom_response_access_granted($node) == false)
    return;

  //Check is the user is the author or is a teacher
  if ( ($node->uid != $user->uid) && (classroom_is_teacher($user, classroom_response_course_node($node) ) == false)) {
    drupal_access_denied();
    return;
  }
  $grade = $node->classroom_response['grade'];

  if ($grade == NULL ) $grade = '---';
  
  $node->content['classroom_response_grade'] = array(
    '#type' => 'item',
    '#title' => t('Grade'),
    '#value' => $grade,
    '#tree' => true,
    '#weight' => 100,
  );
} 

/**
 * Method called to insert the response information
 */
function _classroom_response_nodeapi_insert($node, $op, $a3 = NULL, $a4 = NULL) {
  global $user;
  
  //To create nodes that are not response
  if ( isset($node->classroom_response['assignment_nid']) == FALSE ) return;

  $assignment = node_load($node->classroom_response['assignment_nid']);
  $course =  classroom_response_course_node($node);

  if ( classroom_is_teacher($user, $course) || isset($node->classroom_response['grade']) ) {
    db_query("INSERT INTO {classroom_response} (nid, assignment_nid, grade) VALUES (%d, %d, %f)",
      $node->nid, $node->classroom_response['assignment_nid'], $node->classroom_response['grade']);
  }
  else
  {
    db_query("INSERT INTO {classroom_response} (nid, assignment_nid) VALUES (%d, %d)",
      $node->nid, $node->classroom_response['assignment_nid']);

  }

}

/**
 * Method called to update the response information
 */
function _classroom_response_nodeapi_update($node, $op, $a3 = NULL, $a4 = NULL) {
  global $user;

  //To create nodes that are not responses
  if ( isset($node->classroom_response['assignment_nid']) == FALSE ) return;

  $count = db_fetch_array(db_query("SELECT COUNT(*) AS responses FROM {classroom_response} WHERE nid = %d", $node->nid));
  $exists = (bool) $count['responses'];
  if ($exists) {
    $course =  classroom_response_course_node($node);

    $assignment = node_load($node->classroom_response['assignment_nid']);

    if ( classroom_is_teacher($user, $course) || isset($node->classroom_response['grade']) ) {
      db_query("UPDATE {classroom_response} SET grade = %f, assignment_nid = %d WHERE nid = %d",
        $node->classroom_response['grade'], $node->classroom_response['assignment_nid'],
        $node->nid);
    }
    else {
      db_query("UPDATE {classroom_response} SET assignment_nid = %d WHERE nid = %d",
        $node->classroom_response['assignment_nid'], $node->nid);
    }
  } else {
    _classroom_response_nodeapi_insert($node, $op, $a3, $a4);
  }
}

/**
 * Method called to delete the response information
 */
function _classroom_response_nodeapi_delete($node, $op, $a3 = NULL, $a4 = NULL) {
  db_query("DELETE FROM {classroom_response} WHERE nid = %d", $node->nid);
}

/**
 * Method called to load the response information
 */
function _classroom_response_nodeapi_load($node, $op, $a3 = NULL, $a4 = NULL) {
  // FIXME: return some kind of empty object when row isn't found.
  $data = db_fetch_array(db_query('SELECT  grade, assignment_nid  FROM {classroom_response} WHERE nid = %d', $node->nid));

  return array('classroom_response' => $data);
}

/**
 * Method to validate the response information
 */
function _classroom_response_nodeapi_validate(&$node, $op, $a3 = NULL, $a4 = NULL) {
  global $user;

  if ( isset($node->classroom_response['assignment_nid']) == FALSE ) return;

  //Check that the assignment exists
  $assignment = node_load($node->classroom_response['assignment_nid']);
  $course = node_load($assignment->classroom_assignment['course_nid']);

  if ($assignment == NULL) {
    form_set_error('', t('The assignment for this response must exists'));
  } 

  //Check that response grade is not greater than maximum grade
  if (($node->classroom_response['grade'] != NULL) &&
    ($node->classroom_response['grade'] > $assignment->classroom_assignment['max_grade'])) {
      form_set_error('classroom_response][grade',t('The response cannot be graded overdue the maximum grade'));
    }

  //Assignment date limits
  if (classroom_assignment_check_timestamp(time(), $assignment) == false) {
    form_set_error('', t('The response could not be modified after due date of the assignment'));
  }

  //Course date limits
  if (classroom_course_check_timestamp(time(), $course ) == false) {
    form_set_error('', t('The response could not be modified outside the time limits of the course'));
  }
 
  //Check that the response have not been graded
  if (( $node->uid == $user->uid ) && ( $node->classroom_response['grade'] != NULL)) {
    form_set_error('classroom_response][grade', t('Cannot modify a response that have been graded'));
  }

  //Check whois trying to delete (only the author can do it)
  if (( $_POST['op']==t('Delete') ) && ($node->uid != $user->uid) )
  {
    form_set_error('',t('Only the author could delete a response'));
  }

  //If is a delete operation don't need more validations
  if ( $_POST['op']==t('Delete') )  return;

  //Check that the assignment have no responses from that user
  if ( ! isset($node->nid))
  {
    $count = db_fetch_array(db_query("SELECT COUNT(*) AS responses FROM {classroom_response} as r,{node} as n where r.assignment_nid = %d".
      " AND r.nid = n.nid  AND n.uid = %d", $node->classroom_response['assignment_nid'], $node->uid));

    $exists = (bool) $count['responses'];

    if ( $exists === true) {
      form_set_error('',t('An assignment could not have two responses'));
    }
  }

}

/**
 * Method to get the course node of an response
 */

function classroom_response_course_node($node) {
  $assignment_nid = null;

  if ( isset($_GET['assignment_nid']) )
    $assignment_nid = $_GET['assignment_nid'];

  if ( isset($node->classroom_response['assignment_nid']) )
    $assignment_nid = $node->classroom_response['assignment_nid'];

  if ($assignment_nid == null)
    return false;

  $assignment_node = node_load($assignment_nid);
  $course_node = node_load($assignment_node->classroom_assignment['course_nid']);

  return $course_node;
}

/**
 * Method to control the access
 */

function classroom_response_access_granted($node) {
  global $user;

  $course_node = classroom_response_course_node($node);

  if (( classroom_is_teacher($user, $course_node) == false ) &&
    ( classroom_is_student($user, $course_node) == false )) {
      drupal_access_denied();
      return false;
    }
  else
    return true;
}

/**
 * Returns an array containing data to build the response link.
 *
 * The idea is that modules can provide links for different node types.
 */
function classroom_response_link($node) {
  global $user;

  $urls = module_invoke_all('classroom_response_link', $node, $user);
  foreach ($urls as $module => $url) {
    if ($url) {
      $selected_module = $module;
      break;
    }
  }

  if ($selected_module) {
    return array($selected_module => $urls[$selected_module]);
  } else {
    return _classroom_default_response_link($node, $user);
  }
}

/**
 * Default response link for a node. It's used for hook_classroom_response_link
 * in case that no module returns a response link.
 */
function _classroom_default_response_link($node, $user) {
  $course = node_load(array('nid' => $node->classroom_assignment['course_nid']));
  if (!classroom_is_student($user, $course)) { return FALSE; }

  $response = classroom_get_response($node, $user);
  if ($response) {
    $link = array(
      'title' => t("View response"),
      'href' => "node/{$response->nid}",
    );
  } else {
    $response_types = array_values(_classroom_get_types_for('response'));
    $link = array(
      'title' => t("To answer"),
      'href' => classroom_node_add_url($response_types[0]->type),
      'query' => "assignment_nid={$node->nid}",
    );
  }
  return array('classroom' => $link);
}
