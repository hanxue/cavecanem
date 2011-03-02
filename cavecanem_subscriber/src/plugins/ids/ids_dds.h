
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from ids_dds.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef ids_dds_1288804104937_h
#define ids_dds_1288804104937_h

#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
#else
    #include "ndds_standalone_type.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *host_infoTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct host_info
{
    char*  hostname; /* maximum length = (255) */
    char*  sysname; /* maximum length = (255) */
    char*  release_name; /* maximum length = (255) */
    char*  machine; /* maximum length = (255) */

} host_info;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* host_info_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(host_infoSeq, host_info);
        
NDDSUSERDllExport
RTIBool host_info_initialize(
        host_info* self);
        
NDDSUSERDllExport
RTIBool host_info_initialize_ex(
        host_info* self,RTIBool allocatePointers);

NDDSUSERDllExport
void host_info_finalize(
        host_info* self);
                        
NDDSUSERDllExport
void host_info_finalize_ex(
        host_info* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool host_info_copy(
        host_info* dst,
        const host_info* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


typedef host_info  host_info_t;
        
        
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols. */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* host_info_t_get_typecode(void); /* Type code */
    
DDS_SEQUENCE(host_info_tSeq, host_info_t);                                        
            
NDDSUSERDllExport
RTIBool host_info_t_initialize(
        host_info_t* self);
            
NDDSUSERDllExport
RTIBool host_info_t_initialize_ex(
        host_info_t* self,RTIBool allocatePointers);
                    
NDDSUSERDllExport
void host_info_t_finalize(
        host_info_t* self);
            
NDDSUSERDllExport
void host_info_t_finalize_ex(
        host_info_t* self,RTIBool deletePointers);
                    
NDDSUSERDllExport
RTIBool host_info_t_copy(
        host_info_t* dst,
        const host_info_t* src);

    

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols. */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *node_infoTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct node_info
{
    DDS_UnsignedShort  prt;
    char*  network_addr; /* maximum length = (15) */
    char*  mac; /* maximum length = (17) */

} node_info;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* node_info_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(node_infoSeq, node_info);
        
NDDSUSERDllExport
RTIBool node_info_initialize(
        node_info* self);
        
NDDSUSERDllExport
RTIBool node_info_initialize_ex(
        node_info* self,RTIBool allocatePointers);

NDDSUSERDllExport
void node_info_finalize(
        node_info* self);
                        
NDDSUSERDllExport
void node_info_finalize_ex(
        node_info* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool node_info_copy(
        node_info* dst,
        const node_info* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


typedef node_info  node_info_t;
        
        
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols. */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* node_info_t_get_typecode(void); /* Type code */
    
DDS_SEQUENCE(node_info_tSeq, node_info_t);                                        
            
NDDSUSERDllExport
RTIBool node_info_t_initialize(
        node_info_t* self);
            
NDDSUSERDllExport
RTIBool node_info_t_initialize_ex(
        node_info_t* self,RTIBool allocatePointers);
                    
NDDSUSERDllExport
void node_info_t_finalize(
        node_info_t* self);
            
NDDSUSERDllExport
void node_info_t_finalize_ex(
        node_info_t* self,RTIBool deletePointers);
                    
NDDSUSERDllExport
RTIBool node_info_t_copy(
        node_info_t* dst,
        const node_info_t* src);

    

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols. */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *timestampTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct timestamp
{
    DDS_UnsignedShort  year;
    DDS_UnsignedShort  mon;
    DDS_UnsignedShort  mday;
    DDS_UnsignedShort  hour;
    DDS_UnsignedShort  min;
    DDS_UnsignedShort  sec;

} timestamp;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* timestamp_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(timestampSeq, timestamp);
        
NDDSUSERDllExport
RTIBool timestamp_initialize(
        timestamp* self);
        
NDDSUSERDllExport
RTIBool timestamp_initialize_ex(
        timestamp* self,RTIBool allocatePointers);

NDDSUSERDllExport
void timestamp_finalize(
        timestamp* self);
                        
NDDSUSERDllExport
void timestamp_finalize_ex(
        timestamp* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool timestamp_copy(
        timestamp* dst,
        const timestamp* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


typedef timestamp  timestamp_t;
        
        
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols. */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* timestamp_t_get_typecode(void); /* Type code */
    
DDS_SEQUENCE(timestamp_tSeq, timestamp_t);                                        
            
NDDSUSERDllExport
RTIBool timestamp_t_initialize(
        timestamp_t* self);
            
NDDSUSERDllExport
RTIBool timestamp_t_initialize_ex(
        timestamp_t* self,RTIBool allocatePointers);
                    
NDDSUSERDllExport
void timestamp_t_finalize(
        timestamp_t* self);
            
NDDSUSERDllExport
void timestamp_t_finalize_ex(
        timestamp_t* self,RTIBool deletePointers);
                    
NDDSUSERDllExport
RTIBool timestamp_t_copy(
        timestamp_t* dst,
        const timestamp_t* src);

    

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols. */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *ids_alertTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct ids_alert
{
    host_info_t  host;
    node_info_t  source;
    node_info_t  target;
    timestamp_t  ts;
    char*  msg; /* maximum length = (255) */
    char*  timestamp_string; /* maximum length = (255) */

} ids_alert;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* ids_alert_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(ids_alertSeq, ids_alert);
        
NDDSUSERDllExport
RTIBool ids_alert_initialize(
        ids_alert* self);
        
NDDSUSERDllExport
RTIBool ids_alert_initialize_ex(
        ids_alert* self,RTIBool allocatePointers);

NDDSUSERDllExport
void ids_alert_finalize(
        ids_alert* self);
                        
NDDSUSERDllExport
void ids_alert_finalize_ex(
        ids_alert* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool ids_alert_copy(
        ids_alert* dst,
        const ids_alert* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* ids_dds_1288804104937_h */
