
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from disk_dds.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#include "disk_ddsSupport.h"
#include "disk_ddsPlugin.h"



#ifdef __cplusplus  
    #ifndef dds_c_log_impl_h              
         #include "dds_c/dds_c_log_impl.h"                                
    #endif        
#endif        




/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'host_info' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   host_infoTYPENAME

/* Defines */
#define TDataWriter host_infoDataWriter
#define TData       host_info


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   host_infoTYPENAME

/* Defines */
#define TDataReader host_infoDataReader
#define TDataSeq    host_infoSeq
#define TData       host_info


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    host_infoTYPENAME
#define TPlugin_new  host_infoPlugin_new
#define TPlugin_delete  host_infoPlugin_delete

/* Defines */
#define TTypeSupport host_infoTypeSupport
#define TData        host_info
#define TDataReader  host_infoDataReader
#define TDataWriter  host_infoDataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'filesystem' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   filesystemTYPENAME

/* Defines */
#define TDataWriter filesystemDataWriter
#define TData       filesystem


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   filesystemTYPENAME

/* Defines */
#define TDataReader filesystemDataReader
#define TDataSeq    filesystemSeq
#define TData       filesystem


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    filesystemTYPENAME
#define TPlugin_new  filesystemPlugin_new
#define TPlugin_delete  filesystemPlugin_delete

/* Defines */
#define TTypeSupport filesystemTypeSupport
#define TData        filesystem
#define TDataReader  filesystemDataReader
#define TDataWriter  filesystemDataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete


