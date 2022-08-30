//
// Created by kereem on 8/29/22.
//

#include "Utils/Controller.h"

namespace AirForce {

    bool Controller::a = false;
    bool& Controller::A = a;

    bool Controller::w = false;
    bool& Controller::W = w;

    bool Controller::s = false;
    bool& Controller::S = s;

    bool Controller::d = false;
    bool& Controller::D = d;

    bool Controller::k = false;
    bool& Controller::K = k;

    bool Controller::esc = false;
    bool& Controller::ESC = esc;

    bool Controller::space = false;
    bool& Controller::SPACE = space;

    bool Controller::r_ctrl = false;
    bool& Controller::R_CTRL = r_ctrl;

    bool Controller::l_ctrl = false;
    bool& Controller::L_CTRL = l_ctrl;

    GLFWwindow* Controller::m_Window = nullptr;

    Controller::Controller(GLFWwindow* window)
    {
        m_Window = window;
    }

    Controller::Controller() = default;

    void Controller::PollKeys()
    {
        a = (glfwGetKey(m_Window, GLFW_KEY_A) == GLFW_PRESS);
        s = (glfwGetKey(m_Window, GLFW_KEY_S) == GLFW_PRESS);
        d = (glfwGetKey(m_Window, GLFW_KEY_D) == GLFW_PRESS);
        w = (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS);
        k = (glfwGetKey(m_Window, GLFW_KEY_K) == GLFW_PRESS);
        esc = (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS);
        space = (glfwGetKey(m_Window, GLFW_KEY_SPACE) == GLFW_PRESS);
        r_ctrl = (glfwGetKey(m_Window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS);
        l_ctrl = (glfwGetKey(m_Window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS);
    }
} // AirForce