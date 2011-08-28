
-- SUMMARY --

"Multistep Nodeform" is a modul to split up node forms into single steps.

For each step you can define which fields should be included in this step. 
"Fields" includes core-fields like "Title", "Body" or "Authoring information" 
as well as fields defined by the <a href="drupal.org/project/cck">Content Construction Kit</a>.


For a full description of the module, visit the project page:
  http://drupal.org/project/msnf

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/msnf


-- REQUIREMENTS --

None.


-- INSTALLATION --

Install as usual.
See http://drupal.org/node/70151 for more information about how to install a 
module.


-- CONFIGURATION --

* To split up a node form into steps you have to create the steps for each 
  content type to split. Go to the content type administration (Administer >> 
  Content >> Types) and click "edit" for the desired content type.
  Now you can manage the steps and the field association on the 
  "Manage steps"-tab.
  After adding a tab you can drag it to the position you like and move fields
  into the step. 

  Note: if you use fieldgroups (a field type installed by CCK) you can't put
  core-fields ("Title", "Body", "Authoring information", etc., ) under 
  fieldgroups as this is not supported (not by CCK, nor by this module).
  You are able to visually move the fields under the group but this setting 
  won't be saved.


-- EXPORT --

By using the great <a href="http://drupal.org/project/features">Features</a>
module you can export each step into code.


-- AUTHOR --

Stefan Borchert (http://drupal.org/user/36942)


Development of this module has been sponsored by undpaul (http://www.undpaul.de).

