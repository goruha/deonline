<?php
// $Id: classroom.topics.inc,v 1.4 2009/12/17 17:59:46 osoh Exp $

/**
 * Retrieves all topics for a course.
 *
 * @param $course
 *   Course.
 */
function classroom_get_topics($course) {
  $result = db_query("SELECT tid FROM {classroom_topic} WHERE course_nid = %d ORDER BY number", $course->nid);
  $topics = array();
  while ($row = db_fetch_array($result)) {
    $topics[] = classroom_load_topic($row['tid']);
  }
  return $topics;
}

/**
 * Creates a topic object. It's just an standard object with some
 * attributes.
 *
 * @param $attr
 *   Associative array containing attributes' values. They could be 'course',
 *   'name', 'description' and 'number'.
 * @return
 *   An StdObject that represents the topic.
 */
function classroom_new_topic($attr = array()) {
  $data = array(
    'course' => $attr['course'],
    'name' => $attr['name'],
    'description' => $attr['description'],
    'number' => $attr['number'],
  );
  return ((object) $data);
}

/**
 * Writes a topic object into the database.
 *
 * @param $topic
 *   The topic object. If the topic doesn't exists in the database,
 *   this object is modified adding the assigned 'tid' when saving.
 * @return
 *   Same as drupal_write_record().
 */
function classroom_save_topic(&$topic) {
  $data = (array) $topic;
  $data['course_nid'] = $topic->course->nid;
  if ($topic->tid) { // It exists on database yet.
    $ret = drupal_write_record('classroom_topic', $data, 'tid');
  } else {
    $ret = drupal_write_record('classroom_topic', $data);
    $topic->tid = db_last_insert_id('classroom_topic', 'tid');
  }
  return $ret;
}

/**
 * Loads a topic object from the database.
 *
 * @param $tid
 *   Topic's ID.
 * @return
 *   A topic object with the ID $tid. If a topic with that ID doesn't exist,
 *   the function returns NULL.
 */
function classroom_load_topic($tid) {
  $result = db_query("SELECT * FROM {classroom_topic} WHERE tid = %d", $tid);
  if ($attr = db_fetch_array($result)) {
    $topic = classroom_new_topic($attr);
    $topic->tid = $tid;
    $topic->course = node_load(array('nid' => $attr['course_nid']));
    return $topic;
  } else {
    return NULL;
  }
}

/**
 * Deletes a topic object from the database.
 *
 * @param $tid
 *   The topic object.
 */
function classroom_delete_topic($topic) {
  $tid = $topic->tid;
  // Delete topic's references.
  $result = db_query("UPDATE {classroom_assignment} SET topic_tid = NULL WHERE topic_tid = %d", $tid);
  $result = db_query("UPDATE {classroom_course_resource} SET topic_tid = NULL WHERE topic_tid = %d", $tid);
  // Delete the topic.
  $result = db_query("DELETE FROM {classroom_topic} WHERE tid = %d", $tid);
}

/**
 * Helper function that builds a topic's map for using in form selects.
 *
 * @param $course
 *   Course.
 * @return
 *   An array where keys are 'topic IDs' and values are the respective 'topics'.
 */
function classroom_get_topics_for_select($course) {
  $topics = classroom_get_topics($course);
  $topics_map = array();
  $topics_map[0] = t('None');
  foreach ($topics as $topic) {
    $topics_map[$topic->tid] = $topic->name;
  }
  return $topics_map;
}

/**
 * Helper function that builds a link to the topic page.
 *
 * @param $course
 *   Course.
 * @return
 *   An array where keys are 'topic IDs' and values are the respective 'topics'.
 */
function classroom_topic_link($topic, $title = NULL) {
  $title = ($title) ? $title : "{$topic->number}. {$topic->name}";
  return l($title, "classroom/course/{$topic->course->nid}/topic/{$topic->tid}");
}
