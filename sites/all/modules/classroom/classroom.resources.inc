<?php
// $Id: classroom.resources.inc,v 1.3 2009/12/22 11:44:04 osoh Exp $

/**
 * Get resources associated to a given course.
 *
 * @param $course
 *   Course to query about her resources.
 * @param $topic
 *   Topic which the resource belongs to. It could be: a topic, null (all resources),
 *   or false (only resources without associated topic).
 * @return
 *   An array containing resource objects associated with $course. Returns an
 *   empty array if there's no resources.
 */
function classroom_get_resources_for($course, $topic = NULL) {
  $qry = "SELECT resource_nid FROM {classroom_course_resource} WHERE course_nid = %d";
  $conds = array($course->nid);
  if ($topic) {
    $qry .= " AND topic_tid = %d";
    $conds[] = $topic->tid;
  } elseif ($topic === FALSE) {
    $qry .= " AND topic_tid IS NULL";
  }
  $result = db_query($qry, $conds);
  $resources = array();
  while ($row = db_fetch_array($result)) {
    // OPTIMIZE
    $resources[] = node_load(array('nid' => $row['resource_nid']));
  }
  return $resources;
}

/**
 * Add a resource to a course.
 *
 * @param $course
 *   Course to add the resource.
 * @param $resource
 *   Resource to add.
 * @return
 *   This function returns true if the resource was added to the course
 *   successfully. Otherwise it returns false.
 */
function classroom_add_resource($course, $resource, $topic = NULL) {
  if (isset($course->nid) and isset($resource->nid)) {
    $data = array(
      'course_nid' => $course->nid,
      'resource_nid' => $resource->nid,
    );
    if ($topic) {
      $data['topic_tid'] = $topic->tid;
    }
    drupal_write_record("classroom_course_resource", $data);
    return (db_error() == 0);
  } else {
    return FALSE;
  }
}

/**
 * Remove a resource from a course.
 *
 * @param $course
 *   Course to remove the resource from.
 * @param $resource
 *   Resource to remove.
 * @return
 *   This function returns true if the resource was removed from the course
 *   successfully. Otherwise it returns false.
 *   FIXME: It returns true if the resource and the course weren't associated.
 */
function classroom_remove_resource_from($course, $resource) {
  if (isset($course->nid) and isset($resource->nid)) {
    db_query("DELETE FROM {classroom_course_resource} WHERE resource_nid = %d AND course_nid = %d",
      $resource->nid, $course->nid);
    return (db_error() == 0);
  } else {
    return FALSE;
  }
}

/**
 * Implementation of hook_nodeapi
 */
function _classroom_resource_nodeapi(&$node, $op, $a3 = NULL, $a4 = NULL) {
  switch ($op){
  case 'view':
  case 'alter':
    if (!$a3) {
      classroom_set_breadcrumb($node);
    }
    break;
  }
}

/**
 *  Obtain the course associated to a resource node
 */
function _classroom_resource_get_course( $resource ) {
  $result = db_query("SELECT node.* FROM {node},{classroom_course_resource} WHERE course_nid = nid and resource_nid = %d",
    $resource->nid);
  return db_fetch_object($result);
}
