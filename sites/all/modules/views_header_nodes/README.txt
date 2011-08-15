// $Id: README.txt,v 1.1.2.2 2010/09/18 14:42:56 joachim Exp $

Installation and usage
======================

1. Install the module as usual.
2. Add a display to your view of type 'Header node'.
3. Under "Attachment settings" set the header node display to attach to whichever displays you want the header node to appear on.
3. Create the node at [view path]/header.

If you have Prepopulate module installed, you will see a link in the header to create the node with the path automatically set.

Options
=======

You can set how to determine both the base and the suffix of the path of a header node in the attachment options.

There are two options for the base path:

- View name: This takes the machine name of the view, eg 'frontpage'. Use this if you want the same header node for all your view's displays.
- Display path: This takes the actual path of the current page display of the view, including arguments given in the URL.

You may change the 'header' path suffix to any string.

