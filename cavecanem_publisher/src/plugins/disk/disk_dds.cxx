
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from disk_dds.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/


#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
        #ifndef dds_c_log_impl_h              
            #include "dds_c/dds_c_log_impl.h"                                
        #endif        
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
    
    #ifndef cdr_type_h
        #include "cdr/cdr_type.h"
    #endif    

    #ifndef osapi_heap_h
        #include "osapi/osapi_heap.h" 
    #endif
#else
    #include "ndds_standalone_type.h"
#endif



#include "disk_dds.h"

/* ========================================================================= */
const char *host_infoTYPENAME = "host_info";

DDS_TypeCode* host_info_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode host_info_g_tc_hostname_string = DDS_INITIALIZE_STRING_TYPECODE(255);
    static DDS_TypeCode host_info_g_tc_sysname_string = DDS_INITIALIZE_STRING_TYPECODE(255);
    static DDS_TypeCode host_info_g_tc_release_name_string = DDS_INITIALIZE_STRING_TYPECODE(255);
    static DDS_TypeCode host_info_g_tc_machine_string = DDS_INITIALIZE_STRING_TYPECODE(255);

    static DDS_TypeCode_Member host_info_g_tc_members[4]=
    {
        {
            (char *)"hostname",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"sysname",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"release_name",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"machine",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode host_info_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"host_info", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of members */
        host_info_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for host_info*/

    if (is_initialized) {
        return &host_info_g_tc;
    }


    host_info_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&host_info_g_tc_hostname_string;
    host_info_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&host_info_g_tc_sysname_string;
    host_info_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&host_info_g_tc_release_name_string;
    host_info_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&host_info_g_tc_machine_string;

    is_initialized = RTI_TRUE;

    return &host_info_g_tc;
}


RTIBool host_info_initialize(
    host_info* sample) {
  return host_info_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool host_info_initialize_ex(
    host_info* sample,RTIBool allocatePointers)
{

    sample->hostname = DDS_String_alloc((255));
    if (sample->hostname == NULL) {
        return RTI_FALSE;
    }
            
    sample->sysname = DDS_String_alloc((255));
    if (sample->sysname == NULL) {
        return RTI_FALSE;
    }
            
    sample->release_name = DDS_String_alloc((255));
    if (sample->release_name == NULL) {
        return RTI_FALSE;
    }
            
    sample->machine = DDS_String_alloc((255));
    if (sample->machine == NULL) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void host_info_finalize(
    host_info* sample)
{
    host_info_finalize_ex(sample,RTI_TRUE);
}
        
void host_info_finalize_ex(
    host_info* sample,RTIBool deletePointers)
{        

    DDS_String_free(sample->hostname);                
            
    DDS_String_free(sample->sysname);                
            
    DDS_String_free(sample->release_name);                
            
    DDS_String_free(sample->machine);                
            
}

RTIBool host_info_copy(
    host_info* dst,
    const host_info* src)
{        

    if (!RTICdrType_copyString(
        dst->hostname, src->hostname, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->sysname, src->sysname, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->release_name, src->release_name, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->machine, src->machine, (255) + 1)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'host_info' sequence class.
 */
#define T host_info
#define TSeq host_infoSeq
#define T_initialize_ex host_info_initialize_ex
#define T_finalize_ex   host_info_finalize_ex
#define T_copy       host_info_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */

DDS_TypeCode* host_info_t_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode host_info_t_g_tc =
    {{
        DDS_TK_ALIAS, /* Kind*/
        DDS_BOOLEAN_FALSE, /* Is a pointer? */
        -1, /* Ignored */
        (char *)"host_info_t", /* Name */
        NULL, /* Content type code is assigned later */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for host_info_t */

    if (is_initialized) {
        return &host_info_t_g_tc;
    }

    host_info_t_g_tc._data._typeCode = (RTICdrTypeCode *)host_info_get_typecode(); /* Content type code */

    is_initialized = RTI_TRUE;

    return &host_info_t_g_tc;
}


RTIBool host_info_t_initialize(
    host_info_t* sample)
{
    return host_info_t_initialize_ex(sample,RTI_TRUE);
}

RTIBool host_info_t_initialize_ex(
    host_info_t* sample,RTIBool allocatePointers)
{

    if (!host_info_initialize_ex(sample,allocatePointers)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void host_info_t_finalize(
    host_info_t* sample)
{
    host_info_t_finalize_ex(sample,RTI_TRUE);
}
            
void host_info_t_finalize_ex(
    host_info_t* sample,RTIBool deletePointers)
{

    host_info_finalize_ex(sample,deletePointers);
            
}


RTIBool host_info_t_copy(
    host_info_t* dst,
    const host_info_t* src)
{

    if (!host_info_copy(
        dst, src)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

    
/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'host_info_t' sequence class.
 */
#define T            host_info_t
#define TSeq         host_info_tSeq
#define T_initialize_ex host_info_t_initialize_ex
#define T_finalize_ex   host_info_t_finalize_ex
#define T_copy       host_info_t_copy


#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *filesystemTYPENAME = "filesystem";

DDS_TypeCode* filesystem_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode filesystem_g_tc_name_string = DDS_INITIALIZE_STRING_TYPECODE(255);
    static DDS_TypeCode filesystem_g_tc_mountdir_string = DDS_INITIALIZE_STRING_TYPECODE(255);

    static DDS_TypeCode_Member filesystem_g_tc_members[10]=
    {
        {
            (char *)"host",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"name",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"mountdir",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"total",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"used",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"free",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"used_per",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"free_per",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"write",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"read",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode filesystem_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"filesystem", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        10, /* Number of members */
        filesystem_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for filesystem*/

    if (is_initialized) {
        return &filesystem_g_tc;
    }


    filesystem_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)host_info_t_get_typecode();
    filesystem_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&filesystem_g_tc_name_string;
    filesystem_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&filesystem_g_tc_mountdir_string;
    filesystem_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    filesystem_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    filesystem_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    filesystem_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    filesystem_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    filesystem_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    filesystem_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &filesystem_g_tc;
}


RTIBool filesystem_initialize(
    filesystem* sample) {
  return filesystem_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool filesystem_initialize_ex(
    filesystem* sample,RTIBool allocatePointers)
{

    if (!host_info_t_initialize_ex(&sample->host,allocatePointers)) {
        return RTI_FALSE;
    }
            
    sample->name = DDS_String_alloc((255));
    if (sample->name == NULL) {
        return RTI_FALSE;
    }
            
    sample->mountdir = DDS_String_alloc((255));
    if (sample->mountdir == NULL) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_initLong(&sample->total)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->used)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->free)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->used_per)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->free_per)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->write)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->read)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void filesystem_finalize(
    filesystem* sample)
{
    filesystem_finalize_ex(sample,RTI_TRUE);
}
        
void filesystem_finalize_ex(
    filesystem* sample,RTIBool deletePointers)
{        

    host_info_t_finalize_ex(&sample->host,deletePointers);
            
    DDS_String_free(sample->name);                
            
    DDS_String_free(sample->mountdir);                
            
}

RTIBool filesystem_copy(
    filesystem* dst,
    const filesystem* src)
{        

    if (!host_info_t_copy(
        &dst->host, &src->host)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->name, src->name, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->mountdir, src->mountdir, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->total, &src->total)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->used, &src->used)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->free, &src->free)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->used_per, &src->used_per)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->free_per, &src->free_per)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->write, &src->write)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->read, &src->read)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'filesystem' sequence class.
 */
#define T filesystem
#define TSeq filesystemSeq
#define T_initialize_ex filesystem_initialize_ex
#define T_finalize_ex   filesystem_finalize_ex
#define T_copy       filesystem_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

