# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/250/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/250/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sj/Desktop/4DOF_ARM/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sj/Desktop/4DOF_ARM/src/cmake-build-debug

# Utility rule file for doxygen.

# Include any custom commands dependencies for this target.
include Dependencies/EKF/ball_localization/CMakeFiles/doxygen.dir/compiler_depend.make

# Include the progress variables for this target.
include Dependencies/EKF/ball_localization/CMakeFiles/doxygen.dir/progress.make

doxygen: Dependencies/EKF/ball_localization/CMakeFiles/doxygen.dir/build.make
.PHONY : doxygen

# Rule to build all files generated by this target.
Dependencies/EKF/ball_localization/CMakeFiles/doxygen.dir/build: doxygen
.PHONY : Dependencies/EKF/ball_localization/CMakeFiles/doxygen.dir/build

Dependencies/EKF/ball_localization/CMakeFiles/doxygen.dir/clean:
	cd /home/sj/Desktop/4DOF_ARM/src/cmake-build-debug/Dependencies/EKF/ball_localization && $(CMAKE_COMMAND) -P CMakeFiles/doxygen.dir/cmake_clean.cmake
.PHONY : Dependencies/EKF/ball_localization/CMakeFiles/doxygen.dir/clean

Dependencies/EKF/ball_localization/CMakeFiles/doxygen.dir/depend:
	cd /home/sj/Desktop/4DOF_ARM/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sj/Desktop/4DOF_ARM/src /home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization /home/sj/Desktop/4DOF_ARM/src/cmake-build-debug /home/sj/Desktop/4DOF_ARM/src/cmake-build-debug/Dependencies/EKF/ball_localization /home/sj/Desktop/4DOF_ARM/src/cmake-build-debug/Dependencies/EKF/ball_localization/CMakeFiles/doxygen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Dependencies/EKF/ball_localization/CMakeFiles/doxygen.dir/depend

