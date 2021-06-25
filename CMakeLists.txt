cmake_minimum_required(VERSION 3.10)
project(libcolhash)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(
  colhash
  STATIC
  ${PROJECT_SOURCE_DIR}/src/colhash/tuplehash.h
  )

set_target_properties(
  colhash
  PROPERTIES
  LINKER_LANGUAGE
  CXX
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

