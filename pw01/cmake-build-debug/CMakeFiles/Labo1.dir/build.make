# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "E:\CLion 2022.3.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2022.3.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = S:\Annee1\PRG2\Labo\Labo1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = S:\Annee1\PRG2\Labo\Labo1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Labo1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Labo1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Labo1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Labo1.dir/flags.make

CMakeFiles/Labo1.dir/Graf_Calvin.cpp.obj: CMakeFiles/Labo1.dir/flags.make
CMakeFiles/Labo1.dir/Graf_Calvin.cpp.obj: S:/Annee1/PRG2/Labo/Labo1/Graf_Calvin.cpp
CMakeFiles/Labo1.dir/Graf_Calvin.cpp.obj: CMakeFiles/Labo1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=S:\Annee1\PRG2\Labo\Labo1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Labo1.dir/Graf_Calvin.cpp.obj"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Labo1.dir/Graf_Calvin.cpp.obj -MF CMakeFiles\Labo1.dir\Graf_Calvin.cpp.obj.d -o CMakeFiles\Labo1.dir\Graf_Calvin.cpp.obj -c S:\Annee1\PRG2\Labo\Labo1\Graf_Calvin.cpp

CMakeFiles/Labo1.dir/Graf_Calvin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Labo1.dir/Graf_Calvin.cpp.i"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E S:\Annee1\PRG2\Labo\Labo1\Graf_Calvin.cpp > CMakeFiles\Labo1.dir\Graf_Calvin.cpp.i

CMakeFiles/Labo1.dir/Graf_Calvin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Labo1.dir/Graf_Calvin.cpp.s"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S S:\Annee1\PRG2\Labo\Labo1\Graf_Calvin.cpp -o CMakeFiles\Labo1.dir\Graf_Calvin.cpp.s

# Object files for target Labo1
Labo1_OBJECTS = \
"CMakeFiles/Labo1.dir/Graf_Calvin.cpp.obj"

# External object files for target Labo1
Labo1_EXTERNAL_OBJECTS =

Labo1.exe: CMakeFiles/Labo1.dir/Graf_Calvin.cpp.obj
Labo1.exe: CMakeFiles/Labo1.dir/build.make
Labo1.exe: CMakeFiles/Labo1.dir/linklibs.rsp
Labo1.exe: CMakeFiles/Labo1.dir/objects1.rsp
Labo1.exe: CMakeFiles/Labo1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=S:\Annee1\PRG2\Labo\Labo1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Labo1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Labo1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Labo1.dir/build: Labo1.exe
.PHONY : CMakeFiles/Labo1.dir/build

CMakeFiles/Labo1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Labo1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Labo1.dir/clean

CMakeFiles/Labo1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" S:\Annee1\PRG2\Labo\Labo1 S:\Annee1\PRG2\Labo\Labo1 S:\Annee1\PRG2\Labo\Labo1\cmake-build-debug S:\Annee1\PRG2\Labo\Labo1\cmake-build-debug S:\Annee1\PRG2\Labo\Labo1\cmake-build-debug\CMakeFiles\Labo1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Labo1.dir/depend

