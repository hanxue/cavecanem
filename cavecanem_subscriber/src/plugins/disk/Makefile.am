LIBCAVECANEM_SUBSCRIBER_DISK_VERSION=1:0:0

lib_LTLIBRARIES = libcavecanem_subscriber_disk.la

noinst_HEADERS= \
	disk.hpp \
	disk_ddsSupport.h \
	disk_dds.h \
	$(top_srcdir)/src/plugins/plugin.hpp \
	disk_ddsPlugin.h

libcavecanem_subscriber_disk_la_SOURCES = \
	disk.cpp \
	disk_ddsSupport.cxx \
	disk_dds.cxx \
	disk_ddsPlugin.cxx

EXTRA_DIST=disk_dds.idl

INCLUDES=-I$(top_srcdir)/src
INCLUDES+=-I$(MYSQLPP_INC_DIR)
INCLUDES+=-I$(MYSQL_C_INC_DIR)
INCLUDES+=-I@includedir@

CFLAGS = -DRTI_UNIX -DRTI_LINUX

libcavecanem_subscriber_disk_la_CXXFLAGS = -shared  -Wall -g -c $(INCLUDES) $(NDDS_INCLUDES) $(CFLAGS) -DSYSCONFDIR=\"$(sysconfdir)/cavecanem/\"
libcavecanem_subscriber_disk_la_LIBADD =  -L$(MYSQLPP_LIB_DIR) -lmysqlpp -lmysqlclient
libcavecanem_subscriber_disk_la_LDFLAGS = -version-info $(LIBCAVECANEM_SUBSCRIBER_DISK_VERSION)
