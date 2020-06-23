<?php
// $Id$
/**
 * @file
 * Booklet Views support. Declares all the main tables to Views
 * @author Mark Sanford http://drupal.org/user/191578
 **/

/*
 * hook_views_data()
 */
function booklet_views_views_data() {
  $tables['booklet'] = array(
    'table' => array(
      'group' => t('Booklet'),
      'join' => array(
         'node' => array(
           'left_field' => 'nid',
           'field' => 'nid'
         ),
       ),
    ),
    
    'booklet_nid' => array(
      'title' => t('Booklet'),
      'help' => t('The first node of the booklet this node is in'),
      'relationship' => array(
        'base' => 'node',
        'field' => 'nid',
        'handler' => 'views_handler_relationship',
        'label' => t('Booklet'),
      ),
    ),
    
    'weight' => array(
      'title' => t('Weight'),
      'help' => t('Weight of the node in it\'s booklet'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
    ),

  );

  $tables['booklet']['add_page_link'] = array(
    'field' => array(
      'title' => t('Add page link'),
      'help' => t('Display an add page link.'),
      'handler' => 'views_handler_field_add_page_link',
    ),
  );

  $tables['booklet_items']['table']['group'] = t('Booklet');
  $tables['booklet_items']['table']['join'] = array(
    'node' => array(
      'table' => 'booklet',
      'field' => 'booklet_nid',
      'left_table' => 'booklet',
      'left_field' => 'booklet_nid',
    ),
  );

  $tables['booklet_items']['nid'] = array(
    'title' => t('Booklet Items'),
    'help' => t('The items in this nodes booklet.  Note that this relationship will cause duplicate nodes if there are multiple nodes in the booklet.'),
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Booklet Items'),
    ),
  );

  $tables['booklet_count']['table']['group'] = t('Booklet');
  $tables['booklet_count']['table']['join'] = array(
    'node' => array(
      'type' => 'INNER',
      'left_field' => 'nid',
      'field' => 'booklet_nid',
     ),
  );
  
  $tables['booklet_count']['count'] = array(
    'title' => t('Node count'),
    'help' => t('The number of nodes a booklet has.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
  );
  
  
  return $tables;
}


function booklet_views_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'booklet_views') ,
    ),
    'handlers' => array(
      'views_handler_field_add_page_link' => array(
       'parent' => 'views_handler_field',
      ),
    ),
  );
}


