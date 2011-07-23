<?php
// $Id: classroom_signup.pages.inc,v 1.7 2010/01/13 09:54:15 osoh Exp $

/**
 * Returns a list of sign up requests for a course.
 * TODO: refactor query into a function classroom_get_courses.
 * TODO: allow filtering by date capabilities.
 * @param $course_nid
 *   Course ID.
 */
function classroom_signup_requests_page($course_nid, $status = NULL) {
  $statuses_map = array(
    'pending' => CLASSROOM_SIGNUP_STATUS_PENDING,
    'rejected' => CLASSROOM_SIGNUP_STATUS_REJECTED,
    'accepted' => CLASSROOM_SIGNUP_STATUS_ACCEPTED,
  );
  if ($status) {
    $request_status = $statuses_map[$status];
  }

  $headers = array(
    'name' => array('data' => t('Name'), 'field' => 'name'),
    'datetime' => array('data' => t('Date/Time'), 'field' => 'created'),
    'actions' => array('data' => t('Actions')),
  );

  // FIXME: it must call a function to retrieve data.
  $qry = "SELECT name, rid, course_nid, {classroom_signup_request}.created, {classroom_signup_request}.status status FROM {classroom_signup_request} LEFT JOIN {users} USING (uid) WHERE course_nid = %d";
  $conds = array($course_nid);

  if ($status) {
    $qry .= " AND {classroom_signup_request}.status = %d";
    array_push($conds, $request_status);
  }

  $pager_limit = variable_get('classroom_pager_limit', CLASSROOM_PAGER_LIMIT_DEFAULT);
  $result = pager_query($qry, $pager_limit, 0, NULL, $conds);

  $rows = array();
  while ($request = db_fetch_object($result)) {
    $row = array();
    $row['user'] = l($request->name, "node/$course_nid");
    $row['created'] = format_date($request->created, 'small');
    if ($request->status == CLASSROOM_SIGNUP_STATUS_PENDING) {
      $row['status'] = _classroom_signup_process_link($request);
    } else {
      $row['status'] = _classroom_signup_view_link($request);
    }
    $rows[] = $row;
  }

  if (empty($rows)) {
    $output = "<p>" . t("There are no requests for this course.") . "</p>";
  } else {
    $output = theme('table', $headers, $rows);
    $output .= theme('pager');
  }

  return $output;
}

/**
 * Form to sign up in a course.
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $course_nid
 *   Course ID.
 */
