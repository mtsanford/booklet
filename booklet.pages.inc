<?php
// $id$

/*
 *   callback for "Arrange" tab menu item
 */
function booklet_page_items($node) {
  // note to self: This may get called on submit too!
  drupal_set_title(t('Arrange %title', array('%title' => $node->title)));
  return drupal_get_form('booklet_items_form', $node);
}


/*
 *   The item arrange form
 */
function booklet_items_form(&$form_state, $node) {

  foreach ($node->booklet['items'] as $idx => $item) {
    $data = $item['title'] ? l($item['title'], 'node/' . $item['nid']) : t('<em>You do not have access to this title<em>');
    $form['rows'][$item['nid']]['data']=array(
       '#type' => 'value',
       '#value' => array( $data ),
     );

    //now create the weight form element.  
    //NOTE how we add the id into the element key
    $form['rows'][$item['nid']]['weight-'.$item['nid']]=array(
      '#type'=>'textfield',
      '#size'=>5,
      '#default_value'=>$idx,
      '#attributes' => array('class'=>'weight'),
    );
  }

    $form['booklet']=array(
       '#type' => 'value',
       '#value' => $node->booklet['booklet'],
     );
    
    // Ensure booklet has not changed between arrange form and submit    
    $md5 = md5(implode('+', $node->booklet['nids']));
    $form['booklet_md5']=array(
       '#type' => 'value',
       '#value' => $md5,
     ); 
     // put on form delivered to browser too
    $form['booklet_current_md5'] = array(
      '#type' => 'hidden',
      '#default_value' => $md5,
    );

    $form['submit']=array(
      '#type'=>'submit',
      '#value'=>t('Save changes'),
    );
  
  $form['#redirect'] = array('node/' .  $node->nid);

  return $form;
}

  
/*
 *   Theme the item arrange form
 */
function theme_booklet_items_form($form) {

  if (variable_get('booklet_fix_anchor', 0)) {
    // disable table dragging on the first row
    $first = TRUE;
  } 

   if ($form['rows']) {
    foreach($form['rows'] as $id => $row){
      //we are only interested in numeric keys
      if (intval($id)) {  
        $this_row = $row['data']['#value'];

        if ($first) {
          $form['rows'][$id]['weight-'.$id]['#attributes']['disabled'] = TRUE;
        }

        $this_row[] = drupal_render($form['rows'][$id]['weight-'.$id]);
        $table_rows[] = $first ? array('data'=>$this_row, 'class'=>'notdraggable') : array('data'=>$this_row, 'class'=>'draggable');

        $first = FALSE;
      }
    }
  }
    
    $header = array(
      t('Title'),
      t('Order'),
    );

    $output = theme('table', $header, $table_rows, array('id'=>'booklet-items-table'));
    $output .= drupal_render($form);
 
    // Call add_tabledrag to add and setup the JS for us
    // The key thing here is the first param - the table ID
    // and the 4th param, the class of the form item which holds the weight
    drupal_add_tabledrag('booklet-items-table', 'order', 'sibling', 'weight');      
    if (variable_get('booklet_fix_anchor', 0)) {
      drupal_add_js(drupal_get_path('module', 'booklet') . '/tabledragtopfixed.js', 'module');
      drupal_add_css(drupal_get_path('module', 'booklet') . '/tabledragtopfixed.css', 'module');
    }

    return $output;
}

 
function booklet_items_form_validate($form, &$form_state) {
  if ($form_state['values']['booklet_md5'] != $form_state['values']['booklet_current_md5']) {
    form_set_error('', t('Unable to arrange.  Modified by another user, the changes could not be saved.'));
    $form_state['rebuild'] = TRUE;
  }
}
 
/*
 *   Submit function for item arrange form
 */
function booklet_items_form_submit($form, &$form_state) {

  $new_weights = array();
  foreach($form_state['values'] as $key=>$data){
    //we are only interested in weight elements
    if (substr($key,0,6)=='weight'){
      //cunningly we have the DB id of the row in the element name
      $id = str_replace('weight-','',$key);
      $new_weights[(int)$id] = (int)$data; 
    }
  }

  $new_anchor = booklet_normalize_weights($new_weights);

  if (variable_get('booklet_fix_anchor', 0) && $new_weights[$form_state['values']['booklet']] != 0) {
    // to ensure old anchor remains, set it's weight to -1 and renormalize
    $new_weights[$form_state['values']['booklet']] = -1;
    $new_anchor = booklet_normalize_weights($new_weights);
  }
  
  // If the anchor has changed, update booklet_count.booklet_nid
  $old_anchor = $form_state['values']['booklet'];
  if ($old_anchor != $new_anchor) {
      db_query('UPDATE {booklet_count} SET booklet_nid = %d WHERE booklet_nid=%d', $new_anchor, $old_anchor);
  }
  
  foreach($new_weights as $nid => $weight) {
      db_query('UPDATE {booklet} SET weight=%d, booklet_nid = %d WHERE nid=%d', $weight, $new_anchor, $nid);
  }

  booklet_rebuild_aliases(array_keys($new_weights));
  
  drupal_goto("node/$new_anchor");
  
}

/*********
 *  Node delete form
 **********/

/**
 * Menu callback -- ask for confirmation of node deletion
 * We're using out own form instead of the standard one provided by the node module
 * because we may have to show a list of nodes in booklet to be deleted.
 */
function booklet_delete_confirm(&$form_state, $node) {
  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $node->nid,
  );

  if (variable_get('booklet_delete_all', 0) && !empty($node->booklet) && $node->booklet['numitems'] > 1) {
    $description = t('<p>You are deleting a booklet.  The following items will be deleted:</p>');
    $description .= '<ul>';
    foreach ($node->booklet['items'] as $item) {
      if ($item['title']) {
        $description .= "<li>{$item['title']}</li>";
      }
    }
    $description .= '</ul>';
  }
  else {
    $description = t('This action cannot be undone. ');
  }
  
  return confirm_form($form,
    t('Are you sure you want to delete %title?', array('%title' => $node->title)),
    isset($_GET['destination']) ? $_GET['destination'] : 'node/'. $node->nid,
    $description,
    t('Delete'),
    t('Cancel')
  );
}


/**
 * Execute node deletion
 */
function booklet_delete_confirm_submit($form, &$form_state) {
  // just use the node module's delete confirmation submit function.  The deletion of all 
  // the other pages in the booklet will be handled in the hook_nodeapi
  module_load_include('inc', 'node', 'node.pages');
  node_delete_confirm_submit($form, $form_state);
}

