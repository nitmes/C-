# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles JOM" Generator, CMake Version 3.24

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
CMAKE_COMMAND = C:\Users\nikit\Documents\Qt\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\nikit\Documents\Qt\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\nikit\Documents\Git\HomeWorkes\C-\Qt\Lesson 2\Lesson2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\nikit\Documents\Git\HomeWorkes\C-\Qt\Lesson 2\build-Lesson2-Desktop-Debug"

# Utility rule file for Lesson2_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles\Lesson2_autogen.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\Lesson2_autogen.dir\progress.make

CMakeFiles\Lesson2_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="C:\Users\nikit\Documents\Git\HomeWorkes\C-\Qt\Lesson 2\build-Lesson2-Desktop-Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target Lesson2"
	C:\Users\nikit\Documents\Qt\Tools\CMake_64\bin\cmake.exe -E cmake_autogen "C:/Users/nikit/Documents/Git/HomeWorkes/C-/Qt/Lesson 2/build-Lesson2-Desktop-Debug/CMakeFiles/Lesson2_autogen.dir/AutogenInfo.json" Debug

Lesson2_autogen: CMakeFiles\Lesson2_autogen
Lesson2_autogen: CMakeFiles\Lesson2_autogen.dir\build.make
.PHONY : Lesson2_autogen

# Rule to build all files generated by this target.
CMakeFiles\Lesson2_autogen.dir\build: Lesson2_autogen
.PHONY : CMakeFiles\Lesson2_autogen.dir\build

CMakeFiles\Lesson2_autogen.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lesson2_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Lesson2_autogen.dir\clean

CMakeFiles\Lesson2_autogen.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles JOM" "C:\Users\nikit\Documents\Git\HomeWorkes\C-\Qt\Lesson 2\Lesson2" "C:\Users\nikit\Documents\Git\HomeWorkes\C-\Qt\Lesson 2\Lesson2" "C:\Users\nikit\Documents\Git\HomeWorkes\C-\Qt\Lesson 2\build-Lesson2-Desktop-Debug" "C:\Users\nikit\Documents\Git\HomeWorkes\C-\Qt\Lesson 2\build-Lesson2-Desktop-Debug" "C:\Users\nikit\Documents\Git\HomeWorkes\C-\Qt\Lesson 2\build-Lesson2-Desktop-Debug\CMakeFiles\Lesson2_autogen.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Lesson2_autogen.dir\depend
