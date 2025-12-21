cmake_minimum_required(VERSION 4.0)

# Specify the C compiler
set(CMAKE_C_COMPILER "/usr/local/gcc-15.1.0/bin/gcc-15.1.0")

project(day_one C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)  # Enforce strict C compliance

add_executable(part1 part1.c)
target_compile_options(part1 PRIVATE -Wall -Wextra -Wpedantic -Werror)

add_executable(part2 part2.c)
target_compile_options(part2 PRIVATE -Wall -Wextra -Wpedantic -Werror -Wno-old-style-declaration)


