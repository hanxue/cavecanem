
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from ids_dds.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef ids_ddsPlugin_1298486098444_h
#define ids_ddsPlugin_1298486098444_h

#include "ids_dds.h"




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



#define node_infoPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define node_infoPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define node_infoPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define node_infoPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define node_infoPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define node_infoPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern node_info*
node_infoPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern node_info*
node_infoPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
node_infoPluginSupport_copy_data(
    node_info *out,
    const node_info *in);

NDDSUSERDllExport extern void 
node_infoPluginSupport_destroy_data_ex(
    node_info *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
node_infoPluginSupport_destroy_data(
    node_info *sample);

NDDSUSERDllExport extern void 
node_infoPluginSupport_print_data(
    const node_info *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
node_infoPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
node_infoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
node_infoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
node_infoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
node_infoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    node_info *out,
    const node_info *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
node_infoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const node_info *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
node_infoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    node_info *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
node_infoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    node_info **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
node_infoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
node_infoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
node_infoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int
node_infoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const node_info * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
node_infoPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
node_infoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
node_infoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const node_info *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
node_infoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    node_info * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
node_infoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    node_info ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
node_infoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    node_info *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
node_infoPlugin_new(void);

NDDSUSERDllExport extern void
node_infoPlugin_delete(struct PRESTypePlugin *);
 

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif



#define node_info_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define node_info_tPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define node_info_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define node_info_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define node_info_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define node_info_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern node_info_t*
node_info_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern node_info_t*
node_info_tPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
node_info_tPluginSupport_copy_data(
    node_info_t *out,
    const node_info_t *in);

NDDSUSERDllExport extern void 
node_info_tPluginSupport_destroy_data_ex(
    node_info_t *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
node_info_tPluginSupport_destroy_data(
    node_info_t *sample);

NDDSUSERDllExport extern void 
node_info_tPluginSupport_print_data(
    const node_info_t *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
node_info_tPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
node_info_tPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
node_info_tPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
node_info_tPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
node_info_tPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    node_info_t *out,
    const node_info_t *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
node_info_tPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const node_info_t *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
node_info_tPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    node_info_t *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
node_info_tPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
node_info_tPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
node_info_tPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int
node_info_tPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const node_info_t * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
node_info_tPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
node_info_tPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
node_info_tPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const node_info_t *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
node_info_tPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    node_info_t * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
node_info_tPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    node_info_t *sample,
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



#define timestampPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define timestampPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define timestampPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define timestampPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define timestampPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define timestampPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern timestamp*
timestampPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern timestamp*
timestampPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
timestampPluginSupport_copy_data(
    timestamp *out,
    const timestamp *in);

NDDSUSERDllExport extern void 
timestampPluginSupport_destroy_data_ex(
    timestamp *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
timestampPluginSupport_destroy_data(
    timestamp *sample);

NDDSUSERDllExport extern void 
timestampPluginSupport_print_data(
    const timestamp *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
timestampPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
timestampPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
timestampPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
timestampPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
timestampPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    timestamp *out,
    const timestamp *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
timestampPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const timestamp *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
timestampPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    timestamp *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
timestampPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    timestamp **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
timestampPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
timestampPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
timestampPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int
timestampPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const timestamp * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
timestampPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
timestampPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
timestampPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const timestamp *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
timestampPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    timestamp * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
timestampPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    timestamp ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
timestampPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    timestamp *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
timestampPlugin_new(void);

NDDSUSERDllExport extern void
timestampPlugin_delete(struct PRESTypePlugin *);
 

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif



#define timestamp_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define timestamp_tPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define timestamp_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define timestamp_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define timestamp_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define timestamp_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern timestamp_t*
timestamp_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern timestamp_t*
timestamp_tPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
timestamp_tPluginSupport_copy_data(
    timestamp_t *out,
    const timestamp_t *in);

NDDSUSERDllExport extern void 
timestamp_tPluginSupport_destroy_data_ex(
    timestamp_t *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
timestamp_tPluginSupport_destroy_data(
    timestamp_t *sample);

NDDSUSERDllExport extern void 
timestamp_tPluginSupport_print_data(
    const timestamp_t *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
timestamp_tPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
timestamp_tPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
timestamp_tPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
timestamp_tPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
timestamp_tPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    timestamp_t *out,
    const timestamp_t *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
timestamp_tPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const timestamp_t *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
timestamp_tPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    timestamp_t *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
timestamp_tPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
timestamp_tPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
timestamp_tPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int
timestamp_tPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const timestamp_t * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
timestamp_tPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
timestamp_tPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
timestamp_tPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const timestamp_t *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
timestamp_tPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    timestamp_t * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
timestamp_tPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    timestamp_t *sample,
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
 * ids_alert.
 *
 * By default, this type is struct ids_alert
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct ids_alert)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct ids_alert, the
 * following restriction applies: the key of struct
 * ids_alert must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct ids_alert.
*/
typedef  struct ids_alert ids_alertKeyHolder;


#define ids_alertPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define ids_alertPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define ids_alertPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ids_alertPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define ids_alertPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define ids_alertPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey
 

#define ids_alertPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ids_alertPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ids_alert*
ids_alertPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ids_alert*
ids_alertPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ids_alertPluginSupport_copy_data(
    ids_alert *out,
    const ids_alert *in);

NDDSUSERDllExport extern void 
ids_alertPluginSupport_destroy_data_ex(
    ids_alert *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ids_alertPluginSupport_destroy_data(
    ids_alert *sample);

NDDSUSERDllExport extern void 
ids_alertPluginSupport_print_data(
    const ids_alert *sample,
    const char *desc,
    unsigned int indent);


NDDSUSERDllExport extern ids_alert*
ids_alertPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ids_alert*
ids_alertPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
ids_alertPluginSupport_destroy_key_ex(
    ids_alertKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ids_alertPluginSupport_destroy_key(
    ids_alertKeyHolder *key);
 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ids_alertPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ids_alertPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
ids_alertPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ids_alertPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
ids_alertPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ids_alert *out,
    const ids_alert *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ids_alertPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ids_alert *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ids_alertPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ids_alert *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ids_alertPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ids_alert **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
ids_alertPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
ids_alertPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
ids_alertPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int
ids_alertPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ids_alert * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
ids_alertPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ids_alertPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ids_alertPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ids_alert *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ids_alertPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ids_alert * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ids_alertPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ids_alert ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
ids_alertPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ids_alert *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ids_alertPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ids_alertKeyHolder *key, 
    const ids_alert *instance);

NDDSUSERDllExport extern RTIBool 
ids_alertPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    ids_alert *instance, 
    const ids_alertKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
ids_alertPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const ids_alert *instance);

NDDSUSERDllExport extern RTIBool 
ids_alertPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 
     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ids_alertPlugin_new(void);

NDDSUSERDllExport extern void
ids_alertPlugin_delete(struct PRESTypePlugin *);
 

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif


#ifdef __cplusplus
}
#endif
        

#endif /* ids_ddsPlugin_1298486098444_h */
