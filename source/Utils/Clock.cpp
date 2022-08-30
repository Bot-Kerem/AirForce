//
// Created by kereem on 8/29/22.
//

#include "Utils/Clock.h"

#include <GLFW/glfw3.h>

namespace AirForce {
    float Clock::deltaTime = 0;
    float Clock::currentTime = 0;

    void Clock::clock() {
        deltaTime = (float)glfwGetTime() - currentTime;
        currentTime = (float)glfwGetTime();
    }
} // AirForce