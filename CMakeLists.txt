#-----------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8.7)

include(ExternalProject)

#-----------------------------------------------------------------------------
set(MODULE_NAME "PerkTutorCommon")

string(TOUPPER ${MODULE_NAME} MODULE_NAME_UPPER)

#-----------------------------------------------------------------------------
if ( NOT DEFINED ${EXTENSION_NAME}_SUPERBUILD )
  find_package(Slicer REQUIRED)
  include(${Slicer_USE_FILE})
endif()

# The header '${module_name}Export.h' will be automatically configured.
set(MODULE_EXPORT_DIRECTIVE "${MODULE_NAME_UPPER}_EXPORT")


# Additional directories to include
set(MODULE_INCLUDE_DIRECTORIES
  ${Slicer_Base_INCLUDE_DIRS}
  )

# Source files
set(MODULE_SRCS
  PerkTutorCommon.cxx
  PerkTutorCommon.h
  )

# Additional Target libraries
set(MODULE_TARGET_LIBRARIES
  ${VTK_LIBRARIES}
  ${ITK_LIBRARIES}
  ${MRML_LIBRARIES}
  SlicerBaseLogic
  qSlicerBaseQTCore
  qSlicerBaseQTGUI
  )

SlicerMacroBuildModuleMRML(
  NAME ${MODULE_NAME}
  EXPORT_DIRECTIVE ${MODULE_EXPORT_DIRECTIVE}
  INCLUDE_DIRECTORIES ${MODULE_INCLUDE_DIRECTORIES}
  SRCS ${MODULE_SRCS}
  TARGET_LIBRARIES ${MODULE_TARGET_LIBRARIES}
  )