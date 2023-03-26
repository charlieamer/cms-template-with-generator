cmake_minimum_required(VERSION 3.13)  # CMake version check
project(task)
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard
add_executable(main sol/main.cpp)
add_executable(generator sol/generator.cpp sol/generator_specific.cpp)