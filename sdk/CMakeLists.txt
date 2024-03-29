### This file is used for build example projects.

# set this will supress some warnings
set(BUILDING_SDK "yes" CACHE INTERNAL "")

# basic config
if (NOT PROJ)
    get_filename_component(PROJ ${CMAKE_CURRENT_BINARY_DIR} DIRECTORY)
    get_filename_component(PROJ ${PROJ} NAME)
    string(REPLACE " " "_" PROJ ${PROJ})
    message(STATUS "PROJ not set, use ${PROJ} as PROJ. Also, you can set it manually. e.g. -DPROJ=hello_world")
else()
    message("PROJ = ${PROJ}")
endif ()

cmake_minimum_required(VERSION 3.0)
include(./cmake/common.cmake)

project(${PROJ} C CXX ASM)

# config self use headers
include(./cmake/macros.internal.cmake)
header_directories(${SDK_ROOT}/lib)
header_directories(src/)

# build library first
add_subdirectory(lib)

# compile project
add_source_files(src/*.c src/*.s src/*.S src/*.cpp)

include(./cmake/executable.cmake)

