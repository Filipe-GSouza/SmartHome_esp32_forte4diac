# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3

# Utility rule file for forte_init_generator.

# Include any custom commands dependencies for this target.
include src/CMakeFiles/forte_init_generator.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/forte_init_generator.dir/progress.make

src/CMakeFiles/forte_init_generator:
	cd /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src && /usr/bin/cmake -DFORTE_BINARY_DIR:STRING="/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3" -DFORTE_SOURCE_DIR:STRING="/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte" -DFORTE_LITTLE_ENDIAN:STRING= -DFORTE_BIG_ENDIAN:STRING= -DFORTE_LOGLEVEL:STRING="NOLOG" -P /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/buildsupport/generate_init.cmake

forte_init_generator: src/CMakeFiles/forte_init_generator
forte_init_generator: src/CMakeFiles/forte_init_generator.dir/build.make
.PHONY : forte_init_generator

# Rule to build all files generated by this target.
src/CMakeFiles/forte_init_generator.dir/build: forte_init_generator
.PHONY : src/CMakeFiles/forte_init_generator.dir/build

src/CMakeFiles/forte_init_generator.dir/clean:
	cd /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src && $(CMAKE_COMMAND) -P CMakeFiles/forte_init_generator.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/forte_init_generator.dir/clean

src/CMakeFiles/forte_init_generator.dir/depend:
	cd /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/src /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3 /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/CMakeFiles/forte_init_generator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/forte_init_generator.dir/depend

