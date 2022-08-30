//
// Created by kereem on 8/25/22.
//

#include "Editor.h"
#include "Window.h"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include "RenderScene.h"
//#include "Utils/Clock.h"
#include <iostream>

namespace AirForce {
    Window::Window(int width, int height, std::string title){
        m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        swapInterval(1);

        //glfwSetFramebufferSizeCallback(m_Window, framebufferSizeCallback);
        //glfwSetKeyCallback(m_Window, keyCallback);
        glfwSetCursorPosCallback(m_Window, cursorCallback);

    }

    void Window::init(){
        if(!glfwInit()){
            throw std::runtime_error("Failed to initialize GLFW!");
        }
    }

    GLFWwindow* Window::getWindow() {
        return m_Window;
    }

    void Window::swapBuffers() {
        glfwSwapBuffers(m_Window);
    }

    void Window::pollEvents() {
        glfwPollEvents();
    }

    bool Window::isClosed() {
        return glfwWindowShouldClose(m_Window);
    }

    void Window::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
        //Renderer::setViewportSize(width, height);
    }

    void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    }

    void Window::setUserPointer(void * object) {
        glfwSetWindowUserPointer(m_Window, object);
    }

    void Window::cursorCallback(GLFWwindow *window, double InxPos, double InyPos) {
        auto Scene = static_cast<RenderScene*>(glfwGetWindowUserPointer(window));
        if(Scene->isFocused()) {
            bool clicked = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);

            static bool process = false;

            const auto xPos = static_cast<float>(InxPos);
            const auto yPos = static_cast<float>(InyPos);

            static float lastX = xPos;
            static float lastY = yPos;

            if(clicked) {
                if(process) {
                    float xOffset =  xPos - lastX;
                    float yOffset = lastY - yPos;
                    Scene->camera.processMouseMovement(xOffset, yOffset);
                }
                else{
                    if(Scene->isHovered()) {
                        process = true;
                    }
                }
            }
            else {
                process = false;
            }
            lastX = xPos;
            lastY = yPos;
        }
    }

    void Window::swapInterval(int interval) {
        glfwSwapInterval(interval);
    }
} // AirForce