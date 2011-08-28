<?php

/**
 * @file
 * Implementation of the Select & Order question type.
 *
 * A select & order question displays a list of options to the student and
 * one or more target boxes. The student drags options to the target boxes, and
 * orders the selected options.
 */
class CqQuestionSelectOrder extends CqQuestionAbstract {

  /**
   * HTML containing the question-text.
   *
   * @var string
   */
  private $text;
  /**
   * Title of the box containing the un-selected options.
   *
   * @var string
   */
  private $sourceTitle;
  /**
   * Title of the target-box if there is only one target box.
   *
   * @var string
   */
  private $sectionTitle;
  /**
   * The base-name used for form elements that need to be accessed by
   * javascript.
   *
   * @var string
   */
  private $formElementName;
  /**
   * Allow duplicates?
   * If 1, a student can select one option more than once. If any other value,
   * a student can use an option only once.
   *
   * @var int
   */
  private $duplicates = 0;
  /**
   * The complete list of items that the user can select.
   *
   * @var array of CqOption
   *   Associative array, keys are the opion identifiers.
   */
  private $items = array();
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
   * List of feedback items to use as general hints.
   *
   * @var array of CqFeedback
   */
  private $hints = array();
  /**
   * The state to use when the student has not yet changed any thing.
   *
   * @var string
   */
  private $defaultAnswer = '';
  /**
   * The list of items that are free for the user to select. Either because
   * he has not selected them yet, or because duplicates are allowed.
   *
   * @var array of CqOption
   *   Associative array, keys are the opion identifiers.
   */
  private $unSelected = array();
  /**
   * The list of sections (target boxes). Each section is represented as a
   * CqOption with a numeric identifier.
   *
   * @var array of CqOption
   */
  private $sections = array();
  /**
   * The list of selected items, ordered by section.
   *
   * @var array of arrays of CqOption
   *   Associative array, with section id's as key, containing assocaitive
   *   arrays, with item id's as key, containing CqOptions.
   *   Map<String, Map<String, CqOption>>
   */
  private $selectedBySection = array();
  /**
   * Alignment key.
   * (Default) normal: options are below each other, source box on the left,
   * target boxes on the right
   * horizontal: options are next to each other, source box at the top, target
   * boxes below that.
   *
   * @var string
   */
  private $alignment = "normal";
  /**
   * Minimal height to use for items to force nice alignment if contents are of
   * varying height.
   *
   * @var int or boolean FALSE if not set.
   */
  private $optionHeight = FALSE;

