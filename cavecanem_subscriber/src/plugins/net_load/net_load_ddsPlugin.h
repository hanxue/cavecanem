
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from net_load_dds.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef net_load_ddsPlugin_1297200718267_h
#define net_load_ddsPlugin_1297200718267_h

#include "net_load_dds.h"




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


/* The type used to store keys for instances of type struct
 * netload.
 *
 * By default, this type is struct netload
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct netload)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct netload, the
 * following restriction applies: the key of struct
 * netload must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct netload.
*/
typedef  struct netload netloadKeyHolder;


#define netloadPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define netloadPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define netloadPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define netloadPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define netloadPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define netloadPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey
 

#define netloadPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define netloadPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern netload*
netloadPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern netload*
netloadPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
netloadPluginSupport_copy_data(
    netload *out,
    const netload *in);

NDDSUSERDllExport extern void 
netloadPluginSupport_destroy_data_ex(
    netload *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
netloadPluginSupport_destroy_data(
    netload *sample);

NDDSUSERDllExport extern void 
netloadPluginSupport_print_data(
    const netload *sample,
    const char *desc,
    unsigned int indent);


NDDSUSERDllExport extern netload*
netloadPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern netload*
netloadPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
netloadPluginSupport_destroy_key_ex(
    netloadKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
netloadPluginSupport_destroy_key(
    netloadKeyHolder *key);
 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
netloadPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
netloadPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
netloadPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
netloadPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
netloadPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    netload *out,
    const netload *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
netloadPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const netload *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
netloadPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    netload *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
netloadPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    netload **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
netloadPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
netloadPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
netloadPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int
netloadPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const netload * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
netloadPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
netloadPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
netloadPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const netload *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
netloadPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    netload * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
netloadPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    netload ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
netloadPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    netload *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
netloadPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    netloadKeyHolder *key, 
    const netload *instance);

NDDSUSERDllExport extern RTIBool 
netloadPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    netload *instance, 
    const netloadKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
netloadPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const netload *instance);

NDDSUSERDllExport extern RTIBool 
netloadPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 
     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
netloadPlugin_new(void);

NDDSUSERDllExport extern void
netloadPlugin_delete(struct PRESTypePlugin *);
 

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif


#ifdef __cplusplus
}
#endif
        

#endif /* net_load_ddsPlugin_1297200718267_h */
