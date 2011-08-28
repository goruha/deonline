<?php

/**
 * @file
 * Implementation of a Multiple answer question (multiple choice with more than
 * one selectable)
 */
class CqQuestionCheck extends CqQuestionAbstract {

  /**
   * HTML containing the question-text.
   *
   * @var string
   */
  private $text;
  /**
   * Prompt do display directly above the options.
   *
   * @var string
   */
  private $prompt = '';
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
   * Feedback mappings.
   *
   * @var array of CqMapping
   */
  private $mappings = array();
  /**
   * Mappings that have the "correct" flag set and mached the current answer.
   *
   * @var array of CqMapping
   */
  private $matchedCorrectMappings = array();
  /**
   * Mappings that mached the current answer.
   *
   * @var array of CqMapping
   */
  private $matchedMappings = array();
  /**
   * The feedback to show when the answer is answered correctly.
   *
   * @var CqFeedback
   */
  private $correctFeeback;
  /**
   * Show feedback in-line?
   * 1: yes, any other value: no;
   *
   * @var int
   */
  private $inlineFeedback = 1;
  /**
   * The answer in string-format.
   *
   * @var string
   */
  private $answerString = NULL;

  /**
   * Constructs a check question object.
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
    $this->prompt = t('Pick any number');
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

    // The direct option-related feedback
    if (!$this->isCorrect()) {
      foreach ($this->hints as $fb) {
        if ($fb->inRange($tries)) {
          $feedback[] = $fb;
        }
      }
    }
    // The option-related feedback. Shown always if feedback is inline, or
    // only when the answer is not correct if the feedback is not inline.
    if (!$this->isCorrect() || $this->inlineFeedback) {
      if ($answer !== NULL) {
        foreach ($this->options as $optionNr => $option) {
          $optionName = 'o' . $optionNr;
          $feedbacks = $option->getFeedback($tries, $answer[$optionName]);
          foreach ($feedbacks as $fb) {
            if ($this->inlineFeedback) {
              $fb->setBlock($optionName);
            }
            $feedback[] = $fb;
          }
        }
      }
    }

    // The feedback if the answer is correct.
    if ($this->isCorrect()) {
      if ($this->correctFeeback != NULL) {
        $feedback[] = $this->correctFeeback;
      }
    }

    // The new style mappings.
    if ($this->isCorrect()) {
      foreach ($this->matchedCorrectMappings AS $mapping) {
        $feedback = array_merge($feedback, $mapping->getFeedbackItems($tries));
      }
    }
    else {
      foreach ($this->matchedMappings AS $mapping) {
        $feedback = array_merge($feedback, $mapping->getFeedbackItems($tries));
      }
    }

    // Finally, ask external systems if they want to add extra feedback.
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

        case 'correct':
          $this->correctFeeback = CqFeedback::newCqFeedback($node, $this);
          break;

        case 'mapping': // New style mapping, continues at match by default.
          $map = new CqMapping();
          $map->generateFromNode($node, $this);

          if ($node->nodeName == 'sequence') {
            $map->setStopIfMatch(TRUE);
          }

          $this->mappings[] = $map;
          break;

        default:
          if (!in_array($name, $this->knownElements)) {
            drupal_set_message(t('Unknown node: @nodename', array('@nodename' => $node->nodeName)));
          }
          break;
      }
    }
    $attribs = $dom->attributes;
    $item = $attribs->getNamedItem('inlinefeedback');
    if ($item !== NULL) {
      $this->inlineFeedback = (int) $item->value;
    }
  }

  /**
   * Implements CqQuestionAbstract::getForm()
   */
  public function getForm($formState) {
    $answer = $this->userAnswer->getAnswer();
    $tries = $this->userAnswer->getTries();
    $answered = TRUE;
    if ($answer === NULL) {
      $answer = array();
      $answered = FALSE;
    }

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
      $optionName = 'o' . $optionNr;
      $optionsFinal[$optionName] = $option->getText();
      if ($this->inlineFeedback) {
        $optionsFinal[$optionName] .= '<p><span class="cqFbBlock cqFb-' . $optionName . '" ></span></p>';
      }
    }

