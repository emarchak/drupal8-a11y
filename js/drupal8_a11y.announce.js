/**
 * @file drupal8_a11y.announce.js
 * Custom scrolling functionality to help keyboard navigation between anchor links.
 *
 */
(function ($, Drupal) {

  Drupal.behaviors.drupal8_a11y_weather = {
    attach: function (context) {

      $('#weatherWidget', context).once('weatherWidget').each(function () {
        $(this).after('<button class="btn btn-default" id="weatherWidgetButton">' + Drupal.t('Check the weather') + '</button><p id="weatherWidgetResults"></p>');
      });

      $(document).off('click').on('click', '#weatherWidgetButton',function (event){
        event.preventDefault();
        $.getJSON( "http://api.openweathermap.org/data/2.5/weather?q=Toronto&units=metric&appid=67d30ade4409447712a85ddd96b7b902",
          function( data ) {
            var updates = Drupal.t('@name is @temperatureºc with @weather', {
              '@name': data.name,
              '@temperature': data.main.temp,
              '@weather' : data.weather[0].description
            });

            Drupal.announce(updates, 'assertive');

            $( "#weatherWidgetResults" ).text(updates);
          });
      });

    }}

})(jQuery, Drupal);