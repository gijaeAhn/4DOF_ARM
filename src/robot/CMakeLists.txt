cmake_minimum_required(VERSION 3.20)
project(robot)

option(PYTHON_BINDINGS "Building Python bindings" OFF)
option(BUILD_TESTING "Build unit and integration tests" OFF)
option(SETUP_TEST_IFNAME "Set-up the test VCAN interface automatically" OFF)

if(NOT UNIX)
  message(FATAL_ERROR "Currently this driver only supports Linux!")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
)

add_library(robot SHARED ${SRC_FILES})


target_include_directories(robot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${myactuator_rmd_SOURCE_DIR}/include ${FSM_SOURCE_DIR}/include)
# target_compile_options(robot PRIVATE -Wall -Werror)
target_compile_features(robot PRIVATE cxx_std_17)


# # include(FetchContent)


# FetchContent_Declare(
#   Fmt
#   GIT_REPOSITORY "https://github.com/fmtlib/fmt"
#   GIT_TAG "7.1.3"
#   )
# FetchContent_MakeAvailable(Fmt)
