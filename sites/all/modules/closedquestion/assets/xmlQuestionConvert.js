/**
 * @file
 * ClosedQuestion specific functions for the xmlEditor.
 */

// Bind our jQuery 1.4 to the CQ_jQuery var so the original drupal version is
// put back as jQuery and $
var CQ_jQuery = jQuery.noConflict();

/**
 * Set the sizes of the editor divs.
 */
function CQ_SizeEditors() {
  var divider = CQ_jQuery('#xmlJsonEditor_divider');
  var div_offset = divider.offset();
  var container = CQ_jQuery('#xmlJsonEditor_container');
  var cont_offset = container.offset();
  var tree = CQ_jQuery('#xmlJsonEditor_tree_container');
  var tree_offset = tree.offset();
  var editor = CQ_jQuery('#xmlJsonEditor_editor');
  var editor_offset = editor.offset();
  var width = container.width();
  var left = div_offset.left - cont_offset.left;
  var right = width - left - divider.width();
  divider.css('position', 'relative');
  tree.css('position', 'relative');
  editor.css('position', 'relative');
  tree_offset.top = cont_offset.top;
  editor_offset.top = cont_offset.top;
  div_offset.top = cont_offset.top;
  tree.width(left);
  tree.offset(tree_offset);
  divider.offset(div_offset);
  editor_offset.left = cont_offset.left + left + divider.width();
  editor.width(right);
  editor.offset(editor_offset);
}

/**
 * Select the tab that should be initially selected.
 * This is called by Drupal.behaviours.
 */
function CQ_InitialView(context) {
  var bodyField = CQ_jQuery("#edit-body", context);
  if (bodyField.length > 0) {
    if (bodyField[0].value.length > 0) {
      CQ_ShowTree();
    }
    else {
      CQ_ShowTemplates()
    }
  }
}

/**
 * Shows the editor tab, loads the current XML into the editor and hides the
 * XML and templates tabs.
 */
