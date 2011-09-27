<?php

/**
 * Theme the summary page after the quiz has been completed.
 *
 * @param $quiz
 *  The quiz node object.
 * @param $questions
 *  The questions array as defined by _quiz_get_answers.
 * @param $score
 *  Array of score information as returned by quiz_calculate_score().
 * @param $summary
 *  Filtered text of the summary.
 * @return
 *  Themed html.
 *
 * @ingroup themeable
 */
function meta_quiz_preprocess_meta_quiz_take_summary(&$vars) {
  // Set the title here so themers can adjust.
  drupal_set_title(check_plain($vars['meta_quiz']->title));

  if (!empty($vars['score']['possible_score'])) {
    if (!$vars['score']['is_evaluated']) {
      $msg = t('Parts of this @quiz have not been evaluated yet. The score below is not final.', array('@quiz' => QUIZ_NAME));
      drupal_set_message($msg, 'warning');
    }
    $vars['score_possible'] = t('You got %num_correct of %question_count possible points.', array('%num_correct' => $vars['score']['numeric_score'], '%question_count' => $vars['score']['possible_score']));
    $vars['score_percent'] = t('Your score: %score %', array('%score' => $vars['score']['percentage_score']));
  }
  if (isset($vars['summary']['passfail']))
    $vars['message'] = $vars['summary']['passfail'];
  if (isset($vars['summary']['result']))
    $vars['message'] = $vars['summary']['result'];
  // Get the feedback for all questions. These are included here to provide maximum flexibility for themers
  if ($vars['quiz']->display_feedback) {
    $vars['form'] = drupal_get_form('quiz_report_form', $vars['questions']);
  }

  $quiz_delta = NULL;
  foreach ($vars['meta_quiz']->field_meta_quiz_quiz as $delta => $value) {
    if ($value['nid'] == $vars['quiz']->nid) {
      $quiz_delta = $delta;
    }
  }
  $next_quiz_nid = $vars['meta_quiz']->field_meta_quiz_quiz[$quiz_delta + 1];
  $passed = $vars['score']['passing'];
  $field = $passed ? field_meta_quiz_image_passed : field_meta_quiz_image;
  $vars['image'] = theme_image($vars['meta_quiz']->{$field}[$quiz_delta]['filepath']);
  $vars['text'] = $vars['meta_quiz']->field_meta_quiz_text[$quiz_delta]['value'];
  $vars['finish'] = l('Finish', "node/{$vars['meta_quiz']->nid}");
  if ($passed && $next_quiz_nid) {
      $next_quiz = node_load($next_quiz_nid);
      $vars['next'] = l(t('Test level @node', array('@node' => $next_quiz->title)), "node/{$vars['meta_quiz']->nid}/take");
  }
}
