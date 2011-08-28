<?php
/**
 * @file
 * Theme functions used by closedQuestion.
 */

/**
 * Themes the edit form of a ClosedQuestion node.
 *
 * @param array $form
 *   The edit form to theme.
 */
function theme_closedquestion_node_form($form) {
  $path = drupal_get_path('module', 'closedquestion');

  $jq_ui_in_libraries = library_get_path('jquery.ui', array('ui/minified/ui.core.min.js', 'ui/ui.core.js'), FALSE);
  if ($jq_ui_in_libraries) {
    $path_ui_core = $jq_ui_in_libraries;
    $path_ui_draggable = library_get_path('jquery.ui', array('ui/minified/ui.draggable.min.js', 'ui/ui.core.js'), FALSE);
    $path_ui_resizable = library_get_path('jquery.ui', array('ui/minified/ui.resizable.min.js', 'ui/ui.core.js'), FALSE);
    $path_ui_css = library_get_path('jquery.ui', array('themes/base/jquery-ui.css'), FALSE);
  }
  else {
    $path_ui = drupal_get_path('module', 'jquery_ui');
    $path_ui_core = url($path_ui . '/jquery.ui/ui/ui.core.js');
    $path_ui_draggable = url($path_ui . '/jquery.ui/ui/ui.draggable.js');
    $path_ui_resizable = url($path_ui . '/jquery.ui/ui/ui.resizable.js');
    $path_ui_css = url($path_ui . '/jquery.ui/themes/base/jquery-ui.css');
  }

  $jquery_path = library_get_path('jquery-1.4', array('jquery.min.js', 'jquery.js'), '//ajax.googleapis.com/ajax/libs/jquery/1.4.4/jquery.min.js');
  $jquery_json_path = library_get_path('jquery-json', array('jquery.json.min.js', 'jquery.json.js'), 'http://other.wmmrc.nl/ClosedQuestion/jquery.json.min.js');
  $jquery_jstree_path = library_get_path('jquery-jstree', array('jquery.jstree.min.js', 'jquery.jstree.js'), 'http://other.wmmrc.nl/ClosedQuestion/jquery.jstree.js');
  $jsdraw2d_path = library_get_path('jsDraw2D', array('jsDraw2D.js'), 'http://jsdraw2d.jsfiction.com/jsDraw2D.js');

  drupal_set_html_head('<script type="text/javascript" src="' . $jquery_path . '"></script>');
  drupal_set_html_head('<script type="text/javascript" src="' . $jquery_json_path . '"></script>');
  drupal_set_html_head('<script type="text/javascript" src="' . $jquery_jstree_path . '"></script>');
  drupal_set_html_head('<script type="text/javascript" src="' . $path_ui_core . '"></script>');
  drupal_set_html_head('<script type="text/javascript" src="' . $path_ui_draggable . '"></script>');
  drupal_set_html_head('<script type="text/javascript" src="' . $path_ui_resizable . '"></script>');
  drupal_set_html_head('<script type="text/javascript" src="' . $jsdraw2d_path . '"></script>');

  $script_url = url($path . '/assets/xmlEditor.js');
  drupal_set_html_head('<script type="text/javascript" src="' . $script_url . '"></script>');
  $script_url = url($path . '/assets/plugins/matchImgEditor.js');
  drupal_set_html_head('<script type="text/javascript" src="' . $script_url . '"></script>');
  $script_url = url($path . '/assets/xmlQuestionConfig.js');
  drupal_set_html_head('<script type="text/javascript" src="' . $script_url . '"></script>');
  $script_url = url($path . '/assets/xmlQuestionTemplates.js');
  drupal_set_html_head('<script type="text/javascript" src="' . $script_url . '"></script>');
  $script_url = url($path . '/assets/xmlQuestionConvert.js');
  drupal_set_html_head('<script type="text/javascript" src="' . $script_url . '"></script>');
  drupal_set_html_head('<link rel="stylesheet" href="' . $path_ui_css . '" type="text/css" media="all" />');

  $settings['closedquestion']['basePath'] = url($path);
  drupal_add_js($settings, 'setting');
  drupal_add_css($path . '/assets/closedquestion_xmleditor.css', 'module', 'all', FALSE);

  drupal_add_js('Drupal.behaviors.closedQuestionEditor = function (context) { CQ_InitialView(context); }', 'inline');

  $form['body_field']['body']['#prefix'] .= '
    <a id="xmlJsonEditor_templates" class="xmlJsonEditor_inactiveTab" href="javascript:void(0)" onclick="CQ_ShowTemplates()">' . t('Choose a Template') . '</a>
    <a id="xmlJsonEditor_tree" class="xmlJsonEditor_inactiveTab" href="javascript:void(0)" onclick="CQ_ShowTree()">' . t('Edit Question') . '</a>
    <a id="xmlJsonEditor_xml" class="xmlJsonEditor_activeTab" href="javascript:void(0)" onclick="CQ_ShowXML()">' . t('Edit Source') . '</a>
    <div id="body_field_wrapper">
      <div class="xmlJsonEditor_container" id="xmlJsonEditor_container">
        <div class="xmlJsonEditor_tree_container" id="xmlJsonEditor_tree_container"></div>
        <div class="xmlJsonEditor_divider" id="xmlJsonEditor_divider"></div>
        <div class="xmlJsonEditor_form_elements" id="xmlJsonEditor_editor"></div>
      </div>
      <div class="xmlJsonEditor_templates" id="xmlJsonEditor_template_container">
        <div>' . t('Create a multiple choice question:') . ' <input type="button" name="mc_create" value="Create" onclick="QC_CreateMC()"></div>
        <div>' . t('Create a multiple answer question:') . ' <input type="button" name="ma_create" value="Create" onclick="QC_CreateMA()"></div>
        <div>' . t('Create a multiple answer question with advanced answer mapping:') . ' <input type="button" name="maa_create" value="Create" onclick="QC_CreateMAA()"></div>
        <div>' . t('Create a Select&Order question:') . ' <input type="button" name="so1_create" value="Create" onclick="QC_CreateSO1()"></div>
        <div>' . t('Create a Select&Order question with multiple target boxes:') . ' <input type="button" name="so1_create" value="Create" onclick="QC_CreateSO2()"></div>
        <div>' . t('Create a Hotspot question:') . ' <input type="button" name="hs_create" value="Create" onclick="QC_CreateHS()"></div>
        <div>' . t('Create a Drag&Drop question:') . ' <input type="button" name="dd_create" value="Create" onclick="QC_CreateDD()"></div>
        <div>' . t('Create a Fillblanks question with math:') . ' <input type="button" name="fb1_create" value="Create" onclick="QC_CreateFB1()"></div>
      </div>';
  $form['body_field']['body']['#postfix'] .= '</div>';
  return drupal_render($form);
}

