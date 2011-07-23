<?php
// $Id: classroomquiz.access.inc,v 1.2 2009/08/10 09:49:31 osoh Exp $

/**
 * Determines if the current user is associated with the course (as teacher or
 * student) that owns that quiz or if he is admin ('administer classroom') 
 *
 * @param $quiz_nid
 *   Quiz ID.
 */
function classroomquiz_user_is_signed_up_or_owner_by_quiz($quiz_nid) {
  global $user; 

  if (user_access('administer classroom')) return true;
  
  $quiz_node = node_load($quiz_nid);
  $course_nid = $quiz_node->classroom_assignment["course_nid"];

  if ($course_nid == NULL) return;
  $course_node = node_load($course_nid);

  return classroom_is_user_registered($user, $course_node);
}

/**
 * Determines if the current user is associated with the course
 * that owns that quiz as teacher or if he is admin ('administer classroom')
 *
 * @param $quiz_nid
 *   Quiz ID.
 */
function classroomquiz_is_teacher_or_owner_by_quiz($quiz_nid) {
  global $user;

  if (user_access('administer classroom')) return true;

  $quiz_node = node_load($quiz_nid);
  $course_nid = $quiz_node->classroom_assignment["course_nid"];

  if ($course_nid == NULL) return;
  $course_node = node_load($course_nid);

  return classroom_is_teacher($user, $course_node);
}


