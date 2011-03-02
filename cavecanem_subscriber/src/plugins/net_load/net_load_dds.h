
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from net_load_dds.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef net_load_dds_1297200718267_h
#define net_load_dds_1297200718267_h

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

        
extern const char *netloadTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct netload
{
    host_info_t  host;
    char*  device; /* maximum length = (255) */
    DDS_Long  flags;
    DDS_Long  if_flags;
    DDS_Long  mtu;
    char*  subnet_str; /* maximum length = (255) */
    char*  address_str; /* maximum length = (255) */
    DDS_Long  packets_in;
    DDS_Long  packets_out;
    DDS_Long  packets_total;
    DDS_Long  bytes_in;
    DDS_Long  bytes_out;
    DDS_Long  bytes_total;
    DDS_Long  errors_in;
    DDS_Long  errors_out;
    DDS_Long  errors_total;
    DDS_Long  collisions;
    char*  hwaddress_str; /* maximum length = (255) */

} netload;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* netload_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(netloadSeq, netload);
        
NDDSUSERDllExport
RTIBool netload_initialize(
        netload* self);
        
NDDSUSERDllExport
RTIBool netload_initialize_ex(
        netload* self,RTIBool allocatePointers);

NDDSUSERDllExport
void netload_finalize(
        netload* self);
                        
NDDSUSERDllExport
void netload_finalize_ex(
        netload* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool netload_copy(
        netload* dst,
        const netload* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* net_load_dds_1297200718267_h */
