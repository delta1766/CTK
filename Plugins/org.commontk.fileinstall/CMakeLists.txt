PROJECT(org_commontk_fileinstall)

SET(PLUGIN_export_directive "org_commontk_fileinstall_EXPORT")

SET(PLUGIN_SRCS
  ctkFileInstall.cpp
)

# Files which should be processed by Qts moc
SET(PLUGIN_MOC_SRCS
  
)

# QRC Files which should be compiled into the plugin
SET(PLUGIN_resources
)

SET(PLUGIN_cached_resources
  CTK-INF/metatype/metatype.xml
)

SET(PLUGIN_ts_files
)

#Compute the plugin dependencies
ctkFunctionGetTargetLibraries(PLUGIN_target_libraries)

ctkMacroBuildPlugin(
  NAME ${PROJECT_NAME}
  EXPORT_DIRECTIVE ${PLUGIN_export_directive}
  SRCS ${PLUGIN_SRCS} ${PLUGIN_qm_files}
  MOC_SRCS ${PLUGIN_MOC_SRCS}
  RESOURCES ${PLUGIN_resources}
  CACHED_RESOURCEFILES ${PLUGIN_cached_resources}
  TRANSLATIONS ${PLUGIN_ts_files}
  TARGET_LIBRARIES ${PLUGIN_target_libraries}
)
