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
CMAKE_SOURCE_DIR = "C:\Users\User\Alek dokumenty\Programowanie\Studies\Programowanie_Imperatywne\kartkowka"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Alek dokumenty\Programowanie\Studies\Programowanie_Imperatywne\kartkowka\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/kartkowka.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kartkowka.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kartkowka.dir/flags.make

CMakeFiles/kartkowka.dir/main.cpp.obj: CMakeFiles/kartkowka.dir/flags.make
CMakeFiles/kartkowka.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Alek dokumenty\Programowanie\Studies\Programowanie_Imperatywne\kartkowka\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kartkowka.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\kartkowka.dir\main.cpp.obj -c "C:\Users\User\Alek dokumenty\Programowanie\Studies\Programowanie_Imperatywne\kartkowka\main.cpp"

CMakeFiles/kartkowka.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kartkowka.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Alek dokumenty\Programowanie\Studies\Programowanie_Imperatywne\kartkowka\main.cpp" > CMakeFiles\kartkowka.dir\main.cpp.i

CMakeFiles/kartkowka.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kartkowka.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Alek dokumenty\Programowanie\Studies\Programowanie_Imperatywne\kartkowka\main.cpp" -o CMakeFiles\kartkowka.dir\main.cpp.s

CMakeFiles/kartkowka.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/kartkowka.dir/main.cpp.obj.requires

CMakeFiles/kartkowka.dir/main.cpp.obj.provides: CMakeFiles/kartkowka.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\kartkowka.dir\build.make CMakeFiles/kartkowka.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/kartkowka.dir/main.cpp.obj.provides

CMakeFiles/kartkowka.dir/main.cpp.obj.provides.build: CMakeFiles/kartkowka.dir/main.cpp.obj


# Object files for target kartkowka
kartkowka_OBJECTS = \
"CMakeFiles/kartkowka.dir/main.cpp.obj"

# External object files for target kartkowka
kartkowka_EXTERNAL_OBJECTS =

kartkowka.exe: CMakeFiles/kartkowka.dir/main.cpp.obj
kartkowka.exe: CMakeFiles/kartkowka.dir/build.make
kartkowka.exe: CMakeFiles/kartkowka.dir/linklibs.rsp
kartkowka.exe: CMakeFiles/kartkowka.dir/objects1.rsp
kartkowka.exe: CMakeFiles/kartkowka.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\Alek dokumenty\Programowanie\Studies\Programowanie_Imperatywne\kartkowka\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kartkowka.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\kartkowka.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kartkowka.dir/build: kartkowka.exe

.PHONY : CMakeFiles/kartkowka.dir/build

CMakeFiles/kartkowka.dir/requires: CMakeFiles/kartkowka.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/kartkowka.dir/requires

CMakeFiles/kartkowka.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\kartkowka.dir\cmake_clean.cmake
.PHONY : CMakeFiles/kartkowka.dir/clean

CMakeFiles/kartkowka.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Alek dokumenty\Programowanie\Studies\Programowanie_Imperatywne\kartkowka" "C:\Users\User\Alek dokumenty\Programowanie\Studies\Programowanie_Imperatywne\kartkowka" "C:\Users\User\Alek dokumenty\Programowanie\Studies\Programowanie_Imperatywne\kartkowka\cmake-build-debug" "C:\Users\User\Alek dokumenty\Programowanie\Studies\Programowanie_Imperatywne\kartkowka\cmake-build-debug" "C:\Users\User\Alek dokumenty\Programowanie\Studies\Programowanie_Imperatywne\kartkowka\cmake-build-debug\CMakeFiles\kartkowka.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/kartkowka.dir/depend

