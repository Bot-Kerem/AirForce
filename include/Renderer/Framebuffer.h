//
// Created by kereem on 8/27/22.
//

#ifndef AF_FRAMEBUFFER_H
#define AF_FRAMEBUFFER_H

namespace AirForce{
    class Framebuffer {
        public:
            Framebuffer(int width, int height);
            ~Framebuffer();

            void start() const;
            void end() const;

            unsigned int getRenderImage();

        protected:
            unsigned int m_Framebuffer;
            unsigned int m_TextureColorbuffer;
            unsigned int m_Renderbuffer;
    };
}



#endif // AF_FRAMEBUFFER_H
