/*
 * yaed_event_dispatcher.c
 *
 *  Created on: Nov 21, 2014
 *      Author: mac
 */


#include "php.h"
#include "php_ini.h"
#include "main/SAPI.h"
#include "Zend/zend_interfaces.h"
#include "ext/standard/php_var.h"
#include "ext/standard/basic_functions.h"

#include "php_yaed.h"
#include "yaed_event_dispatcher.h"

zend_class_entry *yaed_event_dispatcher_interface_ce;
zend_class_entry *yaed_event_dispatcher_ce;

/** {{{ ARG_INFO
 *  */
ZEND_BEGIN_ARG_INFO_EX(yaed_dispatcher_interface_dispatch_info, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(YAED_ARGINFO_PASS_BY_VALUE, eventName, IS_STRING, YAED_ARGINFO_NON_NULL)
	ZEND_ARG_OBJ_INFO(YAED_ARGINFO_PASS_BY_REF, event, YAED\\Event, YAED_ARGINFO_ALLOW_NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yaed_dispatcher_interface_add_listener_info, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(YAED_ARGINFO_PASS_BY_VALUE, eventName, IS_STRING, YAED_ARGINFO_NON_NULL)
	ZEND_ARG_TYPE_INFO(YAED_ARGINFO_PASS_BY_VALUE, listener, IS_CALLABLE, YAED_ARGINFO_NON_NULL)
	ZEND_ARG_TYPE_INFO(YAED_ARGINFO_PASS_BY_VALUE, priority, IS_LONG, YAED_ARGINFO_ALLOW_NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yaed_dispatcher_interface_add_subscriber_info, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(YAED_ARGINFO_PASS_BY_VALUE, listener, YAED\\EventSubscriberInterface, YAED_ARGINFO_NON_NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yaed_dispatcher_interface_remove_listener_info, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(YAED_ARGINFO_PASS_BY_VALUE, eventName, IS_STRING, YAED_ARGINFO_NON_NULL)
	ZEND_ARG_TYPE_INFO(YAED_ARGINFO_PASS_BY_VALUE, listener, IS_CALLABLE, YAED_ARGINFO_NON_NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yaed_dispatcher_interface_remove_subscriber_info, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(YAED_ARGINFO_PASS_BY_VALUE, listener, YAED\\EventSubscriberInterface, YAED_ARGINFO_NON_NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yaed_dispatcher_interface_get_listeners_info, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(YAED_ARGINFO_PASS_BY_VALUE, eventName, IS_STRING, YAED_ARGINFO_NON_NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yaed_dispatcher_interface_has_listeners_info, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(YAED_ARGINFO_PASS_BY_VALUE, eventName, IS_STRING, YAED_ARGINFO_NON_NULL)
ZEND_END_ARG_INFO()
/** }}} */

static zend_function_entry yaed_event_dispatcher_interface_functions[] = {
		PHP_ABSTRACT_ME(yaed_event_dispatcher_interface_ce, dispatch, yaed_dispatcher_interface_dispatch_info)
		PHP_ABSTRACT_ME(yaed_event_dispatcher_interface_ce, addListener, yaed_dispatcher_interface_add_listener_info)
		PHP_ABSTRACT_ME(yaed_event_dispatcher_interface_ce, addSubscriber, yaed_dispatcher_interface_add_subscriber_info)
		PHP_ABSTRACT_ME(yaed_event_dispatcher_interface_ce, removeListener, yaed_dispatcher_interface_remove_listener_info)
		PHP_ABSTRACT_ME(yaed_event_dispatcher_interface_ce, removeSubscriber, yaed_dispatcher_interface_remove_subscriber_info)
		PHP_ABSTRACT_ME(yaed_event_dispatcher_interface_ce, getListeners, yaed_dispatcher_interface_get_listeners_info)
		PHP_ABSTRACT_ME(yaed_event_dispatcher_interface_ce, hasListeners, yaed_dispatcher_interface_has_listeners_info)
		PHP_FE_END
};

PHP_METHOD(yaed_event_dispatcher_ce, __construct) {
	zval *pThis, *emptyArray;
	pThis = getThis();
	MAKE_STD_ZVAL(emptyArray);
	array_init(emptyArray);

	zend_update_property(yaed_event_dispatcher_ce, pThis, "listeners", strlen("listeners"), emptyArray TSRMLS_CC);
	zend_update_property(yaed_event_dispatcher_ce, pThis, "sorted", strlen("sorted"), emptyArray TSRMLS_CC);

	Z_DELREF_P(emptyArray);
}

PHP_METHOD(yaed_event_dispatcher_ce, dispatch) {

}

PHP_METHOD(yaed_event_dispatcher_ce, addListener) {

}

PHP_METHOD(yaed_event_dispatcher_ce, addSubscriber) {

}

PHP_METHOD(yaed_event_dispatcher_ce, removeListener) {

}

PHP_METHOD(yaed_event_dispatcher_ce, removeSubscriber) {

}

PHP_METHOD(yaed_event_dispatcher_ce, getListeners) {

}

PHP_METHOD(yaed_event_dispatcher_ce, hasListeners) {

}


static zend_function_entry yaed_event_dispatcher_functions[] = {
		PHP_ME(yaed_event_dispatcher_ce, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
		PHP_ME(yaed_event_dispatcher_ce, dispatch, yaed_dispatcher_interface_dispatch_info, ZEND_ACC_PUBLIC)
		PHP_ME(yaed_event_dispatcher_ce, addListener, yaed_dispatcher_interface_add_listener_info, ZEND_ACC_PUBLIC)
		PHP_ME(yaed_event_dispatcher_ce, addSubscriber, yaed_dispatcher_interface_add_subscriber_info, ZEND_ACC_PUBLIC)
		PHP_ME(yaed_event_dispatcher_ce, removeListener, yaed_dispatcher_interface_remove_listener_info, ZEND_ACC_PUBLIC)
		PHP_ME(yaed_event_dispatcher_ce, removeSubscriber, yaed_dispatcher_interface_remove_subscriber_info, ZEND_ACC_PUBLIC)
		PHP_ME(yaed_event_dispatcher_ce, getListeners, yaed_dispatcher_interface_get_listeners_info, ZEND_ACC_PUBLIC)
		PHP_ME(yaed_event_dispatcher_ce, hasListeners, yaed_dispatcher_interface_has_listeners_info, ZEND_ACC_PUBLIC)
		PHP_FE_END
};

YAED_STARTUP_FUNCTION(event_dispatcher){
	zend_class_entry ce_i;
	INIT_CLASS_ENTRY(ce_i, "YAED\\EventDispatcherInterface", yaed_event_dispatcher_interface_functions);
	yaed_event_dispatcher_interface_ce = zend_register_internal_interface(&ce_i TSRMLS_CC);

	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "YAED\\EventDispatcher", yaed_event_dispatcher_functions);
	yaed_event_dispatcher_ce = zend_register_internal_class(&ce TSRMLS_CC);
	zend_class_implements(yaed_event_dispatcher_ce TSRMLS_CC, 1, yaed_event_dispatcher_interface_ce);

	zend_declare_property_null(yaed_event_dispatcher_ce, "listeners", strlen("listeners"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(yaed_event_dispatcher_ce, "sorted", strlen("sorted"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;
}

