/*
 * yaed_event.h
 *
 *  Created on: Nov 21, 2014
 *      Author: mac
 */

#ifndef YAED_EVENT_H_
#define YAED_EVENT_H_

extern zend_class_entry *yaed_event_ce;

PHP_METHOD(yaed_event_ce, isPropagationStopped);
PHP_METHOD(yaed_event_ce, stopPropagation);
PHP_METHOD(yaed_event_ce, getDispatcher);
PHP_METHOD(yaed_event_ce, setDispatcher);
PHP_METHOD(yaed_event_ce, getName);
PHP_METHOD(yaed_event_ce, setName);

YAED_STARTUP_FUNCTION(event);

#endif /* YAED_EVENT_H_ */
