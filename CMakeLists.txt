cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(cpp_learn)
set(CMAKE_CXX_FLAGS "-fcoroutines")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Collect all source files in the src directory
file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc")

add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp" ${SRC_FILES})
add_executable(target2 "${CMAKE_CURRENT_SOURCE_DIR}/main2.cpp" ${SRC_FILES})

target_include_directories(${PROJECT_NAME}
                                                   PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
                                                                   )
target_sources(${PROJECT_NAME}
                           PUBLIC
                           ${SRC_FILES})

find_package(Threads)

target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)


# include(CTest)
# enable_testing()
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
