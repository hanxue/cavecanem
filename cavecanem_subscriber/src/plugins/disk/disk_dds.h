
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from disk_dds.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef disk_dds_1297179616718_h
#define disk_dds_1297179616718_h

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

        
extern const char *filesystemTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct filesystem
{
    host_info_t  host;
    char*  name; /* maximum length = (255) */
    char*  mountdir; /* maximum length = (255) */
    DDS_Long  total;
    DDS_Long  used;
    DDS_Long  free;
    DDS_Double  used_per;
    DDS_Double  free_per;
    DDS_Long  write;
    DDS_Long  read;

} filesystem;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* filesystem_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(filesystemSeq, filesystem);
        
NDDSUSERDllExport
RTIBool filesystem_initialize(
        filesystem* self);
        
NDDSUSERDllExport
RTIBool filesystem_initialize_ex(
        filesystem* self,RTIBool allocatePointers);

NDDSUSERDllExport
void filesystem_finalize(
        filesystem* self);
                        
NDDSUSERDllExport
void filesystem_finalize_ex(
        filesystem* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool filesystem_copy(
        filesystem* dst,
        const filesystem* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* disk_dds_1297179616718_h */
