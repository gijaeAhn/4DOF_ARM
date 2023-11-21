cmake_minimum_required(VERSION 3.20)
project(driver)


if(NOT UNIX)
  message(FATAL_ERROR "Currently this driver only supports Linux!")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find_package(Threads REQUIRED)


#include header
# include_directories(../Myactuator/include)

add_subdirectory(Myactuator)