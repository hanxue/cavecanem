LIBCAVECANEM_PUBLISHER_SNORT_VERSION=1:0:0

lib_LTLIBRARIES = libcavecanem_publisher_snort.la

noinst_HEADERS= \
	snort.hpp \
	ids_ddsSupport.h \
	ids_dds.h \
	$(top_srcdir)/src/plugins/plugin.hpp \
	ids_ddsPlugin.h
	
libcavecanem_publisher_snort_la_SOURCES = \
	snort.cpp \
	ids_ddsSupport.cxx \
	ids_dds.cxx \
	ids_ddsPlugin.cxx 

EXTRA_DIST=ids_dds.idl

INCLUDES=-I$(top_srcdir)/src
INCLUDES+=-I@includedir@

CFLAGS = -DRTI_UNIX -DRTI_LINUX

libcavecanem_publisher_snort_la_CXXFLAGS = -shared  -Wall -g -c $(INCLUDES) $(CFLAGS) $(NDDS_INCLUDES) -DSYSCONFDIR=\"$(sysconfdir)/cavecanem/\"
libcavecanem_publisher_snort_la_LDFLAGS= -version-info $(LIBCAVECANEM_PUBLISHER_SNORT_VERSION)
