<?php
// $Id: classroom.admin.inc,v 1.7 2009/08/28 00:15:16 osoh Exp $

/**
 * Courses admin tab
 */
function classroom_courses_admin() {
  $form = array();

  $form['classroom_course_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Type'),
    '#description' => t('Content types that could be used as courses.'),
    '#default_value' => variable_get('classroom_course_types', array()),
    '#options' => _classroom_get_node_types(),
  );

  return system_settings_form($form);
}

/**
 * Course validation
 */
function classroom_courses_admin_validate($form, $form_state) {
  //Get the values that are checked and put in an array
  $values = array_unique(array_values($form_state['values']['classroom_course_types']));
  //Removes the empty element
  $values = array_filter($values);

  foreach ($values as $val) {
    if (_classroom_is_type($val, 'resource') ||
        _classroom_is_type($val, 'assignment') ||
        _classroom_is_type($val, 'response')) {
      form_set_error('classroom_courses_types', t('Cannot overlap the types for the elements of Classroom module'));
     }
  } 
}


/**
 * Assignments admin tab
 */
function classroom_assignments_admin() {
  $form = array();

  $form['classroom_assignment_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Type'),
    '#description' => t('Content types that could be used as assignments.'),
    '#default_value' => variable_get('classroom_assignment_types', array()),
    '#options' => _classroom_get_node_types(),
  );

  return system_settings_form($form);
}

/**
 * Assignments admin validation
 */
function classroom_assignments_admin_validate($form, $form_state) {
  //Get the values that are checked and put in an array
  $values = array_unique(array_values($form_state['values']['classroom_assignment_types']));
  //Removes the empty element
  $values = array_filter($values);
  
  foreach($values as $val) {
    if (_classroom_is_type($val, 'course') ||
        _classroom_is_type($val, 'resource') ||
        _classroom_is_type($val, 'response')) {
      form_set_error('classroom_courses_types', t('Cannot overlap the types for the elements of Classroom module'));
    }
  } 
}


/**
 * Response admin tab
 */
function classroom_responses_admin() {
  $form = array();

  $form['classroom_response_types'] = array(
    '#type' => 'radios',
    '#title' => t('Type'),
    '#description' => t('Content types that could be used as responses.'),
    '#default_value' => variable_get('classroom_response_types', null),
    '#options' => _classroom_get_node_types(),
  );

  return system_settings_form($form);
}

/**
 * Response admin validation
 */
function classroom_responses_admin_validate($form, $form_state) {
  //Get the values that are checked and put in an array
  $val = $form_state['values']['classroom_response_types'];
  if ($val == null) return;
  if (_classroom_is_type($val, 'course') ||
      _classroom_is_type($val, 'resource') ||
      _classroom_is_type($val, 'assignment')) {
    form_set_error('classroom_courses_types', t('Cannot overlap the types for the elements of Classroom module'));
  }
}

/**
 * Resources admin tab page
 */
function classroom_resources_admin() {
  $form = array();

  $form['classroom_resource_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Type'),
    '#description' => t('Content types that could be used as resources.'),
    '#default_value' => variable_get('classroom_resource_types', array()),
    '#options' => _classroom_get_node_types(),
  );

  return system_settings_form($form);
}

/**
 * Resource validation
 */
function classroom_resources_admin_validate($form, $form_state) {
  //Get the values that are checked and put in an array
  $values = array_unique(array_values($form_state['values']['classroom_resource_types']));
  //Removes the empty element
  $values = array_filter($values);

  foreach ($values as $val) {
    if (_classroom_is_type($val, 'course') ||
        _classroom_is_type($val, 'assignment') ||
        _classroom_is_type($val, 'response')) {
      form_set_error('classroom_courses_types', t('Cannot overlap the types for the elements of Classroom module'));
    }
  } 
}

/**
 * Form to assign roles and permissions on admin page.
 *
 * @param $form
 *   Form definition (Drupal style).
 */
