<?php
// $Id: classroom_signup.mail.inc,v 1.1 2010/01/28 13:06:25 osoh Exp $

/**
 * Implementation of hook_mail().
 */
function classroom_signup_mail($key, &$message, $params) {
  $course = node_load($params['request']->course_nid);

  switch ($key) {
  case 'request':
    $user = user_load($params['request']->uid);
    $message['subject'] = t("Sign-up request for !course",
      array('!course' => $course->title));
    $message['body'] = t("!username wants to sign up in the course '!course'. You can answer the request by visiting !answer_url.",
      array(
        "!username" => $user->name,
        "!course" => $course->title,
        "!answer_url" => url("classroom/course/{$course->nid}/request/{$params["request"]->rid}/answer", array('absolute' => TRUE)),
      )
    );
    break;

  case 'sign-up notification':
    $message['subject'] = t("Sign-up request for '!course' accepted",
      array('!course' => $course->title));
    $message['body'] = t("Your request to sign up to the course '!course' has been accepted. You can access to the course visiting this link: !course_url.\n!comment",
      array(
        "!course" => $course->title,
        "!course_url" => url("classroom/course/{$course->nid}", array('absolute' => TRUE)),
        "!comment" => $params["request"]->response_comment,
      )
    );
    break;

  case 'reject notification':
    $message['subject'] = t("Sign-up request for '!course' rejected",
      array('!course' => $course->title));
    $message['body'] = t("Your request to sign up to the course '!course' has been rejected.\n!comment",
      array(
        "!course" => $course->title,
        "!answer_url" => url("classroom/course/{$course->nid}/request/{$params["request"]->rid}/answer", array('absolute' => TRUE)),
        "!comment" => $params["request"]->response_comment,
      )
    );
    break;
  }
}
