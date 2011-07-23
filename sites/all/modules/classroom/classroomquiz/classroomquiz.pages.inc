<?php
// $Id: classroomquiz.pages.inc,v 1.4 2010/03/16 18:02:57 osoh Exp $

/**
 * Function to render the quiz title
 */
function _classroomquiz_page_title($quiz_nid) {
  $quiz_node = node_load($quiz_nid);
  if ($quiz_node == NULL) {
    return "";
  }
  return $quiz_node->title;
}

/**
 * Function to render the quiz view page
 */
function _classroomquiz_page($quiz_nid) {
  global $user;
  $quiz_node = node_load($quiz_nid);
  //node/385/questions
 if ($quiz_node == NULL){
    drupal_not_found();
    return;
  }

  if ($quiz_node->type != 'quiz') {
    drupal_not_found();
    return;
  }

  $quiz_node = node_load($quiz_nid);
  $course_nid = $quiz_node->classroom_assignment["course_nid"];
  $course_node = node_load($course_nid);

  $breadcrumb = array(
    l(t("Home"), "<front>"),
    l(t("Courses"), "classroom/"),
    l($course_node->title, "classroom/course/".$course_node->nid),
    l(t("Assignments"), "classroom/course/".$course_node->nid."/assignments"),
  );

  drupal_set_breadcrumb($breadcrumb);
  $questions = quiz_build_question_list($quiz_node);

  if (count($questions) == 0) {
    drupal_set_message(t('No questions were found. Please !assign questions before trying to take this quiz.',
      array( '!assign questions' => l('assign questions', 'node/'. $quiz_nid.'/questions'))), 'error');
  }

  $form=array();
  $form['body'] = array(
    '#type' => 'markup',
    '#value' => $quiz_node->body,
    '#weight' => 0);

  $form['classroom_assignment'] = array(
    '#type' => 'fieldset',
    '#title' => t('Assignment details'),
    '#tree' => true,
    '#collapsible' => true,
    '#weight' => 1
  );

  $form['classroom_assignment']['end_date'] = array(
    '#type' => 'item',
    '#title' => t('End date'),
    '#value' => $quiz_node->classroom_assignment['end_date']['day']."/".
    $quiz_node->classroom_assignment['end_date']['month']."/".
    $quiz_node->classroom_assignment['end_date']['year'],
    '#tree' => true,
    '#weight' => 0,
  );

  $form['classroom_assignment']['max_grade'] = array(
    '#type' => 'item',
    '#title' => t('Maximum grade'),
    '#value' => $quiz_node->classroom_assignment['max_grade'],
    '#weight' => 1,
    '#tree' => true,
  );


  if ($course_node->classroom_course["use_grade_percentages"] == 1) {

    $form->content['classroom_assignment']['grade_percentage'] = array(
      '#type' => 'item',
      '#title' => t('Percentage'),
      '#value' => $quiz_node->classroom_assignment['grade_percentage']." %",
      '#tree' => true,
      '#weight' => 2,
    );

  }
  if (classroom_is_student($user, $course_node)){

    $form['classroom_responses'] = array(
      '#type' => 'fieldset',
      '#title' => t('Responses details'),
      '#tree' => true,
      '#collapsible' => true,
      '#weight' => 4,
    );

   $headers = array(
      'student' => array('data' => t('Student'),     'field' => 'name' ),
      'title'   => array('data' => t('Title'),       'field' => 'title'),
      'date'    => array('data' => t('Submit date'), 'field' => 'changed'),
      'grade'   => array('data' => t('Grade'),       'field' => 'grade'),
    );
    $order_sql = tablesort_sql($headers);

    $rows = classroom_assignment_get_own_response($quiz_node, $order_sql);
    $rows[0]["title"] = l(t("Goto quiz"), "node/".$quiz_node->nid);
    $response_table = theme('table', $headers, $rows);
    $response_table .= theme('pager');

    $form['classroom_responses']['table'] = array(
      '#type' => 'markup',
      '#value' => $response_table,
      '#tree' => true,
    );
  }
  $output = drupal_render($form);

  return $output;

}

/**
 * Method to obtain a row with the user response
 */
function classroom_assignment_get_own_response($assignment, $order = NULL) {
  global $user;
  $limit = variable_get('classroom_pager_limit', CLASSROOM_PAGER_LIMIT_DEFAULT);
  $results = classroom_assignment_get_responses($assignment, $user, $order, $limit);
  $rows = array();

  $types = _classroom_get_types_for('response');
  reset($types);
  $obj = current($types);
  $key = key($types);

  $row = $results[0];

  if (count($results) == 0) {
    $rows[] = array(
      'student' => l($user->name, 'user/'.$user->uid),
      'title' => classroom_response_link($assignment),
      'date'=>'---',
      'grade'=>'---'
    );
  }
  else {
    if ($row['grade'] == NULL) $row['grade'] = '---';
    $rows[] = array (
      'student' => l($user->name, 'user/'.$user->uid),
      'title' =>  l(truncate_utf8($row['title'], 20, false, true),
      'node/'.$row['nid']),
      'date'    => date('d/m/Y', $row['changed']),
      'grade'   => $row['grade'],
    );
  }
  return $rows;
}

