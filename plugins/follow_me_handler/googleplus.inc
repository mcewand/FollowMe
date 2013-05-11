<?php

$plugin = array(
  'title' => t('Follow Me: Google+ Connector'),
  'description' => t('Connect your Google+ Account'),
  'callback' => 'follow_me_googleplus',
  'service name' => 'Google+',
  'url' => 'http://plus.github.com/',

);

function follow_me_googleplus() {
  $form = array();

  $types = variable_get('follow_me_type', array());
  if (isset($types['googleplus'])) {
    $is_active = ($types['googleplus']['active'] == 1) ? 1 : 0;
    $has_account = (isset($types['googleplus']['account']) == TRUE) ? $types['googleplus']['account'] : NULL;
  }

  $form['googleplus']['active'] = array(
    '#type' => 'checkbox',
    '#title' => t('Google+'),
    '#default_value' => (isset($is_active)) ? $is_active : 0,

    '#description' => t("Enable Google+?"),
    '#required' => FALSE,
  );
  $form['googleplus']['account'] = array(
    '#type' => 'textfield',
    '#title' => t('Google+ Username'),
    '#default_value' => (isset($has_account)) ? $has_account :  NULL,
    '#size' => 60,
    '#maxlength' => 60,
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
