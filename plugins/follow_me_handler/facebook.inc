<?php

$plugin = array(
  'title' => t('Follow Me: Facebook Connector'),
  'description' => t('Connect your Facebook Account'),
  'callback' => 'follow_me_facebook',
  'service name' => 'Facebook',
  'url' => 'http://www.facebook.com/',

);

function follow_me_facebook() {
  $form = array();

  $types = variable_get('follow_me_type', array());
  if (isset($types['facebook'])) {
    $is_active = ($types['facebook']['active'] == 1) ? 1 : 0;
    $has_account = (isset($types['facebook']['account']) == TRUE) ? $types['facebook']['account'] : NULL;
  }

  $form['facebook']['active'] = array(
    '#type' => 'checkbox',
    '#title' => t('Facebook'),
    '#default_value' => (isset($is_active)) ? $is_active : 0,

    '#description' => t("Enable Facebook?"),
    '#required' => FALSE,
  );
  $form['facebook']['account'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook Account'),
    '#default_value' => (isset($has_account)) ? $has_account :  NULL,
    '#size' => 60,
    '#maxlength' => 60,
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
