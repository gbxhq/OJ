# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ixsim/Documents/myProjects/Clion/Algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ixsim/Documents/myProjects/Clion/Algorithm/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Sword.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sword.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sword.dir/flags.make

CMakeFiles/Sword.dir/Sword/Swordtemp.cpp.o: CMakeFiles/Sword.dir/flags.make
CMakeFiles/Sword.dir/Sword/Swordtemp.cpp.o: ../Sword/Swordtemp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixsim/Documents/myProjects/Clion/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sword.dir/Sword/Swordtemp.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sword.dir/Sword/Swordtemp.cpp.o -c /Users/ixsim/Documents/myProjects/Clion/Algorithm/Sword/Swordtemp.cpp

CMakeFiles/Sword.dir/Sword/Swordtemp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sword.dir/Sword/Swordtemp.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixsim/Documents/myProjects/Clion/Algorithm/Sword/Swordtemp.cpp > CMakeFiles/Sword.dir/Sword/Swordtemp.cpp.i

CMakeFiles/Sword.dir/Sword/Swordtemp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sword.dir/Sword/Swordtemp.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixsim/Documents/myProjects/Clion/Algorithm/Sword/Swordtemp.cpp -o CMakeFiles/Sword.dir/Sword/Swordtemp.cpp.s

# Object files for target Sword
Sword_OBJECTS = \
"CMakeFiles/Sword.dir/Sword/Swordtemp.cpp.o"

# External object files for target Sword
Sword_EXTERNAL_OBJECTS =

Sword: CMakeFiles/Sword.dir/Sword/Swordtemp.cpp.o
Sword: CMakeFiles/Sword.dir/build.make
Sword: CMakeFiles/Sword.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ixsim/Documents/myProjects/Clion/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sword"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sword.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sword.dir/build: Sword

.PHONY : CMakeFiles/Sword.dir/build

CMakeFiles/Sword.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Sword.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Sword.dir/clean

CMakeFiles/Sword.dir/depend:
	cd /Users/ixsim/Documents/myProjects/Clion/Algorithm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ixsim/Documents/myProjects/Clion/Algorithm /Users/ixsim/Documents/myProjects/Clion/Algorithm /Users/ixsim/Documents/myProjects/Clion/Algorithm/cmake-build-debug /Users/ixsim/Documents/myProjects/Clion/Algorithm/cmake-build-debug /Users/ixsim/Documents/myProjects/Clion/Algorithm/cmake-build-debug/CMakeFiles/Sword.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sword.dir/depend