function CQ_ShowTree() {
  CQ_jQuery('#xmlJsonEditor_tree').addClass('xmlJsonEditor_activeTab');
  CQ_jQuery('#xmlJsonEditor_tree').removeClass('xmlJsonEditor_inactiveTab');
  CQ_jQuery('#xmlJsonEditor_xml').addClass('xmlJsonEditor_inactiveTab');
  CQ_jQuery('#xmlJsonEditor_xml').removeClass('xmlJsonEditor_activeTab');
  CQ_jQuery('#xmlJsonEditor_templates').addClass('xmlJsonEditor_inactiveTab');
  CQ_jQuery('#xmlJsonEditor_templates').removeClass('xmlJsonEditor_activeTab');

  CQ_jQuery('#edit-body-wrapper').css('display', 'none');
  CQ_jQuery('#xmlJsonEditor_container').css('display', 'block');
  CQ_jQuery('#xmlJsonEditor_template_container').css('display', 'none');

  CQ_XML_config.basePath = Drupal.settings.closedquestion.basePath;
  CQ_jQuery('#xmlJsonEditor_tree_container').xmlTreeEditor('init', '#xmlJsonEditor_editor', jQuery('#edit-body')[0].value, CQ_XML_config);
  CQ_jQuery('#xmlJsonEditor_tree_container').xmlTreeEditor('bind', 'change', function(data) {
    CQ_jQuery("#edit-body")[0].value = CQ_jQuery('#xmlJsonEditor_tree_container').xmlTreeEditor('read');
  });

  CQ_jQuery("#xmlJsonEditor_container").resizable({
    resize: function(event, ui) {
      CQ_SizeEditors();
    }
  });
  CQ_jQuery("#xmlJsonEditor_divider").draggable({
    axis: "x",
    containment: "parent",
    start: function(event, ui) {
      CQ_jQuery("#xmlJsonEditor_container").disableSelection();
      return true;
    },
    stop: function(event, ui) {
      CQ_SizeEditors();
      CQ_jQuery("#xmlJsonEditor_container").enableSelection();
      return true;
    }
  });

  var container = CQ_jQuery('#xmlJsonEditor_container');
  container.width(container.width());
  CQ_SizeEditors();
  /**
   * plugin matchImg editor
   */

  /* bind to before load editor */
  CQ_jQuery('#xmlJsonEditor_tree_container').xmlTreeEditor('bind', 'onLoadEditor', function(data) {
    var miEditorConfig = {};
    var matchImage, matchImageData, imageSrc, hotspotIdInput;

    jQuery('.matchImgEditor').remove();

    if (data.type == "hotspot") {
      matchImage = CQ_jQuery('#xmlJsonEditor_tree_container').xmlTreeEditor('search', 'matchimg');
      if (matchImage[0] != undefined) {
        matchImageData = matchImage[0].data();
        imageSrc = matchImageData.jstree.attributes.src;
        if (imageSrc != undefined) {
          miEditorConfig.imageURL = CQ_ParseText(imageSrc, '#xmlJsonEditor_container');
        }
      }
      var shapeSelect = jQuery(data.editorElements.forElement.attributeEditorElements).find("#xmlEditor_shape")[0];
      var coordsFormElement = jQuery(data.editorElements.forElement.attributeEditorElements).find("#xmlEditor_coords")[0];
      var shape = jQuery(shapeSelect).val();
      var coords = jQuery(coordsFormElement).val();

      miEditorConfig.imageFormElements = data.editorElements.forElement.attributeEditorElements;
      miEditorConfig.shapeSelect = shapeSelect;
      miEditorConfig.mode = 'edit hotspot';
      /* create matchImgEditor */
      var miEditor = new matchImgEditor(jQuery('#editor_values'), miEditorConfig);

      //set the selected shape
      jQuery(shapeSelect).change(function() {
        miEditor.clearCanvas();
        miEditor.setCurrentShape(jQuery(this).val());
      })
      miEditor.clearCanvas();
      miEditor.setCurrentShape(shape);

      //draw the shape
      if (coords != '') {
        miEditor.loadShape({
          "shape": shape,
          "coords":coords
        });
      }

      /* bind to ondrawshape event to detect changes */
      miEditor.bind('onDrawShape', function (hotspotData) {
        var dataAsString = '';
        var dataAsArray = [];

        switch (hotspotData.shape) {
          case 'circle':
            dataAsString = parseInt(hotspotData.coords.x) + ',' + parseInt(hotspotData.coords.y) + ',' + hotspotData.radius;
            break;

          default:
            jQuery(hotspotData.coords).each(function () {
              dataAsArray.push(parseInt(this.x) + ',' + parseInt(this.y));
            });
            dataAsString = dataAsArray.join(',');
            break;
        }

        jQuery(coordsFormElement).val(dataAsString);
      });
      return false;

    }
    else if (data.type == "match") {
      miEditorConfig = {};
      var parent = CQ_jQuery('#xmlJsonEditor_tree_container').xmlTreeEditor('closest', data.treeNode, 'question');
      matchImage = CQ_jQuery('#xmlJsonEditor_tree_container').xmlTreeEditor('search', 'matchimg', {
        "parent": parent
      });
      if (matchImage[0] != undefined) {
        matchImageData = matchImage[0].data();
        imageSrc = matchImageData.jstree.attributes.src;
        if (imageSrc != undefined) {
          miEditorConfig.imageURL = CQ_ParseText(imageSrc, '#xmlJsonEditor_container');
        }
      }
      miEditorConfig.imageFormElements = data.editorElements.forElement.attributeEditorElements;
      miEditorConfig.shapeSelect = shapeSelect;
      miEditorConfig.mode = 'view hotspots';

      /* create matchImgEditor */
      miEditor = new matchImgEditor(jQuery('#editor_values'), miEditorConfig);
      if (miEditor.config.imageURL == undefined) {
        return true;
      }

      /* get hotspots, and draw them on the image */
      var hotspots = CQ_jQuery('#xmlJsonEditor_tree_container').xmlTreeEditor('search', 'hotspot');
      var hotspotTitleIds = [];
      // Time is used to create unique id's
      var time = new Date().getTime();
      jQuery(hotspots).each(function() {
        /* get data */
        var hotspotsData = this.data().jstree.attributes;

        //keep track of titles, so we can update them when matched
        var hotspotTitleId = 'xmlEditor_' + time + '_' + hotspotsData.id;
        hotspotTitleIds.push(hotspotTitleId);

        /* add to editor */
        miEditor.loadShape({
          "shape" : hotspotsData.shape,
          "coords" : hotspotsData.coords,
          "title" : '<span id="' + hotspotTitleId + '">' + hotspotsData.id + '</span>'
        }, true);

      });

      /* let the hotspot id input tell us when its contents change, and update
       * the corresponding shapes in the editor
       * TODO: fix selector by giving input fields proper id's
       */
      hotspotIdInput = miEditorConfig.imageFormElements.find("#xmlEditor_hotspot");
      hotspotIdInput.keyup(function () {
        var input = jQuery(this);
        var inputValue = input.val();
        jQuery(hotspotTitleIds).each(function () {
          var span = jQuery('#' + this);
          var spanText = span.html();
          try {
            var inputValueRegExp = new RegExp(inputValue);
            if (spanText.match(inputValueRegExp)) {
              span.parent().addClass('xmlJsonEditor_matched');
            }
            else {
              span.parent().removeClass('xmlJsonEditor_matched');
            }
            input.css('background-color', '');
            input.attr('title', '');
          } catch (e) {
            /* the regular expression provided is not ok */
            span.parent().removeClass('xmlJsonEditor_matched');
            input.css('background-color', '#fcc');
            input.attr('title', 'This is not a correct regular expression');
          }
        });
      });
      hotspotIdInput.keyup(); // run it for the first time.

      return false;
    }
    else {
      /* destroy matchImgEditors */
      jQuery('.matchImgEditor').remove();
      
      return true;
    }

  });
  return true;
}

