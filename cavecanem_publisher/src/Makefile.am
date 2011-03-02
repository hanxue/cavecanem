bin_PROGRAMS=cavecanem-publisher

SUBDIRS=plugins

distdir=@includedir@

nobase_dist_HEADERS= \
	boost/extension/extension.hpp \
	boost/extension/factory.hpp \
	boost/extension/type_map.hpp \
	boost/extension/impl/decl.hpp \
	boost/extension/common.hpp \
	boost/extension/impl/create.hpp \
	boost/extension/impl/typeinfo.hpp \
	boost/extension/impl/create_func.hpp \
    boost/extension/impl/factory.hpp \
    boost/extension/convenience.hpp \
    boost/extension/factory_map.hpp \
    boost/extension/impl/factory_map.hpp \
    boost/extension/shared_library.hpp \
    boost/extension/impl/library_impl.hpp \
    boost/extension/impl/shared_library.hpp \
	boost/property_tree/ptree.hpp \
	boost/property_tree/xml_parser.hpp \
	boost/property_tree/string_path.hpp \
	boost/property_tree/stream_translator.hpp \
	boost/property_tree/exceptions.hpp \
	boost/property_tree/detail/ptree_utils.hpp \
	boost/property_tree/detail/ptree_implementation.hpp \
	boost/property_tree/detail/xml_parser_write.hpp \
	boost/property_tree/detail/xml_parser_error.hpp \
	boost/property_tree/detail/xml_parser_writer_settings.hpp \
	boost/property_tree/detail/xml_parser_flags.hpp \
	boost/property_tree/detail/xml_parser_read_rapidxml.hpp \
	boost/property_tree/ptree_fwd.hpp \
	boost/property_tree/id_translator.hpp \
	boost/property_tree/detail/exception_implementation.hpp \
	boost/property_tree/detail/xml_parser_utils.hpp \
	boost/property_tree/detail/file_parser_error.hpp \
	boost/property_tree/detail/rapidxml.hpp 

INCLUDES=-I$(srcdir)
INCLUDES+=-I@includedir@

LNDDSLIBS=$(NDDS_LIB_DIR)
NDDSLIBS = -lnddsc -lnddscore -lnddscpp
CFLAGS = -DRTI_UNIX -DRTI_LINUX 

cavecanem_publisher_CPPFLAGS = $(INCLUDES) $(CFLAGS) $(NDDS_INCLUDES) -DSYSCONFDIR=\"$(sysconfdir)/cavecanem/\" -DLIBDIR=\"$(libdir)/\" #$(BOOST_CPPFLAGS)
cavecanem_publisher_LDFLAGS = -ldl -lm -lnsl -lrt -rdynamic  -L$(LNDDSLIBS) $(NDDSLIBS)
#cavecanem_publisher_LDADD =   $(BOOST_THREAD_LIBS)
cavecanem_publisher_SOURCES=cavecanem_publisher.cpp

