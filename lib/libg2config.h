/**********************************************************************************
 © Copyright Senzing, Inc. 2017-2020
 The source code for this program is not published or otherwise divested
 of its trade secrets, irrespective of what has been deposited with the U.S.
 Copyright Office.
**********************************************************************************/

#ifndef LIBG2CONFIG_H
#define LIBG2CONFIG_H

/* Platform specific function export header */
#if defined(_WIN32)
  #define _DLEXPORT __declspec(dllexport)
#else
#include <stddef.h>
  #define _DLEXPORT __attribute__ ((visibility ("default")))
#endif


#ifdef __cplusplus 
extern "C"
{
#endif


  /**
   * @brief
   * This method will initialize the G2 Config object.  It must be called
   * prior to any other calls.
   *
   * @param moduleName A name for the auditing node, to help identify it within
   *        system logs.
   * @param iniParams A JSON string containing configuration paramters.
   * @param verboseLogging A flag to enable deeper logging of the G2 processing
   */
  _DLEXPORT int G2Config_init_V2(const char *moduleName, const char *iniParams, const int verboseLogging);


  /**
   * @brief
   * This method will destroy and perform cleanup for the G2 Config object.  It
   * should be called after all other calls are complete.
   */
  _DLEXPORT int G2Config_destroy();


  /* type definitions for Config Handle data  */
  typedef void* ConfigHandle;


  /**
   * @brief
   * This method creates a stock G2 JSON config from the template config
   */
  _DLEXPORT ConfigHandle G2Config_create();


  /**
   * @brief
   * This method initializes the G2 Config object from a JSON string.  Any time you need to edit an existing
   * config from an existing repository you will want to use this method to be able to modify it.
   */
  _DLEXPORT ConfigHandle G2Config_load(const char *jsonConfig);


  /**
   * @brief
   * This method saves the G2 Config object into a JSON string.
   */
  _DLEXPORT int G2Config_save(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );


  /**
   * @brief
   * This method cleans up the G2 Config object pointed to by the handle.
   */
  _DLEXPORT void G2Config_close(ConfigHandle configHandle);


  /**
   * @brief
   * This method adds a data source with the given code (e.g. CUSTOMER, WATCHLIST, etc) to the configuration
   * and automatically assigns an appropriate unique ID.
   * @return 0 for success, otherwise error
   */
  _DLEXPORT int G2Config_addDataSource(ConfigHandle configHandle, const char *code);


  /**
   * @brief
   * This method adds a data source with the given code (e.g. CUSTOMER, WATCHLIST, etc) to the configuration
   * and uses the id provided.  If the id can't be assigned it will error.
   *
   * This method should only be used when an external system wants to manage the IDs as reuse of the IDs will
   * cause data integrity issues.  The Senzing Workbench uses this mechanism as it desires to maintain consistent
   * IDs across multiple projects for potential future capabilities.
   *
   * @return 0 for success, otherwise error
   */
  _DLEXPORT int G2Config_addDataSourceWithID(ConfigHandle configHandle, const char *code, const int id);


  /**
   * @brief
   * This method returns the list of current data sources in a JSON document
   */
  _DLEXPORT int G2Config_listDataSources(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );



  /* Functions for data source configuration */
  _DLEXPORT int G2Config_listDataSources_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addDataSource_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_deleteDataSource_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for entity class configuration */
  _DLEXPORT int G2Config_listEntityClasses_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addEntityClass_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_deleteEntityClass_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for entity type configuration */
  _DLEXPORT int G2Config_listEntityTypes_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addEntityType_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_deleteEntityType_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for feature element configuration */
  _DLEXPORT int G2Config_listFeatureElements_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_getFeatureElement_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addFeatureElement_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_deleteFeatureElement_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for feature class configuration */
  _DLEXPORT int G2Config_listFeatureClasses_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /* Functions for feature configuration */
  _DLEXPORT int G2Config_listFeatures_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_getFeature_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addFeature_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_modifyFeature_V2(ConfigHandle configHandle, const char *inputJson);
  _DLEXPORT int G2Config_deleteFeature_V2(ConfigHandle configHandle, const char *inputJson);
  _DLEXPORT int G2Config_addElementToFeature_V2(ConfigHandle configHandle, const char *inputJson);
  _DLEXPORT int G2Config_modifyElementForFeature_V2(ConfigHandle configHandle, const char *inputJson);
  _DLEXPORT int G2Config_deleteElementFromFeature_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for feature standardization */
  _DLEXPORT int G2Config_listFeatureStandardizationFunctions_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addFeatureStandardizationFunction_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

  /* Functions for feature expression */
  _DLEXPORT int G2Config_listFeatureExpressionFunctions_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addFeatureExpressionFunction_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_modifyFeatureExpressionFunction_V2(ConfigHandle configHandle, const char *inputJson);

  /* Functions for feature comparison */
  _DLEXPORT int G2Config_listFeatureComparisonFunctions_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addFeatureComparisonFunction_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addFeatureComparisonFunctionReturnCode_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

  /* Functions for distinct features */
  _DLEXPORT int G2Config_listFeatureDistinctFunctions_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addFeatureDistinctFunction_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /* Functions for feature standardization function configuration */
  _DLEXPORT int G2Config_listFeatureStandardizationFunctionCalls_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_getFeatureStandardizationFunctionCall_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addFeatureStandardizationFunctionCall_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_deleteFeatureStandardizationFunctionCall_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for feature expression function configuration */
  _DLEXPORT int G2Config_listFeatureExpressionFunctionCalls_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_getFeatureExpressionFunctionCall_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addFeatureExpressionFunctionCall_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_deleteFeatureExpressionFunctionCall_V2(ConfigHandle configHandle, const char *inputJson);
  _DLEXPORT int G2Config_addFeatureExpressionFunctionCallElement_V2(ConfigHandle configHandle, const char *inputJson);
  _DLEXPORT int G2Config_deleteFeatureExpressionFunctionCallElement_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for feature comparison function configuration */
  _DLEXPORT int G2Config_listFeatureComparisonFunctionCalls_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_getFeatureComparisonFunctionCall_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addFeatureComparisonFunctionCall_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_deleteFeatureComparisonFunctionCall_V2(ConfigHandle configHandle, const char *inputJson);
  _DLEXPORT int G2Config_addFeatureComparisonFunctionCallElement_V2(ConfigHandle configHandle, const char *inputJson);
  _DLEXPORT int G2Config_deleteFeatureComparisonFunctionCallElement_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for feature distinct function configuration */
  _DLEXPORT int G2Config_listFeatureDistinctFunctionCalls_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_getFeatureDistinctFunctionCall_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addFeatureDistinctFunctionCall_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_deleteFeatureDistinctFunctionCall_V2(ConfigHandle configHandle, const char *inputJson);
  _DLEXPORT int G2Config_addFeatureDistinctFunctionCallElement_V2(ConfigHandle configHandle, const char *inputJson);
  _DLEXPORT int G2Config_deleteFeatureDistinctFunctionCallElement_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for attribute class configuration */
  _DLEXPORT int G2Config_listAttributeClasses_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /* Functions for attribute configuration */
  _DLEXPORT int G2Config_listAttributes_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_getAttribute_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addAttribute_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_deleteAttribute_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for er rules */
  _DLEXPORT int G2Config_listRules_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_getRule_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addRule_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_deleteRule_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for er rule fragments */
  _DLEXPORT int G2Config_listRuleFragments_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_getRuleFragment_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_addRuleFragment_V2(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_deleteRuleFragment_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for adding new config sections/tables/fields */
  _DLEXPORT int G2Config_addConfigSection_V2(ConfigHandle configHandle, const char *inputJson);
  _DLEXPORT int G2Config_addConfigSectionField_V2(ConfigHandle configHandle, const char *inputJson);


  /* Functions for the config compatibility version */
  _DLEXPORT int G2Config_getCompatibilityVersion_V2(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT int G2Config_modifyCompatibilityVersion_V2(ConfigHandle configHandle, const char *inputJson);


  /**
   * @brief
   * This function retrieves the last exception thrown in G2Config
   * @return number of bytes copied into buffer
   */
  _DLEXPORT int G2Config_getLastException(char *buffer, const size_t bufSize);


  /**
   * @brief
   * This function retrieves the code of the last exception thrown in G2Config
   * @return number of bytes copied into buffer
   */
  _DLEXPORT int G2Config_getLastExceptionCode();


  /**
   * @brief
   * This function clears the last exception thrown in G2Config
   */
  _DLEXPORT void G2Config_clearLastException();


#ifdef __cplusplus 
};
#endif

#endif /* LIBG2CONFIG_H */

