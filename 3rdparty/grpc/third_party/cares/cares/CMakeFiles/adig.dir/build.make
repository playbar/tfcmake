# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc

# Include any dependencies generated for this target.
include third_party/cares/cares/CMakeFiles/adig.dir/depend.make

# Include the progress variables for this target.
include third_party/cares/cares/CMakeFiles/adig.dir/progress.make

# Include the compile flags for this target's objects.
include third_party/cares/cares/CMakeFiles/adig.dir/flags.make

third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o: third_party/cares/cares/CMakeFiles/adig.dir/flags.make
third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o: third_party/cares/cares/adig.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/adig.dir/adig.c.o   -c /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/adig.c

third_party/cares/cares/CMakeFiles/adig.dir/adig.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/adig.dir/adig.c.i"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/adig.c > CMakeFiles/adig.dir/adig.c.i

third_party/cares/cares/CMakeFiles/adig.dir/adig.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/adig.dir/adig.c.s"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/adig.c -o CMakeFiles/adig.dir/adig.c.s

third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o.requires:

.PHONY : third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o.requires

third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o.provides: third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o.requires
	$(MAKE) -f third_party/cares/cares/CMakeFiles/adig.dir/build.make third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o.provides.build
.PHONY : third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o.provides

third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o.provides.build: third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o


third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o: third_party/cares/cares/CMakeFiles/adig.dir/flags.make
third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o: third_party/cares/cares/ares_getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/adig.dir/ares_getopt.c.o   -c /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/ares_getopt.c

third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/adig.dir/ares_getopt.c.i"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/ares_getopt.c > CMakeFiles/adig.dir/ares_getopt.c.i

third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/adig.dir/ares_getopt.c.s"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/ares_getopt.c -o CMakeFiles/adig.dir/ares_getopt.c.s

third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o.requires:

.PHONY : third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o.requires

third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o.provides: third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o.requires
	$(MAKE) -f third_party/cares/cares/CMakeFiles/adig.dir/build.make third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o.provides.build
.PHONY : third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o.provides

third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o.provides.build: third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o


third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o: third_party/cares/cares/CMakeFiles/adig.dir/flags.make
third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o: third_party/cares/cares/ares_nowarn.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/adig.dir/ares_nowarn.c.o   -c /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/ares_nowarn.c

third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/adig.dir/ares_nowarn.c.i"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/ares_nowarn.c > CMakeFiles/adig.dir/ares_nowarn.c.i

third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/adig.dir/ares_nowarn.c.s"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/ares_nowarn.c -o CMakeFiles/adig.dir/ares_nowarn.c.s

third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o.requires:

.PHONY : third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o.requires

third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o.provides: third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o.requires
	$(MAKE) -f third_party/cares/cares/CMakeFiles/adig.dir/build.make third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o.provides.build
.PHONY : third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o.provides

third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o.provides.build: third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o


third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o: third_party/cares/cares/CMakeFiles/adig.dir/flags.make
third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o: third_party/cares/cares/ares_strcasecmp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/adig.dir/ares_strcasecmp.c.o   -c /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/ares_strcasecmp.c

third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/adig.dir/ares_strcasecmp.c.i"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/ares_strcasecmp.c > CMakeFiles/adig.dir/ares_strcasecmp.c.i

third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/adig.dir/ares_strcasecmp.c.s"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/ares_strcasecmp.c -o CMakeFiles/adig.dir/ares_strcasecmp.c.s

third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o.requires:

.PHONY : third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o.requires

third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o.provides: third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o.requires
	$(MAKE) -f third_party/cares/cares/CMakeFiles/adig.dir/build.make third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o.provides.build
.PHONY : third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o.provides

third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o.provides.build: third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o


# Object files for target adig
adig_OBJECTS = \
"CMakeFiles/adig.dir/adig.c.o" \
"CMakeFiles/adig.dir/ares_getopt.c.o" \
"CMakeFiles/adig.dir/ares_nowarn.c.o" \
"CMakeFiles/adig.dir/ares_strcasecmp.c.o"

# External object files for target adig
adig_EXTERNAL_OBJECTS =

third_party/cares/cares/bin/adig: third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o
third_party/cares/cares/bin/adig: third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o
third_party/cares/cares/bin/adig: third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o
third_party/cares/cares/bin/adig: third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o
third_party/cares/cares/bin/adig: third_party/cares/cares/CMakeFiles/adig.dir/build.make
third_party/cares/cares/bin/adig: third_party/cares/cares/lib/libcares.a
third_party/cares/cares/bin/adig: third_party/cares/cares/CMakeFiles/adig.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable bin/adig"
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/adig.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third_party/cares/cares/CMakeFiles/adig.dir/build: third_party/cares/cares/bin/adig

.PHONY : third_party/cares/cares/CMakeFiles/adig.dir/build

third_party/cares/cares/CMakeFiles/adig.dir/requires: third_party/cares/cares/CMakeFiles/adig.dir/adig.c.o.requires
third_party/cares/cares/CMakeFiles/adig.dir/requires: third_party/cares/cares/CMakeFiles/adig.dir/ares_getopt.c.o.requires
third_party/cares/cares/CMakeFiles/adig.dir/requires: third_party/cares/cares/CMakeFiles/adig.dir/ares_nowarn.c.o.requires
third_party/cares/cares/CMakeFiles/adig.dir/requires: third_party/cares/cares/CMakeFiles/adig.dir/ares_strcasecmp.c.o.requires

.PHONY : third_party/cares/cares/CMakeFiles/adig.dir/requires

third_party/cares/cares/CMakeFiles/adig.dir/clean:
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares && $(CMAKE_COMMAND) -P CMakeFiles/adig.dir/cmake_clean.cmake
.PHONY : third_party/cares/cares/CMakeFiles/adig.dir/clean

third_party/cares/cares/CMakeFiles/adig.dir/depend:
	cd /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares /mywork/github/tfcmake/cmake-build-debug/grpc/src/grpc/third_party/cares/cares/CMakeFiles/adig.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third_party/cares/cares/CMakeFiles/adig.dir/depend

