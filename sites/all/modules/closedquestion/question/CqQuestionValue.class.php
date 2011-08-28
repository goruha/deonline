<?php

/**
 * @file
 * Implementation of the Value question type.
 * The same functionality can be created with the Fillblanks question type.
 */
class CqQuestionValue extends CqQuestionAbstract {

  /**
   * HTML containing the question-text.
   *
   * @var string
   */
  private $text;
  /**
   * Ranges to check the student-given value against.
   *
   * @var array of CqRange
   */
  private $ranges = array();
  /**
   * The unit the answer should be in.
   *
   * @var string
   */
  private $unit = '';
  /**
   * List of feedback items to use as general hints.
   *
   * @var array of CqFeedback
   */
  private $hints = array();
  /**
   * The feedback to give when the student gives the correct answer.
   *
   * @var CqFeedback
   */
  private $correctFeeback;

  /**
   * Constructs a value question object
   *
   * @param CqUserAnswerInterface $userAnswer
   *   The CqUserAnswerInterface to use for storing the student's answer.
   * @param object $node
   *   Drupal node object that this question belongs to.
   */
  public function __construct(CqUserAnswerInterface &$userAnswer, &$node) {
    parent::__construct();
    $this->userAnswer = &$userAnswer;
    $this->node = &$node;
  }

  /**
   * Implements CqQuestionAbstract::getOutput()
   */
  public function getOutput() {
    $this->initialise();
    $retval = $this->prefix;
    $retval .= drupal_get_form('closedquestion_get_form_for', $this->node);
    $retval .= $this->postfix;
    return $retval;
  }

  /**
   * Implements CqQuestionAbstract::getFeedbackItems()
   */
  public function getFeedbackItems() {
    $tries = $this->userAnswer->getTries();
    $answer = $this->userAnswer->getAnswer();
    $feedback = array();
    if ($answer == NULL) { // if there is no answer, don't check any further.
      return $feedback;
    }
    if (!$this->isCorrect()) {
      foreach ($this->hints as $fb) {
        if ($fb->inRange($tries)) {
          $feedback[] = $fb;
        }
      }
    }

    foreach ($this->ranges as $rangeNr => $range) {
      if ($range->inRange($answer)) {
        $feedbacks = $range->getFeedback($tries);
        foreach ($feedbacks as $fb) {
          $feedback[] = $fb;
        }
      }
    }

    if ($this->isCorrect()) {
      if ($this->correctFeeback != NULL) {
        $feedback[] = $this->correctFeeback;
      }
    }
    $feedback = array_merge($feedback, $this->fireGetExtraFeedbackItems($this, $tries));
    return $feedback;
  }

  /**
   * Overrides CqQuestionAbstract::loadXml()
   */
  public function loadXml(DOMElement $dom) {
    parent::loadXml($dom);
    module_load_include('inc.php', 'closedquestion', 'lib/XmlLib');

    foreach ($dom->childNodes as $node) {
      $name = drupal_strtolower($node->nodeName);
      switch ($name) {
        case 'range':
          $this->ranges[] = new CqRange($node, $this);
          break;

        case 'unit':
          $this->unit = cq_get_text_content($node, $this);
          break;

        case 'text':
          $this->text = cq_get_text_content($node, $this);
          break;

        case 'hint':
          $this->hints[] = CqFeedback::newCqFeedback($node, $this);
          break;

        case 'correct':
          $this->correctFeeback = CqFeedback::newCqFeedback($node, $this);
          break;

        default:
          if (!in_array($name, $this->knownElements)) {
            drupal_set_message(t('Unknown node: @nodename', array('@nodename' => $node->nodeName)));
          }
          break;
      }
    }
  }

  /**
   * Implements CqQuestionAbstract::getForm()
   */
  public function getForm($formState) {
    $answer = $this->userAnswer->getAnswer();
    $tries = $this->userAnswer->getTries();

    $formPos = strpos($this->text, '<formblock/>');
    if ($formPos !== FALSE) {
      // not using drupal_substr since we use a strpos generated index.
      $preForm = substr($this->text, 0, $formPos);
      $postForm = substr($this->text, $formPos + 12);
    }
    else {
      $form['questionText'] = array(
        '#type' => 'item',
        '#value' => $this->text,
      );
    }

    $form['answer'] = array(
      '#type' => 'textfield',
      '#field_suffix' => $this->unit,
      '#size' => 10,
      '#default_value' => $answer,
    );
    if ($formPos !== FALSE) {
      $form['answer']['#prefix'] = $preForm;
      $form['answer']['#suffix'] = $postForm;
    }

    if ($this->isCorrect()) {
      $attribs = array();
    }
    else {
      $attribs = array('class' => 'error');
    }
    // Wrapper for fieldset contents (used by ahah.js).
    $form['cq-feedback-wrapper'] = array(
      '#prefix' => '<div id="cq-feedback-wrapper">',
      '#suffix' => '</div>',
      'feedback' => array('#value' => ' '),
    );
    $form['cq-feedback-wrapper'] = array_merge($form['cq-feedback-wrapper'], $this->getFeedbackFormItem());


    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Submit',
      '#ahah' => array(
        'path' => 'closedquestion/questionsubmitjs',
        'wrapper' => 'cq-feedback-wrapper',
        'method' => 'replace',
        'progress' => array('type' => 'throbber', 'message' => t('Please wait...')),
      ),
    );

    return $form;
  }

  /**
   * Implements CqQuestionAbstract::checkCorrect()
   */
  public function checkCorrect() {
    $answer = $this->userAnswer->getAnswer();
    foreach ($this->ranges as $rangeNr => $range) {
      if ($range->inRange($answer) && $range->getCorrect()) {
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * Implements CqQuestionAbstract::submitAnswer()
   */
  public function submitAnswer($form, &$form_state) {
    $this->userAnswer->setAnswer($form_state['values']['answer']);
    $correct = $this->isCorrect(TRUE);
    if ($this->userAnswer->answerHasChanged()) {
      if (!$correct) {
        $this->userAnswer->increaseTries();
      }
      $this->userAnswer->store();
    }
  }

  /**
   * Implements CqQuestionAbstract::getAllText()
   */
  public function getAllText() {
    $this->initialise();
    $retval = '';
    $retval .= closedquestion_make_fieldset(t('Text'), $this->text);
    $retval .= closedquestion_make_fieldset(t('Hints'), theme('closedquestion_feedback_list', $this->hints, TRUE));
    $retval .= closedquestion_make_fieldset(t('Ranges'), theme('closedquestion_range_list', $this->ranges));
    return $retval;
  }

}
