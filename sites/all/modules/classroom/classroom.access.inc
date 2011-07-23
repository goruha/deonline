<?php
// $Id: classroom.access.inc,v 1.11 2010/01/07 10:27:54 osoh Exp $

/**
 * Determines if the node can be accessed.
 *
 * @param $nid
 *   Item nid. 
 * @param $roles
 *   Classroom roles. Classroom roles which are allowed to access to the node.
 *   This parameter could be a single role or even an array containing some roles.
 *   Each role could be an integer or a string (which represents an integer) where
 *   '0' = student, '1' = teacher and '2' = role.
 *   If it's NULL, no role checking is performed.
 * @param $type
 *   Type to check against the node.
 */
function classroom_check_access($nid, $roles = NULL, $type = NULL) {
  global $user;

  // Normalize the '$roles' parameter.
  if ($roles !== NULL) {
    $roles_to_normalize = (is_array($roles)) ? $roles : array($roles);
    foreach ($roles_to_normalize as $role) {
      $roles_to_check[] = (int) $role;
    }
  } else {
    $roles_to_check = NULL;
  }

  $node = node_load(array('nid' => $nid));
  if ($node === NULL) {
    return FALSE;
  }

  if (($type !== NULL) && (_classroom_is_type($node->type, $type) == false)) {
    return FALSE;
  }
 
  $course = classroom_get_course_for($node);

  if (user_access('administer classroom')) {
    return TRUE;
  }

  if ($roles_to_check === NULL) { // No role check is needed.
    return classroom_is_user_active($user, $course);
  }

  foreach ($roles_to_check as $role) { // Check the user's role.
    if (classroom_is_user_active($user, $course, (int) $role)) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Get students' permissions.
 *
 * @return
 *   Returns an array containing the added permissions if they were added.
 *   It returns false in case of error.
 */
function classroom_perms() {
  // Student's perms
  $student_perms = array('access classroom');
  $response_types = _classroom_get_types_for('response');
  foreach ($response_types as $type) {
    array_push($student_perms, "create $type->type content");
    array_push($student_perms, "edit own $type->type content");
    array_push($student_perms, "delete own $type->type content");
  }

  // Teachers' perms
  $teacher_perms = array('access classroom');
  $assignment_types = _classroom_get_types_for('assignment');
  foreach ($assignment_types as $type) {
    array_push($teacher_perms, "create $type->type content");
    array_push($teacher_perms, "edit own $type->type content");
    array_push($teacher_perms, "delete own $type->type content");
    array_push($teacher_perms, "edit any $type->type content");
    array_push($teacher_perms, "delete any $type->type content");
  }

  $response_types = _classroom_get_types_for('response');
  foreach ($response_types as $type) {
    array_push($teacher_perms, "edit any $type->type content");
  }

  return array('student' => $student_perms, 'teacher' => $teacher_perms);
}

/**
 * Add permissions to a role.
 *
 * @param $rid
 *   Role ID.
 * @param $perms
 *   Permissions to add.
 * @return
 *   Returns an array containing the added permissions if they were added.
 *   It returns false in case of error.
 */
function classroom_add_perms($rid, $perms = array()) {
  $result = db_query("SELECT * FROM {permission} WHERE rid = %d", $rid);
  $old_perms_obj = db_fetch_object($result);

  if (!$result) {
    return FALSE;
  }

  // Sanitize $perms array.
  // TODO: it must check that permissions are valid.
  $perms = array_unique($perms);

  if ($old_perms_obj) {
    $old_perms = explode(', ', $old_perms_obj->perm);
    $added_perms = array_diff($perms, $old_perms);
    $new_perms = array_merge($old_perms, $added_perms);
    $new_perms_string = implode(', ', $new_perms);
    $result = db_query("UPDATE {permission} SET rid = %d, perm = '%s' WHERE pid = %d", $rid, $new_perms_string, (int) $old_perms_obj->pid);
  } else {
    $result = db_query("INSERT INTO {permission} (rid, perm) VALUES (%d, '%s')",
      $rid, implode(', ', $perms));
    $added_perms = $perms;
  }
  return $added_perms;
}

/**
 * Remove permissions to a role.
 *
 * @param $rid
 *   Role ID.
 * @param $perms
 *   Permissions to remove.
 * @return
 *   Returns an array containing the removed permissions if they were removed.
 *   It returns false in case of error.
 */
function classroom_remove_perms($rid, $perms = array()) {
  $result = db_query("SELECT * FROM {permission} WHERE rid = %d", $rid);
  $old_perms_obj = db_fetch_object($result);

  if (!$result) {
    return FALSE;
  }

  // Sanitize $perms array.
  // TODO: it must check that permissions are valid.
  $perms = array_unique($perms);

  if ($old_perms_obj) {
    $old_perms = explode(', ', $old_perms_obj->perm);
    $removed_perms = array_intersect($perms, $old_perms);
    $new_perms = array_diff($old_perms, $removed_perms);
    $new_perms_string = implode(', ', $new_perms);
    $result = db_query("UPDATE {permission} SET rid = %d, perm = '%s' WHERE pid = %d", $rid, $new_perms_string, (int) $old_perms_obj->pid);
  } else {
    $removed_perms = array();
  }
  return $removed_perms;
}


/**
 * Update access by rid for a given user.
 *
 * Unregister the user from the courses in which she was registered because of
 * the 'access_by_rid' role. Also the user is registered to all courses in
 * which 'access_by_rid' is one of her roles.
 *
 * @param $user
 *   User.
 */
function _classroom_update_user_access_by_rid($user) {
  $regs = classroom_get_registrations_for_user($user);
  $user_rol_ids =  array_keys($user->roles);

  // Sign-off from courses in which she was registered because of 'access_by_rid'
  // and doesn't apply anymore.
  foreach ($regs as $reg) {
    $rid = (int) $reg->access_by_rid;
    if ($reg->access_by_rid and !in_array($rid, $user_rol_ids)) {
      $course = node_load(array('nid' => $reg->course_nid));
      classroom_signoff_student($user, $course);
    }
  }

  // Sign-on in courses by 'access_by_rid'
  $courses = classroom_get_open_courses();
  foreach ($courses as $course) {
    $course_rid = (int) $course->classroom_course["access_by_rid"];
    if ($course_rid and in_array($course_rid, $user_rol_ids)) {
      classroom_register_student($user, $course, $course_rid);
    }
  }
}

/**
 * Implementation of hook_user().
 */
function classroom_user($op, &$edit, &$account, $category = NULL) {
  switch ($op) {
    case "after_update":
      _classroom_update_user_access_by_rid($account);
      break;
  }
}

/**
 * Update access by rid for a given course.
 *
 * Given an 'access_by_rid' role for the course:
 * * If a user was registered by rid and now the user doesn't belong to the
 *   'access_by_rid' role, the user is unregistered.
 * * Users that belongs to the 'access_by_rid' role are registered.
 *
 * @param $course
 *   Course.
 */
function _classroom_update_course_access_by_rid($course) {
  $regs = classroom_get_registrations_for_course($course);
  $rid = (int) $course->classroom_course["access_by_rid"];

  // Unregister users that were signed up by RID (and the RID is not the
  // current access_by_rid).
  foreach ($regs as $reg) {
    if (!$reg->access_by_rid) { continue; }
    $user = user_load($reg->uid);
    $user_rol_ids = array_keys($user->roles);
    if (!in_array($rid, $user_rol_ids)) {
      classroom_signoff_student($user, $course);
    }
  }

  if ($rid) { // Register users that belongs to $rid role (if any).
    $result = db_query("SELECT uid FROM {users_roles} WHERE rid = %d", $rid);
    while ($row = db_fetch_array($result)) {
      classroom_register_student($row["uid"], $course, $rid);
    }
  }
}
