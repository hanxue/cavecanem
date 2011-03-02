
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from net_load_dds.idl using "rtiddsgen".
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



#include "net_load_dds.h"

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
const char *netloadTYPENAME = "netload";

DDS_TypeCode* netload_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode netload_g_tc_device_string = DDS_INITIALIZE_STRING_TYPECODE(255);
    static DDS_TypeCode netload_g_tc_subnet_str_string = DDS_INITIALIZE_STRING_TYPECODE(255);
    static DDS_TypeCode netload_g_tc_address_str_string = DDS_INITIALIZE_STRING_TYPECODE(255);
    static DDS_TypeCode netload_g_tc_hwaddress_str_string = DDS_INITIALIZE_STRING_TYPECODE(255);

    static DDS_TypeCode_Member netload_g_tc_members[18]=
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
            (char *)"device",/* Member name */
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
            (char *)"flags",/* Member name */
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
            (char *)"if_flags",/* Member name */
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
            (char *)"mtu",/* Member name */
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
            (char *)"subnet_str",/* Member name */
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
            (char *)"address_str",/* Member name */
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
            (char *)"packets_in",/* Member name */
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
            (char *)"packets_out",/* Member name */
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
            (char *)"packets_total",/* Member name */
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
            (char *)"bytes_in",/* Member name */
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
            (char *)"bytes_out",/* Member name */
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
            (char *)"bytes_total",/* Member name */
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
            (char *)"errors_in",/* Member name */
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
            (char *)"errors_out",/* Member name */
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
            (char *)"errors_total",/* Member name */
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
            (char *)"collisions",/* Member name */
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
            (char *)"hwaddress_str",/* Member name */
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

    static DDS_TypeCode netload_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"netload", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        18, /* Number of members */
        netload_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for netload*/

    if (is_initialized) {
        return &netload_g_tc;
    }


    netload_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)host_info_t_get_typecode();
    netload_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&netload_g_tc_device_string;
    netload_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&netload_g_tc_subnet_str_string;
    netload_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&netload_g_tc_address_str_string;
    netload_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[11]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[12]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[13]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[14]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[15]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[16]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    netload_g_tc_members[17]._representation._typeCode = (RTICdrTypeCode *)&netload_g_tc_hwaddress_str_string;

    is_initialized = RTI_TRUE;

    return &netload_g_tc;
}


RTIBool netload_initialize(
    netload* sample) {
  return netload_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool netload_initialize_ex(
    netload* sample,RTIBool allocatePointers)
{

    if (!host_info_t_initialize_ex(&sample->host,allocatePointers)) {
        return RTI_FALSE;
    }
            
    sample->device = DDS_String_alloc((255));
    if (sample->device == NULL) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_initLong(&sample->flags)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->if_flags)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->mtu)) {
        return RTI_FALSE;
    }                
            
    sample->subnet_str = DDS_String_alloc((255));
    if (sample->subnet_str == NULL) {
        return RTI_FALSE;
    }
            
    sample->address_str = DDS_String_alloc((255));
    if (sample->address_str == NULL) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_initLong(&sample->packets_in)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->packets_out)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->packets_total)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->bytes_in)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->bytes_out)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->bytes_total)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->errors_in)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->errors_out)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->errors_total)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->collisions)) {
        return RTI_FALSE;
    }                
            
    sample->hwaddress_str = DDS_String_alloc((255));
    if (sample->hwaddress_str == NULL) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void netload_finalize(
    netload* sample)
{
    netload_finalize_ex(sample,RTI_TRUE);
}
        
void netload_finalize_ex(
    netload* sample,RTIBool deletePointers)
{        

    host_info_t_finalize_ex(&sample->host,deletePointers);
            
    DDS_String_free(sample->device);                
            
    DDS_String_free(sample->subnet_str);                
            
    DDS_String_free(sample->address_str);                
            
    DDS_String_free(sample->hwaddress_str);                
            
}

RTIBool netload_copy(
    netload* dst,
    const netload* src)
{        

    if (!host_info_t_copy(
        &dst->host, &src->host)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->device, src->device, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->flags, &src->flags)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->if_flags, &src->if_flags)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->mtu, &src->mtu)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->subnet_str, src->subnet_str, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->address_str, src->address_str, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->packets_in, &src->packets_in)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->packets_out, &src->packets_out)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->packets_total, &src->packets_total)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->bytes_in, &src->bytes_in)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->bytes_out, &src->bytes_out)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->bytes_total, &src->bytes_total)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->errors_in, &src->errors_in)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->errors_out, &src->errors_out)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->errors_total, &src->errors_total)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->collisions, &src->collisions)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->hwaddress_str, src->hwaddress_str, (255) + 1)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'netload' sequence class.
 */
#define T netload
#define TSeq netloadSeq
#define T_initialize_ex netload_initialize_ex
#define T_finalize_ex   netload_finalize_ex
#define T_copy       netload_copy

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

