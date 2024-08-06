cmake_minimum_required(VERSION 3.10)
project(Glen-Engine VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

add_subdirectory(GlenEditor)
add_subdirectory(GlenEngine)
add_subdirectory(Examples)
