cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(cpp_learn)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

find_package(PkgConfig)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(main "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp" $<TARGET_OBJECTS:common_objs>)

find_package (Threads)

target_link_libraries (main ${CMAKE_THREAD_LIBS_INIT})

set_target_properties(main PROPERTIES LINK_FLAGS "-static-libstdc++")
