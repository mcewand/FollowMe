<?php

global $base_url;
$plugin = array(
  'title' => t('Follow Me: RSS Connector'),
  'description' => t('Provide your RSS feed'),
  'callback' => 'follow_me_rss',
  'service name' => 'RSS',
  'url' => $base_url . '/',

);

function follow_me_rss() {
  $form = array();

  $types = variable_get('follow_me_type', array());
  if (isset($types['rss'])) {
    $is_active = ($types['rss']['active'] == 1) ? 1 : 0;
    $has_link = (isset($types['rss']['account']) == TRUE) ? $types['rss']['account'] : NULL;
  }

  $form['rss']['active'] = array(
    '#type' => 'checkbox',
    '#title' => t('RSS'),
    '#default_value' => (isset($is_active)) ? $is_active : 0,

    '#description' => t("Enable RSS?"),
    '#required' => FALSE,
  );
  $form['rss']['account'] = array(
    '#type' => 'textfield',
    '#title' => t('RSS URL'),
    '#default_value' => (isset($has_link)) ? $has_link :  NULL,
    '#size' => 60,
    '#maxlength' => 60,
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
