<?php
/**
 * @global $config
 */

/**
 * register legacy service
 * @return array
 */
function tincdcustom_services()
{
  $services = array();
  $services[] = array(
    'description' => gettext('Tincd Custom'),
    'configd' => array(
      'restart' => array('tincdcustom restart'),
      'start' => array('tincdcustom start'),
      'stop' => array('tincdcustom stop'),
    ),
    'name' => 'tincd', // this one is actually used for pgrep to check the status of the daemon, so we need to choose the daemon name
  );
  return $services;
}