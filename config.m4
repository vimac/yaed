dnl $Id$
dnl config.m4 for extension yaed

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(yaed, for yaed support,
dnl Make sure that the comment is aligned:
dnl [  --with-yaed             Include yaed support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(yaed, whether to enable yaed support,
dnl Make sure that the comment is aligned:
[  --enable-yaed           Enable yaed support])

if test "$PHP_YAED" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-yaed -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/yaed.h"  # you most likely want to change this
  dnl if test -r $PHP_YAED/$SEARCH_FOR; then # path given as parameter
  dnl   YAED_DIR=$PHP_YAED
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for yaed files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       YAED_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$YAED_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the yaed distribution])
  dnl fi

  dnl # --with-yaed -> add include path
  dnl PHP_ADD_INCLUDE($YAED_DIR/include)

  dnl # --with-yaed -> check for lib and symbol presence
  dnl LIBNAME=yaed # you may want to change this
  dnl LIBSYMBOL=yaed # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $YAED_DIR/lib, YAED_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_YAEDLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong yaed lib version or lib not found])
  dnl ],[
  dnl   -L$YAED_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(YAED_SHARED_LIBADD)

  PHP_NEW_EXTENSION(yaed, yaed.c yaed_event_dispatcher.c yaed_event_subscriber.c yaed_event.c, $ext_shared)
fi
