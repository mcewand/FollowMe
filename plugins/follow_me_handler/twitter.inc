<?php

$plugin = array(
  'title' => t('Follow Me: Twitter Connector'),
  'description' => t('Connect your Twitter Account'),
  'callback' => 'follow_me_twitter',
  'service name' => 'Twitter',
  'url' => 'http://www.twitter.com/#!/',

);

function follow_me_twitter() {
  $form = array();

  $types = variable_get('follow_me_type', array());
  if (isset($types['twitter'])) {
    $is_active = ($types['twitter']['active'] == 1) ? 1 : 0;
    $has_account = (isset($types['twitter']['account']) == TRUE) ? $types['twitter']['account'] : '';
  }

  $form['twitter']['active'] = array(
    '#type' => 'checkbox',
    '#title' => t('Twitter'),
    '#default_value' => (isset($is_active)) ? $is_active : 0,

    '#description' => t("Enable Twitter?"),
    '#required' => FALSE,
  );
  $form['twitter']['account'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Handle'),
    '#default_value' => (isset($has_account)) ? $has_account :  NULL,
    '#size' => 60,
    '#maxlength' => 60,
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
