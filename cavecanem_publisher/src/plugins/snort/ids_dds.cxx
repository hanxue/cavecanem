
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from ids_dds.idl using "rtiddsgen".
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



#include "ids_dds.h"

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
const char *node_infoTYPENAME = "node_info";

DDS_TypeCode* node_info_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode node_info_g_tc_network_addr_string = DDS_INITIALIZE_STRING_TYPECODE(15);
    static DDS_TypeCode node_info_g_tc_mac_string = DDS_INITIALIZE_STRING_TYPECODE(17);

    static DDS_TypeCode_Member node_info_g_tc_members[3]=
    {
        {
            (char *)"prt",/* Member name */
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
            (char *)"network_addr",/* Member name */
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
            (char *)"mac",/* Member name */
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

    static DDS_TypeCode node_info_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"node_info", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        3, /* Number of members */
        node_info_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for node_info*/

    if (is_initialized) {
        return &node_info_g_tc;
    }


    node_info_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    node_info_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&node_info_g_tc_network_addr_string;
    node_info_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&node_info_g_tc_mac_string;

    is_initialized = RTI_TRUE;

    return &node_info_g_tc;
}


RTIBool node_info_initialize(
    node_info* sample) {
  return node_info_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool node_info_initialize_ex(
    node_info* sample,RTIBool allocatePointers)
{

    if (!RTICdrType_initUnsignedShort(&sample->prt)) {
        return RTI_FALSE;
    }                
            
    sample->network_addr = DDS_String_alloc((15));
    if (sample->network_addr == NULL) {
        return RTI_FALSE;
    }
            
    sample->mac = DDS_String_alloc((17));
    if (sample->mac == NULL) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void node_info_finalize(
    node_info* sample)
{
    node_info_finalize_ex(sample,RTI_TRUE);
}
        
void node_info_finalize_ex(
    node_info* sample,RTIBool deletePointers)
{        

    DDS_String_free(sample->network_addr);                
            
    DDS_String_free(sample->mac);                
            
}

RTIBool node_info_copy(
    node_info* dst,
    const node_info* src)
{        

    if (!RTICdrType_copyUnsignedShort(
        &dst->prt, &src->prt)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->network_addr, src->network_addr, (15) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->mac, src->mac, (17) + 1)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'node_info' sequence class.
 */
#define T node_info
#define TSeq node_infoSeq
#define T_initialize_ex node_info_initialize_ex
#define T_finalize_ex   node_info_finalize_ex
#define T_copy       node_info_copy

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

DDS_TypeCode* node_info_t_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode node_info_t_g_tc =
    {{
        DDS_TK_ALIAS, /* Kind*/
        DDS_BOOLEAN_FALSE, /* Is a pointer? */
        -1, /* Ignored */
        (char *)"node_info_t", /* Name */
        NULL, /* Content type code is assigned later */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for node_info_t */

    if (is_initialized) {
        return &node_info_t_g_tc;
    }

    node_info_t_g_tc._data._typeCode = (RTICdrTypeCode *)node_info_get_typecode(); /* Content type code */

    is_initialized = RTI_TRUE;

    return &node_info_t_g_tc;
}


RTIBool node_info_t_initialize(
    node_info_t* sample)
{
    return node_info_t_initialize_ex(sample,RTI_TRUE);
}

RTIBool node_info_t_initialize_ex(
    node_info_t* sample,RTIBool allocatePointers)
{

    if (!node_info_initialize_ex(sample,allocatePointers)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void node_info_t_finalize(
    node_info_t* sample)
{
    node_info_t_finalize_ex(sample,RTI_TRUE);
}
            
void node_info_t_finalize_ex(
    node_info_t* sample,RTIBool deletePointers)
{

    node_info_finalize_ex(sample,deletePointers);
            
}


RTIBool node_info_t_copy(
    node_info_t* dst,
    const node_info_t* src)
{

    if (!node_info_copy(
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
 * Configure and implement 'node_info_t' sequence class.
 */
#define T            node_info_t
#define TSeq         node_info_tSeq
#define T_initialize_ex node_info_t_initialize_ex
#define T_finalize_ex   node_info_t_finalize_ex
#define T_copy       node_info_t_copy


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
const char *timestampTYPENAME = "timestamp";

DDS_TypeCode* timestamp_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member timestamp_g_tc_members[6]=
    {
        {
            (char *)"year",/* Member name */
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
            (char *)"mon",/* Member name */
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
            (char *)"mday",/* Member name */
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
            (char *)"hour",/* Member name */
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
            (char *)"min",/* Member name */
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
            (char *)"sec",/* Member name */
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

    static DDS_TypeCode timestamp_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"timestamp", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        6, /* Number of members */
        timestamp_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for timestamp*/

    if (is_initialized) {
        return &timestamp_g_tc;
    }


    timestamp_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    timestamp_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    timestamp_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    timestamp_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    timestamp_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    timestamp_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

    is_initialized = RTI_TRUE;

    return &timestamp_g_tc;
}


RTIBool timestamp_initialize(
    timestamp* sample) {
  return timestamp_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool timestamp_initialize_ex(
    timestamp* sample,RTIBool allocatePointers)
{

    if (!RTICdrType_initUnsignedShort(&sample->year)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initUnsignedShort(&sample->mon)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initUnsignedShort(&sample->mday)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initUnsignedShort(&sample->hour)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initUnsignedShort(&sample->min)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initUnsignedShort(&sample->sec)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void timestamp_finalize(
    timestamp* sample)
{
    timestamp_finalize_ex(sample,RTI_TRUE);
}
        
void timestamp_finalize_ex(
    timestamp* sample,RTIBool deletePointers)
{        

}

RTIBool timestamp_copy(
    timestamp* dst,
    const timestamp* src)
{        

    if (!RTICdrType_copyUnsignedShort(
        &dst->year, &src->year)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedShort(
        &dst->mon, &src->mon)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedShort(
        &dst->mday, &src->mday)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedShort(
        &dst->hour, &src->hour)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedShort(
        &dst->min, &src->min)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedShort(
        &dst->sec, &src->sec)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'timestamp' sequence class.
 */
#define T timestamp
#define TSeq timestampSeq
#define T_initialize_ex timestamp_initialize_ex
#define T_finalize_ex   timestamp_finalize_ex
#define T_copy       timestamp_copy

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

DDS_TypeCode* timestamp_t_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode timestamp_t_g_tc =
    {{
        DDS_TK_ALIAS, /* Kind*/
        DDS_BOOLEAN_FALSE, /* Is a pointer? */
        -1, /* Ignored */
        (char *)"timestamp_t", /* Name */
        NULL, /* Content type code is assigned later */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for timestamp_t */

    if (is_initialized) {
        return &timestamp_t_g_tc;
    }

    timestamp_t_g_tc._data._typeCode = (RTICdrTypeCode *)timestamp_get_typecode(); /* Content type code */

    is_initialized = RTI_TRUE;

    return &timestamp_t_g_tc;
}


RTIBool timestamp_t_initialize(
    timestamp_t* sample)
{
    return timestamp_t_initialize_ex(sample,RTI_TRUE);
}

RTIBool timestamp_t_initialize_ex(
    timestamp_t* sample,RTIBool allocatePointers)
{

    if (!timestamp_initialize_ex(sample,allocatePointers)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void timestamp_t_finalize(
    timestamp_t* sample)
{
    timestamp_t_finalize_ex(sample,RTI_TRUE);
}
            
void timestamp_t_finalize_ex(
    timestamp_t* sample,RTIBool deletePointers)
{

    timestamp_finalize_ex(sample,deletePointers);
            
}


RTIBool timestamp_t_copy(
    timestamp_t* dst,
    const timestamp_t* src)
{

    if (!timestamp_copy(
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
 * Configure and implement 'timestamp_t' sequence class.
 */
#define T            timestamp_t
#define TSeq         timestamp_tSeq
#define T_initialize_ex timestamp_t_initialize_ex
#define T_finalize_ex   timestamp_t_finalize_ex
#define T_copy       timestamp_t_copy


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
const char *ids_alertTYPENAME = "ids_alert";

DDS_TypeCode* ids_alert_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode ids_alert_g_tc_msg_string = DDS_INITIALIZE_STRING_TYPECODE(255);
    static DDS_TypeCode ids_alert_g_tc_timestamp_string_string = DDS_INITIALIZE_STRING_TYPECODE(255);

    static DDS_TypeCode_Member ids_alert_g_tc_members[6]=
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
            (char *)"source",/* Member name */
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
            (char *)"target",/* Member name */
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
            (char *)"ts",/* Member name */
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
            (char *)"msg",/* Member name */
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
            (char *)"timestamp_string",/* Member name */
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
        }
    };

    static DDS_TypeCode ids_alert_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"ids_alert", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        6, /* Number of members */
        ids_alert_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for ids_alert*/

    if (is_initialized) {
        return &ids_alert_g_tc;
    }


    ids_alert_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)host_info_t_get_typecode();
    ids_alert_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)node_info_t_get_typecode();
    ids_alert_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)node_info_t_get_typecode();
    ids_alert_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)timestamp_t_get_typecode();
    ids_alert_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&ids_alert_g_tc_msg_string;
    ids_alert_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&ids_alert_g_tc_timestamp_string_string;

    is_initialized = RTI_TRUE;

    return &ids_alert_g_tc;
}


RTIBool ids_alert_initialize(
    ids_alert* sample) {
  return ids_alert_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool ids_alert_initialize_ex(
    ids_alert* sample,RTIBool allocatePointers)
{

    if (!host_info_t_initialize_ex(&sample->host,allocatePointers)) {
        return RTI_FALSE;
    }
            
    if (!node_info_t_initialize_ex(&sample->source,allocatePointers)) {
        return RTI_FALSE;
    }
            
    if (!node_info_t_initialize_ex(&sample->target,allocatePointers)) {
        return RTI_FALSE;
    }
            
    if (!timestamp_t_initialize_ex(&sample->ts,allocatePointers)) {
        return RTI_FALSE;
    }
            
    sample->msg = DDS_String_alloc((255));
    if (sample->msg == NULL) {
        return RTI_FALSE;
    }
            
    sample->timestamp_string = DDS_String_alloc((255));
    if (sample->timestamp_string == NULL) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void ids_alert_finalize(
    ids_alert* sample)
{
    ids_alert_finalize_ex(sample,RTI_TRUE);
}
        
void ids_alert_finalize_ex(
    ids_alert* sample,RTIBool deletePointers)
{        

    host_info_t_finalize_ex(&sample->host,deletePointers);
            
    node_info_t_finalize_ex(&sample->source,deletePointers);
            
    node_info_t_finalize_ex(&sample->target,deletePointers);
            
    timestamp_t_finalize_ex(&sample->ts,deletePointers);
            
    DDS_String_free(sample->msg);                
            
    DDS_String_free(sample->timestamp_string);                
            
}

RTIBool ids_alert_copy(
    ids_alert* dst,
    const ids_alert* src)
{        

    if (!host_info_t_copy(
        &dst->host, &src->host)) {
        return RTI_FALSE;
    }
            
    if (!node_info_t_copy(
        &dst->source, &src->source)) {
        return RTI_FALSE;
    }
            
    if (!node_info_t_copy(
        &dst->target, &src->target)) {
        return RTI_FALSE;
    }
            
    if (!timestamp_t_copy(
        &dst->ts, &src->ts)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->msg, src->msg, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->timestamp_string, src->timestamp_string, (255) + 1)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'ids_alert' sequence class.
 */
#define T ids_alert
#define TSeq ids_alertSeq
#define T_initialize_ex ids_alert_initialize_ex
#define T_finalize_ex   ids_alert_finalize_ex
#define T_copy       ids_alert_copy

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

