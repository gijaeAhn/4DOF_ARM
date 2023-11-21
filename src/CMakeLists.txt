cmake_minimum_required(VERSION 3.20.0)
project(4DOF_ARM)
set (CMAKE_CXX_STANDARD 17)

add_subdirectory(driver)
add_subdirectory(FSM)
add_subdirectory(robot)
add_subdirectory(run)