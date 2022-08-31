//
// Created by kereem on 8/30/22.
//

#include "Graphics/Sphere.h"

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glad/glad.h>

#include <vector>
#include <cmath>



namespace AirForce {
    Sphere::Sphere(int segmentsX, int segmentsY) {
        std::vector<glm::vec3> positions;
        std::vector<glm::vec2> uv;
        std::vector<glm::vec3> normals;
        std::vector<unsigned int> indices;

        const unsigned int X_SEGMENTS = 64;
        const unsigned int Y_SEGMENTS = 64;
        const float PI = 3.14159265359f;
        for (unsigned int x = 0; x <= X_SEGMENTS; ++x)
        {
            for (unsigned int y = 0; y <= Y_SEGMENTS; ++y)
            {
                float xSegment = (float)x / (float)X_SEGMENTS;
                float ySegment = (float)y / (float)Y_SEGMENTS;
                float xPos = std::cos(xSegment * 2.0f * PI) * std::sin(ySegment * PI);
                float yPos = std::cos(ySegment * PI);
                float zPos = std::sin(xSegment * 2.0f * PI) * std::sin(ySegment * PI);

                positions.push_back(glm::vec3(xPos, yPos, zPos));
                uv.push_back(glm::vec2(xSegment, ySegment));
                normals.push_back(glm::vec3(xPos, yPos, zPos));
            }
        }

        bool oddRow = false;
        for (unsigned int y = 0; y < Y_SEGMENTS; ++y)
        {
            if (!oddRow) // even rows: y == 0, y == 2; and so on
            {
                for (unsigned int x = 0; x <= X_SEGMENTS; ++x)
                {
                    indices.push_back(y       * (X_SEGMENTS + 1) + x);
                    indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
                }
            }
            else
            {
                for (int x = X_SEGMENTS; x >= 0; --x)
                {
                    indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
                    indices.push_back(y       * (X_SEGMENTS + 1) + x);
                }
            }
            oddRow = !oddRow;
        }
        m_IndexCount = static_cast<unsigned int>(indices.size());

        std::vector<float> data;
        for (unsigned int i = 0; i < positions.size(); ++i)
        {
            data.push_back(positions[i].x);
            data.push_back(positions[i].y);
            data.push_back(positions[i].z);
            if (normals.size() > 0)
            {
                data.push_back(normals[i].x);
                data.push_back(normals[i].y);
                data.push_back(normals[i].z);
            }
            if (uv.size() > 0)
            {
                data.push_back(uv[i].x);
                data.push_back(uv[i].y);
            }
        }

        m_VertexArray.bind();
        m_VertexBuffer.bind();
        m_VertexBuffer.bufferData(data.data(), data.size() * sizeof(float));
        m_ElementBuffer.bind();
        m_ElementBuffer.bufferData(indices.data(), indices.size() * sizeof(unsigned int));
        unsigned int stride = (3 + 2 + 3) * sizeof(float);
        m_VertexArray.vertexAttrib(0, 3, stride, (void*)0);
        m_VertexArray.vertexAttrib(1, 2, stride, (void*)(3 * sizeof(float)));
        m_VertexArray.vertexAttrib(2, 3, stride, (void*)(6 * sizeof(float)));
    }

    void Sphere::draw() {
        m_VertexArray.bind();
        glDrawElements(GL_TRIANGLE_STRIP, m_IndexCount, GL_UNSIGNED_INT, nullptr);

    }
} // AirForce