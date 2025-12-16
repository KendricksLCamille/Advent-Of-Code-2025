cmake_minimum_required(VERSION 4.0)

# Specify the C compiler
set(CMAKE_C_COMPILER "/usr/local/gcc-15.1.0/bin/gcc-15.1.0")

project(day_one C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)  # Enforce strict C compliance

add_executable(day_one main.c)
target_compile_options(day_one PRIVATE -Wall -Wextra -Wpedantic -Werror)


