<?php
// $Id: classroom.users.inc,v 1.5 2010/01/12 13:49:20 osoh Exp $

/**
 * Sign up a student for a course.
 *
 * @param $student
 *   User that's going to be signed up to the course.
 *   It could be an object (with an uid attribute) or an integer which
 *   represents the uid.
 * @param $course
 *   The course to be signed up.
 *   It could be an object (with an nid attibute) or an integer which
 *   represents the nid.
 * @param $access_by_role
 *   A user could be registered in a course because she belongs to a given role.
 *   This param could be the rid of a drupal role (or NULL).
 */
function classroom_register_student($student, $course, $access_by_role = NULL) {
  return _classroom_register_user($student, $course, CLASSROOM_STUDENT, $access_by_role);
}

/**
 * Sign up a teacher for a course.
 *
 * @param $teacher
 *   User that's going to be signed up to the course.
 *   It could be an object (with an uid attribute) or an integer which
 *   represents the uid.
 * @param $course
 *   The course to be signed up.
 *   It could be an object (with an nid attibute) or an integer which
 *   represents the nid.
 */
function classroom_register_teacher($teacher, $course) {
  return _classroom_register_user($teacher, $course, CLASSROOM_TEACHER);
}

/**
 * Sign up a manager for a course.
 *
 * @param $manager
 *   User that's going to be signed up to the course.
 *   It could be an object (with an uid attribute) or an integer which
 *   represents the uid.
 * @param $course
 *   The course to be signed up.
 *   It could be an object (with an nid attibute) or an integer which
 *   represents the nid.
 */
function classroom_register_manager($manager, $course) {

  if (is_object($course)) {
    $course_nid = (int) $course->nid;
  } else {
    $course_nid = (int) $course;
  }

  if (is_object($manager)) {
    $uid = (int) $manager->uid;
  } else {
    $uid = (int) $manager;
  }

  if (!($uid AND $course_nid)) return FALSE;

  // FIXME: This implementation sucks.
  if (!classroom_is_student($user, $course)) {
    db_query("INSERT INTO {classroom_registration} (uid, course_nid, role, date, active) VALUES (%d, %d, %d, %d, %d)",
      $uid, $course_nid, CLASSROOM_MANAGER, time(), TRUE);
    return TRUE;
  } else {
    return FALSE;
  }
  return _classroom_register_user($manager, $course, CLASSROOM_MANAGER);
}

/**
 * Sign up a user for a course.
 *
 * @param $user
 *   User that's going to be signed up to the course.
 *   It could be an object (with an uid attribute) or an integer which
 *   represents the uid.
 * @param $course
 *   The course to be signed up.
 *   It could be an object (with an nid attibute) or an integer which
 *   represents the nid.
 * @param $role
 *   Classroom role (CLASSROOM_STUDENT, CLASSROOM_TEACHER or CLASSROOM_MANAGER).
 *   Otherwise, it must be FALSE.
 * @param $access_by_role
 *   A user could be registered in a course because she belongs to a given role.
 *   This param could be the rid of a drupal role (or NULL).
 * @return
 *   True if the user was signed up in the course.
 */
function _classroom_register_user($user, $course, $role = CLASSROOM_STUDENT, $access_by_role = NULL) {

  if (is_object($course)) {
    $course_nid = (int) $course->nid;
  } else {
    $course_nid = (int) $course;
  }

  if (is_object($user)) {
    $uid = (int) $user->uid;
  } else {
    $uid = (int) $user;
  }

  if (!($uid AND $course_nid)) return FALSE;

  if (!(classroom_is_teacher($user, $course) or classroom_is_student($user, $course))) {
    $data = array(
      'uid' => $uid,
      'course_nid' => $course_nid,
      'role' => (int) $role,
      'date' => time(),
      'active' => TRUE,
      'access_by_rid' => $access_by_role,
    );
    return drupal_write_record("classroom_registration", $data);
  } else {
    return FALSE;
  }
}

/**
 * Determines whether a user is student of a given course.
 *
 * @param $user
 *   User to check.
 * @param $course
 *   Course to check against.
 * @return
 *   Returns true if the user is student of a course. Returns false otherwise.
 */
function classroom_is_student($user, $course) {
  return _classroom_is_role($user, $course, CLASSROOM_STUDENT);
}

/**
 * Determines whether a user is teacher of a given course.
 *
 * @param $user
 *   User to check.
 * @param $course
 *   Course to check against.
 * @return
 *   Returns true if the user is teacher of a course. Returns false otherwise.
 */
function classroom_is_teacher($user, $course) {
  return _classroom_is_role($user, $course, CLASSROOM_TEACHER);
}

/**
 * Determines whether a user is manager of a given course.
 *
 * @param $user
 *   User to check.
 * @param $course
 *   Course to check against.
 * @return
 *   Returns true if the user is manager of a course. Returns false otherwise.
 */
function classroom_is_manager($user, $course) {
  return _classroom_is_role($user, $course, CLASSROOM_MANAGER);
}

