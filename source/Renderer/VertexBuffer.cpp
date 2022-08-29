//
// Created by kereem on 8/28/22.
//

#include "Renderer/VertexBuffer.h"

#include <glad/glad.h>


namespace AirForce {
    VertexBuffer::VertexBuffer() {
        glGenBuffers(1, &m_VertexBuffer);
    }

    VertexBuffer::~VertexBuffer() {
        //glDeleteBuffers(1, &m_VertexBuffer);
    }

    void VertexBuffer::bind() {
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
    }

    void VertexBuffer::unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::bufferData(void *data, signed long int size) {
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }
} // AirForce