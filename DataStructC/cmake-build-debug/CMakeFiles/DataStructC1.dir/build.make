# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\k8s\Algorithms\DataStructC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\k8s\Algorithms\DataStructC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DataStructC1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DataStructC1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataStructC1.dir/flags.make

CMakeFiles/DataStructC1.dir/struct/SqList.c.obj: CMakeFiles/DataStructC1.dir/flags.make
CMakeFiles/DataStructC1.dir/struct/SqList.c.obj: ../struct/SqList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\k8s\Algorithms\DataStructC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DataStructC1.dir/struct/SqList.c.obj"
	D:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\DataStructC1.dir\struct\SqList.c.obj -c D:\k8s\Algorithms\DataStructC\struct\SqList.c

CMakeFiles/DataStructC1.dir/struct/SqList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DataStructC1.dir/struct/SqList.c.i"
	D:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\k8s\Algorithms\DataStructC\struct\SqList.c > CMakeFiles\DataStructC1.dir\struct\SqList.c.i

CMakeFiles/DataStructC1.dir/struct/SqList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DataStructC1.dir/struct/SqList.c.s"
	D:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\k8s\Algorithms\DataStructC\struct\SqList.c -o CMakeFiles\DataStructC1.dir\struct\SqList.c.s

# Object files for target DataStructC1
DataStructC1_OBJECTS = \
"CMakeFiles/DataStructC1.dir/struct/SqList.c.obj"

# External object files for target DataStructC1
DataStructC1_EXTERNAL_OBJECTS =

DataStructC1.exe: CMakeFiles/DataStructC1.dir/struct/SqList.c.obj
DataStructC1.exe: CMakeFiles/DataStructC1.dir/build.make
DataStructC1.exe: CMakeFiles/DataStructC1.dir/linklibs.rsp
DataStructC1.exe: CMakeFiles/DataStructC1.dir/objects1.rsp
DataStructC1.exe: CMakeFiles/DataStructC1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\k8s\Algorithms\DataStructC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable DataStructC1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DataStructC1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataStructC1.dir/build: DataStructC1.exe

.PHONY : CMakeFiles/DataStructC1.dir/build

CMakeFiles/DataStructC1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DataStructC1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DataStructC1.dir/clean

CMakeFiles/DataStructC1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\k8s\Algorithms\DataStructC D:\k8s\Algorithms\DataStructC D:\k8s\Algorithms\DataStructC\cmake-build-debug D:\k8s\Algorithms\DataStructC\cmake-build-debug D:\k8s\Algorithms\DataStructC\cmake-build-debug\CMakeFiles\DataStructC1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataStructC1.dir/depend