    $form['options'] = array(
      '#type' => 'checkboxes',
      '#title' => $this->prompt,
      '#options' => $optionsFinal,
      '#default_value' => $answer,
    );
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
    );
    $form['submit']['#ahah'] = array(
      'path' => 'closedquestion/questionsubmitjs',
      'wrapper' => 'cq-feedback-wrapper',
      'method' => 'replace',
      'progress' => array('type' => 'throbber', 'message' => t('Please wait...')),
    );
    return $form;
  }

  /**
   * Implements CqQuestionAbstract::checkCorrect()
   */
  public function checkCorrect() {
    $answer = $this->userAnswer->getAnswer();
    $this->matchedMappings = array();
    $this->matchedCorrectMappings = array();

    if (count($this->mappings) > 0) { // There are mappings, use those.
      $correct = FALSE;
      foreach ($this->mappings as $id => $mapping) {
        if ($mapping->evaluate()) {
          if ($mapping->getCorrect() != 0) {
            $correct = TRUE;
            $this->matchedCorrectMappings[] = $mapping;
          }
          else {
            $this->matchedMappings[] = $mapping;
          }
          if ($mapping->stopIfMatch()) {
            break;
          }
        }
        unset($mapping);
      }
      return $correct;
    }
    else { // No mappings, use direct option-related checks.
      foreach ($this->options as $optionNr => $option) {
        $optionName = 'o' . $optionNr;
        if ($option->getCorrect() >= 0) {
          if ((!isset($answer[$optionName]) || $answer[$optionName] === 0) && $option->getCorrect() > 0) {
            return FALSE;
          }
          if ($answer[$optionName] === $optionName && $option->getCorrect() == 0) {
            return FALSE;
          }
        }
      }
      return TRUE;
    }
  }

  /**
   * Implements CqQuestionAbstract::submitAnswer()
   */
  public function submitAnswer($form, &$form_state) {
    $this->answerString = NULL;
    $this->userAnswer->setAnswer($form_state['values']['options']);
    $correct = $this->isCorrect(TRUE);
    if ($this->userAnswer->answerHasChanged()) {
      if (!$correct) {
        $this->userAnswer->increaseTries();
      }
      $this->userAnswer->store();
    }
  }

  /**
   * Returns the the answer in string form.
   *
   * @param string $identifier
   *   unused in this question type.
   *
   * @return String
   *   the answer in string form.
   */
  public function getAnswerForChoice($identifier) {
    $answer = $this->userAnswer->getAnswer();
    if ($this->answerString === NULL) {
      $this->answerString = '';
      foreach ($this->options as $optionNr => $option) {
        $optionName = 'o' . $optionNr;
        if ($answer[$optionName] === $optionName) {
          $this->answerString .= $option->getIdentifier();
        }
      }
      if (user_access(CLOSEDQUESTION_RIGHT_CREATE)) {
        drupal_set_message(t('Current answer=%a (Teacher only message)', array('%a' => $this->answerString)));
      }
    }
    return $this->answerString;
  }

  /**
   * Implements CqQuestionAbstract::getAllText()
   */
  public function getAllText() {
    $this->initialise();
    $retval = '';
    $retval .= closedquestion_make_fieldset(t('Text'), $this->text);
    if ($this->correctFeeback) {
      $retval .= closedquestion_make_fieldset(t('Correct Feedback'), $this->correctFeeback->getText());
    }
    $retval .= closedquestion_make_fieldset(t('Hints'), theme('closedquestion_feedback_list', $this->hints, TRUE));
    $retval .= closedquestion_make_fieldset(t('Options'), theme('closedquestion_option_list', $this->options, TRUE));
    $retval .= closedquestion_make_fieldset(t('Mappings'), theme('closedquestion_mapping_list', $this->mappings));
    return $retval;
  }

}
