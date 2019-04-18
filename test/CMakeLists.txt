cmake_minimum_required(VERSION 3.0)
project(test)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CONAN_INCLUDE_DIRS})

FILE(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(unittest ${srcs} $<TARGET_OBJECTS:common_objs>)

target_link_libraries(unittest
        PRIVATE
        CONAN_PKG::gtest
        )

set_target_properties(unittest PROPERTIES LINK_FLAGS "-static-libstdc++")
set_target_properties(unittest PROPERTIES COMPILE_FLAGS "-fno-access-control")

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})
install(TARGETS unittest
        RUNTIME DESTINATION output/bin
        )


