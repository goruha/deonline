<?php

/**
 * @file
 * Factory methods for creating questions from XML.
 */

/**
 * Factory method for creating questions from an XML DOMEelement.
 *
 * @param DOMElement $xmlNode
 *   representing the question.
 * @param CqUserAnswerInterface $userAnswer
 *   to use for storing the user's answer
 * @param Object $node
 *   Drupal node object that this comes from.
 *
 * @return CqQuestion
 *   The question.
 */
function cq_question_from_dom_element($xml_node, &$user_answer, &$node) {
  $type = $xml_node->getAttribute('type');
  $question = FALSE;
  switch (drupal_strtoupper($type)) {
    case 'BALANCE':
      $question = new CqQuestionBalance($user_answer, $node);
      break;

    case 'CHECK':
      $question = new CqQuestionCheck($user_answer, $node);
      break;

    case 'DRAGDROP':
      $question = new CqQuestionDragDrop($user_answer, $node);
      break;

    case 'FILLBLANKS':
      $question = new CqQuestionFillblanks($user_answer, $node);
      break;

    case 'FLASH':
      $question = new CqQuestionFlash($user_answer, $node);
      break;

    case 'HOTSPOT':
      $question = new CqQuestionHotspot($user_answer, $node);
      break;

    case 'OPTION':
      $question = new CqQuestionOption($user_answer, $node);
      break;

    case 'SELECTORDER':
    case 'PATTERN':
      $question = new CqQuestionSelectOrder($user_answer, $node);
      break;

    case 'SEQUENCE':
      $question = new CqQuestionSequence($user_answer, $node);
      break;

    case 'VALUE':
      $question = new CqQuestionValue($user_answer, $node);
      break;

    default:
      drupal_set_message(t('Unknown question type: %type', array('%type' => $type)), 'error');
      break;
  }
  return $question;
}

/**
 * Wrapper for cq_question_from_dom_element() that takes plain-text XML, parses it
 * into a DOMElement and passes that on to cq_question_from_dom_element().
 *
 * @param String $xmlContent
 *   containing the XML.
 * @param CqUserAnswerInterface $userAnswer
 *   to use for storing the user's answer
 * @param Object $node
 *   Drupal node object that this comes from.
 *
 * @return CqQuestion
 *   The question.
 */
function cq_question_from_xml($xml_content, &$user_answer, &$node) {
  if (strlen($xml_content) == 0) {
    drupal_set_message(t('Your question XML is empty. Please supply a question.'), 'error');
    return NULL;
  }

  $dom = new DomDocument();
  if (!$dom) {
    drupal_set_message(t('DOM-XML php extension probably not installed, please see the requirements section in the README.txt'), 'error');
    return NULL;
  }

  if (!$dom->loadXML($xml_content)) {
    drupal_set_message(t('Problem loading question in node %nid', array('%nid' => $node->nid)), 'error');
    return NULL;
  }

  $xpath = new DOMXPath($dom);
  $questions = $xpath->query('/question');
  $first_child = $questions->item(0);
  if ($first_child) {
    $question = cq_question_from_dom_element($first_child, $user_answer, $node);
  }
  else {
    drupal_set_message(t('It seems your XML does not contain a &lt;question&gt; tag as root tag.'), 'error');
    return NULL;
  }

  return $question;
}
