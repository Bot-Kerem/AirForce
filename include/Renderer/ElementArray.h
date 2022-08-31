//
// Created by kereem on 8/30/22.
//

#ifndef AF_ELEMENTARRAY_H
#define AF_ELEMENTARRAY_H

namespace AirForce {

    class ElementArray {
        public:
            ElementArray();
            ~ElementArray();

            static void bufferData(void* data, int size);

            void bind() const;
            static void unbind();
        private:
            unsigned int m_ElementArray{};
    };

} // AirForce

#endif // AF_ELEMENTARRAY_H
