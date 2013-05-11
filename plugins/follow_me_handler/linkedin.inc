<?php

$plugin = array(
  'title' => t('Follow Me: LinkedIn Connector'),
  'description' => t('Connect your LinkedIn Account'),
  'callback' => 'follow_me_linkedin',
  'service name' => 'LinkedIn',
  'url' => 'http://www.linkedin.com/in/',

);

function follow_me_linkedin() {
  $form = array();

  $types = variable_get('follow_me_type', array());
  if (isset($types['linkedin'])) {
    $is_active = ($types['linkedin']['active'] == 1) ? 1 : 0;
    $has_account = (isset($types['linkedin']['account']) == TRUE) ? $types['linkedin']['account'] : NULL;
  }

  $form['linkedin']['active'] = array(
    '#type' => 'checkbox',
    '#title' => t('LinkedIn'),
    '#default_value' => (isset($is_active)) ? $is_active : 0,

    '#description' => t("Enable LinkedIn?"),
    '#required' => FALSE,
  );
  $form['linkedin']['account'] = array(
    '#type' => 'textfield',
    '#title' => t('LinkedIn Username'),
    '#default_value' => (isset($has_account)) ? $has_account :  NULL,
    '#size' => 60,
    '#maxlength' => 60,
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
