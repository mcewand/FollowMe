<?php

$plugin = array(
  'title' => t('Follow Me: Flickr Connector'),
  'description' => t('Connect your Flickr Account'),
  'callback' => 'follow_me_flickr',
  'service name' => 'Flickr',
  'url' => 'http://www.flickr.com/',

);

function follow_me_flickr() {
  $form = array();

  $types = variable_get('follow_me_type', array());
  if (isset($types['flickr'])) {
    $is_active = ($types['flickr']['active'] == 1) ? 1 : 0;
    $has_account = (isset($types['flickr']['account']) == TRUE) ? $types['flickr']['account'] : NULL;
  }

  $form['flickr']['active'] = array(
    '#type' => 'checkbox',
    '#title' => t('Flickr'),
    '#default_value' => (isset($is_active)) ? $is_active : 0,

    '#description' => t("Enable Flickr?"),
    '#required' => FALSE,
  );
  $form['flickr']['account'] = array(
    '#type' => 'textfield',
    '#title' => t('Flickr Username'),
    '#default_value' => (isset($has_account)) ? $has_account :  NULL,
    '#size' => 60,
    '#maxlength' => 60,
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
