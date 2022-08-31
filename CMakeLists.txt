cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)

set(IMGUI_SOURCES
        external/imgui/source/imgui.cpp
        external/imgui/source/imgui_demo.cpp
        external/imgui/source/imgui_draw.cpp
        external/imgui/source/imgui_impl_glfw.cpp
        external/imgui/source/imgui_impl_opengl3.cpp
        external/imgui/source/imgui_tables.cpp
        external/imgui/source/imgui_widgets.cpp
        )

set(AF_SOURCES
        external/glad/source/glad.c
        source/main.cpp
        source/Window.cpp
        source/Editor.cpp
        source/Renderer/Renderer.cpp
        source/GUI/Gui.cpp
        source/GUI/Text.cpp
        source/File.cpp
        source/Renderer/Shader.cpp
        source/Renderer/Framebuffer.cpp
        source/RenderScene.cpp
        source/Renderer/Mesh.cpp
        source/Renderer/VertexArray.cpp
        source/Renderer/VertexBuffer.cpp
        source/Utils/Camera.cpp
        source/Utils/Controller.cpp
        source/Utils/Clock.cpp
        source/Utils/SkyBox.cpp
        source/Utils/Grid.cpp
        source/Graphics/Sphere.cpp include/Graphics/Sphere.h source/Renderer/ElementArray.cpp include/Renderer/ElementArray.h)

set(IMGUI_INCLUDE external/imgui/include)
set(GLAD_INCLUDE external/glad/include)
set(STB_INCLUDE external/stb)
set(FREETYPE_INCLUDE "/usr/include/freetype2/")

include_directories(include/ ${IMGUI_INCLUDE} ${GLAD_INCLUDE} ${FREETYPE_INCLUDE} ${STB_INCLUDE})

add_executable(untitled ${AF_SOURCES} ${IMGUI_SOURCES})

target_link_libraries(untitled glfw freetype)
