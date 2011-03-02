LIBCAVECANEM_PUBLISHER_DISK_VERSION=1:0:0

lib_LTLIBRARIES = libcavecanem_publisher_disk.la

noinst_HEADERS= \
	disk.hpp \
	disk_ddsSupport.h \
	disk_dds.h \
	$(top_srcdir)/src/plugins/plugin.hpp \
	disk_ddsPlugin.h

libcavecanem_publisher_disk_la_SOURCES = \
	disk.cpp \
	disk_ddsSupport.cxx \
	disk_dds.cxx \
	disk_ddsPlugin.cxx 

EXTRA_DIST=disk_dds.idl

INCLUDES=-I$(top_srcdir)/src
INCLUDES+=-I@includedir@
INCLUDES+=$(libgtop_CFLAGS)

CFLAGS = -DRTI_UNIX -DRTI_LINUX 

libcavecanem_publisher_disk_la_CXXFLAGS = -shared  -Wall -g -c $(INCLUDES) $(NDDS_INCLUDES) $(CFLAGS) -DSYSCONFDIR=\"$(sysconfdir)/cavecanem/\"
libcavecanem_publisher_disk_la_LIBADD = $(libgtop_LIBS)
libcavecanem_publisher_disk_la_LDFLAGS = -version-info $(LIBCAVECANEM_PUBLISHER_DISK_VERSION)
