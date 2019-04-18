cmake_minimum_required(VERSION 3.0)
project(cpp_learn)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(REQUIRES
                gtest/1.8.1@bincrafters/stable
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CONAN_INCLUDE_DIRS})

FILE(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(common_objs OBJECT ${srcs})

add_executable(main "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp" $<TARGET_OBJECTS:common_objs>)

set_target_properties(main PROPERTIES LINK_FLAGS "-static-libstdc++")

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})
install(TARGETS main RUNTIME DESTINATION output/bin)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
