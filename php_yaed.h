/*
 +----------------------------------------------------------------------+
 | PHP Version 5                                                        |
 +----------------------------------------------------------------------+
 | Copyright (c) 1997-2014 The PHP Group                                |
 +----------------------------------------------------------------------+
 | This source file is subject to version 3.01 of the PHP license,      |
 | that is bundled with this package in the file LICENSE, and is        |
 | available through the world-wide-web at the following url:           |
 | http://www.php.net/license/3_01.txt                                  |
 | If you did not receive a copy of the PHP license and are unable to   |
 | obtain it through the world-wide-web, please send a note to          |
 | license@php.net so we can mail you a copy immediately.               |
 +----------------------------------------------------------------------+
 | Author: Mac Chow(vifix.mac@gmail.com)                                |
 +----------------------------------------------------------------------+
 */

/* $Id$ */

#ifndef PHP_YAED_H
#define PHP_YAED_H

extern zend_module_entry yaed_module_entry;
#define phpext_yaed_ptr &yaed_module_entry

#define PHP_YAED_VERSION "0.1.0" /* Replace with version number for your extension */

#define YAED_ARGINFO_PASS_BY_REF 1
#define YAED_ARGINFO_PASS_BY_VALUE 0
#define YAED_ARGINFO_ALLOW_NULL 1
#define YAED_ARGINFO_NON_NULL 0

#define YAED_PROPERTY_LISTENERS	"listeners"
#define YAED_PROPERTY_SORTED "sorted"
#define YAED_PROPERTY_NAME "name"
#define YAED_PROPERTY_DISPATCHER "dispatcher"
#define YAED_PROPERTY_PROPAGATION_STOPPED "propagationStopped"

#ifdef PHP_WIN32
#define PHP_YAED_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#define PHP_YAED_API __attribute__ ((visibility("default")))
#else
#define PHP_YAED_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/* 
 Declare any global variables you may need between the BEGIN
 and END macros here:

 ZEND_BEGIN_MODULE_GLOBALS(yaed)
 long  global_value;
 char *global_string;
 ZEND_END_MODULE_GLOBALS(yaed)
 */

/* In every utility function you add that needs to use variables 
 in php_yaed_globals, call TSRMLS_FETCH(); after declaring other
 variables used by that function, or better yet, pass in TSRMLS_CC
 after the last function argument and declare your utility function
 with TSRMLS_DC after the last declared argument.  Always refer to
 the globals in your function as YAED_G(variable).  You are
 encouraged to rename these macros something shorter, see
 examples in any other php module directory.
 */

#ifdef ZTS
#define YAED_G(v) TSRMG(yaed_globals_id, zend_yaed_globals *, v)
#else
#define YAED_G(v) (yaed_globals.v)
#endif

#define YAED_VERSION "0.0.1"

#define YAED_STARTUP_FUNCTION(module)   ZEND_MINIT_FUNCTION(yaed_##module)
#define YAED_RINIT_FUNCTION(module)ZEND_RINIT_FUNCTION(yaed_##module)
#define YAED_STARTUP(module)   ZEND_MODULE_STARTUP_N(yaed_##module)(INIT_FUNC_ARGS_PASSTHRU)
#define YAED_SHUTDOWN_FUNCTION(module)  ZEND_MINIT_FUNCTION(yaed_##module)
#define YAED_SHUTDOWN(module)     ZEND_MODULE_SHUTDOWN_N(yaed_##module)(INIT_FUNC_ARGS_PASSTHRU)

#endif /* PHP_YAED_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
