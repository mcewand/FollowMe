<section id="follow">
  <!-- @todo move this to a foreach -->
  <?php foreach ($sites as $site => $link): ?>
    <div class="<?php print $site; ?>-follow" style="<?php print $style; ?>">
      <?php print $link; ?>
    </div>
  <?php endforeach; ?>
</section>
