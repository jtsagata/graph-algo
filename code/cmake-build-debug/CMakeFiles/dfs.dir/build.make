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
include CMakeFiles/dfs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dfs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dfs.dir/flags.make

CMakeFiles/dfs.dir/DFS.cpp.o: CMakeFiles/dfs.dir/flags.make
CMakeFiles/dfs.dir/DFS.cpp.o: ../DFS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dfs.dir/DFS.cpp.o"
	/usr/bin/clang++-5.0  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dfs.dir/DFS.cpp.o -c /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/DFS.cpp

CMakeFiles/dfs.dir/DFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dfs.dir/DFS.cpp.i"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/DFS.cpp > CMakeFiles/dfs.dir/DFS.cpp.i

CMakeFiles/dfs.dir/DFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dfs.dir/DFS.cpp.s"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/DFS.cpp -o CMakeFiles/dfs.dir/DFS.cpp.s

CMakeFiles/dfs.dir/DFS.cpp.o.requires:

.PHONY : CMakeFiles/dfs.dir/DFS.cpp.o.requires

CMakeFiles/dfs.dir/DFS.cpp.o.provides: CMakeFiles/dfs.dir/DFS.cpp.o.requires
	$(MAKE) -f CMakeFiles/dfs.dir/build.make CMakeFiles/dfs.dir/DFS.cpp.o.provides.build
.PHONY : CMakeFiles/dfs.dir/DFS.cpp.o.provides

CMakeFiles/dfs.dir/DFS.cpp.o.provides.build: CMakeFiles/dfs.dir/DFS.cpp.o


# Object files for target dfs
dfs_OBJECTS = \
"CMakeFiles/dfs.dir/DFS.cpp.o"

# External object files for target dfs
dfs_EXTERNAL_OBJECTS =

dfs: CMakeFiles/dfs.dir/DFS.cpp.o
dfs: CMakeFiles/dfs.dir/build.make
dfs: CMakeFiles/dfs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dfs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dfs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dfs.dir/build: dfs

.PHONY : CMakeFiles/dfs.dir/build

CMakeFiles/dfs.dir/requires: CMakeFiles/dfs.dir/DFS.cpp.o.requires

.PHONY : CMakeFiles/dfs.dir/requires

CMakeFiles/dfs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dfs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dfs.dir/clean

CMakeFiles/dfs.dir/depend:
	cd /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug /home/talos/Desktop/Nextcloud/B-Semester/AlgorithmsDS/Assignments/Assignment-4/code/cmake-build-debug/CMakeFiles/dfs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dfs.dir/depend

