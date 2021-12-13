cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(cpp_learn)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -stdlib=libc++")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CONAN_INCLUDE_DIRS})

file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc")

add_library(common_objs OBJECT ${srcs})

add_executable(main "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp" $<TARGET_OBJECTS:common_objs>)

find_package(Threads)

# find_package(Protobuf REQUIRED)

target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})

set_target_properties(main PROPERTIES LINK_FLAGS "-static-libstdc++")

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(
    DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
    "${CMAKE_BINARY_DIR}/conan.cmake"
  )
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(
  REQUIRES
  gtest/1.10.0
  BASIC_SETUP CMAKE_TARGETS
  BUILD missing
)

include(CTest)
enable_testing()
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
