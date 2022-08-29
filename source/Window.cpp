//
// Created by kereem on 8/25/22.
//

#include "Editor.h"
#include "Window.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace AirForce {
    Window::Window(int width, int height, std::string title){
        m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);

        //glfwSetFramebufferSizeCallback(m_Window, framebufferSizeCallback);
        glfwSetKeyCallback(m_Window, keyCallback);
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
        if(action){
            Editor* editor = static_cast<Editor*>(glfwGetWindowUserPointer(window));
            if(editor->scene.isFocused()) {
                switch (key) {
                    case GLFW_KEY_W:
                        editor->scene.camera.processKeyboard(Camera::FORWARD, editor->deltaTime);
                        break;
                    case GLFW_KEY_S:
                        editor->scene.camera.processKeyboard(Camera::BACKWARD, editor->deltaTime);
                        break;
                    case GLFW_KEY_A:
                        editor->scene.camera.processKeyboard(Camera::LEFT, editor->deltaTime);
                        break;
                    case GLFW_KEY_D:
                        editor->scene.camera.processKeyboard(Camera::RIGHT, editor->deltaTime);
                        break;
                }
            }
        }
    }

    void Window::setUserPointer(void * object) {
        glfwSetWindowUserPointer(m_Window, object);
    }
} // AirForce