/**
 * Themes a CqOption for text-review.
 *
 * @param CqOption $option
 *   The CqOption to theme.
 *
 * @ingroup themeable
 */
function theme_closedquestion_option($option) {
  $retval = '';
  $retval .= t('Identifier=%i, Correct=%c', array('%i' => $option->getIdentifier(), '%c' => $option->getCorrect())) . '<br/>';
  $retval .= $option->getText();
  $description = $option->getDescription();
  if ($description) {
    $retval .= closedquestion_make_fieldset(t('Description'), $description);
  }
  $feedback = $option->getFeedbackItems();
  if (count($feedback) > 0) {
    $retval .= closedquestion_make_fieldset(t('Feedback if selected'), theme('closedquestion_feedback_list', $option->getFeedbackItems(), TRUE));
  }
  $feedback = $option->getFeedbackUnselectedItems();
  if (count($feedback) > 0) {
    $retval .= closedquestion_make_fieldset(t('Feedback if not selected'), theme('closedquestion_feedback_list', $option->getFeedbackUnselectedItems(), TRUE));
  }
  return $retval;
}

/**
 * Themes an array of CqOption (multiple choice options) for text-review.
 *
 * @param array $options
 *   Array of CqOption.
 *
 * @ingroup themeable
 */
function theme_closedquestion_option_list($options, $show_correct = TRUE) {
  $retval = '<ul>';
  foreach ($options as $option) {
    $retval .= '<li>' . theme('closedquestion_option', $option, $show_correct) . '</li>' . "\n";
  }
  $retval .= '</ul>';
  return $retval;
}

/**
 * Themes an array of CqFeedback items.
 *
 * @param array $hints
 *   Array of CqFeedback.
 * @param boolean $extendedInfo
 *   (Optional) Show extended info like tries requirements? Defaults to FALSE.
 *
 * @ingroup themeable
 */
