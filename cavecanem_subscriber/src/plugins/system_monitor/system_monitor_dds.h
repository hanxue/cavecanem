
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from system_monitor_dds.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef system_monitor_dds_1297110752368_h
#define system_monitor_dds_1297110752368_h

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

        
extern const char *load_averageTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct load_average
{
    DDS_Double  load_one;
    DDS_Double  load_five;
    DDS_Double  load_fifteen;

} load_average;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* load_average_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(load_averageSeq, load_average);
        
NDDSUSERDllExport
RTIBool load_average_initialize(
        load_average* self);
        
NDDSUSERDllExport
RTIBool load_average_initialize_ex(
        load_average* self,RTIBool allocatePointers);

NDDSUSERDllExport
void load_average_finalize(
        load_average* self);
                        
NDDSUSERDllExport
void load_average_finalize_ex(
        load_average* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool load_average_copy(
        load_average* dst,
        const load_average* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


typedef load_average  load_average_t;
        
        
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols. */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* load_average_t_get_typecode(void); /* Type code */
    
DDS_SEQUENCE(load_average_tSeq, load_average_t);                                        
            
NDDSUSERDllExport
RTIBool load_average_t_initialize(
        load_average_t* self);
            
NDDSUSERDllExport
RTIBool load_average_t_initialize_ex(
        load_average_t* self,RTIBool allocatePointers);
                    
NDDSUSERDllExport
void load_average_t_finalize(
        load_average_t* self);
            
NDDSUSERDllExport
void load_average_t_finalize_ex(
        load_average_t* self,RTIBool deletePointers);
                    
NDDSUSERDllExport
RTIBool load_average_t_copy(
        load_average_t* dst,
        const load_average_t* src);

    

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols. */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *sysmon_statusTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct sysmon_status
{
    host_info_t  host;
    DDS_Double  cpu_temp;
    load_average_t  lavg;
    DDS_Double  cpu_user;
    DDS_Double  cpu_system;
    DDS_Double  cpu_idle;
    DDS_Double  mem_total;
    DDS_Double  mem_used;
    DDS_Double  mem_free;
    DDS_Double  swap_total;
    DDS_Double  swap_used;
    DDS_Double  swap_free;

} sysmon_status;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* sysmon_status_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(sysmon_statusSeq, sysmon_status);
        
NDDSUSERDllExport
RTIBool sysmon_status_initialize(
        sysmon_status* self);
        
NDDSUSERDllExport
RTIBool sysmon_status_initialize_ex(
        sysmon_status* self,RTIBool allocatePointers);

NDDSUSERDllExport
void sysmon_status_finalize(
        sysmon_status* self);
                        
NDDSUSERDllExport
void sysmon_status_finalize_ex(
        sysmon_status* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool sysmon_status_copy(
        sysmon_status* dst,
        const sysmon_status* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* system_monitor_dds_1297110752368_h */
