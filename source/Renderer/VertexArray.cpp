//
// Created by kereem on 8/28/22.
//

#include "Renderer/VertexArray.h"
#include <glad/glad.h>

AirForce::VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_VertexArray);
}

void AirForce::VertexArray::bind() {
    glBindVertexArray(m_VertexArray);
}

void AirForce::VertexArray::unbind() {
    glBindVertexArray(0);
}

void AirForce::VertexArray::vertexAttrib(int location, int size, int stride, void* pointer) {
    glVertexAttribPointer(location, size, GL_FLOAT, GL_FALSE, stride, pointer);
    glEnableVertexAttribArray(location);
}

AirForce::VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_VertexArray);
}
