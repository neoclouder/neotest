# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "*** ${NEOTEST_NAME} - Setting build type to 'Debug' as none was specified. ***")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
else()
  message(STATUS "*** ${NEOTEST_NAME} - Build type: ${CMAKE_BUILD_TYPE} ***")
endif()
