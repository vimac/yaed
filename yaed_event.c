/*
 * yaed_event.c
 *
 *  Created on: Nov 20, 2014
 *      Author: mac
 */


#include "php.h"
#include "php_ini.h"
#include "main/SAPI.h"
#include "Zend/zend_interfaces.h"
#include "ext/standard/php_var.h"
#include "ext/standard/basic_functions.h"

#include "php_yaed.h"
#include "yaed_event.h"

zend_class_entry *yaed_event_ce;

/** {{{ ARG_INFO
 *  */
ZEND_BEGIN_ARG_INFO_EX(yaed_event_is_propagation_stopped_info, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yaed_event_stop_propagation_info, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yaed_event_get_dispatcher_info, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yaed_event_set_dispatcher_info, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(YAED_ARGINFO_PASS_BY_REF, event, YAED\EventDispatcher, YAED_ARGINFO_NON_NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yaed_event_get_name_info, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yaed_event_set_name_info, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(YAED_ARGINFO_PASS_BY_VALUE, name, IS_STRING, YAED_ARGINFO_NON_NULL)
ZEND_END_ARG_INFO()
/** }}} */

PHP_METHOD(yaed_event_ce, isPropagationStopped)
{

}

PHP_METHOD(yaed_event_ce, stopPropagation)
{

}

PHP_METHOD(yaed_event_ce, getDispatcher)
{

}

PHP_METHOD(yaed_event_ce, setDispatcher)
{

}

PHP_METHOD(yaed_event_ce, getName)
{

}

PHP_METHOD(yaed_event_ce, setName)
{

}

static zend_function_entry yaed_event_functions[] = {
		PHP_ME(yaed_event_ce, isPropagationStopped, yaed_event_is_propagation_stopped_info, ZEND_ACC_PUBLIC)
		PHP_ME(yaed_event_ce, stopPropagation, yaed_event_stop_propagation_info, ZEND_ACC_PUBLIC)
		PHP_ME(yaed_event_ce, getDispatcher, yaed_event_get_dispatcher_info, ZEND_ACC_PUBLIC)
		PHP_ME(yaed_event_ce, setDispatcher, yaed_event_set_dispatcher_info, ZEND_ACC_PUBLIC)
		PHP_ME(yaed_event_ce, getName, yaed_event_get_name_info, ZEND_ACC_PUBLIC)
		PHP_ME(yaed_event_ce, setName, yaed_event_set_name_info, ZEND_ACC_PUBLIC)
		PHP_FE_END
};

YAED_STARTUP_FUNCTION(event) {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "YAED\\Event", yaed_event_functions);
    yaed_event_ce = zend_register_internal_class(&ce TSRMLS_CC);

    zend_declare_property_bool(yaed_event_ce, "dispatcher", strlen("dispatcher"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_null(yaed_event_ce, "name", strlen("name"), ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_null(yaed_event_ce, "propagationStopped", strlen("propagationStopped"), ZEND_ACC_PRIVATE TSRMLS_CC);

    return SUCCESS;
}
