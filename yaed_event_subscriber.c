/*
 * yaed_event_subscriber.c
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
#include "yaed_event_subscriber.h"

zend_class_entry *yaed_event_subscriber_interface_ce;

/** {{{ ARG_INFO
 *  */
ZEND_BEGIN_ARG_INFO_EX(yaed_subscriber_interface_get_subscribed_events_info, 0, 0, 0)
ZEND_END_ARG_INFO()
/** }}} */

static zend_function_entry yaed_event_subscriber_interface_functions[] = {
        ZEND_FENTRY(getSubscribedEvents, NULL, yaed_subscriber_interface_get_subscribed_events_info, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT | ZEND_ACC_STATIC)
        PHP_FE_END
};

YAED_STARTUP_FUNCTION(event_subscriber){
    zend_class_entry ce_i;
    INIT_CLASS_ENTRY(ce_i, "YAED\\EventSubscriberInterface", yaed_event_subscriber_interface_functions);
    yaed_event_subscriber_interface_ce = zend_register_internal_interface(&ce_i TSRMLS_CC);

    return SUCCESS;
}

