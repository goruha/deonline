/**
 * The configuration of the xml editor for ClosedQuestion xml format. This is a
 * json object containing the keys:
 * - valid_children: array of node names that are valid root nodes of the XML.
 * - types: json object containing all allowed nodes as name-config pairs. Each
 *   config object contains the following fields:
 *   - alias_of: (optional) String, the name of another node type that this node
 *     type is an alias of. Before processing the name of this node type is
 *     changed to the name of the real node type. If this is set, all other
 *     configurations are ignored and the configuration of the new name is used,
 *     with the exception of content_to_attribute
 *   - content_to_attribute: Used in combination with alias_of, to indicate that
 *     the content of the old node should be put in a parameter of the new node.
 *   - content: int, 1 if all children of the node are to be treated as a single
 *     string and should thus be displayed in a text-box in the editor. 0 if any
 *     children should be treated as separate nodes.
 *   - attributes: (optional) json object containing name-config pairs for all
 *     valid attributes of the node. The config can be a string or an object. If
 *     the config is a string, nothing special is done. If the config is an
 *     object it can contain the following keys:
 *     fields:
 *     - alias_of: (optional) String, the name of another attribute that this
 *       attribute is an alias of. Before processing the name of this attribute
 *       is changed to the name of the real attribute. If this is set, all other
 *       configurations are ignored and the configuration of the new name is
 *       used.
 *     - title: (optional) The human readable title of the attribute
 *     - descripion: (optional) String with a description of the attribute.
 *     - values: (optional) Either a json array containing valid values of the
 *       attribute or an object specifying the valid values in another way.
 *       If it is an array then each value is either a string or an object. If
 *       the value is a string, that string will be used as the actual value and
 *       as human-readable string for display. If the value is an object it must
 *       contain the following:
 *       - title: The human-readable title of the attribute value.
 *       - value: The actual value for the attribute.
 *       If the values option is an object it must contain the following keys:
 *       - node_search_string: A search string to find the nodes to takes values
 *         from.
 *       - get_values_from: An attribute name that the values should be taken
 *         from.
 *       - get_titles_from: An attribute name that the titles should be taken
 *         from, or "/content" if the title should be taken from the content of
 *         the nodes.
 *
 *     - value_aliases: (optional) Object with oldname/newname combinations.
 *       Used to indicate that a certain (old) value is an alias of another
 *       (new) value. Before processing the old value will be replaced with the
 *       new value.
 *     - mandatory: (optional) String. Indicates this attribute has to exist
 *       if it does not exist, it is created with the given string value.
 *     - depricated: (optional) int 0 or 1. Indicates this attribute is depri-
 *       cated. This will hide the attribute if it has no value, and show a
 *       warning if it does have a value.
 *     - css: (optional) Object with css name/value pairs to style the attribute
 *       editor's form element OR an array with class names to apply to the form
 *       element.
 *     - hint_on_empty (optional) string. The hint the user gets when the
 *       attribute form element (i.c. a input or a textarea) is empty.
 *     - feedback (optional) Array with objects, allowing for feedback on user
 *       input in the attribute editors. Each object can/should have following
 *       keys:
 *       - correct: int 0 or 1. Indicates that this match refers to a correct
 *         user input.
 *       - match: String containing a regular expression, which will be matched
 *         against the attribute's value
 *       - text: String with the text to show to the user when there is a match.
 *       - fatal: (optional) int 0 or 1. (only available when correct=0)
 *         Indicates whether the error should prevent the user from saving the
 *         node. Default: 0.
 *       - stop: (optional) int 0 or 1. Indicates whether the feedback script
 *         should check for the next feedbacks in the array. Default: 1.
 *
 *   - valid_children: Array of node names that are valid children of this node.
 *   - max_children: Integer indicating the maximum number of children allowed
 *     in this node. -1 for no limit.
 *   - max_count: Integer indicating the maximum mumber of this node type that
 *     is allowed as a child of another node.
 *   - icon: (optional) Object to set a custom tree-icon for this node type.
 *     - image: URL of the image to use as an icon in the tree .
 *   - descripion: (optional) String with a description of the node.
 *   - atts_in_title: (optional) Array of attribute names that should be added
 *     to the title in the tree. Each listed attribute is added to the title as
 *     ", attname: attvalue"
 *   - auto_children: (optional) Array of node names. One node of each of the
 *     given types is automaticly created when a node of the current type is
 *     added to the tree.
 *   - children_in_editor: (optional) Array of node names. Children of the given
 *     types are hidden in the tree and their editor-widgets are added to the
 *     current node.
 *   - hidden: (optional) int 0 or 1. Indicates that this node should be hidden
 *     in the tree. Should probably combined with children_in_editor on the
 *     parent node.
 *   - is_group: (optional) int 0 or 1. Indicates that this node is a virtual
 *     node that is only present in the tree, to group other nodes together, and
 *     not present in the XML.
 *   - in_group: (optional) String name of the group to put this node in. This
 *     group is only present in the tree to group similar nodes together. The
 *     group is not an actual XML node.
 *
 * - xml_specific_config: Array of objects describing changes of the config
 *   based on the XML being edited. E.g. a node having 'valid_children' x,y,z
 *   when its attribute 'type' has a value of '1', and 'valid_children' a,b,c
 *   when 'type' has a value of '2''. Each object has the following properties:
 *   - conditions: object describing the conditions under which the config
 *     should be changed. This object can have the following properties:
 *     OR a condition object:
 *     - node: (optional, use this or family_node) the search string (see search
 *       function in the editor api) of the node; when used, all nodes in the
 *       XML with this name will be evaluated.
 *     - family_node: (optional, use this or node) the name of the; when used,
 *     only the nodes within the subtree of the node currently edited by the
 *       user will be evaluated.
 *     - attribute: string. Name of the attribute of which the value is matched
 *     - attributeValue: string. The value required value of the attribute.
 *     OR a logical operator:
 *     - and (optional) Array containing one or more condition objects/logical
 *       operators. All these should return true.
 *     - or (optional) Array containing one or more condition objects/logical
 *       operators. One of these should return true.
 *   - config_changes: Object describing changes in the config when the
 *     conditions are matched. This object can have the same properties as the
 *     "types" object. Arrays will be replaced, objects will be merged. Set the
 *     value of a member to null to remove it from an object.
 */
