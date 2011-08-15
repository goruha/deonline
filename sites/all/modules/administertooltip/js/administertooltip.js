
(function ($) {

  // Initialize Administer Tool Tip.
  Drupal.behaviors.administerToolTip = function(context) {
    Drupal.administerToolTip.initializeTooltips();
  };

  /**
   * Create the administertooltip (att) object.
   */
  Drupal.administerToolTip = {
    // Array of tooltips with content for objects.
    tooltips: {},

    // Objects containing icons with click to tooltip.
    objects: {},

    // Default beautytips options.
    btoptions: {
      shadow:               true,
      closeWhenOthersOpen:  true,
      shadowOffsetX:        3,
      shadowOffsetY:        3,
      shadowBlur:           12,
      shadowColor:          'rgba(0,0,0,.25)',
      shadowOverlap:        false,
      trigger:              ['click'],
      padding:              '0px',
      spikeGirth:           20,
      spikeLength:          15,
      strokeWidth:          0,
      width:                '250px',
      fill:                 'rgba(161, 218, 248,1)',
      cornerRadius:         0,
      cssClass:             'btwrapper',
      showTip: function(box) {
        $(box).fadeIn(90);
        // The label makes the tip disapear when clicked. So here's a work-a-round.
        var wrap = $('<div style="position:relative"></div>');
        var frame = $('<div style="position:absolute;width:14px;height:14px;">&nbsp;</div>');
        $('.bt-content label:has(input[@type=checkbox])').wrap(wrap).before(frame).click(function(event) {
          if (!$(event.target).is('input')) { // Not for the input itself.
            var c = $(this).find('input[@type=checkbox]:checked').val();
            $(this).find('input[@type=checkbox]').attr('checked', !c);
            event.preventDefault();
          }
        });
        frame.click(function(event) { // The input itself behaves weird on firefox, therefor the extra div above it.
          var c = $(this).siblings('label').find('input[@type=checkbox]:checked').val();
          $(this).siblings('label').find('input[@type=checkbox]').attr('checked', !c);
        });
      }
    },

    /**
     * Simple wrapper function to create the ATT.
     */
    initializeTooltips: function() {
      this.findTooltips();
      this.findObjects();
      this.addIcons();
      this.addHover();
      this.addBT();
    },

    /**
     * Easy function to get all tooltips.
     */
    findTooltips: function() {
      this.tooltips = $(".administertooltip");
    },

    /**
     * For each tooltip we find it's object.
     * This can be a parent div, but it could be much higher up the tree.
     * Themes are thus required to use the 'block'- and 'node'-classnames!
     */
    findObjects: function() {
      this.tooltips.each(function(i) {
        // Default it is it's parent.
        var wrapper;
        var object = $(this).parent();

        // Try to find the "main"-div of the block.
        if($(this).hasClass('administertooltip-for-block')) {
          object = $(this).parents('.block').eq(0);
        }
        // Node object needs the parent of the parent.
        else if($(this).hasClass('administertooltip-for-node')) {
          object = $(this).parents('.node').eq(0);
        }
        // Views' tip needs also the parent of the parent.
        else if($(this).parent().hasClass('view-footer')) {
          object = $(this).parent().parent();
        }

        // Wrap the object with our own div, it needs a id for the sortable.
        object.wrap('<div id="att_'+i+'" class="administertooltip_wrapper" />');

        // Add some data to the wrapper.
        wrapper = object.parents('.administertooltip_wrapper').eq(0);
        wrapper.tooltip = $(this).attr('administertooltip_id', i);

        // The wrapper gets a float if the object has a float.
        if (object.css('float') != 'none') {
          wrapper.css('float', object.css('float'));
        }

        // The wrapper gets a width if the object is a span.
        if ($(object).get(0) && $(object).get(0).tagName.toLowerCase() == 'span') {
          wrapper.width(object.outerWidth());
        }
        Drupal.administerToolTip.objects[i] = wrapper;
      });
    },

    /**
     * Function to add hidden icons to objects. They will be shown on mouse over.
     * The handle gets a specific click-function to open the beautytip.
     * The dragger gets a handler to hide all beautytips. You won't use it while dragging.
     */
    addIcons: function() {
      $.each(this.objects, function(i) {
        var obj = this;
        $(this).append($(this.tooltip).children('.administertooltip_icons').eq(0).remove());
        $(this).attr('administertooltip_for', i);
        this.icons = $(this).children('.administertooltip_icons').eq(0);
        this.icons.handle = $(this.icons).children('.administertooltip_handle').eq(0).attr('administertooltip_for', i);
        this.icons.dragger = $(this.icons).children('.administertooltip_dragger').eq(0).mousedown(function() {
          $(jQuery.bt.vars.closeWhenOpenStack).btOff();
        });
      });
    },

    /**
     * The hover function on each object changes the class and the visibility of the icons.
     */
    addHover: function() {
      $.each(this.objects, function(i) {
        var obj = this;
        $(this).hover(
          function() {
            $(this).addClass('administertooltip_hover');
            $(obj.icons).show();
          },
          function() {
            $(this).removeClass('administertooltip_hover');
            $(obj.icons).hide();
          }
        );
      });
    },

    /**
     * This function adds a beautytip to the object, and adds the content of the tooltip to it.
     */
    addBT: function() {
      var options = jQuery.extend(true, {}, this.btoptions);
      $.each(this.objects, function(i) {
        options.contentSelector = "$('[administertooltip_id=' +$(this).attr('administertooltip_for')+ ']')";
        // QUIRK
        options.offsetParent = $('body');
        $(this.icons.handle).bt(options);
      });
    }

  };

})(jQuery);