function theme_closedquestion_feedback_list($hints, $extended_info = FALSE) {
  $retval = '';
  if (count($hints) > 0) {
    $retval .= '<ul>';
    foreach ($hints as $hint) {
      if ($extended_info) {
        $retval .= '<li>mintries=' . $hint->getMinTries() . ', maxtries=' . $hint->getMaxTries() . ':<br/>' . $hint->getText() . '</li>' . "\n";
      }
      else {
        $retval .= '<li>' . $hint->getText() . '</li>' . "\n";
      }
    }
    $retval .= '</ul>';
  }
  return $retval;
}

/**
 * Themes an array of CqInlineOption (fillblanks options) for text-review.
 *
 * @param array $options
 *   Array of CqInlineOption.
 *
 * @ingroup themeable
 */
function theme_closedquestion_inline_option_list($options) {
  $retval = '<ul>';
  foreach ($options as $option) {
    $retval .= '<li>' . $option->getGroup() . ' : ' . $option->getIdentifier() . '<br/>' . $option->getText() . '</li>' . "\n";
  }
  $retval .= '</ul>';
  return $retval;
}

/**
 * Themes a CqRange for text-review.
 *
 * @param int $correct
 *   the correct property of the range.
 * @param number $minval
 *   the correct property of the range.
 * @param number $maxval
 *   the correct property of the range.
 * @param array $feedback
 *   the feedback list of the range.
 *
 * @ingroup themeable
 */
function theme_closedquestion_range($correct, $minval, $maxval, $feedback) {
  $retval = t('Range, correct=@correct, minval=@minval, maxval=@maxval.', array(
    '@correct' => $correct,
    '@minval' => $minval,
    '@maxval' => $maxval,
    ));
  if (count($feedback) > 0) {
    $retval .= closedquestion_make_fieldset(t('Feedback'), theme('closedquestion_feedback_list', $feedback, TRUE));
  }
  return $retval;
}

/**
 * Themes an array of CqRange (match range) for text-review.
 *
 * @param array $ranges
 *   Array of CqRange.
 *
 * @ingroup themeable
 */
function theme_closedquestion_range_list($ranges) {
  $retval = '<ul>';
  foreach ($ranges as $range) {
    $retval .= '<li>' . $range->getAllText() . '</li>' . "\n";
  }
  $retval .= '</ul>';
  return $retval;
}

/**
 * Themes a CqMappingAbstract for text review.
 *
 * @param CqMappingAbstract $mapping
 *   The mapping to theme
 *
 * @ingroup themeable
 */
function theme_closedquestion_mapping_abstract($mapping) {
  if (count($mapping->feedback) > 0) {
    $retval .= closedquestion_make_fieldset(t('Feedback'), theme('closedquestion_feedback_list', $mapping->feedback, TRUE));
  }
  if (count($mapping->children)) {
    $retval .= '<ul>';
    foreach ($mapping->children as $child) {
      $retval .= '<li>' . $child->getAllText() . '</li>';
    }
    $retval .= '</ul>';
  }
  return $retval;
}

/**
 * Themes a CqMapping for text-review.
 *
 * @param CqMapping $mapping
 *   The mapping to theme.
 *
 * @ingroup themeable
 */
function theme_closedquestion_mapping($mapping) {
  $retval = t('Mapping, Correct=%cor', array('%cor' => $mapping->getCorrect())) . '<br/>';
  if (count($mapping->children)) {
    $logic = '<ul>';
    foreach ($mapping->children as $child) {
      $logic .= '<li>' . $child->getAllText() . '</li>';
    }
    $logic .= '</ul>';
    $retval .= closedquestion_make_fieldset(t('Logic'), $logic, TRUE, TRUE);
  }
  if (count($mapping->feedback) > 0) {
    $retval .= closedquestion_make_fieldset(t('Feedback'), theme('closedquestion_feedback_list', $mapping->feedback, TRUE));
  }
  return $retval;
}

/**
 * Themes an array of CqMapping for text-review.
 *
 * @param array $mappings
 *   Array of CqMapping
 *
 * @ingroup themeable
 */
function theme_closedquestion_mapping_list($mappings) {
  $retval = '<ul>';
  foreach ($mappings as $mapping) {
    $retval .= '<li>' . $mapping->getAllText() . '</li>' . "\n";
  }
  $retval .= '</ul>';
  return $retval;
}

