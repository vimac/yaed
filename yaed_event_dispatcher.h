/*
 * yaed_event_dispatcher.h
 *
 *  Created on: Nov 21, 2014
 *      Author: mac
 */

#ifndef YAED_EVENT_DISPATCHER_H_
#define YAED_EVENT_DISPATCHER_H_

extern zend_class_entry *yaed_event_dispatcher_interface_ce;
extern zend_class_entry *yaed_event_dispatcher_ce;

PHP_METHOD(yaed_event_dispatcher_ce, __construct);
PHP_METHOD(yaed_event_dispatcher_ce, dispatch);
PHP_METHOD(yaed_event_dispatcher_ce, addListener);
PHP_METHOD(yaed_event_dispatcher_ce, addSubscriber);
PHP_METHOD(yaed_event_dispatcher_ce, removeListener);
PHP_METHOD(yaed_event_dispatcher_ce, removeSubscriber);
PHP_METHOD(yaed_event_dispatcher_ce, getListeners);
PHP_METHOD(yaed_event_dispatcher_ce, hasListeners);

YAED_STARTUP_FUNCTION(event_dispatcher);

#endif /* YAED_EVENT_DISPATCHER_H_ */
