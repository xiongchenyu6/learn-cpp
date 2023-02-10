cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(cpp_learn)

<<<<<<< Updated upstream
set(CMAKE_BUILD_TYPE Debug)
=======
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
>>>>>>> Stashed changes
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

find_package(PkgConfig)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

FILE(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(common_objs OBJECT ${srcs})

add_executable(main "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp" $<TARGET_OBJECTS:common_objs>)

find_package (Threads)

target_link_libraries (main ${CMAKE_THREAD_LIBS_INIT})

set_target_properties(main PROPERTIES LINK_FLAGS "-static-libstdc++")

<<<<<<< Updated upstream
# add_custom_command(TARGET main
#         POST_BUILD
#         COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/Debug/bin/main)

# add_custom_target(main_run
#   COMMAND main
#   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Debug/bin
#   COMMENT "run generated test2 in ${CMAKE_CURRENT_SOURCE_DIR}"
# )

# include(CTest)
# enable_testing()

# if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
#    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
#    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
#                   "${CMAKE_BINARY_DIR}/conan.cmake")
# endif()

# include(${CMAKE_BINARY_DIR}/conan.cmake)
# conan_cmake_run(REQUIRES
#                 gtest/1.8.1@bincrafters/stable
#                 BASIC_SETUP CMAKE_TARGETS
#                 BUILD missing)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
=======


include(CTest)
enable_testing()
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
>>>>>>> Stashed changes
