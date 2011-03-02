
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from system_monitor_dds.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef system_monitor_ddsPlugin_1297110752368_h
#define system_monitor_ddsPlugin_1297110752368_h

#include "system_monitor_dds.h"




struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif


#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif


#ifdef __cplusplus
extern "C" {
#endif


#define host_infoPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define host_infoPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define host_infoPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define host_infoPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define host_infoPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define host_infoPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern host_info*
host_infoPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern host_info*
host_infoPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
host_infoPluginSupport_copy_data(
    host_info *out,
    const host_info *in);

NDDSUSERDllExport extern void 
host_infoPluginSupport_destroy_data_ex(
    host_info *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
host_infoPluginSupport_destroy_data(
    host_info *sample);

NDDSUSERDllExport extern void 
host_infoPluginSupport_print_data(
    const host_info *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
host_infoPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
host_infoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
host_infoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
host_infoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
host_infoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    host_info *out,
    const host_info *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
host_infoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const host_info *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
host_infoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    host_info *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
host_infoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    host_info **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
host_infoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
host_infoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
host_infoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int
host_infoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const host_info * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
host_infoPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
host_infoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
host_infoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const host_info *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
host_infoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    host_info * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
host_infoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    host_info ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
host_infoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    host_info *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
host_infoPlugin_new(void);

NDDSUSERDllExport extern void
host_infoPlugin_delete(struct PRESTypePlugin *);
 

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif



#define host_info_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define host_info_tPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define host_info_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define host_info_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define host_info_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define host_info_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern host_info_t*
host_info_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern host_info_t*
host_info_tPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
host_info_tPluginSupport_copy_data(
    host_info_t *out,
    const host_info_t *in);

NDDSUSERDllExport extern void 
host_info_tPluginSupport_destroy_data_ex(
    host_info_t *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
host_info_tPluginSupport_destroy_data(
    host_info_t *sample);

NDDSUSERDllExport extern void 
host_info_tPluginSupport_print_data(
    const host_info_t *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
host_info_tPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
host_info_tPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
host_info_tPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
host_info_tPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
host_info_tPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    host_info_t *out,
    const host_info_t *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
host_info_tPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const host_info_t *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
host_info_tPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    host_info_t *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
host_info_tPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
host_info_tPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
host_info_tPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int
host_info_tPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const host_info_t * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
host_info_tPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
host_info_tPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
host_info_tPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const host_info_t *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
host_info_tPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    host_info_t * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
host_info_tPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    host_info_t *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif



#define load_averagePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define load_averagePlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define load_averagePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define load_averagePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define load_averagePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define load_averagePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern load_average*
load_averagePluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern load_average*
load_averagePluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
load_averagePluginSupport_copy_data(
    load_average *out,
    const load_average *in);

NDDSUSERDllExport extern void 
load_averagePluginSupport_destroy_data_ex(
    load_average *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
load_averagePluginSupport_destroy_data(
    load_average *sample);

NDDSUSERDllExport extern void 
load_averagePluginSupport_print_data(
    const load_average *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
load_averagePlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
load_averagePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
load_averagePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
load_averagePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
load_averagePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    load_average *out,
    const load_average *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
load_averagePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const load_average *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
load_averagePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    load_average *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
load_averagePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    load_average **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
load_averagePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
load_averagePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
load_averagePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int
load_averagePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const load_average * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
load_averagePlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
load_averagePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
load_averagePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const load_average *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
load_averagePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    load_average * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
load_averagePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    load_average ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
load_averagePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    load_average *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
load_averagePlugin_new(void);

NDDSUSERDllExport extern void
load_averagePlugin_delete(struct PRESTypePlugin *);
 

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif



#define load_average_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define load_average_tPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define load_average_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define load_average_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define load_average_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define load_average_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern load_average_t*
load_average_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern load_average_t*
load_average_tPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
load_average_tPluginSupport_copy_data(
    load_average_t *out,
    const load_average_t *in);

NDDSUSERDllExport extern void 
load_average_tPluginSupport_destroy_data_ex(
    load_average_t *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
load_average_tPluginSupport_destroy_data(
    load_average_t *sample);

NDDSUSERDllExport extern void 
load_average_tPluginSupport_print_data(
    const load_average_t *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
load_average_tPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
load_average_tPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
load_average_tPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
load_average_tPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
load_average_tPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    load_average_t *out,
    const load_average_t *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
load_average_tPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const load_average_t *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
load_average_tPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    load_average_t *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
load_average_tPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
load_average_tPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
load_average_tPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int
load_average_tPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const load_average_t * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
load_average_tPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
load_average_tPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
load_average_tPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const load_average_t *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
load_average_tPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    load_average_t * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
load_average_tPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    load_average_t *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif


/* The type used to store keys for instances of type struct
 * sysmon_status.
 *
 * By default, this type is struct sysmon_status
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct sysmon_status)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct sysmon_status, the
 * following restriction applies: the key of struct
 * sysmon_status must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct sysmon_status.
*/
typedef  struct sysmon_status sysmon_statusKeyHolder;


#define sysmon_statusPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define sysmon_statusPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define sysmon_statusPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define sysmon_statusPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define sysmon_statusPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define sysmon_statusPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey
 

#define sysmon_statusPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define sysmon_statusPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern sysmon_status*
sysmon_statusPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern sysmon_status*
sysmon_statusPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
sysmon_statusPluginSupport_copy_data(
    sysmon_status *out,
    const sysmon_status *in);

NDDSUSERDllExport extern void 
sysmon_statusPluginSupport_destroy_data_ex(
    sysmon_status *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
sysmon_statusPluginSupport_destroy_data(
    sysmon_status *sample);

NDDSUSERDllExport extern void 
sysmon_statusPluginSupport_print_data(
    const sysmon_status *sample,
    const char *desc,
    unsigned int indent);


NDDSUSERDllExport extern sysmon_status*
sysmon_statusPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern sysmon_status*
sysmon_statusPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
sysmon_statusPluginSupport_destroy_key_ex(
    sysmon_statusKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
sysmon_statusPluginSupport_destroy_key(
    sysmon_statusKeyHolder *key);
 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
sysmon_statusPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
sysmon_statusPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
sysmon_statusPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
sysmon_statusPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
sysmon_statusPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    sysmon_status *out,
    const sysmon_status *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
sysmon_statusPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const sysmon_status *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
sysmon_statusPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    sysmon_status *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
sysmon_statusPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    sysmon_status **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
sysmon_statusPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
sysmon_statusPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
sysmon_statusPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int
sysmon_statusPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const sysmon_status * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
sysmon_statusPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
sysmon_statusPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
sysmon_statusPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const sysmon_status *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
sysmon_statusPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    sysmon_status * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
sysmon_statusPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    sysmon_status ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
sysmon_statusPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    sysmon_status *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
sysmon_statusPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    sysmon_statusKeyHolder *key, 
    const sysmon_status *instance);

NDDSUSERDllExport extern RTIBool 
sysmon_statusPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    sysmon_status *instance, 
    const sysmon_statusKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
sysmon_statusPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const sysmon_status *instance);

NDDSUSERDllExport extern RTIBool 
sysmon_statusPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 
     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
sysmon_statusPlugin_new(void);

NDDSUSERDllExport extern void
sysmon_statusPlugin_delete(struct PRESTypePlugin *);
 

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif


#ifdef __cplusplus
}
#endif
        

#endif /* system_monitor_ddsPlugin_1297110752368_h */
