cmake_minimum_required(VERSION 3.20)
project(libcolhash)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FindPkgConfig)

add_library(
  colhash
  SHARED
  ${PROJECT_SOURCE_DIR}/src/colhash/tuplehash.h
  )

set_target_properties(
  colhash
  PROPERTIES
  LINKER_LANGUAGE
  CXX
  POSITION_INDEPENDENT_CODE
  ON
  )

target_include_directories(
  colhash
  PUBLIC
  ${PROJECT_SOURCE_DIR}/src
  )

include(GNUInstallDirs)

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/colhash/tuplehash.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/colhash/
  )

install(
  TARGETS
  colhash
  )

configure_file(
  ${PROJECT_SOURCE_DIR}/libcolhash.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/libcolhash.pc
  @ONLY
  )
install(
  FILES
  ${CMAKE_CURRENT_BINARY_DIR}/libcolhash.pc
  DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/pkgconfig/
  )
