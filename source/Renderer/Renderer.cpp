//
// Created by kereem on 8/26/22.
//

#include "Renderer/Renderer.h"
#include <glad/glad.h>

namespace AirForce{
    void Renderer::clearColor(float red, float green, float blue, float alpha) {
        glClearColor(red, green, blue, alpha);
    }

    void Renderer::clear() {
        glClear(GL_COLOR_BUFFER_BIT | (DepthTesting ? GL_DEPTH_BUFFER_BIT : 0));
    }

    Renderer::Renderer() {
        gladLoadGL();
    }

    void Renderer::setViewportSize(float width, float height, float offsetWidth, float offsetHeight) {
        glViewport(offsetWidth, offsetHeight, width, height);
    }

}

