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
CMAKE_COMMAND = /home/talos/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4668.70/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/talos/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4668.70/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/topSort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/topSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/topSort.dir/flags.make

CMakeFiles/topSort.dir/topSort.cpp.o: CMakeFiles/topSort.dir/flags.make
CMakeFiles/topSort.dir/topSort.cpp.o: ../topSort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/topSort.dir/topSort.cpp.o"
	/usr/bin/clang++-5.0  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/topSort.dir/topSort.cpp.o -c /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/topSort.cpp

CMakeFiles/topSort.dir/topSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/topSort.dir/topSort.cpp.i"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/topSort.cpp > CMakeFiles/topSort.dir/topSort.cpp.i

CMakeFiles/topSort.dir/topSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/topSort.dir/topSort.cpp.s"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/topSort.cpp -o CMakeFiles/topSort.dir/topSort.cpp.s

CMakeFiles/topSort.dir/topSort.cpp.o.requires:

.PHONY : CMakeFiles/topSort.dir/topSort.cpp.o.requires

CMakeFiles/topSort.dir/topSort.cpp.o.provides: CMakeFiles/topSort.dir/topSort.cpp.o.requires
	$(MAKE) -f CMakeFiles/topSort.dir/build.make CMakeFiles/topSort.dir/topSort.cpp.o.provides.build
.PHONY : CMakeFiles/topSort.dir/topSort.cpp.o.provides

CMakeFiles/topSort.dir/topSort.cpp.o.provides.build: CMakeFiles/topSort.dir/topSort.cpp.o


# Object files for target topSort
topSort_OBJECTS = \
"CMakeFiles/topSort.dir/topSort.cpp.o"

# External object files for target topSort
topSort_EXTERNAL_OBJECTS =

topSort: CMakeFiles/topSort.dir/topSort.cpp.o
topSort: CMakeFiles/topSort.dir/build.make
topSort: CMakeFiles/topSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable topSort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/topSort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/topSort.dir/build: topSort

.PHONY : CMakeFiles/topSort.dir/build

CMakeFiles/topSort.dir/requires: CMakeFiles/topSort.dir/topSort.cpp.o.requires

.PHONY : CMakeFiles/topSort.dir/requires

CMakeFiles/topSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/topSort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/topSort.dir/clean

CMakeFiles/topSort.dir/depend:
	cd /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug/CMakeFiles/topSort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/topSort.dir/depend

