# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Wester35\Desktop\lab_tasks_lin\laba17

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Wester35\Desktop\lab_tasks_lin\laba17\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/laba17.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/laba17.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/laba17.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/laba17.dir/flags.make

CMakeFiles/laba17.dir/main.c.obj: CMakeFiles/laba17.dir/flags.make
CMakeFiles/laba17.dir/main.c.obj: C:/Users/Wester35/Desktop/lab_tasks_lin/laba17/main.c
CMakeFiles/laba17.dir/main.c.obj: CMakeFiles/laba17.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Wester35\Desktop\lab_tasks_lin\laba17\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/laba17.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/laba17.dir/main.c.obj -MF CMakeFiles\laba17.dir\main.c.obj.d -o CMakeFiles\laba17.dir\main.c.obj -c C:\Users\Wester35\Desktop\lab_tasks_lin\laba17\main.c

CMakeFiles/laba17.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/laba17.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Wester35\Desktop\lab_tasks_lin\laba17\main.c > CMakeFiles\laba17.dir\main.c.i

CMakeFiles/laba17.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/laba17.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Wester35\Desktop\lab_tasks_lin\laba17\main.c -o CMakeFiles\laba17.dir\main.c.s

CMakeFiles/laba17.dir/resources.rc.obj: CMakeFiles/laba17.dir/flags.make
CMakeFiles/laba17.dir/resources.rc.obj: C:/Users/Wester35/Desktop/lab_tasks_lin/laba17/resources.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Wester35\Desktop\lab_tasks_lin\laba17\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object CMakeFiles/laba17.dir/resources.rc.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) C:\Users\Wester35\Desktop\lab_tasks_lin\laba17\resources.rc CMakeFiles\laba17.dir\resources.rc.obj

# Object files for target laba17
laba17_OBJECTS = \
"CMakeFiles/laba17.dir/main.c.obj" \
"CMakeFiles/laba17.dir/resources.rc.obj"

# External object files for target laba17
laba17_EXTERNAL_OBJECTS =

laba17.exe: CMakeFiles/laba17.dir/main.c.obj
laba17.exe: CMakeFiles/laba17.dir/resources.rc.obj
laba17.exe: CMakeFiles/laba17.dir/build.make
laba17.exe: CMakeFiles/laba17.dir/linkLibs.rsp
laba17.exe: CMakeFiles/laba17.dir/objects1.rsp
laba17.exe: CMakeFiles/laba17.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Wester35\Desktop\lab_tasks_lin\laba17\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable laba17.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\laba17.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/laba17.dir/build: laba17.exe
.PHONY : CMakeFiles/laba17.dir/build

CMakeFiles/laba17.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\laba17.dir\cmake_clean.cmake
.PHONY : CMakeFiles/laba17.dir/clean

CMakeFiles/laba17.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Wester35\Desktop\lab_tasks_lin\laba17 C:\Users\Wester35\Desktop\lab_tasks_lin\laba17 C:\Users\Wester35\Desktop\lab_tasks_lin\laba17\cmake-build-debug C:\Users\Wester35\Desktop\lab_tasks_lin\laba17\cmake-build-debug C:\Users\Wester35\Desktop\lab_tasks_lin\laba17\cmake-build-debug\CMakeFiles\laba17.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/laba17.dir/depend

