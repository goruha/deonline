<?php

/**
 * @file
 * Pages associated with quiz prerequisites
 */

function quiz_prerequisite_admin_form() {
  $form['prerequisite_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Quiz Prequisite Message'),
    '#description' => t('Message to display to users if they need to take the prerequisite quiz'),
    '#default_value' => PREREQUISITE_MESSAGE,
  );

  $form['prerequisite_url'] = array(
    '#type' => 'checkbox',
    '#title' => t('Redirect to prerequisite quiz.'),
    '#description' => t('When a user has to take a prerequisite quiz before proceeding, redirect to the previous quiz.  The default behavior is to send user to an empty page with a message.'),
    '#default_value' => PREREQUISITE_URL,
  );
  return system_settings_form($form);
}

/**
 * Form for setting up the prerequisite quiz
 */
function quiz_prerequisite_select_form() {
  $quiz = menu_get_object();

  $form['quiz_nid'] = array(
    '#type' => 'value',
    '#value' => $quiz->nid,
  );
  $form['prereq_quiz_nid'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#title' => t('Prerequisite Quiz'),
    '#description' => t('Select prerequisite quiz before this quiz can be taken'),
    '#options' => quiz_prerequisite_load_quizzes($quiz->nid),
    '#default_value' => $quiz->prerequisite_nid,
    '#weight' => 1,
  );
  $form['role'] = array(
    '#type' => 'fieldset',
    '#title' => t('Roles allowed to skip prerequisite quiz'),
    '#description' => t('The following roles are allowed to skip the prerequisite requirement.'),
    '#weight' => 2,
  );
  $form['role']['roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Roles that can skip the prerequisite quiz'),
    '#description' => t('Select roles that can skip the prerequisite quiz.'),
    '#options' => user_roles(),
    '#default_value' => variable_get("quiz_prereq_can_skip_$quiz->nid", array()),
  );
  $form['op'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#weight' => 5,
  );
  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset'),
    '#weight' => 6,
  );

  return $form;
}

/**
 * Saves the prerequisite information into the database
 */
function quiz_prerequisite_select_form_submit($form, &$form_state) {
  $quiz_nid = $form_state['values']['quiz_nid'];
  $prereq_quiz = $form_state['values']['prereq_quiz_nid'];
  if ($form_state['values']['op'] == 'Reset') {
    // clear all prerequisites
    db_query("DELETE FROM {quiz_prereq_list} where quiz_nid = %d and prereq_quiz_nid = %d", $quiz_nid, $prereq_quiz);
    variable_del("quiz_prereq_can_skip_$quiz_nid");
    drupal_set_message(t('Prerequisite cleared'));
  }
  else {
    db_query("DELETE FROM {quiz_prereq_list} where quiz_nid = %d and prereq_quiz_nid = %d", $quiz_nid, $prereq_quiz);
    db_query("INSERT INTO {quiz_prereq_list} (quiz_nid, prereq_quiz_nid) VALUES (%d, %d)", $quiz_nid, $prereq_quiz);
  
    // store the access roles configuration in the variables table
    variable_set("quiz_prereq_can_skip_$quiz_nid", $form_state['values']['roles']);
    drupal_set_message(t('Prerequisite saved'));
  }
}

/**
 * Small page to redirect users if they have not met the quiz prereq
 */
function quiz_prerequisite_not_met_page() {
  $output = check_plain(PREREQUISITE_MESSAGE);
  return $output;
}