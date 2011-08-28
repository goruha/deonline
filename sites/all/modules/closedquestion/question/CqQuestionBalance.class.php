<?php

/**
 * @file
 * Implementation of the Balance question type.
 *
 * A balance equation takes the form of:
 * accumulation = transport + reaction
 *
 * In this question type the teacher can define a list of terms for each of
 * these and ask the student to pick the correct ones.
 */
class CqQuestionBalance extends CqQuestionAbstract {

  /**
   * HTML containing the question-text.
   *
   * @var string
   */
  private $text;
  /**
   * List of options for the three sections of the balance equation.
   *
   * @var array
   *   An associative array containing the three keys defined in $SECTIONS. Each
   *   entry contains a list of CqOption
   */
  private $options = array();
  /**
   * List of feedback items to use as general hints.
   *
   * @var array of CqFeedback
   */
  private $hints = array();
  /**
   * The feedback to show for each section if that section is correct.
   *
   * @var array
   *   An associative array containing the three keys defined in $SECTIONS. Each
   *   value is a CqFeedback.
   */
  private $correctFeeback;
  /**
   * Place the feedback for each option next to the option instead of in the
   * feedback are below the question?
   *
   * @var int
   *   1 to use inline feedback, any other value to not use inline feedback.
   */
  private $inlineFeedback = 0;
  /**
   * Definition section names.
   *
   * @var array of string
   */
  private $SECTIONS = array('acc', 'flow', 'prod');

  /**
   * Constructs a balance question object
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
    drupal_add_css(drupal_get_path('module', 'closedquestion') . '/assets/closedquestion.css');
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

      if ($answer !== NULL) {
        foreach ($this->SECTIONS as $section) {

          $sectionCorrect = TRUE;
          foreach ($this->options[$section] as $optionNr => $option) {
            $optionName = $section . $optionNr;
            if (!$option->correctlyAnswered($answer[$section][$optionName])) {
              $sectionCorrect = FALSE;
            }
            if (!$this->inlineFeedback) {
              $feedbacks = $option->getFeedback($tries, $answer[$section][$optionName]);
              foreach ($feedbacks as $fb) {
                $feedback[] = $fb;
              }
            }
          }

          if ($sectionCorrect) {
            if ($this->correctFeeback[$section]) {
              $feedback[] = $this->correctFeeback[$section];
            }
          }
        }
      }
    }
    else {
      if ($this->correctFeeback != NULL) {
        $feedback[] = $this->correctFeeback['all'];
      }
    }

    // Finally, ask external systems if they want to add extra feedback.
    $feedback = array_merge($feedback, $this->fireGetExtraFeedbackItems($this, $tries));
    return $feedback;
  }

  /**
   * Parses the part of the XML that defines the options for a section of the
   * balance equation.
   *
   * @param DOMNode $sectionNode
   *   The XML DOMNode containing the definitions for the section.
   */
  private function parseSection(DOMNode $sectionNode) {
    $sectionName = $sectionNode->nodeName;
    foreach ($sectionNode->childNodes as $node) {
      switch ($node->nodeName) {
        case 'option':
          $this->options[$sectionName][] = new CqOption($node, $this);
          break;

        case 'correct':
          $this->correctFeeback[$sectionName] = CqFeedback::newCqFeedback($node, $this);
          break;

        case '#text':
        case '#comment':
          break;

        default:
          drupal_set_message(t('Unknown node: @nodename', array('@nodename' => $node->nodeName)));
          break;
      }
    }
  }

  /**
   * Overrides CqQuestionAbstract::loadXml()
   */
  public function loadXml(DOMElement $dom) {
    parent::loadXml($dom);
    module_load_include('inc.php', 'closedquestion', 'lib/XmlLib');

    foreach ($dom->childNodes as $node) {
      if (in_array($node->nodeName, $this->SECTIONS)) {
        $this->parseSection($node);
      }
      else {
        $name = drupal_strtolower($node->nodeName);
        switch ($name) {
          case 'text':
            $this->text = cq_get_text_content($node, $this);
            break;

          case 'hint':
            $this->hints[] = CqFeedback::newCqFeedback($node, $this);
            break;

          case 'correct':
            $this->correctFeeback['all'] = CqFeedback::newCqFeedback($node, $this);
            break;

          default:
            if (!in_array($name, $this->knownElements)) {
              drupal_set_message(t('Unknown node: @nodename', array('@nodename' => $node->nodeName)));
            }
            break;
        }
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
    if ($answer === NULL) {
      $answer = array();
    }

    // The question part is themed
    $form['question']['#theme'] = 'closedquestion_question_balance';
    $form['question']['questionText'] = array(
      '#type' => 'item',
      '#value' => $this->text,
    );

    $optionsFinal = array();
    foreach ($this->SECTIONS as $section) {
      foreach ($this->options[$section] as $optionNr => $option) {
        $optionName = $section . $optionNr;
        $optionsFinal[$section][$optionName] = $option->getText();
        // If we use inline feedback, we add the feedback to the option.
        if ($tries > 0 && $this->inlineFeedback) {
          $optionsFinal[$section][$optionName] .= theme('closedquestion_feedback_list', $option->getFeedback($tries, $answer[$section][$optionName]));
        }
      }
    }


    for ($i = 0; $i < count($this->SECTIONS); $i++) {
      $secName = $this->SECTIONS[$i];
      $answers = $answer[$secName];
      if ($answers == NULL) {
        $answers = array();
      }

      $form['question']['options' . $secName] = array(
        '#type' => 'checkboxes',
        '#title' => '',
        '#options' => $optionsFinal[$secName],
        '#default_value' => $answers,
      );
    }

    // The feedback and submit buttons are not themed by default.
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
    $correct = TRUE;
    foreach ($this->options as $sectionName => $optionList) {
      foreach ($optionList as $optionNr => $option) {
        $optionName = $sectionName . $optionNr;
        if (!$option->correctlyAnswered($answer[$sectionName][$optionName])) {
          return FALSE;
        }
      }
    }
    return $correct;
  }

  /**
   * Implements CqQuestionAbstract::submitAnswer()
   */
  public function submitAnswer($form, &$form_state) {
    foreach ($this->SECTIONS as $secName) {
      $answer[$secName] = $form_state['values']['options' . $secName];
    }
    $this->userAnswer->setAnswer($answer);
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
    return 'not implemented yet.';
  }

}
