LIBCAVECANEM_SUBSCRIBER_IDS_VERSION=1:0:0

lib_LTLIBRARIES = libcavecanem_subscriber_ids.la

noinst_HEADERS= \
	ids.hpp \
	ids_ddsSupport.h \
	ids_dds.h \
	$(top_srcdir)/src/plugins/plugin.hpp \
	ids_ddsPlugin.h

libcavecanem_subscriber_ids_la_SOURCES = \
	ids.cpp \
	ids_ddsSupport.cxx \
	ids_dds.cxx \
	ids_ddsPlugin.cxx

EXTRA_DIST=ids_dds.idl

INCLUDES=-I$(top_srcdir)/src
INCLUDES+=-I$(MYSQLPP_INC_DIR)
INCLUDES+=-I$(MYSQL_C_INC_DIR)
INCLUDES+=-I@includedir@

CFLAGS = -DRTI_UNIX -DRTI_LINUX

libcavecanem_subscriber_ids_la_CXXFLAGS = -shared  -Wall -g -c $(INCLUDES) $(NDDS_INCLUDES) $(CFLAGS) -DSYSCONFDIR=\"$(sysconfdir)/cavecanem/\"
libcavecanem_subscriber_ids_la_LIBADD = -L$(MYSQLPP_LIB_DIR) -lmysqlpp -lmysqlclient
libcavecanem_subscriber_ids_la_LDFLAGS= -version-info $(LIBCAVECANEM_SUBSCRIBER_IDS_VERSION)