/**
 * Themes the question part of a balance-question form.
 *
 * @param array $formpart
 *   The question part of the form.
 *
 * @ingroup themeable
 */
function theme_closedquestion_question_balance($formpart) {
  $header = array(
    t('Accumulation'),
    '=',
    t('&Sigma; Transfer'),
    '+',
    t('&Sigma; Reaction')
  );
  $rows = array();
  $row = array();
  $row[] = drupal_render($formpart['optionsacc']);
  $row[] = ' ';
  $row[] = drupal_render($formpart['optionsflow']);
  $row[] = ' ';
  $row[] = drupal_render($formpart['optionsprod']);
  $rows[] = $row;

  $form_pos = strpos($formpart['questionText']['#value'], '<formblock/>');
  if ($form_pos !== FALSE) {
    $pre_form = substr($formpart['questionText']['#value'], 0, $form_pos);
    $post_form = substr($formpart['questionText']['#value'], $form_pos + 12);
  }
  else {
    $pre_form = $formpart['questionText']['#value'];
    $post_form = '';
  }

  $html = '';
  $html .= $pre_form;
  $html .= theme_table($header, $rows, array('class' => 'cqTable'));
  $html .= $post_form;

  return $html;
}

/**
 * Themes the question part of a check-question form.
 *
 * @param array $formpart
 *   The question part of the form.
 *
 * @ingroup themeable
 */
function theme_closedquestion_question_check($formpart) {

  $html = '';
  $html .= drupal_render($formpart['questionText']);
  $html .= drupal_render($formpart['options']);

  return $html;
}

/**
 * Themes the question part of a drag&drop-question form.
 *
 * @param array $formpart
 *   The question part of the form, containing:
 *   - questionText: Drupal form-field with the quetsion text.
 *   - data['#value']: associative array with content:
 *     - elementname: The base-name used for form elements that need to be
 *         accessed by javascript.
 *     - mapname: The name of the imagemap to use.
 *     - image
 *       - url: the url of the image to use.
 *       - height: the height of the image to use.
 *       - width: the height of the image to use.
 *     - hotspots: array containing the hotspots, each containing:
 *       - termid: the id of the hotspot.
 *       - maphtml: the imagemap "area" html for this hotspot.
 *       - description: the description of the hotspot.
 *     - draggables: array containing the draggables, each containing:
 *       - cqvalue: the identifier of the draggable.
 *       - x: the x coordinate of the draggable.
 *       - y: the y coordinate of the draggable.
 *
 * @ingroup themeable
 */
function theme_closedquestion_question_drag_drop($formpart) {
  jquery_ui_add(array('ui.sortable', 'ui.draggable', 'ui.droppable'));
  drupal_add_js(drupal_get_path('module', 'closedquestion') . '/assets/closedquestion_dd.js');

  $data = $formpart['data']['#value'];

  $form_pos = strpos($formpart['questionText']['#value'], '<formblock/>');
  if ($form_pos !== FALSE) {
    $pre_form = substr($formpart['questionText']['#value'], 0, $form_pos);
    $post_form = substr($formpart['questionText']['#value'], $form_pos + 12);
  }
  else {
    $pre_form = $formpart['questionText']['#value'];
    $post_form = '';
  }

  $html = '';
  $html .= $pre_form;

  $html .= '<div id="' . $data['elementname'] . 'answerContainer" class="cqMatchImgBox">' . "\n";
  $html .= '<img usemap="#' . $data['mapname'] . '" src="' . $data['image']['url'] . '" />' . "\n";

  $start_positions = array(); // Starting positions of the draggables.
  foreach ($data['draggables'] as $id => $draggable) {
    $html .= '  <div cqvalue="' . $id . '" class="' . $draggable['class'] . '">' . $draggable['text'] . '</div>' . "\n";
    // Add the draggable starting position to the javascript settings.
    $start_positions[] = array(
      'cqvalue' => $draggable['cqvalue'],
      'x' => $draggable['x'],
      'y' => $draggable['y'],
    );
  }

  $settings['closedQuestion']['dd'][$data['elementname']]['ddDraggableStartPos'] = $start_positions;
  $settings['closedQuestion']['dd'][$data['elementname']]['ddImage'] = array(
    "height" => $data['image']['height'],
    "width" => $data['image']['width'],
    "url" => $data['image']['url'],
  );

  $html .= '</div>' . "\n";
  $map_html = '';
  $map_html .= '<map name="' . $data['mapname'] . '">' . "\n";
  foreach ($data['hotspots'] as $id => $hotspot) {
    if (!empty($hotspot['description'])) {
      $map_html .= '<area id="' . $hotspot['termid'] . '" ' . $hotspot['maphtml'] . ' href="javascript: void(0)" />' . "\n";
      $html .= '<div target="' . $hotspot['termid'] . '" class="hovertip">' . $hotspot['description'] . '</div>' . "\n";
    }
  }
  $map_html .= '</map>' . "\n";

  $html .= $map_html;
  $html .= $post_form;

  drupal_add_js($settings, 'setting');

  return $html;
}

