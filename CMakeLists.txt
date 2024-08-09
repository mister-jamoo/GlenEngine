cmake_minimum_required(VERSION 3.10)
project(Glen-Engine VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/Debug.cmake) 

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_compile_options(-g)

enable_testing()

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_subdirectory(GlenEditor GLEN_EDITOR_BUILD)
add_subdirectory(GlenEngine GLEN_ENGINE_BUILD)
add_subdirectory(Examples)