var CQ_XML_config = {
  "valid_children": ["question"],
  "xml_specific_config": [
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue": " "
    },
    "config_changes": {
      "types": {
        "question": {
          "valid_children": []
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue" : "option"
    },
    "config_changes": {
      "types": {
        "question": {
          "valid_children": ["text","matheval","hints","options","prompt"]
        },
        "option": {
          "attributes": {
            "correct": {
              "values": [
              {
                "title": "No",
                "value": " "
              },
              {
                "title": "Yes",
                "value": "1"
              }
              ]
            }
          }
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue" : "sequence"
    },
    "config_changes": {
      "types": {
        "question": {
          "valid_children": ["question"]
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue" : "dragdrop"
    },
    "config_changes": {
      "types": {
        "question": {
          "valid_children": ["text","matheval","hints","matchimg","startstate","mappings"]
        },
        "match": {
          "attributes": {
            "matchall": {
              "title": "Match all items",
              "values": [
              {
                "title": "No, Stop after first success",
                "value": " "
              },
              {
                "title": "All selected hotspots should have one of the selected draggables",
                "value": "h"
              },
              {
                "title": "All selected draggables should be on one of the selected hotspots",
                "value": "d"
              },
              {
                "title": "Both",
                "value": "b"
              }
              ]
            },
            "hotspot": {
              "title": "hotspot",
              "description": "Select the Hotspot item, that you want to match with a Draggable, in the left panel. Copy the name in the field 'identifier' over there and paste it here."
            },
            "draggable": {
              "title": "draggable",
              "description": "Select the Draggable item, that you want to match with a Hotspot, in the left panel. Copy the name in the field 'identifier' over there and paste it here.'"
            },
            "inlinechoice": null,
            "inlineoption": null,
            "pattern": null
          }
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue" : "hotspot"
    },
    "config_changes": {
      "types": {
        "question": {
          "valid_children": ["text","matheval","hints","matchimg","startstate","mappings"]
        },
        "matchimg": {
          "valid_children": ["hotspot"]
        },
        "match": {
          "attributes": {
            "matchall": {
              "title": "Match all items",
              "values": [
              {
                "title": "No, Stop after first success",
                "value": " "
              },
              {
                "title": "All selected hotspots should have one of the draggables",
                "value": "h"
              },
              {
                "title": "All draggables should be on one of the selected hotspots",
                "value": "d"
              },
              {
                "title": "Both",
                "value": "b"
              }
              ]
            },
            "hotspot": {
              "title": "hotspot",
              "description": "Select the Hotspot item, that you want to match with a Draggable, in the left panel. Copy the name in the field 'identifier' over there and paste it here."
            },
            "inlinechoice": null,
            "inlineoption": null,
            "pattern": null,
            "draggable": null
          }
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue" : "option|check|value|fillblanks|selectorder"
    },
    "config_changes": {
      "types": {
        "question": {
          "valid_children": ["text","matheval","hints","startstate","mappings"]
        },
        "matchimg": {
          "valid_children": ["hotspot"]
        },
        "match": {
          "attributes": {
            "matchall": {
              "title": "Match all items",
              "values": [
              {
                "title": "No, Stop after first success",
                "value": " "
              },
              {
                "title": "Yes, All must match for success",
                "value": "1"
              }
              ]
            },
            "inlinechoice": {
              "title": "inlinechoice",
              "description": "Select - in the left panel -  that 'Inlineoption' item, that you want this 'Inlinechoice' to match  with. In the right panel now go to the  field 'identifier', copy the name that is shown there, and paste it here."
            },
            "inlineoption": {
              "title": "inlineoption",
              "description": "Select - in the left panel -  the item 'Text'. In the right panel now go to the field 'Content' and look for the tags called <inlinechoice>. Find the one that you want to match this 'inlineoption' with, and look for the attribute called 'id'. Copy the name that is given between the quotes and paste it here. Example: <inlineChoice id='A' /> => copy A ."
            },
            "pattern": {
              "title": "pattern",
              "description": "Enter a regular expression here to match against the given answer."
            },
            "hotspot": null,
            "draggable": null
          }
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue" : "check"
    },
    "config_changes": {
      "types": {
        "question": {
          "valid_children": ["text","matheval","hints","correct","options","prompt","mappings"]
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue" : "fillblanks"
    },
    "config_changes": {
      "types": {
        "question": {
          "valid_children": ["text","matheval","hints","inlineoption","mappings"]
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue" : "flash"
    },
    "config_changes": {
      "types": {
        "question": {
          "valid_children": ["text","matheval"]
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue" : "selectorder"
    },
    "config_changes": {
      "types": {
        "question": {
          "valid_children": ["text","matheval","hints","options","startstate","mappings"]
        },
        "option": {
          "valid_children": ["choice", "description"],
          "attributes": {
            "id": {
              "description": "A letter (a-zA-Z) for options, a number (0-9) for groups.",
              "feedback": [
              {
                "correct": 0,
                "match": "^.{2,}$",
                "text": "You should use only 1 character for the ID in a select and order option.",
                "fatal": 0,
                "stop": 1
              },
              {
                "correct": 1,
                "match": "^[0-9]$",
                "text": "This option is now a target-box.",
                "fatal": 0,
                "stop": 1
              },
              {
                "correct": 1,
                "match": "^[a-zA-Z]$",
                "text": "This option is now a normal selectable option.",
                "fatal": 0,
                "stop": 1
              }
              ]
            }
          }
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue" : "value"
    },
    "config_changes": {
      "types": {
        "question": {
          "valid_children": ["text","matheval","hints","range","unit"]
        },
        "range": {
          "content": 0,
          "attributes": {
            "matchall": null,
            "inlinechoice": null,
            "value": null,
            "minval": null,
            "maxval": null
          },
          "valid_children": ["minval","maxval","feedback"],
          "max_children": -1,
          "icon": {
            "image": "icons/mapping_icon.png"
          },
          "in_group": "mappings",
          "atts_in_title": ["correct"]
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue": "check|dragdrop|hotspot|fillblanks|selectorder"
    },
    "config_changes": {
      "types": {
        "mappings": {
          "content": 0,
          "attributes": {},
          "valid_children": ["mapping"],
          "max_children": -1,
          "is_group": 1
        },
        "range": {
          "valid_children": [],
          "max_children": 0,
          "attributes": {
            "correct": null
          }
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue" : "selectorder|dragdrop|hotspot|value|fillblanks|flash|sequence"
    },
    "config_changes": {
      "types": {
        "question": {
          "attributes": {
            "inlinefeedback": null
          }
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue" : "balance"
    },
    "config_changes": {
      "types": {
        "question": {
          "valid_children": ["text","hints","acc","flow","prod","correct"]
        }
      }
    }
  },
  {
    "conditions": {
      "family_node": "question",
      "attribute": "type",
      "attributeValue": "option|check|dragdrop|hotspot|balance|value|fillblanks|flash|sequence"
    },
    "config_changes": {
      "types": {
        "question": {
          "attributes": {
            "duplicates": null,
            "alignment": null,
            "optionheight": null
          }
        }
      }
    }
  }
  ],
  "types": {
    "question": {
      "content": 0,
      "valid_children": ["text","matheval","hints","correct","options","inlineoption","matchimg","prompt","startstate","mappings","range","question","acc","flow","prod"],
      "max_children": -1,
      "description": "Explanation about Question.",
      "attributes": {
        "type": {
          "title": "Question type",
          "values": [" ", "option", "check", "dragdrop", "hotspot", "balance", "value", "fillblanks", "selectorder", "flash", "sequence"],
          "value_aliases": {
            "pattern": "selectorder"
          },
          "mandatory": " ",
          "description": "A Question type is ...",
          "feedback" :[
          {
            "correct": 1,
            "match": "option",
            "text": "An option-type question is....",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": "check",
            "text": "A check-type question is....",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": "dragdrop",
            "text": "An dragdrop-type question is....",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": "hotspot",
            "text": "An hotspot-type question is....",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": "balance",
            "text": "An balance-type question is....",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": "value",
            "text": "A value-type question is....",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": "fillblanks",
            "text": "A fillblanks-type question is....",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": "selectorder",
            "text": "A selectorder-type question is....",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": "flash",
            "text": "A flash-type question is....",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": "sequence",
            "text": "A sequence-type question is....",
            "fatal": 0,
            "stop": 0
          }
          ]
        },
        "inlinefeedback": {
          "title": "Feedback between options",
          "values": [
          {
            "title": "No",
            "value": " "
          },
          {
            "title": "Yes",
            "value": 1
          }
          ],
          "description": "Should the feedback apear between the options, or all together at the bottom?",
          "feedback" :[
          {
            "correct": 1,
            "match": "1",
            "text": "Yes means that the feedback text will appear directly under each offered choice.",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": " ",
            "text": "No means that the feedback text will appear in the feedback field at the bottom of the page.",
            "fatal": 0,
            "stop": 0
          }
          ]
        },
        "duplicates": {
          "title": "Allow duplicates",
          "values": [
          {
            "title": "No",
            "value": " "
          },
          {
            "title": "Yes",
            "value": 1
          }
          ],
          "description": "Can options be chosen more than once?",
          "feedback" :[
          {
            "correct": 1,
            "match": "1",
            "text": "Yes means that options can be copied from the source box to one or more target boxes. So an option can be dragged to the target boxes more than once",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": " ",
            "text": "No means that options can be moved from the source box to one or more target boxes. So an option can be dragged to the target boxes only once",
            "fatal": 0,
            "stop": 0
          }
          ]
        },
        "alignment": {
          "title": "Alignment",
          "description": "Should the options be aligned horizontally or vertically.",
          "values": [
          {
            "title": "Default",
            "value": " "
          },
          {
            "title": "Horizontal",
            "value": "horizontal"
          }
          ],
          "feedback" :[
          {
            "correct": 1,
            "match": " ",
            "text": "'Default' means that options will be placed  below one another in the target box, when dropped there.",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": "horizontal",
            "text": "'Horizontal' means that options will be placed next to one another in the target box, when dropped there.",
            "fatal": 0,
            "stop": 0
          }
          ]
        },
        "optionheight": {
          "title": "Option Height",
          "description": "Give a CSS heigt value here to fix the hight of the options."
        },
        "width": {
          "depricated": 1,
          "title": "Width (This should be moved to the Matchimg)",
          "feedback" : [
          {
            "correct": 0,
            "match": ".+",
            "text": "Width should be moved to the Matchimg"
          }
          ]
        },
        "height": {
          "depricated": 1,
          "title": "Height (This should be moved to the Matchimg)",
          "feedback" : [
          {
            "correct": 0,
            "match": ".+",
            "text": "Height should be moved to the Matchimg"
          }
          ]
        }
      },
      "atts_in_title": ["type"]
    },
    "text": {
      "content": 1,
      "attributes": {},
      "valid_children": [],
      "icon" : {
        "image": "icons/text_icon.png"
      },
      "max_children": 0,
      "max_count": 1
    },
    "prompt": {
      "content": 1,
      "attributes": {},
      "valid_children": [],
      "icon" : {
        "image": "icons/text_icon.png"
      },
      "max_children": 0,
      "max_count": 1,
      "description": "Shown above the list of options in a MC question, for instance: Pick One"
    },
    "unit": {
      "content": 1,
      "attributes": {},
      "valid_children": [],
      "icon" : {
        "image": "icons/text_icon.png"
      },
      "max_children": 0,
      "max_count": 1,
      "description": "The unit of the answer."
    },
    "matheval":{
      "content": 0,
      "description": "Evaluate a mathematical expression.",
      "attributes": {
        "e": {
          "title": "e",
          "description": "An expression. Examples: a=random(); a=round(a*0.8+0.11,2); min=min(round(ans,1),(ans-0.01)); etc. See advanced help."
        },
        "expression": {
          "alias_of": "e"
        },
        "store": {
          "description": "Store all variables after this point?",
          "values": [
          {
            "title": "No",
            "value": " "
          },
          {
            "title": "Yes",
            "value": "1"
          }
          ]
        }
      },
      "valid_children": [],
      "max_children": 0,
      "icon": {
        "image": "icons/matheval_icon.png"
      },
      "atts_in_title": ["store", "e"]
    },
    "hints": {
      "content": 0,
      "description": "Here all hints are grouped together.",
      "attributes": {},
      "valid_children": ["hint"],
      "max_children": -1,
      "max_count": 1,
      "is_group": 1
    },
    "hint": {
      "content": 1,
      "attributes": {
        "mintries": {
          "title": "Minimum tries",
          "description": "A value that determines the minimum number of tries before showing the hint.",
          "feedback": [
          {
            "correct": 0,
            "match": "[^0-9]",
            "text": "This should be a positive number!",
            "fatal": 1,
            "stop": 1
          }
          ]
        },
        "maxtries": {
          "title": "Maximum tries",
          "description": "A value that determines the maximum number of tries during which the hint will appear. If nothing is entered, the hint will not disappear once it is shown.",
          "feedback": [
          {
            "correct": 0,
            "match": "[^0-9]",
            "text": "This should be a positive number!",
            "fatal": 1 ,
            "stop": 1
          }
          ]
        },
        "block": {
          "title": "block",
          "description": "The feedbackblock in which the hint should appear."
        }
      },
      "valid_children": [],
      "max_children": 0,
      "icon": {
        "image": "icons/hint_icon.png"
      },
      "in_group": "hints",
      "atts_in_title": ["mintries", "maxtries", "block"]
    },
    "correct": {
      "content": 1,
      "description": "This is the feedback shown when the the answer is correct.",
      "attributes": {},
      "valid_children": [],
      "max_children": 0,
      "max_count": 1,
      "icon": {
        "image": "icons/correct_icon.png"
      }
    },
    "options": {
      "content": 0,
      "description": "Here all the options are grouped together.",
      "attributes": {},
      "valid_children": ["option"],
      "max_children": -1,
      "max_count": 1,
      "is_group": 1
    },
    "option": {
      "content": 0,
      "attributes": {
        "id": {
          "title": "Identifier",
          "description": "A unique name for this item."
        },
        "identifier": {
          "alias_of": "id"
        },
        "name": {
          "alias_of": "id"
        },
        "correct": {
          "title": "This option is correct",
          "description": "Describes whether this option is correct, not correct or irrelevant. Irrelevant means that it does not matter whether a student checks this option or not. ",
          "values": [
          {
            "title": "No",
            "value": " "
          },
          {
            "title": "Yes",
            "value": "1"
          },
          {
            "title": "Irrelevant",
            "value": "-1"
          }
          ]
        }
      },
      "atts_in_title": ["id", "correct"],
      "icon": {
        "image": "icons/option_icon.png"
      },
      "valid_children": ["choice", "description", "feedback", "feedbackunselected"],
      "auto_children": ["choice"],
      "children_in_editor": ["choice"],
      "max_children": -1,
      "in_group": "options"
    },
    "choice": {
      "title": "Text",
      "content": 1,
      "attributes": {},
      "valid_children": [],
      "max_children": 0,
      "max_count": 1,
      "icon": {
        "image": "icons/text_icon.png"
      },
      "hidden": 1
    },
    "description": {
      "content": 1,
      "description": "A description of the option, shown in a mouse-over of the option.",
      "attributes": {},
      "valid_children": [],
      "max_children": 0,
      "max_count": 1
    },
    "feedback": {
      "content": 1,
      "attributes": {
        "mintries": {
          "title": "Minimum tries",
          "description": "A value that determines the minimum number of tries before showing the hint. If nothing is entered, the hint will be shown after the first try.",
          "feedback": [
          {
            "correct": 0,
            "match": "[^0-9]",
            "text": "This should be a positive number!",
            "fatal": 1 ,
            "stop": 1
          }
          ]
        },
        "maxtries": {
          "title": "Maximum tries",
          "description": "A value that determines the maximum number of tries during which the hint will appear. If nothing is entered, the hint will not disappear once it is shown.",
          "feedback": [
          {
            "correct": 0,
            "match": "[^0-9]",
            "text": "This should be a positive number!",
            "fatal": 1 ,
            "stop": 1
          }
          ]
        },
        "block": {
          "title": "block",
          "description": "The feedbackblock in which the hint should appear."
        }
      },
      "valid_children": [],
      "max_children": 0,
      "icon": {
        "image": "icons/feedback_icon.png"
      },
      "atts_in_title": ["mintries", "maxtries", "block"]
    },
    "feedbackunselected": {
      "content": 1,
      "attributes": {
        "mintries": {
          "title": "Minimum tries",
          "description": "A value that determines the minimum number of tries before showing the hint. If nothing is entered, the hint will be shown after the first try.",
          "feedback": [
          {
            "correct": 0,
            "match": "[^0-9]",
            "text": "This should be a positive number!",
            "fatal": 1 ,
            "stop": 1
          }
          ]
        },
        "maxtries": {
          "title": "Maximum tries",
          "description": "A value that determines the maximum number of tries during which the hint will appear. If nothing is entered, the hint will not disappear once it is shown.",
          "feedback": [
          {
            "correct": 0,
            "match": "[^0-9]",
            "text": "This should be a positive number!",
            "fatal": 1 ,
            "stop": 1
          }
          ]
        },
        "block": {
          "title": "block",
          "description": "The feedbackblock in which the hint should appear."
        }
      },
      "valid_children": [],
      "max_children": 0,
      "icon": {
        "image": "icons/feedback_icon.png"
      },
      "atts_in_title": ["mintries", "maxtries", "block"]
    },
    "inlineoption": {
      "content": 1,
      "attributes": {
        "id": {
          "title": "Identifier",
          "description": "A unique name for this item."
        },
        "identifier": {
          "alias_of": "id"
        },
        "group": {
          "title": "Group",
          "description": "Define here to which group (a dropdownbox) the option should be added."
        }
      },
      "atts_in_title": ["id", "group"],
      "valid_children": [],
      "max_children": 0
    },
    "matchimg": {
      "content": 0,
      "attributes": {
        "src":{
          "description": "The name of the uploaded image file in 'File Attachments'. This name should be entered here like this: [attachurl:image_name.png]"
        },
        "height": {
          "description": "The desired height of the picture in pixel units. If nothing is entered here nor in width, the actual size of the image will be used.",
          "hint_on_empty" : "Type a number",
          "feedback": [
          {
            "correct": 0,
            "match": "[^0-9]",
            "text": "Enter only numbers.",
            "fatal": 1,
            "stop": 1
          }
          ]
        },
        "width": {
          "description": "The desired width of the picture in pixel units. If nothing is entered here nor in height, the actual size of the image will be used.",
          "feedback": [
          {
            "correct": 0,
            "match": "[^0-9]",
            "text": "Enter only numbers.",
            "fatal": 1 ,
            "stop": 1
          }
          ]
        },
        "maxchoices": {
          "description": "the maximum number of choices that can be entered.",
          "feedback": [
          {
            "correct": 0,
            "match": "[^0-9]",
            "text": "Enter only numbers.",
            "fatal": 1,
            "stop": 1
          }
          ]
        }
      },
      "valid_children": ["hotspot", "draggable"],
      "max_children": -1,
      "max_count": 1
    },
    "hotspot": {
      "content": 1,
      "attributes": {
        "shape": {
          "values": ["rect","circle","poly"],
          "description": "In the dropdown box you can choose a shape to draw the hotspot",
          "feedback" :[
          {
            "correct": 1,
            "match": "rect",
            "text": "Click on two points in the picture. The first click determines the top-left point of the rectangle, the second click determines the bottom-right point.",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": "circle",
            "text": "Click on two points in the picture. The first click determines the center point of the circle, the second click determines the radius.",
            "fatal": 0,
            "stop": 0
          },
          {
            "correct": 1,
            "match": "poly",
            "text": "Click on multiple points in the picture. The first click determines the start of the polygonal; the polygonal is closed by clicking on the first point again.",
            "fatal": 0,
            "stop": 0
          }
          ]
        },
        "id": {
          "title": "Identifier",
          "description": "A unique name for this item.",
          "css" : {
            "width" : "100px"
          }
        },
        "identifier": {
          "alias_of": "id"
        },
        "coords":{
          "title": "coords",
          "description": "These coordinates are automatically generated when you draw the rectangle, the circle, or the polygonal of the hotspot. If you prefer entering them yourself, you can also type in the numbers seperated by kommas.",
          "feedback": [
          {
            "correct": 0,
            "match": "[^0-9,]",
            "text": "Enter only numbers - seperated by komma's - to define the coordinates. Spaces are not allowed!",
            "fatal": 1,
            "stop": 1
          }
          ]
        }
      },
      "valid_children": [],
      "max_children": 0,
      "icon": {
        "image": "icons/hotspot_icon.png"
      },
      "atts_in_title": ["id"]
    },
    "draggable": {
      "content": 1,
      "attributes": {
        "id": {
          "title": "Identifier",
          "description": "A unique name for this item."
        },
        "identifier": {
          "alias_of": "id"
        },
        "class": {
          "title": "class",
          "description": "The CSS class used to style this draggable."
        }
      },
      "valid_children": [],
      "max_children": 0,
      "icon": {
        "image": "icons/draggable_icon.png"
      },
      "atts_in_title": ["id"]
    },
    "default": {
      "alias_of": "startstate"
    },
    "startstate": {
      "content": 0,
      "description": "If the student has not answered the question yet, this 'answer' is used to show the question.",
      "attributes": {
        "value": {
          "title": "value",
          "description": "When you have finished designing a drag and drop  question in the editor, and saved it, all the draggables will appear on top of each other in the top-left corner. Now you can drag them one by one to the desired positions that you want your students to see when they open the question for the first time. Then click the Submit button. When you are a teacher, you now will see a green bar just above the submit button. In this bar you will see someting like this: Current answer=d1,590,11;d2,566.5,228;d3,587,83;d4,567,204; Copy everything after  the '= ' character. Then open the editor again and paste it here in this textbox."
        }
      },
      "valid_children": [],
      "max_children": 0,
      "max_count": 1,
      "icon": {
        "image": "icons/startstate_icon.png"
      }
    },
    "mappings": {
      "content": 0,
      "attributes": {},
      "valid_children": ["mapping"],
      "max_children": -1,
      "is_group": 1,
      "max_count": 1
    },
    "mapping": {
      "content": 0,
      "attributes": {
        "correct": {
          "title": "This option is correct",
          "description": "Describes whether this option is correct",
          "values": [
          {
            "title": "No",
            "value": " "
          },
          {
            "title": "Yes",
            "value": "1"
          }
          ]
        },
        "stop": {
          "title": "If this mapping matches",
          "description": "Choose whether to Stop processing or Continue processing",
          "values": [
          {
            "title": "Continue processing",
            "value": " "
          },
          {
            "title": "Stop processing",
            "value": "1"
          }
          ]
        }
      },
      "valid_children": ["and","or","not","match","range","feedback"],
      "max_children": -1,
      "icon": {
        "image": "icons/mapping_icon.png"
      },
      "in_group": "mappings",
      "atts_in_title": ["correct", "stop"]
    },
    "and": {
      "content": 0,
      "attributes": {
      },
      "valid_children": ["and","or","not","match","range"],
      "max_children": -1,
      "icon": {
        "image": "icons/and_icon.png"
      }
    },
    "or": {
      "content": 0,
      "attributes": {
      },
      "valid_children": ["and","or","not","match","range"],
      "max_children": -1,
      "icon": {
        "image": "icons/or_icon.png"
      }
    },
    "not": {
      "content": 0,
      "attributes": {
      },
      "valid_children": ["and","or","not","match","range"],
      "max_children": 1,
      "icon": {
        "image": "icons/not_icon.png"
      }
    },
    "match": {
      "content": 0,
      "attributes": {
        "matchall": "string",
        "inlinechoice": "string",
        "inlineoption": "string",
        "pattern": "string",
        "hotspot": "string",
        "hotspotpattern": {
          "alias_of": "hotspot"
        },
        "draggable": "string",
        "draggablepattern": {
          "alias_of": "draggable"
        }
      },
      "valid_children": [],
      "max_children": 0,
      "icon": {
        "image": "icons/match_icon.png"
      },
      "atts_in_title": ["inlinechoice", "inlineoption", "hotspot", "draggable", "pattern"]
    },
    "combination": {
      "alias_of": "match"
    },
    "range": {
      "content": 0,
      "attributes": {
        "matchall": {
          "title": "matchall",
          "description": "If more than one inlinechoice is selected, do all of them have to be in this range or only one?",
          "values": [
          {
            "title": "One is enough",
            "value": " "
          },
          {
            "title": "All must match",
            "value": "1"
          }
          ]
        },
        "inlinechoice": "string",
        "value": "string",
        "minval": "string",
        "maxval": "string",
        "correct": {
          "title": "This option is correct",
          "description": "Describes whether this option is correct",
          "values": [
          {
            "title": "No",
            "value": " "
          },
          {
            "title": "Yes",
            "value": "1"
          }
          ]
        }
      },
      "valid_children": ["minval","maxval","feedback"],
      "max_children": -1,
      "icon": {
        "image": "icons/range_icon.png"
      },
      "atts_in_title": ["correct", "inlinechoice", "value", "minval", "maxval"]
    },
    "minval": {
      "content": 1,
      "max_children": 0,
      "max_count": 1
    },
    "maxval": {
      "content": 1,
      "max_children": 0,
      "max_count": 1
    },
    "sequence": {
      "alias_of": "mapping"
    },
    "pattern": {
      "alias_of": "match",
      "content_to_attribute": "pattern"
    },
    "acc": {
      "title": "Accumulation",
      "valid_children": ["option", "correct"],
      "max_count": 1
    },
    "prod": {
      "title": "Production",
      "valid_children": ["option", "correct"],
      "max_count": 1
    },
    "flow": {
      "title": "Transport",
      "valid_children": ["option", "correct"],
      "max_count": 1
    }
  }
}
