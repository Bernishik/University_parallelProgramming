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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\paralProg\lab6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\paralProg\lab6\cmake-build-debug-mingw

# Include any dependencies generated for this target.
include CMakeFiles/lab6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab6.dir/flags.make

CMakeFiles/lab6.dir/lab6.c.obj: CMakeFiles/lab6.dir/flags.make
CMakeFiles/lab6.dir/lab6.c.obj: CMakeFiles/lab6.dir/includes_C.rsp
CMakeFiles/lab6.dir/lab6.c.obj: ../lab6.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\paralProg\lab6\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab6.dir/lab6.c.obj"
	C:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lab6.dir\lab6.c.obj -c D:\paralProg\lab6\lab6.c

CMakeFiles/lab6.dir/lab6.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab6.dir/lab6.c.i"
	C:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\paralProg\lab6\lab6.c > CMakeFiles\lab6.dir\lab6.c.i

CMakeFiles/lab6.dir/lab6.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab6.dir/lab6.c.s"
	C:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\paralProg\lab6\lab6.c -o CMakeFiles\lab6.dir\lab6.c.s

# Object files for target lab6
lab6_OBJECTS = \
"CMakeFiles/lab6.dir/lab6.c.obj"

# External object files for target lab6
lab6_EXTERNAL_OBJECTS =

lab6.exe: CMakeFiles/lab6.dir/lab6.c.obj
lab6.exe: CMakeFiles/lab6.dir/build.make
lab6.exe: CMakeFiles/lab6.dir/linklibs.rsp
lab6.exe: CMakeFiles/lab6.dir/objects1.rsp
lab6.exe: CMakeFiles/lab6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\paralProg\lab6\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab6.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab6.dir/build: lab6.exe

.PHONY : CMakeFiles/lab6.dir/build

CMakeFiles/lab6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab6.dir/clean

CMakeFiles/lab6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\paralProg\lab6 D:\paralProg\lab6 D:\paralProg\lab6\cmake-build-debug-mingw D:\paralProg\lab6\cmake-build-debug-mingw D:\paralProg\lab6\cmake-build-debug-mingw\CMakeFiles\lab6.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab6.dir/depend

