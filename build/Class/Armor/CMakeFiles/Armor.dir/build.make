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
include Class/Armor/CMakeFiles/Armor.dir/depend.make

# Include the progress variables for this target.
include Class/Armor/CMakeFiles/Armor.dir/progress.make

# Include the compile flags for this target's objects.
include Class/Armor/CMakeFiles/Armor.dir/flags.make

Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o: Class/Armor/CMakeFiles/Armor.dir/flags.make
Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o: ../Class/Armor/Armor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rosen/桌面/Rosen/Task1_Detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o"
	cd /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Armor && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Armor.dir/Armor.cpp.o -c /home/rosen/桌面/Rosen/Task1_Detect/Class/Armor/Armor.cpp

Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Armor.dir/Armor.cpp.i"
	cd /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Armor && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rosen/桌面/Rosen/Task1_Detect/Class/Armor/Armor.cpp > CMakeFiles/Armor.dir/Armor.cpp.i

Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Armor.dir/Armor.cpp.s"
	cd /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Armor && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rosen/桌面/Rosen/Task1_Detect/Class/Armor/Armor.cpp -o CMakeFiles/Armor.dir/Armor.cpp.s

Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o.requires:

.PHONY : Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o.requires

Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o.provides: Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o.requires
	$(MAKE) -f Class/Armor/CMakeFiles/Armor.dir/build.make Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o.provides.build
.PHONY : Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o.provides

Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o.provides.build: Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o


# Object files for target Armor
Armor_OBJECTS = \
"CMakeFiles/Armor.dir/Armor.cpp.o"

# External object files for target Armor
Armor_EXTERNAL_OBJECTS =

Class/Armor/libArmor.a: Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o
Class/Armor/libArmor.a: Class/Armor/CMakeFiles/Armor.dir/build.make
Class/Armor/libArmor.a: Class/Armor/CMakeFiles/Armor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rosen/桌面/Rosen/Task1_Detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libArmor.a"
	cd /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Armor && $(CMAKE_COMMAND) -P CMakeFiles/Armor.dir/cmake_clean_target.cmake
	cd /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Armor && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Armor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Class/Armor/CMakeFiles/Armor.dir/build: Class/Armor/libArmor.a

.PHONY : Class/Armor/CMakeFiles/Armor.dir/build

Class/Armor/CMakeFiles/Armor.dir/requires: Class/Armor/CMakeFiles/Armor.dir/Armor.cpp.o.requires

.PHONY : Class/Armor/CMakeFiles/Armor.dir/requires

Class/Armor/CMakeFiles/Armor.dir/clean:
	cd /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Armor && $(CMAKE_COMMAND) -P CMakeFiles/Armor.dir/cmake_clean.cmake
.PHONY : Class/Armor/CMakeFiles/Armor.dir/clean

Class/Armor/CMakeFiles/Armor.dir/depend:
	cd /home/rosen/桌面/Rosen/Task1_Detect/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rosen/桌面/Rosen/Task1_Detect /home/rosen/桌面/Rosen/Task1_Detect/Class/Armor /home/rosen/桌面/Rosen/Task1_Detect/build /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Armor /home/rosen/桌面/Rosen/Task1_Detect/build/Class/Armor/CMakeFiles/Armor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Class/Armor/CMakeFiles/Armor.dir/depend