/**
 * Themes in inline choice as a dropdown selection, or a free-form text box.
 *
 * @param array $choice
 *   Associative array with the choice parameters:
 *   - name: string, name to use for the input element.
 *   - group: string, group the options belong to.
 *   - style: string, style to use for the input element
 *   - class: string, class to use for the input element.
 *   - size: int, size attribute to use for the input element.
 *   - freeform: int, 1: style as textbox, other: style as selectbox.
 *   - options: array of CqInlineOption, the options to give the user.
 *   - value: currently selected/given answer.
 *
 * @ingroup themeable
 */
function theme_closedquestion_inline_choice($choice) {
  $html = '';

  $style_html = '';
  if (!empty($choice['style'])) {
    $style_html = ' style=' . $choice['style'];
  }
  $class_html = '';
  if (!empty($choice['class'])) {
    $class_html = ' class=' . $choice['class'];
  }

  if ($choice['freeform']) {
    $html .= '<input type="text" name="' . $choice['name'] . '" value="' . $choice['value'] . '"' . $style_html . $class_html . ' size="' . $choice['size'] . '" />';
  }
  else {
    $html .= '<select name="' . $choice['name'] . '" size="1"' . $style_html . $class_html . '>';
    if (is_array($choice['options']) && count($choice['options']) > 0) {
      foreach ($choice['options'] AS $option_id => $option) {
        $selected_tag = '';
        if ($choice['value'] == $option_id) {
          $selected_tag = ' selected';
        }
        $html .= '<option' . $selected_tag . ' value="' . $option_id . '">' . $option->getText() . '</option>';
      }
    }
    else {
      drupal_set_message(t('inlineChoice with id "%id" has no options.', array('%id' => $choice['id'])), 'warning');
    }
    $html .= '</select>';
  }
  return $html;
}

/**
 * Themes the question part of a hotspot-question form.
 *
 * @param array $formpart
 *   The question part of the form, containing:
 *   - questionText: Drupal form-field with the quetsion text.
 *   - data['#value']: associative array with content:
 *     - elementname: the base-name used for form elements that need to be
 *         accessed by javascript.
 *     - mapname: the name of the imagemap to use.
 *     - crosshairurl: the url of the crosshair image to use.
 *     - image
 *       - url: the url of the image to use.
 *       - height: the height of the image to use.
 *       - width: the height of the image to use.
 *     - hotspots: array containing the hotspots, each containing:
 *       - termid: the id of the hotspot.
 *       - maphtml: the imagemap "area" html for this hotspot.
 *       - description: the description of the hotspot.
 *     - draggables: array containing the draggables, each containing:
 *       - cqvalue: the identifier of the draggable.
 *       - x: the x coordinate of the draggable.
 *       - y: the y coordinate of the draggable.
 *
 * @ingroup themeable
 */
