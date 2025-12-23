cmake_minimum_required(VERSION 4.1)
project(Day_2)
set(CMAKE_CXX_COMPILER "/usr/local/gcc-15.1.0/bin/g++-15.1.0")
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_INSTALL_RPATH "/usr/local/gcc-15.1.0/lib64")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

add_executable(part_1 part1.cpp)
add_executable(part_2 part2.cpp)
