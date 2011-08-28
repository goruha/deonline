// $Id: node_wizard.js,v 1.2 2010/11/19 13:09:21 vladsavitsky Exp $

/**
 * @file node_wizard.js
 **/

Drupal.behaviors.node_wizard  = function(context) {
  //Disable buttons label input fields if choosen use fieldset labels for buttons
  $('input[name=node_wizard_use_fieldset_labels]').change(function(){
    var checked = 0;
    $('input[name=node_wizard_use_fieldset_labels]:checked').each(function() {
        checked = 1;
    });
    if (checked) {
      $('#edit-node-wizard-button-previous-label').attr('disabled', 'disabled');
      $('#edit-node-wizard-button-next-label').attr('disabled', 'disabled');
      $('#edit-node-wizard-button-done-label').attr('disabled', 'disabled');
    }
    else {
      $('#edit-node-wizard-button-previous-label').removeAttr('disabled');
      $('#edit-node-wizard-button-next-label').removeAttr('disabled');
      $('#edit-node-wizard-button-done-label').removeAttr('disabled');
    }
  });

   

//Disable "Use this group name as a label for buttons" if group will be shown at every step
  $('#edit-settings-node-wizard-step').change(function(){
    if ($(this).val() == 0) {
      $('#edit-settings-node-wizard-button-label').attr('disabled', 'disabled')
      $('#edit-settings-node-wizard-button-label-wrapper').hide();
    }
    else {
      $('#edit-settings-node-wizard-button-label').removeAttr('disabled');
      $('#edit-settings-node-wizard-button-label-wrapper').show();
    }
  });
  $('#edit-settings-node-wizard-step').change();
  
};


