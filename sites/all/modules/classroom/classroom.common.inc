<?php
// $Id: classroom.common.inc,v 1.5 2009/09/22 18:37:45 osoh Exp

/**
 * Returns an associative array containing node type ids and names.
 * It's used in the settings form.
 * TODO: rename and move to classroom.admin.inc.
 *
 * @return
 *   An associative array using ids as keys and names as values.
 *   Example: array('story' => 'Story', 'my_type' => 'My cool type').
 */
function _classroom_get_node_types() {
  $types = array();
  foreach (node_get_types('types') as $id => $type) {
    $types[$id] = $type->name;
  }
  return $types;
}

/**
 * Returns which types can be of a given classroom type ($search_type).
 *
 * @param $search_type
 *   Classroom type
 * 
 * @return
 *   Associative array containing all node types that can be use as $search_type.
 *   The key is the type id and the value the whole type object.
 */
function _classroom_get_types_for($search_type = 'course') {
  $all_types = node_get_types('types');
  $enabled_types = variable_get("classroom_{$search_type}_types", array());

  if (is_array($enabled_types) == false) {
    $type = $enabled_types;
    $enabled_types = array (
      $type => $type );
  }

  $types = array();
  foreach ($all_types as $type) {
    if ($enabled_types[$type->type] && ($enabled_types[$type->type] !== 0)) {
      $types[$type->type] = $type;
    }
  }
  return $types;
}

/**
 * Tells if a node type can be use as a classroom type.
 *
 * @param $value
 *   Node type
 * @param $type
 *   Classroom type
 * @return
 *   True if $value can be use as $type. Otherwise, returns false.
 *   Example: _classroom_is_type('story', 'course') is tru if 'story' could be
 *   a course.
 */
function _classroom_is_type($value, $type) {
  $types = _classroom_get_types_for($type);
  return isset($types[$value]);
}

/** 
 * Convert a timestamp into array form
 *
 * @param $timestamp
 *   Timestamp to convert
 * @return 
 *   NULL if the timestamp is null or an array containing
 *   fields 'day', 'month' and 'year' otherwise.
 */
function _classroom_timestamp_to_form_date($timestamp) {
  if ($timestamp == NULL) {
    return NULL;
  }
  else {
    $timestamp -= _classroom_get_user_timezone();
    $date = explode('/', gmdate('d/m/Y', $timestamp));
    return  array(
      'day' => (int) $date[0],
      'month' => (int) $date[1],
      'year' => (int) $date[2],
    );
  }
}

/**
 * Convenience function to format dates.
 *
 * @param $date
 *   Date to be formatted.
 * @param $fmt
 *   Format to be used.
 * @return
 *   The formatted date. It returns '-' if $date is null (instead of returning
 *   something like '1970-01-01').
 */
function _classroom_format_date($date, $fmt = 'small') {
  if (!is_null($date)) {
    return format_date($date, $fmt);
  } else {
    return t('---');
  }
}

/**
 * Determines whether the node can be a course or not.
 *
 * @param $node
 *   Item to be checked.
 * @return
 *   True if the node is a course. Otherwise it returns false.
 */
function classroom_is_course($node) {
  return _classroom_is_type($node->type, 'course');
}

/**
 * Determines whether the node can be an assignment or not.
 *
 * @param $node
 *   Item to be checked.
 * @return
 *   True if the node is a assignment. Otherwise it returns false.
 */
function classroom_is_assignment($node) {
  return _classroom_is_type($node->type, 'assignment');
}

/**
 * Determines whether the node can be a response or not.
 *
 * @param $node
 *   Item to be checked.
 * @return
 *   True if the node is a response. Otherwise it returns false.
 */
function classroom_is_response($node) {
  return _classroom_is_type($node->type, 'response');
}

/**
 * Determines whether the node can be a resource or not.
 *
 * @param $node
 *   Item to be checked.
 * @return
 *   True if the node is a response. Otherwise it returns false.
 */
function classroom_is_resource($node) {
  return _classroom_is_type($node->type, 'resource');
}

/**
 * Function that retrieve the course related with a given node.
 *
 * @param $node
 *   It must be a course (return itself), an assignment or a response.
 * @return
 *   The course which is related to the node $node.
 */
function classroom_get_course_for($node) {
  if (classroom_is_course($node)) { // It's a course (return the course)
    return $node;

  } else if (classroom_is_response($node)) { // It's an assignment
    $assignment = node_load($node->classroom_response['assignment_nid']);
    return classroom_get_course_for($assignment);

  } else if (classroom_is_assignment($node)) { // Its an assignment
    $nid = $node->classroom_assignment['course_nid'];
    if ($nid) {
      return node_load($nid);
    }
  }

  return NULL;
}