/**
 * Determines whether a user is teacher or student of a given course.
 *
 * @param $user
 *   User to check.
 * @param $course
 *   Course to check against.
 * @return
 *   Returns true if the user is teacher or student of a course. Returns
 *   false otherwise.
 */
function classroom_is_user_registered($user, $course) {
  return _classroom_is_role($user, $course, NULL);
}

/**
 * Determines whether a user is teacher or student for a given course.
 *
 * @param $user
 *   User to check.
 * @param $course
 *   Course to check against.
 * @param $teacher
 *   0: check if the user is student; 1: check if the user is teacher;
 *   NULL: doesn't matter if it's student or teacher.
 * @return
 *   Returns true if the user is teacher or student of a course. Returns false
     otherwise.
 */
function _classroom_is_role($user, $course, $role = NULL) {
  $uid = null;

  if (is_object($user) == true) { 
    $uid = $user->uid;
  }  else {
    $uid = $user;  
  }

  $qry = "SELECT COUNT(*) AS e FROM {classroom_registration} WHERE uid = %d and course_nid = %d";
  $conds = array($uid, $course->nid);
  if ($role !== NULL) {
    $qry .= " AND role = %d";
    $conds[] = $role;
  }
  $result = db_query($qry, $conds);
  $exists = db_fetch_array($result);
  return $exists['e'] > 0;
}

/**
 * Determines whether a user is active as teacher for a given course.
 *
 * @param $user
 *   User to check.
 * @param $course
 *   Course to check against.
 * @return
 *   Returns true if the user is active as teacher for the course $course.
 *   Returns false otherwise.
 */
function classroom_is_active_as_teacher($user, $course) {
  return classroom_is_user_active($user, $course, CLASSROOM_TEACHER);
}

/**
 * Determines whether a user is active as teacher for a given course.
 *
 * @param $user
 *   User to check.
 * @param $course
 *   Course to check against.
 * @return
 *   Returns true if the user is active as teacher for the course $course.
 *   Returns false otherwise.
 */
function classroom_is_active_as_student($user, $course) {
  return classroom_is_user_active($user, $course, CLASSROOM_STUDENT);
}

/**
 * Determines whether a user is active as manager for a given course.
 *
 * @param $user
 *   User to check.
 * @param $course
 *   Course to check against.
 * @return
 *   Returns true if the user is active as teacher for the course $course.
 *   Returns false otherwise.
 */
function classroom_is_active_as_manager($user, $course) {
  return classroom_is_user_active($user, $course, CLASSROOM_MANAGER);
}

/**
 * Determines whether a user is teacher or student for a given course.
 *
 * @param $user
 *   User to check.
 * @param $course
 *   Course to check against.
 * @param $teacher
 *   0: check if the user is student; 1: check if the user is teacher;
 *   NULL: doesn't matter if it's student or teacher.
 * @return
 *   Returns true if the user is teacher or student of a course. Returns false
     otherwise.
 */
function classroom_is_user_active($user, $course, $teacher = NULL) {
  $uid = null;

  if (is_object($user) == true) {
    $uid = $user->uid;
  }  else {
    $uid = $user;
  }

  $qry = "SELECT COUNT(*) AS e FROM {classroom_registration} WHERE uid = %d and course_nid = %d and active = %d";
  $conds = array($uid, $course->nid, 1);
  if ($teacher !== NULL) {
    $qry .= " AND role = %d";
    $conds[] = $teacher;
  }
  $result = db_query($qry, $conds);
  $exists = db_fetch_array($result);
  return $exists['e'] > 0;
}

/**
 * Sign off a student of a course.
 *
 * @param $student
 *   User that's going to be signed off of the course.
 *   It must be an object with an uid attribute.
 * @param $course
 *   The course to be signed off.
 */
function classroom_signoff_student($student, $course) {
  return _classroom_signoff_user($student, $course, CLASSROOM_STUDENT);
}

/**
 * Sign off a teacher for a course.
 *
 * @param $teacher
 *   User that's going to be signed off of the course.
 *   It must be an object with an uid attribute.
 * @param $course
 *   The course to be signed off.
 */
function classroom_signoff_teacher($teacher, $course) {
  return _classroom_signoff_user($teacher, $course, CLASSROOM_TEACHER);
}

/**
 * Sign off a teacher for a course.
 *
 * @param $manager
 *   User that's going to be signed off of the course.
 *   It must be an object with an uid attribute.
 * @param $course
 *   The course to be signed off.
 */
function classroom_signoff_manager($manager, $course) {
  return _classroom_signoff_user($manager, $course, CLASSROOM_MANAGER);
}

/**
 * Sign off a user for a course.
 *
 * @param $user
 *   User that's going to be signed off of the course.
 *   It must be an object with an uid attribute.
 * @param $course
 *   The course to be signed up.
 * @return
 *   True if the user was signed off of the course.
 */
