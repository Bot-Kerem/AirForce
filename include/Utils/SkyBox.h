//
// Created by kereem on 8/30/22.
//

#ifndef AF_CUBEMAP_H
#define AF_CUBEMAP_H

#include <string>
#include "Renderer/VertexArray.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/Shader.h"

namespace AirForce {

    class SkyBox {
        public:
            explicit SkyBox(const std::string& texture);

            void draw();

            static void init();

        private:
            VertexArray m_VertexArray{};
            VertexBuffer m_VertexBuffer{};
            static Shader* m_Shader;

            unsigned int m_Texture{};
    };

} // AirForce

#endif // AF_CUBEMAP_H
