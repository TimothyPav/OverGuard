# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tim/OverGuard/backend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tim/OverGuard/backend/build

# Include any dependencies generated for this target.
include CMakeFiles/OverGuard.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OverGuard.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OverGuard.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OverGuard.dir/flags.make

CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.o: CMakeFiles/OverGuard.dir/flags.make
CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.o: /home/tim/OverGuard/backend/src/Database_Operations.cpp
CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.o: CMakeFiles/OverGuard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tim/OverGuard/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.o -MF CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.o.d -o CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.o -c /home/tim/OverGuard/backend/src/Database_Operations.cpp

CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tim/OverGuard/backend/src/Database_Operations.cpp > CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.i

CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tim/OverGuard/backend/src/Database_Operations.cpp -o CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.s

CMakeFiles/OverGuard.dir/src/main.cpp.o: CMakeFiles/OverGuard.dir/flags.make
CMakeFiles/OverGuard.dir/src/main.cpp.o: /home/tim/OverGuard/backend/src/main.cpp
CMakeFiles/OverGuard.dir/src/main.cpp.o: CMakeFiles/OverGuard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tim/OverGuard/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OverGuard.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OverGuard.dir/src/main.cpp.o -MF CMakeFiles/OverGuard.dir/src/main.cpp.o.d -o CMakeFiles/OverGuard.dir/src/main.cpp.o -c /home/tim/OverGuard/backend/src/main.cpp

CMakeFiles/OverGuard.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OverGuard.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tim/OverGuard/backend/src/main.cpp > CMakeFiles/OverGuard.dir/src/main.cpp.i

CMakeFiles/OverGuard.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OverGuard.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tim/OverGuard/backend/src/main.cpp -o CMakeFiles/OverGuard.dir/src/main.cpp.s

CMakeFiles/OverGuard.dir/src/API_Handler.cpp.o: CMakeFiles/OverGuard.dir/flags.make
CMakeFiles/OverGuard.dir/src/API_Handler.cpp.o: /home/tim/OverGuard/backend/src/API_Handler.cpp
CMakeFiles/OverGuard.dir/src/API_Handler.cpp.o: CMakeFiles/OverGuard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tim/OverGuard/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OverGuard.dir/src/API_Handler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OverGuard.dir/src/API_Handler.cpp.o -MF CMakeFiles/OverGuard.dir/src/API_Handler.cpp.o.d -o CMakeFiles/OverGuard.dir/src/API_Handler.cpp.o -c /home/tim/OverGuard/backend/src/API_Handler.cpp

CMakeFiles/OverGuard.dir/src/API_Handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OverGuard.dir/src/API_Handler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tim/OverGuard/backend/src/API_Handler.cpp > CMakeFiles/OverGuard.dir/src/API_Handler.cpp.i

CMakeFiles/OverGuard.dir/src/API_Handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OverGuard.dir/src/API_Handler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tim/OverGuard/backend/src/API_Handler.cpp -o CMakeFiles/OverGuard.dir/src/API_Handler.cpp.s

CMakeFiles/OverGuard.dir/src/Heroes.cpp.o: CMakeFiles/OverGuard.dir/flags.make
CMakeFiles/OverGuard.dir/src/Heroes.cpp.o: /home/tim/OverGuard/backend/src/Heroes.cpp
CMakeFiles/OverGuard.dir/src/Heroes.cpp.o: CMakeFiles/OverGuard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tim/OverGuard/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OverGuard.dir/src/Heroes.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OverGuard.dir/src/Heroes.cpp.o -MF CMakeFiles/OverGuard.dir/src/Heroes.cpp.o.d -o CMakeFiles/OverGuard.dir/src/Heroes.cpp.o -c /home/tim/OverGuard/backend/src/Heroes.cpp

CMakeFiles/OverGuard.dir/src/Heroes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OverGuard.dir/src/Heroes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tim/OverGuard/backend/src/Heroes.cpp > CMakeFiles/OverGuard.dir/src/Heroes.cpp.i