/**
 * Convert an associative array that describes a date into a GMT timestamp.
 *
 * @param $date
 *   The array must contain three keys: 'month', 'day' and 'year'.
 * @return
 *   Timestamp (as GMT) that correspond to the date described by the array.
 */
function _classroom_date_to_timestamp($date) {
  if (!isset($date)) {
    return NULL;
  }

  global $user;
  if (variable_get('configurable_timezones', 1) && $user->uid && strlen($user->timezone)) {
    $timezone = $user->timezone;
  }
  else {
    $timezone = variable_get('date_default_timezone', 0);
  }

  $timestamp = gmmktime(23, 59, 59,
    $date['month'], $date['day'], $date['year']);
  return $timestamp - $timezone;
}

/**
 * Returns the user's timezone.
 *
 * @return
 *   User's timezone according to Drupal settings and user's profile.
 */
function _classroom_get_user_timezone() {
  global $user;

  if (variable_get('configurable_timezones', 1) && $user->uid && strlen($user->timezone)) {
    return $user->timezone;
  }
  else {
    return variable_get('date_default_timezone', 0);
  }
}


/**
 * Builds the breadcrumb specification depending on a node. It's used by
 * classroom_set_breadcrumb(), but it could be useful when building a
 * self made *_set_breadcrumb() function.
 *
 * @param $node
 *   This is the reference node to set the breadcrumb.
 * @param $include_self
 *   If it's TRUE, a link to the node itself is appended at the end of the
 *   breadcrumb.
 * @return
 *   An array containing the links to be included in the breadcrumb.
 */
function classroom_build_breadcrumb($node, $include_self = FALSE) {
  // Base breadcrumb
  $breadcrumb = array(
    l(t("Home"), "<front>"),
    l(t("Courses"), "classroom"),
  );

  if (classroom_is_assignment($node)) { // Assignment
    $course = node_load(array('nid' => $node->classroom_assignment["course_nid"]));
    $breadcrumb = array_merge($breadcrumb,
      array(
        l($course->title, "classroom/course/{$course->nid}"),
        l(t("Assignments"), "classroom/course/{$course->nid}/assignments"),
      )
    );

  } elseif (classroom_is_response($node)) { // Response
    $assignment = node_load(array('nid' => $node->classroom_response["assignment_nid"]));
    $course = node_load(array('nid' => $assignment->classroom_assignment["course_nid"]));
    $breadcrumb = array_merge($breadcrumb,
      array(
        l($course->title, "classroom/course/{$course->nid}"),
        l(t("Assignments"), "classroom/course/{$course->nid}/assignments"),
        l($assignment->title, "node/{$assignment->nid}"),
      )
    );

  } elseif (classroom_is_resource($node)) { // Resource
    $course = node_load(array('nid' => $node->classroom_resource["course_nid"]));
    $breadcrumb = array_merge($breadcrumb,
      array(
        l($course->title, "classroom/course/{$course->nid}"),
        l(t("Resources"), "classroom/course/{$course->nid}/resources"),
      )
    );
  }

  if ($include_self) { // Include a link to the node.
    if (classroom_is_course($node)) {
      array_push($breadcrumb, l($node->title, "classroom/course/{$node->nid}"));
    } else {
      array_push($breadcrumb, l($node->title, "node/{$node->nid}"));
    }
  }

  return $breadcrumb;
}

/**
 * Set breadcrumb depending on the node attributes.
 *
 * @param $node
 *   This is the reference node to set the breadcrumb.
 * @param $include_self
 *   If it's TRUE, a link to the node itself is appended at the end of the
 *   breadcrumb.
 */
function classroom_set_breadcrumb($node, $include_self = FALSE) {
  $breadcrumb = classroom_build_breadcrumb($node, $include_self);
  drupal_set_breadcrumb($breadcrumb);
}

/**
 * Returns the node/add URL for a content type. I think that this
 * function could be in the Drupal's core.
 *
 * @param $type
 *   Content type. It could be an object representing a content type
 *   (with an attribute 'type') or the content type's name.
 * @return
 *   The URL for creating a $type node.
 */
function classroom_node_add_url($type) {
  if (is_object($type)) {
    $type_name = $type->type;
  } else {
    $type_name = $type;
  }
  $type_url = str_replace("_", "-", $type_name);
  return "node/add/$type_url";
}
