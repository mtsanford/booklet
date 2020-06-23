<?php
// $Id$
/**
 * @file booklet-naviation.tpl.php
 * Default theme implementation to navigate booklets. 
 * Presented under nodes that are part of a booklet.
 *
 * Available variables:
 * - $prev_link: link to previous item node
 * - $next_link: link to previous item node
 * - $has_links: Flags TRUE whenever the previous or next data has a value.
 * - $items: a themed list of links to items in a booklet
 *
 * @see template_preprocess_booklet_navigation()
 */
?>
<?php if ($items || $has_links): ?>
  <div id="booklet-navigation-<?php print $node->nid ?>" class="booklet-navigation">
    <?php if ($items) : ?>
      <div class='booklet-items'><?php print $items; ?></div>
    <?php endif; ?>
    <?php if ($has_links): ?>
    <div class="page-links clear-block">
      <?php echo $prev_link; ?>
      <?php echo $next_link; ?>
    </div>
    <?php endif; ?>
  </div>
<?php endif; ?>
