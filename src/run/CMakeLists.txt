cmake_minimum_required(VERSION 3.20)
project(myactuator_rmd_test)


if(NOT UNIX)
  message(FATAL_ERROR "Currently this driver only supports Linux!")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Threads REQUIRED)


#include header
# include_directories(../Myactuator/include)

add_executable(rmd_lib_test src/test.cc)
target_link_libraries(rmd_lib_test myactuator_rmd Threads::Threads)