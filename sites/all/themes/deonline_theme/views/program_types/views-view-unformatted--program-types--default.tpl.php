<?php
// $Id: views-view-unformatted.tpl.php,v 1.6 2008/10/01 20:52:11 merlinofchaos Exp $
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="oveflow-show grid16-8 row nested clearfix gruen-base equal-height">
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes[$id]; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
<?php print $image; ?>
</div>
<div id="program-descirption" class="row nested clearfix equal-height">
  fjsdkafjkl jfkldjsaflk djklfajds klfjsdk af
</div>


