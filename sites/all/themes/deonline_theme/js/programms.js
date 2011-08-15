/**
 * Created by JetBrains PhpStorm.
 * User: goruha
 * Date: 8/4/11
 * Time: 9:02 PM
 * To change this template use File | Settings | File Templates.
 */


Drupal.behaviors.deonline_programms = function(context) {
  var image = $("#gruen-image", context);
  deonline_set_default_img(image);
  
  $("div.view-program-types div.views-row", context).mouseenter(function() {
    var image = $("#gruen-image", context);
    var postion = $(this).position();
    image.css({"position": "relative", "top": postion.top - image.height(), "left": postion.left});
    $('#program-descirption').html($('.info', $(this)).html());
  });

  $("div.view-program-types div.views-row", context).mouseleave(function() {
    var image = $("#gruen-image", context);
    deonline_set_default_img(image);
  });

  $('.view-program-types .equal-height').equalHeights();
}

function deonline_set_default_img(image) {
  var width =  image.parent().width();
  var height = image.parent().height();
  image.css({"position": "relative", "top": height - image.height(), "left": 0});
  $('#program-descirption').html('');
}