function classroom_signup_request_form($form, $course_nid)
{
  global $user;
  $course = node_load(array('nid' => $course_nid));

  $form = array();

  $form['message'] = array(
    '#type' => 'markup',
    '#value' => "<p>" . t('Course %title', array('%title' => $course->title)) . "</p>",
  );

  $form['request_comment'] = array(
    '#type' => 'textarea',
    '#title' => 'Comment (if any)',
    '#value' => '',
    '#description' => t('Comment for the requester to read (if any).'),
    '#rows' => 3,
  );

  $form['course_nid'] = array(
    '#type' => 'hidden',
    '#value' => $course_nid,
  );

  $form['#redirect'] = array("classroom/course");

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Form to sign up in a course. (hook_form_submit() implementation).
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $form_state
 *   Form state (Drupal style).
 */
function classroom_signup_request_form_submit($form, $form_state)
{
  global $user;

  $course_nid = $form['#post']['course_nid'];
  $course = node_load($course_nid);
  $request = classroom_signup_new_request();
  $request->uid = $user->uid;
  $request->course_nid = $course_nid;
  $request->request_comment = check_plain($form['#post']['request_comment']);
  classroom_signup_save_request($request);
  drupal_set_message(
    t("Your request has been sent. It will be processed as soon as possible."),
    'status'
  );

  // Notify managers
  foreach (classroom_get_managers_for($course) as $manager) {
    drupal_mail('classroom_signup', 'request', $manager->mail,
      user_preferred_language($manager), array('request' => $request));
  }
}

/**
 * Form to answer a sign up request.
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $rid
 *   Request ID.
 */
function classroom_signup_answer_form($form, $rid) {
  $request = classroom_signup_get_request_by_rid($rid);
  $user = user_load(array('uid' => $request->uid));

  $form = array();

  $form['rid'] = array(
    '#type' => 'hidden',
    '#value' => $rid
  );

  $form['request'] = array(
    '#type' => 'fieldset',
    '#title' => t('Request data'),
    '#collapsible' => TRUE,
  );

  $data_list = array(
    t('User: %username', array('%username' => $user->name)),
    t('Sent on %date', array('%date' => _classroom_format_date($request->created))),
  );

  if ($request->request_comment) {
    $data_list[] = "Comment:<br>" . $request->request_comment;
  }

  $form['request']['data'] = array(
    '#type' => 'markup',
    '#value' => theme('item_list', $data_list),
  );

  $form['response_comment'] = array(
    '#type' => 'textarea',
    '#value' => $request->response_comment,
    '#description' => t('Comment for the requester to read (if any).'),
    '#rows' => 3,
  );

  $form['accept'] = array(
    '#type' => 'submit',
    '#value' => t('Accept'),
  );

  $form['deny'] = array(
    '#type' => 'submit',
    '#value' => t('Reject'),
  );

  $form['#redirect'] = array("classroom/course/{$request->course_nid}/students/pending");

  return $form;
}

/**
 * Form to answer a sign up request. (hook_form_submit() implementation).
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $form_state
 *   Form state (Drupal style).
 */
function classroom_signup_answer_form_submit($form, $form_state) {
  $request = classroom_signup_get_request_by_rid($form['#post']['rid']);
  $request->response_comment = check_plain($form['#post']['response_comment']);
  switch ($form['#post']['op']) {
  case t('Accept'):
    classroom_signup_accept_request($request);
    $mail_message = 'sign-up notification';
    break;
  case t('Reject'):
    classroom_signup_reject_request($request);
    $mail_message = 'reject notification';
    break;
  }
  $user = user_load($request->uid);
  if (drupal_mail('classroom_signup', $mail_message, $user->mail,
    user_preferred_language($user), array('request' => $request))) {
    drupal_set_message(
      t("A notification e-mail has been sent to the user."),
      'status'
    );
  }
}

/**
 * Builds a page containing a sign-up request information.
 *
 * @param $rid
 *   Request ID.
 */
function classroom_signup_request_page($rid) {
  $request = classroom_signup_get_request_by_rid($rid);
  $course = node_load(array('nid' => $request->course_nid));
  $user = user_load(array('uid' => $request->uid));

  $breadcrumb = classroom_build_breadcrumb($course, TRUE);
  array_push($breadcrumb,
    l(t("Students"), "classroom/course/{$request->course_nid}/students")
  );
  drupal_set_breadcrumb($breadcrumb);

  $data_list = array(
    t('Course: %course', array('%course' => $course->title)),
    t('User: %username', array('%username' => $user->name)),
    t('Status: %status', array('%status' => _classroom_signup_status_label($request->status))),
    t('Sent on %date', array('%date' => _classroom_format_date($request->created))),
  );

  if ($request->request_comment) {
    $data_list[] = t("Comment:") . "<br>" . $request->request_comment;
  }

  if ($request->response_comment) {
    $data_list[] = t("Response:") . "<br>" . $request->response_comment;
  }

  return theme('item_list', $data_list);
}

/**
 * Builds a link to the view of a sign-up request.
 */
function _classroom_signup_view_link($request, $label = 'view') {
  return l($label,
    "classroom/course/{$request->course_nid}/students/request/{$request->rid}/view");
}

/**
 * Builds a link to the process form of a sign-up request.
 */
function _classroom_signup_process_link($request, $label = 'process') {
  return l($label,
    "classroom/course/{$request->course_nid}/request/{$request->rid}/answer");
}
