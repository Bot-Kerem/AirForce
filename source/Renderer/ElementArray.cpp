//
// Created by kereem on 8/30/22.
//

#include "Renderer/ElementArray.h"

#include <glad/glad.h>

namespace AirForce {
    ElementArray::ElementArray() {
        glGenBuffers(1, &m_ElementArray);
    }

    void ElementArray::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementArray);
    }

    void ElementArray::unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void ElementArray::bufferData(void *data, int size) {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    ElementArray::~ElementArray() {
        glDeleteBuffers(1, &m_ElementArray);
    }
} // AirForce