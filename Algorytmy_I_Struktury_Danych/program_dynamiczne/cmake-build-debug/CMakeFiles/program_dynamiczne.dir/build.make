# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\User\Alek dokumenty\Programowanie\Studies\Algorytmy_I_Struktury_Danych\program_dynamiczne"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Alek dokumenty\Programowanie\Studies\Algorytmy_I_Struktury_Danych\program_dynamiczne\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/program_dynamiczne.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/program_dynamiczne.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/program_dynamiczne.dir/flags.make

CMakeFiles/program_dynamiczne.dir/main.cpp.obj: CMakeFiles/program_dynamiczne.dir/flags.make
CMakeFiles/program_dynamiczne.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Alek dokumenty\Programowanie\Studies\Algorytmy_I_Struktury_Danych\program_dynamiczne\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/program_dynamiczne.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\program_dynamiczne.dir\main.cpp.obj -c "C:\Users\User\Alek dokumenty\Programowanie\Studies\Algorytmy_I_Struktury_Danych\program_dynamiczne\main.cpp"

CMakeFiles/program_dynamiczne.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program_dynamiczne.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Alek dokumenty\Programowanie\Studies\Algorytmy_I_Struktury_Danych\program_dynamiczne\main.cpp" > CMakeFiles\program_dynamiczne.dir\main.cpp.i

CMakeFiles/program_dynamiczne.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program_dynamiczne.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Alek dokumenty\Programowanie\Studies\Algorytmy_I_Struktury_Danych\program_dynamiczne\main.cpp" -o CMakeFiles\program_dynamiczne.dir\main.cpp.s

CMakeFiles/program_dynamiczne.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/program_dynamiczne.dir/main.cpp.obj.requires

CMakeFiles/program_dynamiczne.dir/main.cpp.obj.provides: CMakeFiles/program_dynamiczne.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\program_dynamiczne.dir\build.make CMakeFiles/program_dynamiczne.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/program_dynamiczne.dir/main.cpp.obj.provides

CMakeFiles/program_dynamiczne.dir/main.cpp.obj.provides.build: CMakeFiles/program_dynamiczne.dir/main.cpp.obj


# Object files for target program_dynamiczne
program_dynamiczne_OBJECTS = \
"CMakeFiles/program_dynamiczne.dir/main.cpp.obj"

# External object files for target program_dynamiczne
program_dynamiczne_EXTERNAL_OBJECTS =

program_dynamiczne.exe: CMakeFiles/program_dynamiczne.dir/main.cpp.obj
program_dynamiczne.exe: CMakeFiles/program_dynamiczne.dir/build.make
program_dynamiczne.exe: CMakeFiles/program_dynamiczne.dir/linklibs.rsp
program_dynamiczne.exe: CMakeFiles/program_dynamiczne.dir/objects1.rsp
program_dynamiczne.exe: CMakeFiles/program_dynamiczne.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\Alek dokumenty\Programowanie\Studies\Algorytmy_I_Struktury_Danych\program_dynamiczne\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable program_dynamiczne.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\program_dynamiczne.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/program_dynamiczne.dir/build: program_dynamiczne.exe

.PHONY : CMakeFiles/program_dynamiczne.dir/build

CMakeFiles/program_dynamiczne.dir/requires: CMakeFiles/program_dynamiczne.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/program_dynamiczne.dir/requires

CMakeFiles/program_dynamiczne.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\program_dynamiczne.dir\cmake_clean.cmake
.PHONY : CMakeFiles/program_dynamiczne.dir/clean

CMakeFiles/program_dynamiczne.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Alek dokumenty\Programowanie\Studies\Algorytmy_I_Struktury_Danych\program_dynamiczne" "C:\Users\User\Alek dokumenty\Programowanie\Studies\Algorytmy_I_Struktury_Danych\program_dynamiczne" "C:\Users\User\Alek dokumenty\Programowanie\Studies\Algorytmy_I_Struktury_Danych\program_dynamiczne\cmake-build-debug" "C:\Users\User\Alek dokumenty\Programowanie\Studies\Algorytmy_I_Struktury_Danych\program_dynamiczne\cmake-build-debug" "C:\Users\User\Alek dokumenty\Programowanie\Studies\Algorytmy_I_Struktury_Danych\program_dynamiczne\cmake-build-debug\CMakeFiles\program_dynamiczne.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/program_dynamiczne.dir/depend
