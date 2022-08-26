cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)

set(AF_SOURCES
        source/main.cpp
        source/glad.c
        source/Window.cpp
        source/Editor.cpp
        source/Renderer/Renderer.cpp)

include_directories(include/)

add_executable(untitled ${AF_SOURCES})

target_link_libraries(untitled glfw)