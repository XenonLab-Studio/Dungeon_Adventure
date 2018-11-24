# cmake files for the "Dungeon Adventure" project.

cmake_minimum_required(VERSION 3.5.0)

# Compiler settings (this must come before calling project).
set(CMAKE_C_STANDARD 11)

project(Dungeon_Adventure)

# Bring the headers, such as termcolor.hpp into the project.
include_directories(include)

# However, the file(GLOB...) allows for wildcard additions.
file(GLOB SOURCES "src/*.c")

# Project folder completed.
set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/build
)

# Delete all generated cmake files, including the binary executable in the "build" folder.
# It does not delete project files in the "src" folder:
#
# * include
# * CMakeLists.txt
# * LICENSE
#
# run the command from the terminal: make clean-all to clean the project.
add_custom_target(clean-all
rm -rf CMakeCache.txt cmake_install.cmake Makefile CMakeFiles/
)

# Also add resources to the target so they are visible in the IDE.
add_executable(dungeonadv ${SOURCES})