  /**
   * Constructs a Select&Order question object
   *
   * @param CqUserAnswerInterface $userAnswer
   *   The CqUserAnswerInterface to use for storing the student's answer.
   * @param object $node
   *   Drupal node object that this question belongs to.
   */
  public function __construct(CqUserAnswerInterface &$userAnswer, &$node) {
    parent::__construct();
    $this->sourceTitle = t('Available Items');
    $this->sectionTitle = t('Selected Items');
    $this->userAnswer = &$userAnswer;
    $this->node = &$node;
    $this->formElementName = 'cq_so_' . $this->node->nid . '_';
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
   * Implements CqQuestionAbstract::getForm()
   */
  public function getForm($formState) {
    $answer = $this->userAnswer->getAnswer();
    $this->sortItems();

    // The question part is themed
    $form['question']['#theme'] = 'closedquestion_question_select_order';
    $form['question']['questionText'] = array(
      '#type' => 'item',
      '#value' => $this->text,
    );

    // The data needed by the theme function.
    $data = array();
    $data['elementname'] = $this->formElementName;
    $data['duplicates'] = $this->duplicates;
    $data['alignment'] = $this->alignment;
    $data['optionHeight'] = $this->optionHeight;
    $data['sourceTitle'] = $this->sourceTitle;
    $selected = '';

    foreach ($this->unSelected as $item) {
      $data['unselected'][] = array(
        'identifier' => $item->getIdentifier(),
        'text' => $item->getText(),
        'description' => $item->getDescription(),
      );
    }

    foreach ($this->selectedBySection as $sectionId => $sectionSelected) {
      if (isset($this->sections[$sectionId])) {
        $sectionItem = $this->sections[$sectionId];
        $sectionData = array(
          'text' => $sectionItem->getText(),
          'identifier' => $sectionItem->getIdentifier(),
          'items' => array(),
        );
        $selected .= $sectionItem->getIdentifier();
      }
      else {
        $sectionData = array(
          'text' => $this->sectionTitle,
          'items' => array(),
        );
      }

      foreach ($sectionSelected as $item) {
        $sectionData['items'][] = array(
          'identifier' => $item->getIdentifier(),
          'text' => $item->getText(),
          'description' => $item->getDescription(),
        );
        $selected .= $item->getIdentifier();
      }
      $data['sections'][] = $sectionData;
    }
    $form['question']['data'] = array('#type' => 'value', '#value' => $data);

    // This element will be filled by Javascript to contain the answer.
    $form['selected'] = array(
      '#id' => $this->formElementName . 'selected',
      '#type' => 'hidden',
      '#input' => TRUE,
      '#default_value' => $selected,
    );

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
   * Parses the student's answer ans sorts the items according to the selection
   * the student made.
   */
  private function sortItems() {
    $answer = $this->userAnswer->getAnswer();

    $this->unSelected = array();
    foreach ($this->selectedBySection AS $id => $list) {
      $this->selectedBySection[$id] = array();
    }

    foreach ($this->items as $key => $item) {
      if (!is_numeric($key) && ($this->duplicates || !strstr($answer, $key))) {
        $this->unSelected[] = $item;
      }
    }
    $curSection = 1;
    foreach (str_split($answer) as $key) {
      if (isset($this->sections[$key])) {
        $curSection = $key;
      }
      elseif (isset($this->items[$key])) {
        $this->selectedBySection[$curSection][] = $this->items[$key];
      }
    }
  }

  /**
   * Implements CqQuestionAbstract::getFeedbackItems()
   */
  public function getFeedbackItems() {
    $answer = $this->userAnswer->getAnswer();
    $tries = $this->userAnswer->getTries();
    $feedback = array();

    if ($tries == 0 && $answer == $this->defaultAnswer) { // if there is no answer, don't check any further.
      return $feedback;
    }

    // The general hints, only of the answer is not correct.
    if (!$this->isCorrect()) {
      foreach ($this->hints as $fb) {
        if ($fb->inRange($tries)) {
          $feedback[] = $fb;
        }
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
   * Implements CqQuestionAbstract::checkCorrect()
   */
  public function checkCorrect() {
    $this->matchedMappings = array();
    $this->matchedCorrectMappings = array();
    $answer = $this->userAnswer->getAnswer();
    $tries = $this->userAnswer->getTries();

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
        case 'item':
          $option = new CqOption($node, $this);
          if (is_numeric($option->getIdentifier())) {
            $this->sections[$option->getIdentifier()] = $option;
            $this->selectedBySection[$option->getIdentifier()] = array();
          }
          if (isset($this->items[$option->getIdentifier()])) {
            drupal_set_message(t('Option identifier %identifier used more than once!', array('%identifier' => $option->getIdentifier())), 'warning');
          }
          $this->items[$option->getIdentifier()] = $option;
          break;

        case 'sequence': // Old style sequence, would stop at first match.
        case 'mapping': // New style mapping, continues at match by default.
          $map = new CqMapping();
          $map->generateFromNode($node, $this);

          if ($node->nodeName == 'sequence') {
            $map->setStopIfMatch(TRUE);
          }

          $this->mappings[] = $map;
          break;

        case 'text':
          $this->text = cq_get_text_content($node, $this);
          break;

        case 'hint':
          $this->hints[] = CqFeedback::newCqFeedback($node, $this);
          break;

        case 'default':
        case 'startstate':
          $attribs = $node->attributes;
          $item = $attribs->getNamedItem('value');
          if ($item !== NULL) {
            $this->defaultAnswer = $item->value;
          }
          break;

        default:
          if (!in_array($name, $this->knownElements)) {
            drupal_set_message(t('Unknown node: @nodename', array('@nodename' => $node->nodeName)));
          }
          break;
      }
    }
    $attribs = $dom->attributes;
    $item = $attribs->getNamedItem('duplicates');
    if ($item !== NULL) {
      $this->duplicates = (int) $item->value;
    }
    $item = $attribs->getNamedItem('alignment');
    if ($item !== NULL) {
      $this->alignment = $item->value;
    }
    $item = $attribs->getNamedItem('optionheight');
    if ($item !== NULL) {
      $this->optionHeight = $item->value;
    }

    $answer = $this->userAnswer->getAnswer();
    if (empty($answer)) {
      $this->userAnswer->setAnswer($this->defaultAnswer);
    }

    if (count($this->selectedBySection) == 0) { // No sections defined, make one.
      $this->selectedBySection[1] = array();
    }
  }

  /**
   * Implements CqQuestionAbstract::submitAnswer()
   */
  public function submitAnswer($form, &$form_state) {
    if (user_access(CLOSEDQUESTION_RIGHT_CREATE)) {
      drupal_set_message(t('Answer=%answer', array('%answer' => $form_state['values']['selected'])));
    }
    $this->userAnswer->setAnswer($form_state['values']['selected']);
    $correct = $this->isCorrect(TRUE);
    if ($this->userAnswer->answerHasChanged()) {
      if (!$correct) {
        $this->userAnswer->increaseTries();
      }
      $this->userAnswer->store();
    }
  }

  /**
   * Get the answer the student has given for the given target box, or the full
   * answer string if the given identifier is not a target box.
   *
   * @param string $identifier
   *   The target-box number to fetch the answer for.
   *
   * @return string the answer.
   */
  public function getAnswerForChoice($identifier) {
    $answer = $this->userAnswer->getAnswer();
    if (is_numeric($identifier)) {
      $part = (int) $identifier;
      $start = strpos($answer, $part);
      $end = strpos($answer, $part + 1, $start);
      $length = max(0, max(drupal_strlen($answer), $end) - $start);
      // not using drupal_substr since we use a strpos generated indexes.
      return substr($aswer, $start, $length);
    }
    else {
      return $answer;
    }
  }

  /**
   * Implements CqQuestionAbstract::getAllText()
   */
  public function getAllText() {
    $this->initialise();
    $retval = '';
    $retval .= closedquestion_make_fieldset(t('Text'), $this->text);
    $retval .= closedquestion_make_fieldset(t('Options'), theme('closedquestion_option_list', $this->items, FALSE));
    $retval .= closedquestion_make_fieldset(t('Hints'), theme('closedquestion_feedback_list', $this->hints, TRUE));
    $retval .= closedquestion_make_fieldset(t('Mappings'), theme('closedquestion_mapping_list', $this->mappings));
    return $retval;
  }

}
