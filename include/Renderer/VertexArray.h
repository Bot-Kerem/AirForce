//
// Created by kereem on 8/28/22.
//

#ifndef VAO_VERTEXARRAY_H
#define VAO_VERTEXARRAY_H

namespace AirForce{
    class VertexArray {
        public:
            VertexArray();
            ~VertexArray();

            VertexArray(const VertexArray &) = delete;
            VertexArray& operator=(const VertexArray &) = delete;

            void bind();
            static void unbind();

            static void vertexAttrib(int location, int size, int stride, void* pointer);
        protected:
            unsigned int m_VertexArray{};
    };
}

#endif // VAO_VERTEXARRAY_H
