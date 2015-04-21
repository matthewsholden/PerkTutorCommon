#-----------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8.7)

#-----------------------------------------------------------------------------
# Module name (usually identique to the directory name)
set(MODULE_NAME "PerkTutorCommon")
set(MODULE_TITLE "Perk Tutor Common")

string(TOUPPER ${MODULE_NAME} MODULE_NAME_UPPER)

#-----------------------------------------------------------------------------
if ( NOT DEFINED ${EXTENSION_NAME}_SUPERBUILD )
  find_package(Slicer REQUIRED)
  include(${Slicer_USE_FILE})
endif()

#-----------------------------------------------------------------------------
# Build module sub libraries

set(MODULE_EXPORT_DIRECTIVE "Q_SLICER_QTMODULES_${MODULE_NAME_UPPER}_EXPORT")

# Additional includes - Current_{source,binary} and Slicer_{Libs,Base} already included
set(MODULE_INCLUDE_DIRECTORIES
  )

# Source files
set(MODULE_SRCS
  ${MODULE_NAME}.cxx
  ${MODULE_NAME}.h
  )

# Headers that should run through moc
set(MODULE_MOC_SRCS
  )

# UI files
set(MODULE_UI_SRCS
  )

# Additional Target libraries
set(MODULE_TARGET_LIBRARIES
  ${VTK_LIBRARIES}
  ${MRML_LIBRARIES}
  ${QT_LIBRARIES}
  )

# Resources
set(MODULE_RESOURCES
  )

#-----------------------------------------------------------------------------
slicerMacroBuildLoadableModule(
  NAME ${MODULE_NAME}
  TITLE ${MODULE_TITLE}
  EXPORT_DIRECTIVE ${MODULE_EXPORT_DIRECTIVE}
  INCLUDE_DIRECTORIES ${MODULE_INCLUDE_DIRECTORIES}
  SRCS ${MODULE_SRCS}
  MOC_SRCS ${MODULE_MOC_SRCS}
  UI_SRCS ${MODULE_UI_SRCS}
  TARGET_LIBRARIES ${MODULE_TARGET_LIBRARIES}
  RESOURCES ${MODULE_RESOURCES}
  )

#-----------------------------------------------------------------------------
