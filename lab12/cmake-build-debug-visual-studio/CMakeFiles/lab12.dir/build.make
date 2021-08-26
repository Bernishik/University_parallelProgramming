# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\paralProg\lab12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\paralProg\lab12\cmake-build-debug-visual-studio

# Include any dependencies generated for this target.
include CMakeFiles\lab12.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\lab12.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\lab12.dir\flags.make

CMakeFiles\lab12.dir\lab_12_1.cu.obj: CMakeFiles\lab12.dir\flags.make
CMakeFiles\lab12.dir\lab_12_1.cu.obj: ..\lab_12_1.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\paralProg\lab12\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CUDA object CMakeFiles/lab12.dir/lab_12_1.cu.obj"
	C:\PROGRA~1\NVIDIA~2\CUDA\v11.3\bin\nvcc.exe -forward-unknown-to-host-compiler $(CUDA_DEFINES) $(CUDA_INCLUDES) $(CUDA_FLAGS) -x cu -dc D:\paralProg\lab12\lab_12_1.cu -o CMakeFiles\lab12.dir\lab_12_1.cu.obj -Xcompiler=-FdCMakeFiles\lab12.dir\,-FS

CMakeFiles\lab12.dir\lab_12_1.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CUDA source to CMakeFiles/lab12.dir/lab_12_1.cu.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_PREPROCESSED_SOURCE

CMakeFiles\lab12.dir\lab_12_1.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CUDA source to assembly CMakeFiles/lab12.dir/lab_12_1.cu.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_ASSEMBLY_SOURCE

# Object files for target lab12
lab12_OBJECTS = \
"CMakeFiles\lab12.dir\lab_12_1.cu.obj"

# External object files for target lab12
lab12_EXTERNAL_OBJECTS =

CMakeFiles\lab12.dir\cmake_device_link.obj: CMakeFiles\lab12.dir\lab_12_1.cu.obj
CMakeFiles\lab12.dir\cmake_device_link.obj: CMakeFiles\lab12.dir\build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\paralProg\lab12\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CUDA device code CMakeFiles\lab12.dir\cmake_device_link.obj"
	C:\PROGRA~1\NVIDIA~2\CUDA\v11.3\bin\nvcc.exe -forward-unknown-to-host-compiler -D_WINDOWS -Xcompiler=" /GR /EHsc" -Xcompiler="-Zi -Ob0 -Od /RTC1" --generate-code=arch=compute_52,code=[compute_52,sm_52] -Xcompiler=-MDd -Wno-deprecated-gpu-targets -shared -dlink $(lab12_OBJECTS) $(lab12_EXTERNAL_OBJECTS) -o CMakeFiles\lab12.dir\cmake_device_link.obj  cudadevrt.lib cudart_static.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib  -Xcompiler=-FdD:\paralProg\lab12\cmake-build-debug-visual-studio\CMakeFiles\lab12.dir\,-FS

# Rule to build all files generated by this target.
CMakeFiles\lab12.dir\build: CMakeFiles\lab12.dir\cmake_device_link.obj

.PHONY : CMakeFiles\lab12.dir\build

# Object files for target lab12
lab12_OBJECTS = \
"CMakeFiles\lab12.dir\lab_12_1.cu.obj"

# External object files for target lab12
lab12_EXTERNAL_OBJECTS =

lab12.exe: CMakeFiles\lab12.dir\lab_12_1.cu.obj
lab12.exe: CMakeFiles\lab12.dir\build.make
lab12.exe: CMakeFiles\lab12.dir\cmake_device_link.obj
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\paralProg\lab12\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CUDA executable lab12.exe"
	"C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\lab12.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\mt.exe --manifests -- C:\PROGRA~2\MICROS~3\2019\ENTERP~1\VC\Tools\MSVC\1428~1.299\bin\Hostx64\x64\link.exe /nologo $(lab12_OBJECTS) $(lab12_EXTERNAL_OBJECTS) CMakeFiles\lab12.dir\cmake_device_link.obj @<<
 /out:lab12.exe /implib:lab12.lib /pdb:D:\paralProg\lab12\cmake-build-debug-visual-studio\lab12.pdb /version:0.0 /debug /INCREMENTAL /subsystem:console  cudadevrt.lib cudart_static.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib  -LIBPATH:"C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.3/lib/x64" 
<<

# Rule to build all files generated by this target.
CMakeFiles\lab12.dir\build: lab12.exe

.PHONY : CMakeFiles\lab12.dir\build

CMakeFiles\lab12.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab12.dir\cmake_clean.cmake
.PHONY : CMakeFiles\lab12.dir\clean

CMakeFiles\lab12.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\paralProg\lab12 D:\paralProg\lab12 D:\paralProg\lab12\cmake-build-debug-visual-studio D:\paralProg\lab12\cmake-build-debug-visual-studio D:\paralProg\lab12\cmake-build-debug-visual-studio\CMakeFiles\lab12.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\lab12.dir\depend
