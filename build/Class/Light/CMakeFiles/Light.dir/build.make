# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rosen/桌面/Rosen/Task1_Detect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rosen/桌面/Rosen/Task1_Detect/build

# Include any dependencies generated for this target.
include Class/Light/CMakeFiles/Light.dir/depend.make

# Include the progress variables for this target.
include Class/Light/CMakeFiles/Light.dir/progress.make

# Include the compile flags for this target's objects.
include Class/Light/CMakeFiles/Light.dir/flags.make

Class/Light/CMakeFiles/Light.dir/Light.cpp.o: Class/Light/CMakeFiles/Light.dir/flags.make
Class/Light/CMakeFiles/Light.dir/Light.cpp.o: ../Class/Light/Light.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rosen/桌面/Rosen/Task1_Detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Class/Light/CMakeFiles/Light.dir/Light.cpp.o"
	cd /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Light && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Light.dir/Light.cpp.o -c /home/rosen/桌面/Rosen/Task1_Detect/Class/Light/Light.cpp

Class/Light/CMakeFiles/Light.dir/Light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Light.dir/Light.cpp.i"
	cd /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Light && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rosen/桌面/Rosen/Task1_Detect/Class/Light/Light.cpp > CMakeFiles/Light.dir/Light.cpp.i

Class/Light/CMakeFiles/Light.dir/Light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Light.dir/Light.cpp.s"
	cd /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Light && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rosen/桌面/Rosen/Task1_Detect/Class/Light/Light.cpp -o CMakeFiles/Light.dir/Light.cpp.s

Class/Light/CMakeFiles/Light.dir/Light.cpp.o.requires:

.PHONY : Class/Light/CMakeFiles/Light.dir/Light.cpp.o.requires

Class/Light/CMakeFiles/Light.dir/Light.cpp.o.provides: Class/Light/CMakeFiles/Light.dir/Light.cpp.o.requires
	$(MAKE) -f Class/Light/CMakeFiles/Light.dir/build.make Class/Light/CMakeFiles/Light.dir/Light.cpp.o.provides.build
.PHONY : Class/Light/CMakeFiles/Light.dir/Light.cpp.o.provides

Class/Light/CMakeFiles/Light.dir/Light.cpp.o.provides.build: Class/Light/CMakeFiles/Light.dir/Light.cpp.o


# Object files for target Light
Light_OBJECTS = \
"CMakeFiles/Light.dir/Light.cpp.o"

# External object files for target Light
Light_EXTERNAL_OBJECTS =

Class/Light/libLight.a: Class/Light/CMakeFiles/Light.dir/Light.cpp.o
Class/Light/libLight.a: Class/Light/CMakeFiles/Light.dir/build.make
Class/Light/libLight.a: Class/Light/CMakeFiles/Light.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rosen/桌面/Rosen/Task1_Detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libLight.a"
	cd /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Light && $(CMAKE_COMMAND) -P CMakeFiles/Light.dir/cmake_clean_target.cmake
	cd /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Light && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Light.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Class/Light/CMakeFiles/Light.dir/build: Class/Light/libLight.a

.PHONY : Class/Light/CMakeFiles/Light.dir/build

Class/Light/CMakeFiles/Light.dir/requires: Class/Light/CMakeFiles/Light.dir/Light.cpp.o.requires

.PHONY : Class/Light/CMakeFiles/Light.dir/requires

Class/Light/CMakeFiles/Light.dir/clean:
	cd /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Light && $(CMAKE_COMMAND) -P CMakeFiles/Light.dir/cmake_clean.cmake
.PHONY : Class/Light/CMakeFiles/Light.dir/clean

Class/Light/CMakeFiles/Light.dir/depend:
	cd /home/rosen/桌面/Rosen/Task1_Detect/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rosen/桌面/Rosen/Task1_Detect /home/rosen/桌面/Rosen/Task1_Detect/Class/Light /home/rosen/桌面/Rosen/Task1_Detect/build /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Light /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Light/CMakeFiles/Light.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Class/Light/CMakeFiles/Light.dir/depend

