cmake_minimum_required(VERSION 3.20.0)
project(
  4DOF_ARM
  VERSION 0.1
  LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGSS -pthread)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(driver)
add_subdirectory(FSM)
add_subdirectory(robot)
add_subdirectory(run)








