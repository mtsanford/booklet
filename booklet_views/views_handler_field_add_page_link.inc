<?php
// $Id: $
/**
* Handler for showing add pages to booklet link.
 */
class views_handler_field_add_page_link extends views_handler_field {
  function construct() {
    parent::construct();

    // Add the node fields that add_page_link will need..
    $this->additional_fields['booklet_nid'] = array(
      'field' => 'booklet_nid',
    );
    $this->additional_fields['node_type'] = array(
      'table' => 'node',
      'field' => 'type',
    );
  }

    function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
  
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    return l(t('Add page'), 'node/add/' . $values->{$this->aliases['node_type']}, array('query' => array('booklet' =>  $values->{$this->aliases['booklet_nid']})));
  }

}

