<?php
/**
 * @file forms.inc
 * Overrides for accessible form elements.
 */

/**
 * Helper function to clean up required for accessibility.
 *
 * @param array $variables
 */
function _drupal8_a11y_accessible_required_forms(&$variables = []) {
  // Remove the HTML5 "required" attribute to correct NVDA performace.
  // http://usability.com.au/2013/05/accessible-forms-2-required-fields-and-extra-information
  if (isset($variables['attributes']['required'])) {
    unset($variables['attributes']['required']);
  }
}

/**
 * Implements template_preprocess_select().
 */
function drupal8_a11y_preprocess_select(&$variables) {
  _drupal8_a11y_accessible_required_forms($variables);
}

/**
 * Implements template_preprocess_checkboxes().
 */
function drupal8_a11y_preprocess_checkboxes(&$variables) {
  _drupal8_a11y_accessible_required_forms($variables);
}

/**
 * Implements template_preprocess_input().
 */
function drupal8_a11y_preprocess_input(&$variables) {
  _drupal8_a11y_accessible_required_forms($variables);
}

/**
 * Implements template_preprocess_radios().
 */
function drupal8_a11y_preprocess_radios(&$variables) {
  _drupal8_a11y_accessible_required_forms($variables);
}

/**
 * Implements template_preprocess_textarea().
 */
function drupal8_a11y_preprocess_textarea(&$variables) {
  _drupal8_a11y_accessible_required_forms($variables);
}
