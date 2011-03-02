dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(cavecanem_publisher, 0.1.1)

AC_CONFIG_MACRO_DIR([m4])
AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()

AC_PROG_CXX
AM_PROG_LIBTOOL

#--------------------------------------------------
#NDDS Cheking Stuff
#--------------------------------------------------
NDDS_CHECK

#--------------------------------------------------
#Boost Checking Stuff
#--------------------------------------------------
BOOST_REQUIRE([1.38.0])
#BOOST_THREADS
BOOST_OPTIONAL
BOOST_TYPETRAITS
BOOST_STATICASSERT
BOOST_TYPETRAITS
BOOST_SERIALIZATION
BOOST_UTILITY
BOOST_PREPROCESSOR
BOOST_BIND
BOOST_FUNCTION
BOOST_SMART_PTR

#--------------------------------------------------
# PKG MODULES
#--------------------------------------------------

PKG_CHECK_MODULES(libgtop,libgtop-2.0 >= 2.12)
AC_SUBST(libgtop_CFLAGS)
AC_SUBST(libgtop_LIBS)


AC_CONFIG_FILES([Makefile
                etc/Makefile
                src/Makefile
                src/plugins/Makefile
                src/plugins/disk/Makefile
		src/plugins/system_monitor/Makefile
		src/plugins/net_load/Makefile
		src/plugins/snort/Makefile])
AC_OUTPUT

