
(function ($) {

  // Initialize Administer Tool Tip Drag N Drop.
  Drupal.behaviors.administerToolTip_dragAndDrop = function(context) {
    Drupal.administerToolTip_dragAndDrop.initializeDragAndDrop();
  };

  /**
   * Create the administertooltip drag and drop (att_dnd) object.
   */
  Drupal.administerToolTip_dragAndDrop = {
    // Array containing all theme's regions.
    regions: [],

    // Comma separated tring with regions of this theme.
    regions_string: '',

    // Boolean to make sure we use the ajax call once.
    save_blocks: false,

    /**
     * Simple wrapper function to enable drag and drop.
     */
    initializeDragAndDrop: function() {
      this.getRegions();
      this.createSortable();
    },

    /**
     * Find all the regions within this theme that has an id.
     * (Only those are the ones that are supported!).
     */
    getRegions: function() {
      var obj = this;
      $("span[administertooltip-region]").each(function(i) {
        var id = $(this).parents('div[id]').attr('id');
        if(id != "") obj.regions[obj.regions.length] = "#"+id;
      });
      this.regions_string = this.regions.join(',');
    },

    /**
     * Create a new sortable from the JQueryUI library.
     */
    createSortable: function() {
      if(this.regions_string == '') {
        return;
      }
      var obj = this;
      $(this.regions_string).sortable({
        cursor: 'move',
        handle: '.administertooltip_dragger',
        items: '.administertooltip_wrapper',
        helper: 'clone', // The administertooltip selection rectangle is buggy on 'original'.
        tolerance: 'pointer', // Div's get strange sizes on different regions, pointer is therefor better.
        connectWith: obj.regions,
placeholder: 'administertooltip_placeholder',
forcePlaceholderSize: true,

        // Remove the messages when you begin dragging again.
        start: function(event, ui) {
          $("#administertooltip_messages").fadeOut(250);
          // Show region titles.
          $(".administertooltip_region").addClass('administertoolregion_hover').fadeIn(190);
        },
        // When the mouse is released we need to save the new blocks.
        update: function(event, ui) {
          obj.att_dnd_update(ui.item);
        },
        stop: function(event, ui) {
          // Remove the region titles.
          $(".administertooltip_region").removeClass('administertoolregion_hover').hide();
        }
      });
    },

    /**
     * When the mouse is released we need to save the new blocks.
     */
    att_dnd_update: function (obj) {
      if(this.save_blocks) return;

      // Find out the information of the block.
      this.save_blocks = true;
      var region = $(obj).parent().find('span[administertooltip-region]').eq(0);
      var region_id = region.parents('div[id]').attr('id');
      var region_name = region.attr('administertooltip-region');
      if (region_id == '') { return; }

      // Get the new order of blocks within this region.
      var result = $("#"+region_id).sortable('toArray');
      var blocks = '';
      for(var i in result) {
        if(result[i] != "") { // We do not want the empty items in the array.
          var block_info = $("#"+result[i]).find('.administertooltip_dragger').eq(0);
          // Use the strange attributes of the dragger div to find out which block we are dealing with.
          if(block_info != undefined && block_info.attr('id') != undefined && block_info.attr('nr') != undefined) {
            blocks += block_info.attr('id')+":"+block_info.attr('nr')+";";
          }
        }
      }

      // Start ajax-call to module.
      if(blocks != '') {
        $(this.regions_string).sortable({ disabled: true });
        var i = this;
        $.get(Drupal.settings.basePath+'administertooltip/update', {'entity':'block','blocks': blocks,'region':region_name}, function(data) {
          var result = Drupal.parseJson(data);
          if(result.status == "ok") {
            $("#administertooltip_messages").html('<div class="messages info">'+Drupal.t('New order set.')+'</div>');
            // Nice little "delay"-trick because we use jquery < 1.4.
            $("#administertooltip_messages").fadeIn(80).animate({opacity: 1.0}, 2000).fadeOut(100);
            $(i.regions_string).sortable({ disabled: false });
          } else {
            alert(result.status);
          }
          i.save_blocks = false;
        });
      }
    }

  };

})(jQuery);
