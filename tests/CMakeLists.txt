file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(unit_tests ${srcs} $<TARGET_OBJECTS:common_objs>)

target_link_libraries(
  unit_tests
  PRIVATE
  CONAN_PKG::gtest
)

set_target_properties(unit_tests PROPERTIES LINK_FLAGS "-static-libstdc++")
set_target_properties(unit_tests PROPERTIES COMPILE_FLAGS "-fno-access-control")

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(
  unit_tests
  PROPERTIES
  LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
  240
)
