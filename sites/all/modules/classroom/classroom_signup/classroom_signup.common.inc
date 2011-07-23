<?php
// $Id: classroom_signup.common.inc,v 1.2 2010/01/13 09:54:15 osoh Exp $

/**
 * Creates an empty request.
 * Only 'created' attribute have a value. You can think of this function
 * as a constructor.
 *
 * @return
 *   An stdClass instance which represents the new request.
 */
function classroom_signup_new_request()
{
  $data = array(
    'uid' => NULL,
    'rid' => NULL,
    'created' => time(),
    'course_nid' => NULL,
    'status' => CLASSROOM_SIGNUP_STATUS_PENDING,
    'request_comment' => NULL,
    'response_comment' => NULL,
  );
  return ((object) $data);
}

/**
 * Creates a sign-up request for a course and a user.
 * TODO: check that user and course exist. Check also that course type
 * is a 'classroom course type'.
 *
 * @param $user
 *   User who is filling up the request. It must be an object (with a 'uid').
 * @param $course
 *   Course. It must be a node (with a 'uid').
 */
function classroom_signup_request($user, $course) {
  if (!classroom_signup_get_request($user, $course)) {
    $request = classroom_signup_new_request();
    $request->uid = $user->uid;
    $request->course_nid = $course->nid;
    classroom_signup_save_request($request);
    return classroom_signup_get_request($user, $course);
  } else {
    return FALSE;
  }
}

/**
 * Gets an existing user's sign-up request for a course.
 * TODO: check that user and course exist. Check also that course type
 * is a 'classroom course type'.
 *
 * @param $user
 *   User who is filling up the request. It must be an object (with a 'uid').
 * @param $course
 *   Course. It must be a node (with a 'uid').
 * @return
 *   An object which represents the sign-up request. FALSE if no request
 *   is found for this user and course.
 */
function classroom_signup_get_request($user, $course) {
  $qry = "SELECT * FROM {classroom_signup_request} WHERE uid = %d AND course_nid = %d";
  $result = db_query($qry, $user->uid, $course->nid);
  return db_fetch_object($result);
}

/**
 * Gets an existing sign-up request using the request ID.
 *
 * @param $rid
 *   Sign-up request ID.
 * @return
 *   An object which represents the sign-up request. FALSE if no request
 *   is found with this ID ($rid).
 */
function classroom_signup_get_request_by_rid($rid) {
  $qry = "SELECT * FROM {classroom_signup_request} WHERE rid = %d";
  $result = db_query($qry, $rid);
  return db_fetch_object($result);
}

/**
 * Accepts a sign up request.
 * It marks the request as 'accepted' and sign up the user to the course.
 *
 * @param $request
 *   Request to be accepted. This parameter is passed by reference.
 */
function classroom_signup_accept_request(&$request) {
  $request->status = CLASSROOM_SIGNUP_STATUS_ACCEPTED;
  classroom_register_student($request->uid, $request->course_nid);
  classroom_signup_save_request($request);
}

/**
 * Rejects a sign up request.
 * It marks the request as 'rejected'.
 *
 * @param $request
 *   Request to be rejected. This parameter is passed by reference.
 */
function classroom_signup_reject_request(&$request) {
  $request->status = CLASSROOM_SIGNUP_STATUS_REJECTED;
  classroom_signup_save_request($request);
}

/**
 * Writes a request in the database. If the request exists in the database,
 * just update its data.
 *
 * TODO: return FALSE in case of failure!
 *
 * @param $request
 *   Request to be saved.
 */
function classroom_signup_save_request(&$request) {
  if (classroom_signup_get_request_by_rid($request->rid)) {
    $qry = "UPDATE {classroom_signup_request} "
      ."SET status = %d, request_comment = '%s', response_comment = '%s' "
      ."WHERE rid = %d";
    db_query($qry, $request->status, $request->request_comment,
      $request->response_comment, $request->rid);
  } else {
    $qry = "INSERT INTO {classroom_signup_request} (created, uid, course_nid, status, request_comment, response_comment) VALUES (%d, %d, %d, %d, '%s', '%s')";
    db_query($qry, $request->created, $request->uid, $request->course_nid, $request->status, $request->request_comment, $request->response_comment);
    $request->rid = db_last_insert_id('classroom_signup_request', 'rid');
  }
}

/**
 * Translates a request status, which is a numeric code, into a meaningful
 * string.
 *
 * @param $status
 *   Status code to translate.
 * @return
 *   Code translation (string).
 */
function _classroom_signup_status_label($status) {
  switch ($status) {
  case CLASSROOM_SIGNUP_STATUS_ACCEPTED:
    return t("accepted");
  case CLASSROOM_SIGNUP_STATUS_REJECTED:
    return t("rejected");
  case CLASSROOM_SIGNUP_STATUS_PENDING:
    return t("pending");
  }
}
