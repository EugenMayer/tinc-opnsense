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
    'name' => 'tincdcustom',
  );
  return $services;
}