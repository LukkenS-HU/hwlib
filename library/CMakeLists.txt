add_library(hwlib INTERFACE)
target_sources(hwlib INTERFACE hwlib.cpp)
target_include_directories(hwlib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set(TARGET_DIR "targets")

function(HWLIB_AddExecutable name)
    foreach (target IN LISTS HWLIB_AVAILABLE_TARGETS)
        _add_target_executable(${name} ${target} ${ARGN})
    endforeach()
endfunction()

function(HWLIB_TargetLinkLibraries name)
    foreach (target IN LISTS HWLIB_AVAILABLE_TARGETS)
        _target_link_libraries(${name} ${target} ${ARGN})
    endforeach()
endfunction()

function(HWLIB_TargetIncludeDirectories name)
    foreach (target IN LISTS HWLIB_AVAILABLE_TARGETS)
        _target_include_directories(${name} ${target} ${ARGN})
    endforeach()
endfunction()

function(_target_link_libraries executableName targetName)
    target_link_libraries(${executableName}_${targetName} ${ARGN})
endfunction()

function(_add_target_executable executableName targetName)
    add_executable(${executableName}_${targetName} ${ARGN})
    _target_link_libraries(${executableName} ${targetName} hwlib hwlib_target_${targetName})
endfunction()

function(_target_include_directories executableName targetName)
    target_include_directories(${executableName}_${targetName} ${ARGN})
endfunction()

macro(_add_target targetName)
    add_library(hwlib_target_${targetName} INTERFACE)
    target_link_libraries(hwlib_target_${targetName} INTERFACE ${ARGN})
    target_compile_definitions(hwlib_target_${targetName} INTERFACE HWLIB_TARGET="${TARGET_DIR}/hwlib-${targetName}.hpp")

    list(APPEND TEMP_AVAILABLE_TARGETS ${targetName})
endmacro()

if (BUILD_FOR_NATIVE)
    find_package(SFML REQUIRED system window graphics)

    _add_target(native-linux sfml-system sfml-graphics sfml-window)
else()
    if (USE_PICO_SDK)
        _add_target(rp2040 pico_stdlib hardware_gpio hardware_i2c hardware_uart)
    endif()
endif()

set(HWLIB_AVAILABLE_TARGETS ${TEMP_AVAILABLE_TARGETS} CACHE INTERNAL "HWLIB_AVAILABLE_TARGETS")
