<?php

/**
 * @file
 * Implementation of the Option question type (multiple choice with only one
 * selectable option)
 */
class CqQuestionOption extends CqQuestionAbstract {

  /**
   * HTML containing the question-text.
   *
   * @var string
   */
  private $text;
  /**
   * The list of options for the student to choose from.
   *
   * @var array of CqOption
   */
  private $options = array();
  /**
   * List of feedback items to use as general hints.
   *
   * @var array of CqFeedback
   */
  private $hints = array();
  /**
   * Prompt do display directly above the options.
   *
   * @var string
   */
  private $prompt = '';

  /**
   * Constructs an option question object
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
    $this->prompt = t('Pick One');
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
    if ($answer === NULL) { // if there is no answer, don't check any further.
      return $feedback;
    }
    if (!$this->isCorrect()) {
      foreach ($this->hints as $fb) {
        if ($fb->inRange($tries)) {
          $feedback[] = $fb;
        }
      }
    }
    if ($answer !== NULL && $this->options[$answer] != NULL) {
      $feedbacks = $this->options[$answer]->getFeedback($tries, TRUE);
      foreach ($feedbacks as $fb) {
        $feedback[] = $fb;
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
        case 'option':
          $this->options[] = new CqOption($node, $this);
          break;

        case 'text':
          $this->text = cq_get_text_content($node, $this);
          break;

        case 'prompt':
          $this->prompt = cq_get_text_content($node, $this);
          break;

        case 'hint':
          $this->hints[] = CqFeedback::newCqFeedback($node, $this);
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

    $optionsFinal = array();
    foreach ($this->options as $optionNr => $option) {
      $optionsFinal[$optionNr] = $option->getText();
    }
    $answer = $this->userAnswer->getAnswer();
    $form['options'] = array(
      '#type' => 'radios',
      '#title' => $this->prompt,
      '#options' => $optionsFinal,
    );
    if ($answer !== NULL) {
      $form['options']['#default_value'] = $answer;
    }
    if ($formPos !== FALSE) {
      $form['options']['#prefix'] = $preForm;
      $form['options']['#suffix'] = $postForm;
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
      '#value' => t('Submit'),
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
    if ($answer !== NULL && isset($this->options[$answer]) && $this->options[$answer]->getCorrect() != 0) {
      return 1;
    }
    return 0;
  }

  /**
   * Implements CqQuestionAbstract::submitAnswer()
   */
  public function submitAnswer($form, &$form_state) {
    if (strlen($form_state['values']['options']) == 0) {
      $this->userAnswer->setAnswer(-1);
    }
    else {
      $this->userAnswer->setAnswer((int) $form_state['values']['options']);
    }
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
    $retval .= closedquestion_make_fieldset(t('Options'), theme('closedquestion_option_list', $this->options, TRUE));
    return $retval;
  }

}
