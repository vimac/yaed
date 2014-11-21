--TEST--
Check for yaed presence
--SKIPIF--
<?php if (!extension_loaded("yaed")) print "skip"; ?>
--FILE--
<?php 
use YAED\EventDispatcher;
use YAED\Event;

echo isset(new EventDispatcher());
echo isset(new Event());
?>
--EXPECT--
11
