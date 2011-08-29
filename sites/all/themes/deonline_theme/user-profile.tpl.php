<div class="grid16-inner-8 nested row">
  <?php print $profile['content_profile']; ?>
</div>
<div class="grid16-inner-8 nested row right">
    <div class="grid16-inner-8 nested row right">
      <div class="grid16-inner-5 nested row">
        <?php print $group_program_type_prices_rendered; ?>
        <?php print $subscribe_link; ?>
      </div>
      <div class="grid16-inner-3  nested row right">
        <?php if ($field_pt_book_rendered): ?>
          <h2> <?php print t('Учебник'); ?></h2>
          <?php print $field_pt_book_rendered; ?>
        <?php endif; ?>
      </div>
    </div>
    <div class="grid16-inner-8 nested row right">
      <h2> <?php print t(''); ?></h2>
      <?php print views_embed_view('node_program_type_teacher', 'node_program_type', $node->nid); ?>
    </div>
</div>
