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
CMAKE_SOURCE_DIR = /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug

# Include any dependencies generated for this target.
include Myactuator/CMakeFiles/myactuator_rmd.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Myactuator/CMakeFiles/myactuator_rmd.dir/compiler_depend.make

# Include the progress variables for this target.
include Myactuator/CMakeFiles/myactuator_rmd.dir/progress.make

# Include the compile flags for this target's objects.
include Myactuator/CMakeFiles/myactuator_rmd.dir/flags.make

Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.o: Myactuator/CMakeFiles/myactuator_rmd.dir/flags.make
Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.o: /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/can/node.cpp
Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.o: Myactuator/CMakeFiles/myactuator_rmd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.o"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.o -MF CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.o.d -o CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.o -c /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/can/node.cpp

Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.i"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/can/node.cpp > CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.i

Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.s"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/can/node.cpp -o CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.s

Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.o: Myactuator/CMakeFiles/myactuator_rmd.dir/flags.make
Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.o: /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/can/utilities.cpp
Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.o: Myactuator/CMakeFiles/myactuator_rmd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.o"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.o -MF CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.o.d -o CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.o -c /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/can/utilities.cpp

Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.i"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/can/utilities.cpp > CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.i

Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.s"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/can/utilities.cpp -o CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.s

Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.o: Myactuator/CMakeFiles/myactuator_rmd.dir/flags.make
Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.o: /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/protocol/requests.cpp
Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.o: Myactuator/CMakeFiles/myactuator_rmd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.o"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.o -MF CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.o.d -o CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.o -c /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/protocol/requests.cpp

Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.i"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/protocol/requests.cpp > CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.i

Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.s"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/protocol/requests.cpp -o CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.s

Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.o: Myactuator/CMakeFiles/myactuator_rmd.dir/flags.make
Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.o: /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/protocol/responses.cpp
Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.o: Myactuator/CMakeFiles/myactuator_rmd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.o"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.o -MF CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.o.d -o CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.o -c /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/protocol/responses.cpp

Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.i"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/protocol/responses.cpp > CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.i

Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.s"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/protocol/responses.cpp -o CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.s

Myactuator/CMakeFiles/myactuator_rmd.dir/src/driver.cpp.o: Myactuator/CMakeFiles/myactuator_rmd.dir/flags.make
Myactuator/CMakeFiles/myactuator_rmd.dir/src/driver.cpp.o: /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/driver.cpp
Myactuator/CMakeFiles/myactuator_rmd.dir/src/driver.cpp.o: Myactuator/CMakeFiles/myactuator_rmd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Myactuator/CMakeFiles/myactuator_rmd.dir/src/driver.cpp.o"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Myactuator/CMakeFiles/myactuator_rmd.dir/src/driver.cpp.o -MF CMakeFiles/myactuator_rmd.dir/src/driver.cpp.o.d -o CMakeFiles/myactuator_rmd.dir/src/driver.cpp.o -c /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/driver.cpp

Myactuator/CMakeFiles/myactuator_rmd.dir/src/driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myactuator_rmd.dir/src/driver.cpp.i"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/driver.cpp > CMakeFiles/myactuator_rmd.dir/src/driver.cpp.i

Myactuator/CMakeFiles/myactuator_rmd.dir/src/driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myactuator_rmd.dir/src/driver.cpp.s"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator/src/driver.cpp -o CMakeFiles/myactuator_rmd.dir/src/driver.cpp.s

# Object files for target myactuator_rmd
myactuator_rmd_OBJECTS = \
"CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.o" \
"CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.o" \
"CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.o" \
"CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.o" \
"CMakeFiles/myactuator_rmd.dir/src/driver.cpp.o"

# External object files for target myactuator_rmd
myactuator_rmd_EXTERNAL_OBJECTS =

Myactuator/libmyactuator_rmd.so: Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/node.cpp.o
Myactuator/libmyactuator_rmd.so: Myactuator/CMakeFiles/myactuator_rmd.dir/src/can/utilities.cpp.o
Myactuator/libmyactuator_rmd.so: Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/requests.cpp.o
Myactuator/libmyactuator_rmd.so: Myactuator/CMakeFiles/myactuator_rmd.dir/src/protocol/responses.cpp.o
Myactuator/libmyactuator_rmd.so: Myactuator/CMakeFiles/myactuator_rmd.dir/src/driver.cpp.o
Myactuator/libmyactuator_rmd.so: Myactuator/CMakeFiles/myactuator_rmd.dir/build.make
Myactuator/libmyactuator_rmd.so: Myactuator/CMakeFiles/myactuator_rmd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library libmyactuator_rmd.so"
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myactuator_rmd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Myactuator/CMakeFiles/myactuator_rmd.dir/build: Myactuator/libmyactuator_rmd.so
.PHONY : Myactuator/CMakeFiles/myactuator_rmd.dir/build

Myactuator/CMakeFiles/myactuator_rmd.dir/clean:
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator && $(CMAKE_COMMAND) -P CMakeFiles/myactuator_rmd.dir/cmake_clean.cmake
.PHONY : Myactuator/CMakeFiles/myactuator_rmd.dir/clean

Myactuator/CMakeFiles/myactuator_rmd.dir/depend:
	cd /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/Myactuator /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator /home/gj/Desktop/4DOF_ARM/src/Dependencies/driver/cmake-build-debug/Myactuator/CMakeFiles/myactuator_rmd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Myactuator/CMakeFiles/myactuator_rmd.dir/depend
