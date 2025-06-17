cmake_minimum_required(VERSION 3.30)
project(ashtech_vendor VERSION 0.0.1 LANGUAGES C CXX)

include(ExternalProject)
# include(CMakePrintHelpers) # for troubleshooting (optional)

set(VENDOR_PREFIX "${CMAKE_SOURCE_DIR}")
set(VENDOR_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
file(MAKE_DIRECTORY "${VENDOR_INSTALL_PREFIX}")        # ensure it exists

# Use CMAKE_BUILD_TYPE or $<CONFIG> depending on generator. Needed so we can propagate in ExternalProject_Add.
if(NOT DEFINED BUILD_CONFIG)
    if(CMAKE_CONFIGURATION_TYPES)
        # Multi-config (e.g. Ninja Multi-Config, MSVC): use generator expression
        set(BUILD_CONFIG $<CONFIG>)
    else()
        # Single-config (e.g. Ninja, Makefiles): use CMAKE_BUILD_TYPE
        set(BUILD_CONFIG "${CMAKE_BUILD_TYPE}")
    endif()
endif()

list(APPEND CMAKE_MODULE_PATH "${VENDOR_PREFIX}/cmake")
include(SDL3)
