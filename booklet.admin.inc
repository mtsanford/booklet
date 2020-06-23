<?php
// $Id$
/**
 * @file
 * Administration pages for Booklet
 *
 * @author Mark Sanford http://drupal.org/user/191578
 *
 */

function booklet_settings() {

  $form['booklet_delete_all']= array(
    '#type' => 'checkbox', 
     '#title' => t('Delete all nodes in booklet'),
     '#description' =>  t('If enabled, deleting the first node in a booklet (anchor) will cause all nodes to be deleted.  Node delete confirmation form will show nodes to be deleted.'),
     '#default_value' => variable_get('booklet_delete_all', 0),
  );

  $form['booklet_fix_anchor']= array(
    '#type' => 'checkbox', 
     '#title' => t('Fix booklet anchor'),
     '#description' =>  t('First node in booklet (anchor) cannot be moved.  It will always be the first in it\'s booklet.  NOTE: To fully ensure a booklet never has it\'s anchor node change you should enable \'Delete all nodes in booklet\' option also.'),
     '#default_value' => variable_get('booklet_fix_anchor', 0),
  );
  
  $form['booklet_rebuild_aliases']= array(
    '#type' => 'checkbox', 
     '#title' => t('Rebuild URL aliases on delete and arrange'),
     '#description' =>  t('If enabled, URL aliases for all nodes in the booklet will be rebuilt if a node has been deleted, or it is rearranged.  This is only relevant if you have pathauto module enabled and are using tokens from booklet module to generate URLs.'),
     '#default_value' => variable_get('booklet_rebuild_aliases', 0),
  );

  $form['ui_settings'] = array(
    '#type' => 'fieldset', 
     '#title' => t('User interface settings'),
  );
  $form['ui_settings']['booklet_ui_add']= array(
    '#type' => 'checkbox', 
     '#title' => t('Show append new link'),
     '#description' => t('Show "Append New ---" link on nodes with booket enabled.'),
     '#default_value' => variable_get('booklet_ui_add', 1),
  );
  $form['ui_settings']['booklet_ui_toc']= array(
    '#type' => 'checkbox', 
     '#title' => t('Show TOC on first page of booklet'),
     '#description' => t('Show links to all nodes in the booklet when on the first page.'),
     '#default_value' => variable_get('booklet_ui_toc', 1),
  );
 
  return system_settings_form($form);

}