/**
 * Shows the XML tab and hides the editor and templates tabs.
 */
function CQ_ShowXML() {
  CQ_jQuery('#xmlJsonEditor_tree').addClass('xmlJsonEditor_inactiveTab');
  CQ_jQuery('#xmlJsonEditor_tree').removeClass('xmlJsonEditor_activeTab');
  CQ_jQuery('#xmlJsonEditor_xml').addClass('xmlJsonEditor_activeTab');
  CQ_jQuery('#xmlJsonEditor_xml').removeClass('xmlJsonEditor_inactiveTab');
  CQ_jQuery('#xmlJsonEditor_templates').addClass('xmlJsonEditor_inactiveTab');
  CQ_jQuery('#xmlJsonEditor_templates').removeClass('xmlJsonEditor_activeTab');

  CQ_jQuery('#xmlJsonEditor_container').css('display', 'none');
  CQ_jQuery('#edit-body-wrapper').css('display', 'block');
  CQ_jQuery('#xmlJsonEditor_template_container').css('display', 'none');
}

/**
 * Shows the templates tab and hides the editor and XML tabs.
 */
function CQ_ShowTemplates() {
  CQ_jQuery('#xmlJsonEditor_tree').addClass('xmlJsonEditor_inactiveTab');
  CQ_jQuery('#xmlJsonEditor_tree').removeClass('xmlJsonEditor_activeTab');
  CQ_jQuery('#xmlJsonEditor_xml').addClass('xmlJsonEditor_inactiveTab');
  CQ_jQuery('#xmlJsonEditor_xml').removeClass('xmlJsonEditor_activeTab');
  CQ_jQuery('#xmlJsonEditor_templates').addClass('xmlJsonEditor_activeTab');
  CQ_jQuery('#xmlJsonEditor_templates').removeClass('xmlJsonEditor_inactiveTab');

  CQ_jQuery('#xmlJsonEditor_container').css('display', 'none');
  CQ_jQuery('#edit-body-wrapper').css('display', 'none');
  CQ_jQuery('#xmlJsonEditor_template_container').css('display', 'block');
}

/**
 * Posts the text, with the form-id to the server so the server can parse the
 * text for any tags, and return the replaced text.
 *
 * @param text
 *   String containing the text to parse.
 * @param editorDivSelector
 *   String the selector of the current editor.
 *
 * @return String
 *   The parsed text.
 */
function CQ_ParseText(text, editorDivSelector) {
  var form_id = CQ_jQuery(editorDivSelector).parents('form').find('[name=form_build_id]')[0];
  var target_url = Drupal.settings.basePath + 'closedquestion/parsecontentjs';
  var result = $.ajax({
    url: target_url,
    data: {
      form_build_id : form_id.value,
      parse_content : text
    },
    async: false
  }).responseText;
  var obj = CQ_jQuery.parseJSON(result);
  return obj.data;
}

/**
 * Loads a template into the editor. Gives a warning if the editor is not empty.
 *
 * @param template
 *   The XML string to load.
 */
function CQ_LoadTemplate(template) {
  var confirmed = true;
  if (CQ_jQuery("#edit-body")[0].value.length > 0) {
    confirmed = confirm("Loading this template will overwrite your current question. Are you sure?");
  }
  if (confirmed) {
    CQ_jQuery("#edit-body")[0].value = template;
    CQ_ShowTree();
  }
}
