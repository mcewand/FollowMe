<?php

$plugin = array(
  'title' => t('Follow Me: Github Connector'),
  'description' => t('Connect your Github Account'),
  'callback' => 'follow_me_github',
  'service name' => 'Github',
  'url' => 'http://www.github.com/',

);

function follow_me_github() {
  $form = array();

  $types = variable_get('follow_me_type', array());
  if (isset($types['github'])) {
    $is_active = ($types['github']['active'] == 1) ? 1 : 0;
    $has_account = (isset($types['github']['account']) == TRUE) ? $types['github']['account'] : NULL;
  }

  $form['github']['active'] = array(
    '#type' => 'checkbox',
    '#title' => t('Github'),
    '#default_value' => (isset($is_active)) ? $is_active : 0,

    '#description' => t("Enable Github?"),
    '#required' => FALSE,
  );
  $form['github']['account'] = array(
    '#type' => 'textfield',
    '#title' => t('Github Username'),
    '#default_value' => (isset($has_account)) ? $has_account :  NULL,
    '#size' => 60,
    '#maxlength' => 60,
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
