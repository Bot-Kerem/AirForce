//
// Created by kereem on 8/30/22.
//

#ifndef AF_GRID_H
#define AF_GRID_H

#include "Renderer/VertexArray.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/Shader.h"

#include <glm/vec3.hpp>

namespace AirForce{
    class Grid {
        public:
            Grid(int Size);
            int Size;

            void draw() const;
            static void init();

            glm::vec3 Color{0.52f};
        private:
            static Shader* m_Shader;
    };
}

#endif // AF_GRID_H
