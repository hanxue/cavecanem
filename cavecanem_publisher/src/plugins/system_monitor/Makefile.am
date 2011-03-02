LIBCAVECANEM_PUBLISHER_SYSTEM_MONITOR_VERSION=1:0:0

lib_LTLIBRARIES = libcavecanem_publisher_system_monitor.la

noinst_HEADERS= \
	system_monitor.hpp \
	system_monitor_ddsSupport.h \
	system_monitor_dds.h \
	$(top_srcdir)/src/plugins/plugin.hpp \
	system_monitor_ddsPlugin.h
 
libcavecanem_publisher_system_monitor_la_SOURCES = \
	system_monitor.cpp \
	system_monitor_ddsSupport.cxx \
	system_monitor_dds.cxx \
	system_monitor_ddsPlugin.cxx

EXTRA_DIST=system_monitor_dds.idl
	
INCLUDES=-I$(top_srcdir)/src
INCLUDES+=-I@includedir@
INCLUDES+=$(libgtop_CFLAGS)

CFLAGS = -DRTI_UNIX -DRTI_LINUX 

libcavecanem_publisher_system_monitor_la_CXXFLAGS = -shared  -Wall -g -c $(INCLUDES) $(CFLAGS)  $(NDDS_INCLUDES) -DSYSCONFDIR=\"$(sysconfdir)/cavecanem/\"
libcavecanem_publisher_system_monitor_la_LIBADD = $(libgtop_LIBS)
libcavecanem_publisher_system_monitor_la_LDFLAGS= -version-info $(LIBCAVECANEM_PUBLISHER_SYSTEM_MONITOR_VERSION)
