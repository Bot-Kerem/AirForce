//
// Created by kereem on 8/25/22.
//

#include "Window.h"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include "Renderer/Renderer.h"

namespace AirForce {
    Window::Window(int width, int height, std::string title){
        m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);

        //glfwSetFramebufferSizeCallback(m_Window, framebufferSizeCallback);
        //glfwSetWindowUserPointer(window, this);
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
} // AirForce