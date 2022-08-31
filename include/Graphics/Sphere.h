//
// Created by kereem on 8/30/22.
//

#ifndef AF_SPHERE_H
#define AF_SPHERE_H

#include "Mesh.h"

namespace AirForce {

    class Sphere: public Mesh{
        public:
            Sphere(int segmentsX, int segmentsY);
            void draw() override;
        private:
            int m_IndexCount = 0;
    };

} // AirForce

#endif // AF_SPHERE_H
