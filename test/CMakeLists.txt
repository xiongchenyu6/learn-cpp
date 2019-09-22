
FILE(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(unit_tests ${srcs} $<TARGET_OBJECTS:common_objs>)

target_link_libraries(unit_tests
        PRIVATE
        CONAN_PKG::gtest
        )

set_target_properties(unit_tests PROPERTIES LINK_FLAGS "-static-libstdc++")
set_target_properties(unit_tests PROPERTIES COMPILE_FLAGS "-fno-access-control")

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_CURRENT_SOURCE_DIR}/../Debug/bin/unit_tests
  )

# install(TARGETS unittest
#         RUNTIME DESTINATION output/bin
#         )
