cmake_minimum_required(VERSION 3.31)

include(vcpkg/BootstrapVcpkg.cmake)

project(eigen-example)

find_package(Eigen3 CONFIG REQUIRED)

add_library(lib)
target_sources(lib
  PRIVATE
    src/lib.cpp

  INTERFACE
    FILE_SET HEADERS
    BASE_DIRS
      src
    FILES
      src/lib.hpp
)
target_link_libraries(lib
  PRIVATE
    Eigen3::Eigen
)

add_executable(test_add)
target_sources(test_add
  PRIVATE
    test/test_add.cpp
)
target_link_libraries(test_add
  PRIVATE
    lib
)

enable_testing()
add_test(NAME test_add COMMAND test_add)
