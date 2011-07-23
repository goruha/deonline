<?php
// $Id: classroom.blocks.inc,v 1.5 2010/02/03 18:10:03 osoh Exp $

/**
 * Builds the 'My courses' block.
 */
function classroom_my_courses_block() {
  global $user;

  $courses = classroom_get_courses_for_user($user);
  $list = array();
  foreach ($courses as $course) {
    $list[] = l($course->title, "classroom/course/$course->nid");
  }

  if (!empty($list)) {
    return theme('item_list', $list);
  }
}

function classroom_my_assignments_block($qty = 5) {
  global $user;

  $output = "";
  $courses = classroom_get_courses_for_user($user);

  foreach ($courses as $course) {
    $qry = "SELECT * FROM {node} LEFT JOIN {classroom_assignment} USING (nid) "
      ."WHERE course_nid = %d ORDER BY created DESC LIMIT %d";
    $result = db_query($qry, $course->nid, $qty);
    $rows = array();
    while ($assignment = db_fetch_object($result)) {
      if ($assignment->type == 'quiz')
        $rows[] = l($assignment->title, "classroomquiz/$assignment->nid");
      else
        $rows[] = l($assignment->title, "node/$assignment->nid");
    }

    if (!empty($rows)) {
      $output .= "<div class=\"course-title\">";
      $output .= l($course->title, "classroom/course/$course->nid");
      $output .= "</div>";
      $output .= theme('item_list', $rows);
    }
  }

  return $output;
}

/**
 * Builds the 'Topics' block.
 */
function classroom_topics_block() {
  global $user;

  $path = drupal_get_path_alias($_GET['q']);
  $matches = array();
  preg_match("/^classroom\/course\/(\d+)/", $path, $matches);

  $course = node_load(array('nid' => $matches[1]));

  if (classroom_is_user_registered($user, $course)) {
    $topics = classroom_get_topics($course);
    if (!empty($topics)) {
      $topics_list = array();
      foreach ($topics as $topic) {
        $topics_list[] = classroom_topic_link($topic);
      }
      return theme('item_list', $topics_list);
    }
  }
}
