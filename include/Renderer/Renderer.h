//
// Created by kereem on 8/26/22.
//

#ifndef AF_RENDERER_H
#define AF_RENDERER_H


namespace AirForce{
    class Renderer{
        public:
            Renderer();
            Renderer(const Renderer &) = delete;
            Renderer operator=(const Renderer &) = delete;

            static void setViewportSize(float width, float height, float offsetWidth = 0, float offsetHeight = 0);
            static void clearColor(float red, float green, float blue, float alpha);
            void clear();
        private:
            bool DepthTesting = false;
    };
}

#endif // AF_RENDERER_H
