/**
 * Created by JetBrains PhpStorm.
 * User: goruha
 * Date: 7/28/11
 * Time: 11:42 PM
 * To change this template use File | Settings | File Templates.
 */


Drupal.behaviors.drupal_atooltip = function(context) {
  $('.atooltip').each(function () {
    $(this).aToolTip({
      // no need to change/override
      closeTipBtn: 'aToolTipCloseBtn',
      toolTipId: 'aToolTip',
      // ok to override
      fixed: true,                   // Set true to activate fixed position
      clickIt: true,                 // set to true for click activated tooltip
      inSpeed: 200,                   // Speed tooltip fades in
      center: true,
      outSpeed: 100,                  // Speed tooltip fades out
      tipContent: 'Hello I am aToolTip with content from param',
      toolTipClass: 'defaultTheme'   // Set class name for custom theme/styles
    });
  });
}

jQuery.fn.center = function () {
    this.css("position","absolute");

    return this;
}
