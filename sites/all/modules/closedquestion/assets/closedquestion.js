
/**
 *@file
 *Javascript functions for the Drag&Drop questions.
 */

/**
 * Attach the code that puts in-line feedback in the right spot to a Drupal
 * behaviour.
 */
Drupal.behaviors.closedQuestion = function (context) {
  jQuery('#closedquestion-get-form-for input').attr('autocomplete', 'off');
  cqMoveFeedback(context);
};

/**
 * Function that moves feedback from the general feedback area to the correct
 * place in the question.
 *
 * It clears out all existing feedback first, so only the new feedback is
 * visible.
 */
function cqMoveFeedback(context) {
  $(".cqFbBlock").empty();
  $(".cqFbItem", context).filter("[class*=block-]").each(function(index, Element){
    var fbItem = $(this);
    var parent = fbItem.parent();
    var fieldSet = parent.parent();
    var classString = fbItem.attr("class");
    var pos1 = classString.indexOf("block-");
    var pos2 = classString.indexOf(" ", pos1 + 6);
    if (pos2 < 0) {
      pos2 = classString.length;
    }
    var targetId = classString.substr(pos1 + 6, pos2 - pos1);
    var targetBlock = $(".cqFbBlock.cqFb-" + targetId + "");
    targetBlock.append(fbItem);
    parent.remove();
    if (fieldSet.children().length <= 1) {
      fieldSet.hide();
    }
  })
}
