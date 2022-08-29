//
// Created by kereem on 8/28/22.
//

#ifndef AF_VERTEXBUFFER_H
#define AF_VERTEXBUFFER_H

namespace AirForce {
    class VertexBuffer {
        public:
            VertexBuffer();
            ~VertexBuffer();

            VertexBuffer(const VertexBuffer &) = delete;
            VertexBuffer& operator=(const VertexBuffer &) = delete;

            void bind();
            static void unbind();

            static void bufferData(void* data, signed long int size) ;
        private:
            unsigned int m_VertexBuffer{};
    };

} // AirForce

#endif // AF_VERTEXBUFFER_H
