<?php
// $Id: classroom_signup.admin.inc,v 1.1 2010/01/28 13:06:25 osoh Exp $

/**
 * Sign up tab
 */
function classroom_signup_admin() {
  $form = array();

  $form['messages'] = array(
    '#type' => 'fieldset',
    '#title' => t('Messages'),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['messages']['signup_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Sign up message'),
    '#help' => t("You can use !course as course's title placeholder"),
    '#description' => t('Message to be shown when a user is signing up.'),
    '#default_value' => variable_get('classroom_signup_signup_message', ''),
  );

  return system_settings_form($form);
}
