# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/list.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/list.dir/flags.make

CMakeFiles/list.dir/TupleFunctionsa.c.obj: CMakeFiles/list.dir/flags.make
CMakeFiles/list.dir/TupleFunctionsa.c.obj: ../TupleFunctionsa.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/list.dir/TupleFunctionsa.c.obj"
	C:\Win-builds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\list.dir\TupleFunctionsa.c.obj   -c "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\TupleFunctionsa.c"

CMakeFiles/list.dir/TupleFunctionsa.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/list.dir/TupleFunctionsa.c.i"
	C:\Win-builds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\TupleFunctionsa.c" > CMakeFiles\list.dir\TupleFunctionsa.c.i

CMakeFiles/list.dir/TupleFunctionsa.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/list.dir/TupleFunctionsa.c.s"
	C:\Win-builds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\TupleFunctionsa.c" -o CMakeFiles\list.dir\TupleFunctionsa.c.s

CMakeFiles/list.dir/TupleFunctionsb.c.obj: CMakeFiles/list.dir/flags.make
CMakeFiles/list.dir/TupleFunctionsb.c.obj: ../TupleFunctionsb.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/list.dir/TupleFunctionsb.c.obj"
	C:\Win-builds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\list.dir\TupleFunctionsb.c.obj   -c "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\TupleFunctionsb.c"

CMakeFiles/list.dir/TupleFunctionsb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/list.dir/TupleFunctionsb.c.i"
	C:\Win-builds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\TupleFunctionsb.c" > CMakeFiles\list.dir\TupleFunctionsb.c.i

CMakeFiles/list.dir/TupleFunctionsb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/list.dir/TupleFunctionsb.c.s"
	C:\Win-builds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\TupleFunctionsb.c" -o CMakeFiles\list.dir\TupleFunctionsb.c.s

# Object files for target list
list_OBJECTS = \
"CMakeFiles/list.dir/TupleFunctionsa.c.obj" \
"CMakeFiles/list.dir/TupleFunctionsb.c.obj"

# External object files for target list
list_EXTERNAL_OBJECTS =

liblist.dll: CMakeFiles/list.dir/TupleFunctionsa.c.obj
liblist.dll: CMakeFiles/list.dir/TupleFunctionsb.c.obj
liblist.dll: CMakeFiles/list.dir/build.make
liblist.dll: CMakeFiles/list.dir/linklibs.rsp
liblist.dll: CMakeFiles/list.dir/objects1.rsp
liblist.dll: CMakeFiles/list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library liblist.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\list.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/list.dir/build: liblist.dll

.PHONY : CMakeFiles/list.dir/build

CMakeFiles/list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\list.dir\cmake_clean.cmake
.PHONY : CMakeFiles/list.dir/clean

CMakeFiles/list.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library" "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library" "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\cmake-build-debug" "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\cmake-build-debug" "C:\Users\sammu\Documents\UoM\Programming Principles In C\Code\Assignment\A Tuples library\cmake-build-debug\CMakeFiles\list.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/list.dir/depend
