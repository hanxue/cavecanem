LIBCAVECANEM_SUBSCRIBER_NET_LOAD_VERSION=1:0:0

lib_LTLIBRARIES = libcavecanem_subscriber_net_load.la

noinst_HEADERS= \
	net_load.hpp \
	net_load_ddsSupport.h \
	net_load_dds.h \
	$(top_srcdir)/src/plugins/plugin.hpp \
	net_load_ddsPlugin.h

libcavecanem_subscriber_net_load_la_SOURCES = \
	net_load.cpp \
	net_load_ddsSupport.cxx \
	net_load_dds.cxx \
	net_load_ddsPlugin.cxx

EXTRA_DIST=net_load_dds.idl

INCLUDES=-I$(top_srcdir)/src
INCLUDES+=-I$(MYSQLPP_INC_DIR)
INCLUDES+=-I$(MYSQL_C_INC_DIR)
INCLUDES+=-I@includedir@

CFLAGS = -DRTI_UNIX -DRTI_LINUX

libcavecanem_subscriber_net_load_la_CXXFLAGS = -shared  -Wall -g -c $(INCLUDES) $(NDDS_INCLUDES) $(CFLAGS) -DSYSCONFDIR=\"$(sysconfdir)/cavecanem/\"
libcavecanem_subscriber_net_load_la_LIBADD =  -L$(MYSQLPP_LIB_DIR) -lmysqlpp -lmysqlclient
libcavecanem_subscriber_net_load_la_LDFLAGS = -version-info $(LIBCAVECANEM_SUBSCRIBER_NET_LOAD_VERSION)
