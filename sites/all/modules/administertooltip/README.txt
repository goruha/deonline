********************************************************************
                     D R U P A L    M O D U L E
********************************************************************
Name:
  Administer Tool Tip

Author:
  Kevin Franke <k.franke@madcap.nl>
  Jaap Broeders <j.broeders@madcap.nl>

Maintainers:
  Kevin Franke <k.franke@madcap.nl>
  Jaap Broeders <j.broeders@madcap.nl>

Website:
  http://administertooltip.open.madcap.nl/

********************************************************************
DESCRIPTION:

The Administer Tool Tip module adds little icons to all entities
on mouseover where you can click on to open a tool tip where all
kinds of functionality exists such as block position settings,
links to edit the entity and statistic information.
The module itself can be extended via hooks to add more
functionality to each different kind of tip.

********************************************************************
INSTALLATION:

1. Install the jquery_ui and beautytips modules according to their
   readme's. Administer Tool Tip will not function without them.

2. Place the entire Administer Tool Tip directory into your Drupal
   sites/all/modules directory.

3. Enable the administertooltip module by navigating to:
     Administer > Site building > Modules

4. If you want anyone besides the administrative user to see the
  administertooltips, they must be given the
  "access administertooltips" acces permission:
  Administer > User management > Permissions

5. If you want anyone besides the administrative user to be able
   to configure the administertooltip module, they must be given
   the "administer administertooltips" access permission.

   When the module is enabled and the user has the
   "administer administertooltips" permission, a
   "administertooltip" menu should appear in the menu system under
   Administer -> Site configuration.

********************************************************************
GETTING STARTED:

The Administer Tool Tip module in principle already works out of
the box, but you might want to choose where the tips will appear.

To do so, browse to the administration area of your website and
navigate to Site Configuration > Administer Tool Tip. This page
has 3 sections: General settings, entities settings and
node specific settings.

The general settings give you the options to decide if you want
to enable dragging and dropping of blocks.

The entities settings give you the options to decide for which
entity the tips will be showed.

In the "node content type settings" fieldset you can enable/disable
the visibility of the Administer Tool Tip per nodetype and
display mode.

The Administer Tool Tip module also has the access rule
"access contextual tips" so you can choose which user can see
the Administer Tool Tip.

