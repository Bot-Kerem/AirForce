//
// Created by kereem on 8/30/22.
//

#ifndef AF_MESH_H
#define AF_MESH_H

#include "Renderer/VertexArray.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/ElementArray.h"

namespace AirForce {

    class Mesh {
        public:
            Mesh() = default;

            virtual void draw() = 0;
        protected:
            VertexArray m_VertexArray;
            VertexBuffer m_VertexBuffer;
            ElementArray m_ElementBuffer;
    };

} // AirForce

#endif // AF_MESH_H
