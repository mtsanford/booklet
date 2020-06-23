<?php
// $Id: $

/**
 * @file
 * Booklet Views support. A couple of default example views.
 * @author Mark Sanford http://drupal.org/user/191578
 */

/**
 * Implementation of hook_default_view_views().
 */
function booklet_views_views_default_views() {
  $view = new view;
  $view->name = 'booklet_views';
  $view->description = 'booklet sample views';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = TRUE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
  'title' => array(
  'label' => 'Title',
  'alter' => array(
    'alter_text' => 0,
    'text' => '',
    'make_link' => 0,
    'path' => '',
    'link_class' => '',
    'alt' => '',
    'prefix' => '',
    'suffix' => '',
    'target' => '',
    'help' => '',
    'trim' => 0,
    'max_length' => '',
    'word_boundary' => 1,
    'ellipsis' => 1,
    'strip_tags' => 0,
    'html' => 0,
  ),
  'empty' => '',
  'hide_empty' => 0,
  'empty_zero' => 0,
  'link_to_node' => 0,
  'exclude' => 0,
  'id' => 'title',
  'table' => 'node',
  'field' => 'title',
  'relationship' => 'none',
  ),
  ));
  $handler->override_option('access', array(
  'type' => 'none',
  ));
  $handler->override_option('cache', array(
  'type' => 'none',
  ));
  $handler->override_option('footer_format', '1');
  $handler->override_option('footer_empty', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
  'grouping' => '',
  'override' => 1,
  'sticky' => 0,
  'order' => 'asc',
  'columns' => array(
  'title' => 'title',
  'title_1' => 'title_1',
  ),
  'info' => array(
  'title' => array(
    'sortable' => 0,
    'separator' => '',
  ),
  'title_1' => array(
    'sortable' => 0,
    'separator' => '',
  ),
  ),
  'default' => '-1',
  ));
  $handler = $view->new_display('page', 'All Booklets', 'page_2');
  $handler->override_option('fields', array(
  'title_1' => array(
  'label' => 'booklet Title',
  'alter' => array(
    'alter_text' => 0,
    'text' => '',
    'make_link' => 0,
    'path' => '',
    'link_class' => '',
    'alt' => '',
    'prefix' => '',
    'suffix' => '',
    'target' => '',
    'help' => '',
    'trim' => 0,
    'max_length' => '',
    'word_boundary' => 1,
    'ellipsis' => 1,
    'strip_tags' => 0,
    'html' => 0,
  ),
  'empty' => '',
  'hide_empty' => 0,
  'empty_zero' => 0,
  'link_to_node' => 1,
  'exclude' => 0,
  'id' => 'title_1',
  'table' => 'node',
  'field' => 'title',
  'relationship' => 'none',
  'override' => array(
    'button' => 'Use default',
  ),
  ),
  'count' => array(
  'label' => 'Pages',
  'alter' => array(
    'alter_text' => 0,
    'text' => '',
    'make_link' => 0,
    'path' => '',
    'link_class' => '',
    'alt' => '',
    'prefix' => '',
    'suffix' => '',
    'target' => '',
    'help' => '',
    'trim' => 0,
    'max_length' => '',
    'word_boundary' => 1,
    'ellipsis' => 1,
    'strip_tags' => 0,
    'html' => 0,
  ),
  'empty' => '',
  'hide_empty' => 0,
  'empty_zero' => 0,
  'set_precision' => FALSE,
  'precision' => 0,
  'decimal' => '.',
  'separator' => ',',
  'prefix' => '',
  'suffix' => '',
  'exclude' => 0,
  'id' => 'count',
  'table' => 'booklet_count',
  'field' => 'count',
  'override' => array(
    'button' => 'Use default',
  ),
  'relationship' => 'none',
  ),
  ));
  $handler->override_option('filters', array(
  'weight' => array(
  'operator' => '=',
  'value' => array(
    'value' => '0',
    'min' => '',
    'max' => '',
  ),
  'group' => '0',
  'exposed' => FALSE,
  'expose' => array(
    'operator' => FALSE,
    'label' => '',
  ),
  'id' => 'weight',
  'table' => 'booklet',
  'field' => 'weight',
  'override' => array(
    'button' => 'Use default',
  ),
  'relationship' => 'none',
  ),
  ));
  $handler->override_option('title', 'All Booklets');
  $handler->override_option('header', 'This view displays all <em>first pages</em> of booklets, along with the number of pages in the booklet.');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 0);
  $handler->override_option('empty', 'There are currently no booklets.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('path', 'booklet/all-booklets');
  $handler->override_option('menu', array(
  'type' => 'normal',
  'title' => 'All Booklets',
  'description' => '',
  'weight' => '3',
  'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  ));
  $handler = $view->new_display('block', 'In Booklet', 'block_1');
  $handler->override_option('relationships', array(
  'nid' => array(
  'label' => 'Booklet Items',
  'required' => 0,
  'id' => 'nid',
  'table' => 'booklet_items',
  'field' => 'nid',
  'override' => array(
    'button' => 'Use default',
  ),
  'relationship' => 'none',
  ),
  ));
  $handler->override_option('fields', array(
  'title_1' => array(
  'label' => '',
  'alter' => array(
    'alter_text' => 0,
    'text' => '',
    'make_link' => 0,
    'path' => '',
    'link_class' => '',
    'alt' => '',
    'prefix' => '',
    'suffix' => '',
    'target' => '',
    'help' => '',
    'trim' => 0,
    'max_length' => '',
    'word_boundary' => 1,
    'ellipsis' => 1,
    'strip_tags' => 0,
    'html' => 0,
  ),
  'empty' => '',
  'hide_empty' => 0,
  'empty_zero' => 0,
  'link_to_node' => 0,
  'exclude' => 0,
  'id' => 'title_1',
  'table' => 'node',
  'field' => 'title',
  'relationship' => 'nid',
  'override' => array(
    'button' => 'Use default',
  ),
  ),
  ));
  $handler->override_option('sorts', array(
  'weight' => array(
  'order' => 'ASC',
  'id' => 'weight',
  'table' => 'booklet',
  'field' => 'weight',
  'override' => array(
    'button' => 'Use default',
  ),
  'relationship' => 'nid',
  ),
  ));
  $handler->override_option('arguments', array(
  'nid' => array(
  'default_action' => 'default',
  'style_plugin' => 'default_summary',
  'style_options' => array(),
  'wildcard' => 'all',
  'wildcard_substitution' => 'All',
  'title' => '',
  'breadcrumb' => '',
  'default_argument_type' => 'node',
  'default_argument' => '',
  'validate_type' => 'none',
  'validate_fail' => 'not found',
  'break_phrase' => 0,
  'not' => 0,
  'id' => 'nid',
  'table' => 'node',
  'field' => 'nid',
  'validate_user_argument_type' => 'uid',
  'validate_user_roles' => array(
    '2' => 0,
    '4' => 0,
    '3' => 0,
  ),
  'override' => array(
    'button' => 'Use default',
  ),
  'relationship' => 'none',
  'default_options_div_prefix' => '',
  'default_argument_user' => 0,
  'default_argument_fixed' => '',
  'default_argument_php' => '',
  'validate_argument_node_type' => array(
    'book' => 0,
    'book_container' => 0,
    'book_page' => 0,
    'container' => 0,
    'multipage' => 0,
    'booklet' => 0,
    'page' => 0,
    'story' => 0,
  ),
  'validate_argument_node_access' => 0,
  'validate_argument_nid_type' => 'nid',
  'validate_argument_vocabulary' => array(),
  'validate_argument_type' => 'tid',
  'validate_argument_transform' => 0,
  'validate_user_restrict_roles' => 0,
  'validate_argument_php' => '',
  ),
  ));
  $handler->override_option('title', 'In This Booklet');
  $handler->override_option('footer', 'This block view shows the titles of the items in the booklet that the current node is in.  The "Booklet Items" relationship brings in information about *all* the nodes in the booklet.');
  $handler->override_option('footer_empty', 1);
  $handler->override_option('style_plugin', 'list');
  $handler->override_option('style_options', array(
  'grouping' => '',
  'type' => 'ul',
  ));
  $handler->override_option('row_options', array(
  'inline' => array(
  'title_1' => 'title_1',
  'title' => 'title',
  ),
  'separator' => '---',
  'hide_empty' => 0,
  ));
  $handler->override_option('block_description', 'Nodes in Booklet');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('block', 'In Booklet 2', 'block_2');
  $handler->override_option('relationships', array(
  'booklet_nid' => array(
  'label' => 'Booklet',
  'required' => 0,
  'id' => 'booklet_nid',
  'table' => 'booklet',
  'field' => 'booklet_nid',
  'override' => array(
    'button' => 'Use default',
  ),
  'relationship' => 'none',
  ),
  'nid' => array(
  'label' => 'Booklet Items',
  'required' => 0,
  'id' => 'nid',
  'table' => 'booklet_items',
  'field' => 'nid',
  'override' => array(
    'button' => 'Use default',
  ),
  'relationship' => 'none',
  ),
  ));
  $handler->override_option('fields', array(
  'title_1' => array(
  'label' => '',
  'alter' => array(
    'alter_text' => 0,
    'text' => '',
    'make_link' => 0,
    'path' => '',
    'link_class' => '',
    'alt' => '',
    'prefix' => '',
    'suffix' => '',
    'target' => '',
    'help' => '',
    'trim' => 0,
    'max_length' => '',
    'word_boundary' => 1,
    'ellipsis' => 1,
    'strip_tags' => 0,
    'html' => 0,
  ),
  'empty' => '',
  'hide_empty' => 0,
  'empty_zero' => 0,
  'link_to_node' => 0,
  'exclude' => 0,
  'id' => 'title_1',
  'table' => 'node',
  'field' => 'title',
  'override' => array(
    'button' => 'Use default',
  ),
  'relationship' => 'booklet_nid',
  ),
  'title' => array(
  'label' => '',
  'alter' => array(
    'alter_text' => 0,
    'text' => '',
    'make_link' => 0,
    'path' => '',
    'link_class' => '',
    'alt' => '',
    'prefix' => '',
    'suffix' => '',
    'target' => '',
    'help' => '',
    'trim' => 0,
    'max_length' => '',
    'word_boundary' => 1,
    'ellipsis' => 1,
    'strip_tags' => 0,
    'html' => 0,
  ),
  'empty' => '',
  'hide_empty' => 0,
  'empty_zero' => 0,
  'link_to_node' => 0,
  'exclude' => 0,
  'id' => 'title',
  'table' => 'node',
  'field' => 'title',
  'relationship' => 'nid',
  'override' => array(
    'button' => 'Use default',
  ),
  ),
  ));
  $handler->override_option('sorts', array(
  'weight' => array(
  'order' => 'ASC',
  'id' => 'weight',
  'table' => 'booklet',
  'field' => 'weight',
  'override' => array(
    'button' => 'Use default',
  ),
  'relationship' => 'nid',
  ),
  ));
  $handler->override_option('arguments', array(
  'nid' => array(
  'default_action' => 'default',
  'style_plugin' => 'default_summary',
  'style_options' => array(),
  'wildcard' => 'all',
  'wildcard_substitution' => 'All',
  'title' => '',
  'breadcrumb' => '',
  'default_argument_type' => 'node',
  'default_argument' => '',
  'validate_type' => 'none',
  'validate_fail' => 'not found',
  'break_phrase' => 0,
  'not' => 0,
  'id' => 'nid',
  'table' => 'node',
  'field' => 'nid',
  'validate_user_argument_type' => 'uid',
  'validate_user_roles' => array(
    '2' => 0,
    '4' => 0,
    '3' => 0,
  ),
  'override' => array(
    'button' => 'Use default',
  ),
  'relationship' => 'none',
  'default_options_div_prefix' => '',
  'default_argument_user' => 0,
  'default_argument_fixed' => '',
  'default_argument_php' => '',
  'validate_argument_node_type' => array(
    'book' => 0,
    'book_container' => 0,
    'book_page' => 0,
    'container' => 0,
    'multipage' => 0,
    'booklet' => 0,
    'page' => 0,
    'story' => 0,
  ),
  'validate_argument_node_access' => 0,
  'validate_argument_nid_type' => 'nid',
  'validate_argument_vocabulary' => array(),
  'validate_argument_type' => 'tid',
  'validate_argument_transform' => 0,
  'validate_user_restrict_roles' => 0,
  'validate_argument_php' => '',
  ),
  ));
  $handler->override_option('title', 'In This Booklet 2');
  $handler->override_option('footer', 'This block view shows the items in the booklet that the current node is in.  It shows the title of the first node in the booklet followed by the title of the node.  Two relationships are used: (1) "Booklet" which brings information about the first page in the booklet (and enables it\'s title to be displayed as a field), and (2) "Booklet Items" which brings in information about *all* the nodes in the booklet (and enabled their titles to be displayed as a field).');
  $handler->override_option('style_plugin', 'list');
  $handler->override_option('style_options', array());
  $handler->override_option('row_options', array(
  'inline' => array(
  'title' => 'title',
  'title_1' => 'title_1',
  ),
  'separator' => '---',
  'hide_empty' => 0,
  ));
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $views[$view->name] = $view;

  return $views;
}
