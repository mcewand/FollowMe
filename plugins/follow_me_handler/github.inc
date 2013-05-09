$plugin = array(
  'title' => t('Follow Me: Github Connector'),
  'description' => t('Connect your Github Account'),
  'callback' => 'follow_me_github_ctools_access_check', //this should be where things happen
  'default' => array('field_age_value' => 0),
  'settings form' => 'follow_me_github_ctools_settings',
  'summary' => 'follow_me_github_ctools_summary',
);

function follow_me_github_ctools_access_check(){

  return TRUE;

}

function follow_me_github_ctools_settings($form, &$form_state, $conf){
  $form['settings']['github'] = array(
    '#type' => 'checkbox',
    '#title' => t('Github'),
    '#description' => t('Connect your github account'),
    '#default_value' => $conf['github'],
  );
  return $form;

}

function follow_me_github_ctools_summary(){

}

function follow_me_github_config() {
  $form = array();

  $types = variable_get('follow_me_type', array());
  $form['follow_me_type']['github']['active'] = array(
    '#type' => 'checkbox',
    '#title' => t('Github'),
    '#default_value' => (($types['github']['active'] == 1) ? 1 : 0),

    '#description' => t("Enable Github?"),
    '#required' => FALSE,
  );
  $form['follow_me_type']['github']['account'] = array(
    '#type' => 'textfield',
    '#title' => t('Github'),
    '#default_value' => ((isset($types['github']['account']) == TRUE) ? $types['github']['account'] : NULL),
    '#size' => 60,
    '#maxlength' => 60,
    '#description' => t("Enter your Github user name"),
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
