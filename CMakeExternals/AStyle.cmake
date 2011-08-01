#
# AStyle
#

SET(AStyle_DEPENDS)
ctkMacroShouldAddExternalProject(AStyle_LIBRARIES add_project)
IF(${add_project})
  
  # Sanity checks
  IF(DEFINED AStyle_DIR AND NOT EXISTS ${AStyle_DIR})
    MESSAGE(FATAL_ERROR "AStyle_DIR variable is defined but corresponds to non-existing directory")
  ENDIF()

  SET(AStyle_enabling_variable AStyle_LIBRARIES)

  SET(proj AStyle)
  SET(proj_DEPENDENCIES)

  SET(AStyle_DEPENDS ${proj})

  IF(NOT DEFINED AStyle_DIR)
    # Set CMake OSX variable to pass down the external project
    set(CMAKE_OSX_EXTERNAL_PROJECT_ARGS)
    if(APPLE)
      list(APPEND CMAKE_OSX_EXTERNAL_PROJECT_ARGS
        -DCMAKE_OSX_ARCHITECTURES=${CMAKE_OSX_ARCHITECTURES}
        -DCMAKE_OSX_SYSROOT=${CMAKE_OSX_SYSROOT}
        -DCMAKE_OSX_DEPLOYMENT_TARGET=${CMAKE_OSX_DEPLOYMENT_TARGET})
    endif()
    
    #     MESSAGE(STATUS "Adding project:${proj}")
    ExternalProject_Add(${proj}
      SOURCE_DIR ${CMAKE_BINARY_DIR}/${proj}
      BINARY_DIR ${proj}-build
      PREFIX ${proj}${ep_suffix}
      GIT_REPOSITORY "${git_protocol}://github.com/saschazelzer/AStyle.git"
      GIT_TAG "origin/2.02-patched"
      CMAKE_GENERATOR ${gen}
      INSTALL_COMMAND ""
      CMAKE_ARGS
        ${ep_common_args}
        ${CMAKE_OSX_EXTERNAL_PROJECT_ARGS}
      DEPENDS
        ${proj_DEPENDENCIES}
      )
    SET(AStyle_DIR "${CMAKE_BINARY_DIR}/${proj}-build/AStyle")
    
    # Since AStyle is statically build, there is not need to add its corresponding
    # library output directory to CTK_EXTERNAL_LIBRARY_DIRS

  ELSE()
    ctkMacroEmptyExternalProject(${proj} "${proj_DEPENDENCIES}")
  ENDIF()
  
  LIST(APPEND CTK_SUPERBUILD_EP_ARGS -DAStyle_DIR:PATH=${AStyle_DIR})

  SET(${AStyle_enabling_variable}_INCLUDE_DIRS AStyle_INCLUDE_DIRS)
  SET(${AStyle_enabling_variable}_FIND_PACKAGE_CMD AStyle)
      
ENDIF()
