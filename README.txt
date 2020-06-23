// $Id$

OVERVIEW
========

The Booklet module allows content creators to make linear lists of nodes. A booklet is somewhat similar to a book from Drupal core, except that the nodes are assembled into a flat list rather than a hierarchy. Nodes can be appended to a booklet by clicking a "Append new <content type>..." link at the bottom of a node page. Booklets can be arranged into a different order by clicking the "arrange" tab available on the first page of a booklet. Note that these features are abailable only to users that have permission to edit the first node in the booklet. A block is available to show all the nodes in the currently viewed booklet, and a navigation section (e.g. previous/next links) is added to the display of each node.



FEATURES
========

* Enable specific content type to be assemblable into booklets.

* Simple workflow for end users: no parent selection or weights.

* Items are added to booklets by clicking on "Append New..." link at bottom of nodes.

* Items in booklet can be arranged by dragging in "Arrange" tab for booklet nodes.

* Navigation region for next/previous items in booklet.

* Block to show table of contents of currently viewed booklet.

* Theming friendly

* Views 2 support (default sample views provided)

* (optional) First node in booklet cannot be arranged such that a new node becomes the first

* (optional) Deleting the first node in a booklet deletes all nodes in booklet. Delete confirm form will show all nodes to be deleted.

* Node add form title is changed to "Append new <content type> to <title of first node in booklet>"


USAGE
=====

1) Install module 
2) Enable booklets for a content type (e.g. 'Page'). Go to the Content Types page and in the "workflow settings" section, select "enable" for the Booklets option.
3) Go to admin/content/booklet-settings to enable/disable optional features.
4) Go to admin/build/block to enable the "Booklet navigation block" block.
5) OPTIONAL: install BoolketViews module for Views 2 support.  Go to admin/build/views to enable booklet_views default views for sample views.

End user usage:

1) Create a new node of the content type enabled for booklets.
2) Click on "Append new...." link at bottom of node to add to the booklet.
3) Repeat 2
4) Go back to first page, and click on "arrange" tab.
5) Drag to reorder

NOTE ON SHOWING LINKS TO NODES IN BOOKLETS
===========================================

  Normally, links to unpublished nodes should not be shown.  However, in some cases an
  administrator may want grant view access to unpublished nodes, for example in the 
  case where there is an 'editor' role, that is not granted 'administer nodes' permission, but
  should still be able to view some unpublished content.  There is no satisfactory way to
  do this in Drupal 6.  In these situations, a hook may be implemented to grant 'view' access
  to unpublished nodes.
  
  Example:
  
  /* 
   * WARNING: $node argument is only partial with these properties: nid, title, status, type, uid
   * If you need the full node, you must call node_load($node->nid)
   * If this is being called, the current user had not been denied access to the node by modules emplementing
   * hook_db_rewrite_sql, and the node's status is unpublished.
   */
  function MYMODULE_booklet_show_unpublished_node_link($node) {
    if ( in_array("editor", $user->roles) && $node->type == 'article' ) {
      return array('MYMODULE' => TRUE);
    }
  }

KNOWN ISSUES
=============

Revisions are not kept for changes to the item list for a node.

AUTHOR / MAINTAINER
===================
Mark Sanford (http://drupal.org/user/191578)
