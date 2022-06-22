cmake_minimum_required(VERSION 3.17)

option(BUILD_FOR_NATIVE "Whether to build for a native target or not." ON)
option(USE_PICO_SDK "Whether to use the RPi Pico SDK or not (disabling this essentially disables Pico support.)" ON)
option(EXTERNAL_PICO_SDK "Whether or not to expect an external pico sdk to be present." ON)

if (BUILD_FOR_NATIVE)
    message("Building for a native target!")
else()
    message("Building for an embedded target!")
endif()

if (NOT BUILD_FOR_NATIVE AND USE_PICO_SDK AND NOT EXTERNAL_PICO_SDK)
    include(pico-sdk/pico_sdk_init.cmake)
endif()

project(hwlib)
set(CMAKE_CXX_VERSION 17)

if (NOT BUILD_FOR_NATIVE AND USE_PICO_SDK AND NOT EXTERNAL_PICO_SDK)
    pico_sdk_init()
endif()

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(library)
add_subdirectory(test)
