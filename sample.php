<?php
require_once('template.class.inc');
$template = new Template('template.tpl');
$template->bind('list', array(10,'<A&B>',NULL));

$template->display(array('h1' => 'hedgehog'));