function _classroom_signoff_user($user, $course, $role) {
  if (_classroom_is_role($user, $course, $role)) {
    db_query("DELETE FROM {classroom_registration} WHERE uid = %d AND course_nid = %d and role = %d", $user->uid, $course->nid, $role);
    return (db_error == 0);
  } else {
    return FALSE;
  }
}

/**
 * Suspend the registration for a user in a course.
 *
 * @param $user
 *   It could be an object (with an uid attribute) or an integer which
 *   represents the uid.
 * @param $course
 *   It could be an object (with an nid attibute) or an integer which
 *   represents the nid.
 */
function classroom_suspend_registration($user, $course) {
  return _classroom_set_registration_status($user, $course, FALSE);
}

/**
 * Activate the registration for a user in a course.
 *
 * @param $user
 *   It could be an object (with an uid attribute) or an integer which
 *   represents the uid.
 * @param $course
 *   It could be an object (with an nid attibute) or an integer which
 *   represents the nid.
 */
function classroom_activate_registration($user, $course) {
  return _classroom_set_registration_status($user, $course, TRUE);
}

/**
 * Set the registration status ('active' or 'suspended') for a user and a course.
 *
 * @param $user
 *   It could be an object (with an uid attribute) or an integer which
 *   represents the uid.
 * @param $course
 *   It could be an object (with an nid attibute) or an integer which
 *   represents the nid.
 * @param $status
 *   TRUE (active) or FALSE (suspended).
 */
function _classroom_set_registration_status($user, $course, $status) {
  if (is_object($course)) {
    $course_nid = (int) $course->nid;
  } else {
    $course_nid = (int) $course;
  }

  if (is_object($user)) {
    $uid = (int) $user->uid;
  } else {
    $uid = (int) $user;
  }

  if (!($uid AND $course_nid)) return FALSE;
  if (classroom_is_user_registered($user, $course)) {
    $qry = "UPDATE {classroom_registration} SET active = %d WHERE uid = %d AND course_nid = %d";
    db_query($qry, (int) $status, $uid, $course_nid);
  } // FIXME: returns some value to check if operation succeeds or fails.
}

/**
 * Retrieve registration data for a user.
 *
 * @param $user
 *   User to retrieve the data.
 */
function classroom_get_registrations_for_user($user) {
  $qry = "SELECT * FROM {classroom_registration} WHERE uid = %d";
  $result = db_query($qry, $user->uid);
  $regs = array();
  while ($reg = db_fetch_object($result)) {
    $regs[] = $reg;
  }
  return $regs;
}

/**
 * Retrieve registration data for users that are registered in a course.
 *
 * @param $course
 *   Course to retrieve the data.
 */
function classroom_get_registrations_for_course($course) {
  $qry = "SELECT * FROM {classroom_registration} WHERE course_nid = %d";
  $result = db_query($qry, $course->nid);
  $regs = array();
  while ($reg = db_fetch_object($result)) {
    $regs[] = $reg;
  }
  return $regs;
}

/**
 * Get the courses where a user is registered (as student or teacher).
 *
 * @param $user
 *   The object that represents the user or an integer with the uid
 * @return
 *   An array containing all the courses in which the user is registered.
 */
function classroom_get_courses_for_user($user) {
  if (is_object($user)) {
    $uid = (int) $user->uid;
  } else {
    $uid = (int) $user;
  }

  // FIXME: refactor
  $types = array();
  foreach (_classroom_get_types_for('course') as $name => $type) {
    $types[] = $name;
  }
  $types_sql = "'" . implode("','", $types) . "'";
  $qry = "SELECT DISTINCT(nid) FROM {classroom_registration} AS r LEFT JOIN {node} AS n ON (course_nid = nid) WHERE r.uid = %d AND n.type in ($types_sql)";
  $result = db_query($qry, $uid);
  $courses = array();
  while ($row = db_fetch_array($result)) {
    $courses[] = node_load(array('nid' => $row['nid']));
  }
  return $courses;
}

/**
 * Get the date that a user is registered into a course
 *
 * @param $user
 *  The object that represents the user or an integer with the uid
 * @param $course
 *  The object that represents the course or an integer with the nid
 *  
 *  Return the user registration date or false if the user is inactive
 */
function classroom_get_registration_date($user, $course) {
  if (is_object($course)) {
    $course_nid = (int) $course->nid;
  } else {
    $course_nid = (int) $course;
    $course = node_load($course_nid);
  }

  if (is_object($user)) {
    $uid = (int) $user->uid;
  } else {
    $uid = (int) $user;
  }
  
  if (!($uid AND $course_nid)) return FALSE;

  if (! classroom_is_user_registered($user, $course)) return FALSE;

  $qry = "SELECT * from {classroom_registration} where uid = %d and course_nid = %d";
  $result = db_fetch_array(db_query($qry, (int) $uid, (int) $course_nid));
  if ($result["active"])
    return _classroom_timestamp_to_form_date($result["date"]);
  else
    return FALSE; 
}

