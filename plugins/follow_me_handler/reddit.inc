<?php

$plugin = array(
  'title' => t('Follow Me: Reddit Connector'),
  'description' => t('Connect your Reddit Account'),
  'callback' => 'follow_me_reddit',
  'service name' => 'Reddit',
  'url' => 'http://www.reddit.com/user/',

);

function follow_me_reddit() {
  $form = array();

  $types = variable_get('follow_me_type', array());
  if (isset($types['reddit'])) {
    $is_active = ($types['reddit']['active'] == 1) ? 1 : 0;
    $has_account = (isset($types['reddit']['account']) == TRUE) ? $types['reddit']['account'] : NULL;
  }

  $form['reddit']['active'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reddit'),
    '#default_value' => (isset($is_active)) ? $is_active : 0,

    '#description' => t("Enable Reddit?"),
    '#required' => FALSE,
  );
  $form['reddit']['account'] = array(
    '#type' => 'textfield',
    '#title' => t('Reddit Username'),
    '#default_value' => (isset($has_account)) ? $has_account :  NULL,
    '#size' => 60,
    '#maxlength' => 60,
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
