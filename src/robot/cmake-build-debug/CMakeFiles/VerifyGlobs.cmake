# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.26
cmake_policy(SET CMP0009 NEW)

# SRC_FILES at CMakeLists.txt:15 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/home/gj/Desktop/4DOF_ARM/src/robot/src/*.cc")
set(OLD_GLOB
  "/home/gj/Desktop/4DOF_ARM/src/robot/src/controller/robot_gravityCompensation.cc"
  "/home/gj/Desktop/4DOF_ARM/src/robot/src/controller/robot_impedenceController.cc"
  "/home/gj/Desktop/4DOF_ARM/src/robot/src/controller/robot_positionController.cc"
  "/home/gj/Desktop/4DOF_ARM/src/robot/src/robot_body.cc"
  "/home/gj/Desktop/4DOF_ARM/src/robot/src/robot_builder.cc"
  "/home/gj/Desktop/4DOF_ARM/src/robot/src/robot_pub.cc"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/gj/Desktop/4DOF_ARM/src/robot/cmake-build-debug/CMakeFiles/cmake.verify_globs")
endif()