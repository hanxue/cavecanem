LIBCAVECANEM_SUBSCRIBER_SYSTEM_MONITOR_VERSION=1:0:0

lib_LTLIBRARIES = libcavecanem_subscriber_system_monitor.la

noinst_HEADERS= \
	system_monitor.hpp \
	system_monitor_ddsSupport.h \
	system_monitor_dds.h \
	$(top_srcdir)/src/plugins/plugin.hpp \
	system_monitor_ddsPlugin.h

libcavecanem_subscriber_system_monitor_la_SOURCES = \
	system_monitor.cpp \
	system_monitor_ddsSupport.cxx \
	system_monitor_dds.cxx \
	system_monitor_ddsPlugin.cxx

EXTRA_DIST=system_monitor_dds.idl

INCLUDES=-I$(top_srcdir)/src
INCLUDES+=-I/usr/include
INCLUDES+=-I$(MYSQLPP_INC_DIR)
INCLUDES+=-I$(MYSQL_C_INC_DIR)
INCLUDES+=-I@includedir@

CFLAGS = -DRTI_UNIX -DRTI_LINUX

libcavecanem_subscriber_system_monitor_la_CXXFLAGS = -shared  -Wall -g -c $(INCLUDES) $(NDDS_INCLUDES) $(CFLAGS) -DSYSCONFDIR=\"$(sysconfdir)/cavecanem/\"
libcavecanem_subscriber_system_monitor_la_LIBADD = -L$(MYSQLPP_LIB_DIR) -lmysqlpp -lmysqlclient
libcavecanem_subscriber_system_monitor_la_LDFLAGS= -version-info $(LIBCAVECANEM_SUBSCRIBER_SYSTEM_MONITOR_VERSION)