function theme_closedquestion_question_hotspot($formpart) {
  jquery_ui_add(array('ui.sortable', 'ui.draggable', 'ui.droppable'));
  drupal_add_js(drupal_get_path('module', 'closedquestion') . '/assets/closedquestion_hs.js');

  $data = $formpart['data']['#value'];

  $form_pos = strpos($formpart['questionText']['#value'], '<formblock/>');
  if ($form_pos !== FALSE) {
    $pre_form = substr($formpart['questionText']['#value'], 0, $form_pos);
    $post_form = substr($formpart['questionText']['#value'], $form_pos + 12);
  }
  else {
    $pre_form = $formpart['questionText']['#value'];
    $post_form = '';
  }

  $html = '';
  $html .= $pre_form;

  $html .= '<div id="' . $data['elementname'] . 'answerContainer" class="cqMatchImgBox">' . "\n";
  $html .= '<img usemap="#' . $data['mapname'] . '" src="' . $data['image']['url'] . '" />' . "\n";

  $start_positions = array(); // Starting positions of the draggables.
  if (isset($data['draggables'])) {
    foreach ($data['draggables'] as $id => $draggable) {
      $html .= '  <div cqvalue="' . $draggable['cqvalue'] . '" class="' . $draggable['class'] . '"><img src="' . $data['crosshairurl'] . '" /></div>' . "\n";
      // Add the draggable starting position to the javascript settings.
      $start_positions[] = array(
        'cqvalue' => $draggable['cqvalue'],
        'x' => $draggable['x'],
        'y' => $draggable['y'],
      );
    }
  }

  $settings['closedQuestion']['hs'][$data['elementname']]['ddDraggableStartPos'] = $start_positions;
  $settings['closedQuestion']['hs'][$data['elementname']]['ddImage'] = array(
    "height" => $data['image']['height'],
    "width" => $data['image']['width'],
    "url" => $data['image']['url'],
  );
  $settings['closedQuestion']['hs'][$data['elementname']]['maxChoices'] = $data['maxchoices'];
  $settings['closedQuestion']['hsimage'] = $data['crosshairurl'];

  $html .= '</div>' . "\n";
  $map_html = '';
  $map_html .= '<map name="' . $data['mapname'] . '">' . "\n";
  if (isset($data['hotspots'])) {
    foreach ($data['hotspots'] as $id => $hotspot) {
      if (!empty($hotspot['description'])) {
        $map_html .= '<area id="' . $hotspot['termid'] . '" ' . $hotspot['maphtml'] . ' href="javascript: void(0)" />' . "\n";
        $html .= '<div target="' . $hotspot['termid'] . '" class="hovertip">' . $hotspot['description'] . '</div>' . "\n";
      }
    }
  }
  $map_html .= '</map>' . "\n";

  $html .= $map_html;
  $html .= $post_form;

  drupal_add_js($settings, 'setting');

  return $html;
}

/**
 * Themes the question part of a select&order-question form.
 *
 * @param array $formpart
 *   The question part of the form, containing:
 *   - questionText: Drupal form-field with the quetsion text.
 *   - data['#value']: associative array with content:
 *     - elementname: The base-name used for form elements that need to be
 *         accessed by javascript.
 *     - duplicates: Are duplicates allowed?
 *     - alignment: string "horizontal" or "normal".
 *     - optionHeight: Minimal height to use for items to force nice alignment if
 *         contents are of varying height, or boolean FALSE if not set.
 *     - sourceTitle: title of the source-section
 *     - unselected: array of items, each one containing:
 *       - identifier: item identifier.
 *       - text: item text.
 *       - description: item description.
 *     - sections: array of target sections, each one containing:
 *       - identifier: section identifier.
 *       - text: section title.
 *       - items: array of items, each one containing:
 *         - identifier: item identifier.
 *         - text: item text.
 *         - description: item description.
 *
 * @ingroup themeable
 */