function classroom_roles_admin($form)
{
  $form = array();

  $form['classroom_teachers_role'] = array(
    '#type' => 'select',
    '#title' => t("Teacher's role"),
    '#description' => t('Role which users could be teachers.'),
    '#default_value' => variable_get('classroom_teachers_role', array()),
    '#options' => user_roles(),
  );

  $form['classroom_students_role'] = array(
    '#type' => 'select',
    '#title' => t("Student's role"),
    '#description' => t('Role which users could be students.'),
    '#default_value' => variable_get('classroom_students_role', array()),
    '#options' => user_roles(),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Adjust permissions'),
  );

  return $form;
}

/**
 * Form to assign roles and permissions on admin page (hook_form_submit()
 * implementation).
 *
 * @param $form
 *   Form definition (Drupal style).
 * @param $form_state
 *   Form state (Drupal style).
 */
function classroom_roles_admin_submit($form, $form_state) {
  $students_rid = (int) $form['#post']['classroom_students_role'];
  $teachers_rid = (int) $form['#post']['classroom_teachers_role'];

  $removed_perms = _classroom_clean_assigned_perms();
  $added_perms = _classroom_assign_perms($students_rid, $teachers_rid);

  $roles_ids = array_merge(array_keys($added_perms),
    array_keys($removed_perms));
  $roles_ids = array_unique($roles_ids);

  $messages = array();
  $roles = user_roles();

  foreach ($roles_ids as $rid) {
    $added_for_role = ($added_perms[$rid]) ? $added_perms[$rid] : array();
    $removed_for_role = ($removed_perms[$rid]) ? $removed_perms[$rid] : array();

    $added = array_diff($added_for_role, $removed_for_role);
    if (!empty($added)) {
      $msg = t("Permissions granted to role '%role_name': ", array(
        '%role_name' => $roles[$rid]));
      $messages[] = $msg . implode(", ", $added);
    }

    $removed = array_diff($removed_for_role, $added_for_role);
    if (!empty($removed)) {
      $msg = t("Permissions revoked to role '%role_name': ", array(
        '%role_name' => $roles[$rid]));
      $messages[] = $msg . implode(", ", $removed);
    }
  }

  if (empty($messages)) {
    drupal_set_message("No permissions where changed.");
  } else {
    drupal_set_message(theme('item_list', $messages));
  }
}

function _classroom_clean_assigned_perms() {
  $assigned = variable_get("classroom_assigned_perms", array());
  $removed = array();
  if (!empty($assigned)) {
    foreach ($assigned as $rid => $perms) {
      $removed[$rid] = classroom_remove_perms($rid, $perms);
    }
  }
  variable_set("classroom_assigned_perms", array());
  return $removed;
}

function _classroom_assign_perms($students_rid = NULL, $teachers_rid = NULL) {
  variable_set("classroom_teachers_role", $teachers_rid);
  variable_set("classroom_students_role", $students_rid);

  $perms = classroom_perms();
  $teacher_perms = $perms['teacher'];
  $student_perms = $perms['student'];

  // Retrieve all permissions to assign.
  foreach (module_invoke_all('classroom_perms') as $perms) {
    $teacher_perms = array_merge($teacher_perms, $perms['teacher']);
    $student_perms = array_merge($student_perms, $perms['student']);
  }
  $teacher_perms = array_unique($teacher_perms);
  $student_perms = array_unique($student_perms);

  // Added perms.
  $added_perms = array();

  // Assign teachers' permissions.
  $added_perms[$teachers_rid] = ($teachers_rid) ?
    classroom_add_perms($teachers_rid, $teacher_perms) : NULL;

  // Assign students' permissions.
  $added_perms[$students_rid] = ($students_rid) ?
    classroom_add_perms($students_rid, $student_perms) : NULL;

  variable_set("classroom_assigned_perms", $added_perms);
  return $added_perms;
}
