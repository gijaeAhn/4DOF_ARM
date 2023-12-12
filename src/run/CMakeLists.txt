cmake_minimum_required(VERSION 3.20)
project(run)


if(NOT UNIX)
  message(FATAL_ERROR "Currently this driver only supports Linux!")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_package(Threads REQUIRED)


#include header
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${myactuator_rmd_SOURCE_DIR}/include 
                    ${FSM_SOURCE_DIR}/include
                    ${robot_SOURCE_DIR}/include)

add_executable(PIDrun src/PIDrun.cc)
target_link_libraries(PIDrun robot
                           Threads::Threads)

add_executable(POSITIONrun src/POSITIONrun.cc)
target_link_libraries(POSITIONrun robot)
