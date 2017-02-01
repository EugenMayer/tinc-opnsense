<?php

/**
 *  register legacy service
 * @return array
 */
function tincdcustom_services()
{
  global $config;
  $services = array();
  if (isset($config['OPNsense']['tincdcustom']['general']['enabled']) && $config['OPNsense']['tincdcustom']['general']['enabled'] == 1) {
    $services[] = array(
      'description' => gettext('Tincd'),
      'configd' => array(
        'restart' => array('tincdcustom restart'),
        'start' => array('tincdcustom start'),
        'stop' => array('tincdcustom stop'),
      ),
      'name' => 'tincdcustom',
    );
  }
  return $services;
}