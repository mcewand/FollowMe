(function ($) {
  Drupal.behaviors.followMe = {
    attach: function (context, settings) {

      $('#edit-follow-me-type .form-type-textfield').each(function() {
        if ( $(this).prev().children('input').is(':checked') == 0 ) {
          $(this).hide();
        }

      });

      $('#edit-follow-me-type .form-type-checkbox').click(function(){
        $(this).next().toggle('fast');

      });
    }
  };
})(jQuery);