CMakeFiles/OverGuard.dir/src/Heroes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OverGuard.dir/src/Heroes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tim/OverGuard/backend/src/Heroes.cpp -o CMakeFiles/OverGuard.dir/src/Heroes.cpp.s

CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.o: CMakeFiles/OverGuard.dir/flags.make
CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.o: /home/tim/OverGuard/backend/src/Json_Serializer.cpp
CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.o: CMakeFiles/OverGuard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tim/OverGuard/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.o -MF CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.o.d -o CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.o -c /home/tim/OverGuard/backend/src/Json_Serializer.cpp

CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tim/OverGuard/backend/src/Json_Serializer.cpp > CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.i

CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tim/OverGuard/backend/src/Json_Serializer.cpp -o CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.s

CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.o: CMakeFiles/OverGuard.dir/flags.make
CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.o: /home/tim/OverGuard/backend/src/Crow_Routes.cpp
CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.o: CMakeFiles/OverGuard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tim/OverGuard/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.o -MF CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.o.d -o CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.o -c /home/tim/OverGuard/backend/src/Crow_Routes.cpp

CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tim/OverGuard/backend/src/Crow_Routes.cpp > CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.i

CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tim/OverGuard/backend/src/Crow_Routes.cpp -o CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.s

CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.o: CMakeFiles/OverGuard.dir/flags.make
CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.o: /home/tim/OverGuard/backend/lib/sqlite/sqlite3.c
CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.o: CMakeFiles/OverGuard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tim/OverGuard/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.o -MF CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.o.d -o CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.o -c /home/tim/OverGuard/backend/lib/sqlite/sqlite3.c

CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tim/OverGuard/backend/lib/sqlite/sqlite3.c > CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.i

CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tim/OverGuard/backend/lib/sqlite/sqlite3.c -o CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.s

# Object files for target OverGuard
OverGuard_OBJECTS = \
"CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.o" \
"CMakeFiles/OverGuard.dir/src/main.cpp.o" \
"CMakeFiles/OverGuard.dir/src/API_Handler.cpp.o" \
"CMakeFiles/OverGuard.dir/src/Heroes.cpp.o" \
"CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.o" \
"CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.o" \
"CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.o"

# External object files for target OverGuard
OverGuard_EXTERNAL_OBJECTS =

OverGuard: CMakeFiles/OverGuard.dir/src/Database_Operations.cpp.o
OverGuard: CMakeFiles/OverGuard.dir/src/main.cpp.o
OverGuard: CMakeFiles/OverGuard.dir/src/API_Handler.cpp.o
OverGuard: CMakeFiles/OverGuard.dir/src/Heroes.cpp.o
OverGuard: CMakeFiles/OverGuard.dir/src/Json_Serializer.cpp.o
OverGuard: CMakeFiles/OverGuard.dir/src/Crow_Routes.cpp.o
OverGuard: CMakeFiles/OverGuard.dir/lib/sqlite/sqlite3.c.o
OverGuard: CMakeFiles/OverGuard.dir/build.make
OverGuard: _deps/cpr-build/cpr/libcpr.so.1.10.5
OverGuard: libsqlite.a
OverGuard: _deps/curl-build/lib/libcurl.so.4.8.0
OverGuard: CMakeFiles/OverGuard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tim/OverGuard/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable OverGuard"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OverGuard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OverGuard.dir/build: OverGuard
.PHONY : CMakeFiles/OverGuard.dir/build

CMakeFiles/OverGuard.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OverGuard.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OverGuard.dir/clean

CMakeFiles/OverGuard.dir/depend:
	cd /home/tim/OverGuard/backend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tim/OverGuard/backend /home/tim/OverGuard/backend /home/tim/OverGuard/backend/build /home/tim/OverGuard/backend/build /home/tim/OverGuard/backend/build/CMakeFiles/OverGuard.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/OverGuard.dir/depend

