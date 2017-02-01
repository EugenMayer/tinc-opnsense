<?php

/**
 *  register legacy service
 * @return array
 */
function tincdcustom_services()
{
  global $config;
  $services = array();
  if (isset($config['OPNsense']['HAProxy']['general']['enabled']) && $config['OPNsense']['HAProxy']['general']['enabled'] == 1) {
    $services[] = array(
      'description' => gettext('HAProxy load balancer'),
      'configd' => array(
        'restart' => array('haproxy restart'),
        'start' => array('haproxy start'),
        'stop' => array('haproxy stop'),
      ),
      'name' => 'haproxy',
    );
  }
  return $services;
}