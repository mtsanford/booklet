/* $Id$ */

Drupal.behaviors.Booklet = function (context) {
    $('tr.notdraggable', $('table#booklet-items-table')).each(function(item) { 
      var self = this;
      // Create the handle.
      var handle = $('<a href="#" class="nottabledrag-handle"><div class="handle">&nbsp;</div></a>').attr('title', Drupal.t('This item cannot be moved'));
      // Insert the handle after indentations (if any).
      if ($('td:first .indentation:last', item).after(handle).size()) {
        // Update the total width of indentation in this entire table.
        self.indentCount = Math.max($('.indentation', item).size(), self.indentCount);
      }
      else {
        $('td:first', item).prepend(handle);
      }

    });
};

