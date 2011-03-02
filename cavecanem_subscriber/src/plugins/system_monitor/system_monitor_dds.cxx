
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from system_monitor_dds.idl using "rtiddsgen".
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



#include "system_monitor_dds.h"

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
const char *load_averageTYPENAME = "load_average";

DDS_TypeCode* load_average_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member load_average_g_tc_members[3]=
    {
        {
            (char *)"load_one",/* Member name */
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
            (char *)"load_five",/* Member name */
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
            (char *)"load_fifteen",/* Member name */
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

    static DDS_TypeCode load_average_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"load_average", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        3, /* Number of members */
        load_average_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for load_average*/

    if (is_initialized) {
        return &load_average_g_tc;
    }


    load_average_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    load_average_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    load_average_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &load_average_g_tc;
}


RTIBool load_average_initialize(
    load_average* sample) {
  return load_average_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool load_average_initialize_ex(
    load_average* sample,RTIBool allocatePointers)
{

    if (!RTICdrType_initDouble(&sample->load_one)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->load_five)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->load_fifteen)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void load_average_finalize(
    load_average* sample)
{
    load_average_finalize_ex(sample,RTI_TRUE);
}
        
void load_average_finalize_ex(
    load_average* sample,RTIBool deletePointers)
{        

}

RTIBool load_average_copy(
    load_average* dst,
    const load_average* src)
{        

    if (!RTICdrType_copyDouble(
        &dst->load_one, &src->load_one)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->load_five, &src->load_five)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->load_fifteen, &src->load_fifteen)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'load_average' sequence class.
 */
#define T load_average
#define TSeq load_averageSeq
#define T_initialize_ex load_average_initialize_ex
#define T_finalize_ex   load_average_finalize_ex
#define T_copy       load_average_copy

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

DDS_TypeCode* load_average_t_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode load_average_t_g_tc =
    {{
        DDS_TK_ALIAS, /* Kind*/
        DDS_BOOLEAN_FALSE, /* Is a pointer? */
        -1, /* Ignored */
        (char *)"load_average_t", /* Name */
        NULL, /* Content type code is assigned later */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for load_average_t */

    if (is_initialized) {
        return &load_average_t_g_tc;
    }

    load_average_t_g_tc._data._typeCode = (RTICdrTypeCode *)load_average_get_typecode(); /* Content type code */

    is_initialized = RTI_TRUE;

    return &load_average_t_g_tc;
}


RTIBool load_average_t_initialize(
    load_average_t* sample)
{
    return load_average_t_initialize_ex(sample,RTI_TRUE);
}

RTIBool load_average_t_initialize_ex(
    load_average_t* sample,RTIBool allocatePointers)
{

    if (!load_average_initialize_ex(sample,allocatePointers)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void load_average_t_finalize(
    load_average_t* sample)
{
    load_average_t_finalize_ex(sample,RTI_TRUE);
}
            
void load_average_t_finalize_ex(
    load_average_t* sample,RTIBool deletePointers)
{

    load_average_finalize_ex(sample,deletePointers);
            
}


RTIBool load_average_t_copy(
    load_average_t* dst,
    const load_average_t* src)
{

    if (!load_average_copy(
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
 * Configure and implement 'load_average_t' sequence class.
 */
#define T            load_average_t
#define TSeq         load_average_tSeq
#define T_initialize_ex load_average_t_initialize_ex
#define T_finalize_ex   load_average_t_finalize_ex
#define T_copy       load_average_t_copy


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
const char *sysmon_statusTYPENAME = "sysmon_status";

DDS_TypeCode* sysmon_status_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member sysmon_status_g_tc_members[12]=
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
            (char *)"cpu_temp",/* Member name */
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
            (char *)"lavg",/* Member name */
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
            (char *)"cpu_user",/* Member name */
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
            (char *)"cpu_system",/* Member name */
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
            (char *)"cpu_idle",/* Member name */
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
            (char *)"mem_total",/* Member name */
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
            (char *)"mem_used",/* Member name */
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
            (char *)"mem_free",/* Member name */
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
            (char *)"swap_total",/* Member name */
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
            (char *)"swap_used",/* Member name */
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
            (char *)"swap_free",/* Member name */
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

    static DDS_TypeCode sysmon_status_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"sysmon_status", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        12, /* Number of members */
        sysmon_status_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for sysmon_status*/

    if (is_initialized) {
        return &sysmon_status_g_tc;
    }


    sysmon_status_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)host_info_t_get_typecode();
    sysmon_status_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    sysmon_status_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)load_average_t_get_typecode();
    sysmon_status_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    sysmon_status_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    sysmon_status_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    sysmon_status_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    sysmon_status_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    sysmon_status_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    sysmon_status_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    sysmon_status_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    sysmon_status_g_tc_members[11]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &sysmon_status_g_tc;
}


RTIBool sysmon_status_initialize(
    sysmon_status* sample) {
  return sysmon_status_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool sysmon_status_initialize_ex(
    sysmon_status* sample,RTIBool allocatePointers)
{

    if (!host_info_t_initialize_ex(&sample->host,allocatePointers)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_initDouble(&sample->cpu_temp)) {
        return RTI_FALSE;
    }                
            
    if (!load_average_t_initialize_ex(&sample->lavg,allocatePointers)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_initDouble(&sample->cpu_user)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->cpu_system)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->cpu_idle)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->mem_total)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->mem_used)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->mem_free)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->swap_total)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->swap_used)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->swap_free)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void sysmon_status_finalize(
    sysmon_status* sample)
{
    sysmon_status_finalize_ex(sample,RTI_TRUE);
}
        
void sysmon_status_finalize_ex(
    sysmon_status* sample,RTIBool deletePointers)
{        

    host_info_t_finalize_ex(&sample->host,deletePointers);
            
    load_average_t_finalize_ex(&sample->lavg,deletePointers);
            
}

RTIBool sysmon_status_copy(
    sysmon_status* dst,
    const sysmon_status* src)
{        

    if (!host_info_t_copy(
        &dst->host, &src->host)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->cpu_temp, &src->cpu_temp)) {
        return RTI_FALSE;
    }
            
    if (!load_average_t_copy(
        &dst->lavg, &src->lavg)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->cpu_user, &src->cpu_user)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->cpu_system, &src->cpu_system)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->cpu_idle, &src->cpu_idle)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->mem_total, &src->mem_total)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->mem_used, &src->mem_used)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->mem_free, &src->mem_free)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->swap_total, &src->swap_total)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->swap_used, &src->swap_used)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->swap_free, &src->swap_free)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'sysmon_status' sequence class.
 */
#define T sysmon_status
#define TSeq sysmon_statusSeq
#define T_initialize_ex sysmon_status_initialize_ex
#define T_finalize_ex   sysmon_status_finalize_ex
#define T_copy       sysmon_status_copy

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