function theme_closedquestion_question_select_order($formpart) {
  drupal_add_js(drupal_get_path('module', 'closedquestion') . '/assets/closedquestion_so.js');
  jquery_ui_add(array('ui.sortable', 'ui.draggable'));

  $form_pos = strpos($formpart['questionText']['#value'], '<formblock/>');
  if ($form_pos !== FALSE) {
    $pre_form = substr($formpart['questionText']['#value'], 0, $form_pos);
    $post_form = substr($formpart['questionText']['#value'], $form_pos + 12);
  }
  else {
    $pre_form = $formpart['questionText']['#value'];
    $post_form = '';
  }

  $html = '';
  $html .= $pre_form;

  $data = $formpart['data']['#value'];

  if ($data['duplicates']) {
    $sourceclass = 'cqDDList cqCopyList cqNoDel';
    $targetclass = 'cqDDList cqDropableList';
  }
  else {
    $sourceclass = 'cqDDList cqDropableList cqNoDel';
    $targetclass = 'cqDDList cqDropableList cqNoDel';
  }

  $html .= '<div class="cqSo' . drupal_ucfirst($data['alignment']) . '">' . "\n";
  $html .= '<div class="cqSources" id="' . $data['elementname'] . 'sources">' . "\n";
  $html .= '  <div class="cqSource">' . "\n";
  $html .= '    <p>' . $data['sourceTitle'] . '</p>' . "\n";
  $html .= '<ul id="' . $data['elementname'] . 'source" class="' . $sourceclass . '">' . "\n";
  if (isset($data['unselected'])) {
    foreach ($data['unselected'] as $item) {
      $html .= cq_make_li($item['identifier'], $item['text'], $item['description'], $data['optionHeight']);
    }
  }
  $html .= '<div class="cqSoClear"></div>' . "\n"; // To make sure that with horizontal alignment the ul encloses the li's
  $html .= '</ul>' . "\n";
  $html .= '</div>' . "\n";
  $html .= '</div>' . "\n";

  $html .= '<div class="cqTargets" id="' . $data['elementname'] . 'targets">' . "\n";
  foreach ($data['sections'] as $section_selected) {
    $html .= '  <div class="Cqtarget">' . "\n";
    $html .= '    <p>' . $section_selected['text'] . '</p>' . "\n";
    $html .= '    <ul class="' . $targetclass . '" cqvalue="' . $section_selected['identifier'] . '">' . "\n";
    foreach ($section_selected['items'] as $item) {
      $html .= cq_make_li($item['identifier'], $item['text'], $item['description'], $data['optionHeight']);
    }
    $html .= '    </ul>' . "\n";
    $html .= '  </div>' . "\n";
  }
  $html .= '</div>' . "\n"; // cqSource
  $html .= '</div>' . "\n"; // CqSO_normal

  $html .= '<div style="clear: left;">' . "\n";
  $html .= '</div>' . "\n";
  $html .= $post_form;

  return $html;
}

/**
 * Helper function to make one item for a select&order question
 *
 * @param string $identifier
 *   The item's identifier
 * @param string $text
 *   The item's html content
 * @param string $description
 *   The item's extra description (put in a hovertip popup)
 * @param mixed $height
 *   Minimal height to use for items to force nice alignment if contents are of
 *   varying height, or boolean FALSE if not set.
 *
 * @return string
 *   The html for one item.
 */
function cq_make_li($identifier, $text, $description, $height=FALSE) {
  $retval = '';
  $style = '';
  if ($height) {
    $style = ' style="height: ' . $height . '"';
  }
  $retval .= '<li class="cqDraggable" cqvalue="' . $identifier . '" ' . $style . '>';
  if (!empty($description)) {
    $retval .= '<span>' . $text . '</span>';
    $retval .= '<span class="hovertip">' . $description . '</span>';
  }
  else {
    $retval .= $text;
  }
  $retval .= '</li>' . "\n";
  return $retval;
}

/**
 * Themes a sequence question.
 *
 * @param string $curQuestion
 *   The html output for the current question.
 * @param string $backNext
 *   The html of the back/next link.
 * @param string $prefix
 *   The question's html prefix.
 * @param string $postfix
 *   The question's html postfix.
 *
 * @ingroup themeable
 */
function theme_closedquestion_question_sequence($cur_question, $back_next, $prefix, $postfix) {
  $html = '';
  $html .= '<h2>' . $back_next . '</h2>';
  $html .= $prefix;
  $html .= $cur_question;
  $html .= $postfix;
  return $html;
}

/**
 * Themes the back/next links for the sequence question.
 *
 * @param int $index
 *   The index of the current sub-question.
 * @param int $total
 *   The total number of sub-questions.
 * @param string $prev_url
 *   The url to the previous sub-question.
 * @param string $next_url
 *   The url to the next sub-question.
 *
 * @ingroup themeable
 */
function theme_closedquestion_sequence_back_next($index, $total, $prev_url, $next_url) {
  $html = '';
  $html .= t('This is part @part of a @total part question.', array('@part' => ($index + 1), '@total' => $total));
  if ($prev_url) {
    $html .= ' ' . t('[ <a href="@prevurl">Previous Step</a> ]', array('@prevurl' => $prev_url));
  }
  if ($next_url) {
    $html .= ' ' . t('[ <a href="@nextUrl">Next Step</a> ]', array('@nextUrl' => $next_url));
  }
  return $html;
}
