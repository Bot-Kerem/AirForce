//
// Created by kereem on 8/25/22.
//

#ifndef AF_APP_H
#define AF_APP_H

#include "Window.h"
#include "Renderer/Renderer.h"
#include "Renderer/Framebuffer.h"
#include "GUI/Text.h"
#include <glm/vec2.hpp>
#include "RenderScene.h"
#include <memory>

#include "Renderer/VertexArray.h"
#include "Renderer/Shader.h"
#include "Utils/Controller.h"
#include "Utils/SkyBox.h"
#include "Utils/Grid.h"

namespace AirForce {
    class Editor {
        public:

            const glm::vec2 renderSize{1920.0f, 1080.0f};
            int WIDTH = 800;
            int HEIGHT = 600;

            Editor();

            void run();
            void build();
            static void init();

            void drawGUI();
            void dockSpace();

            void draw();

            RenderScene scene{};
        private:
            Window AF_Window{WIDTH, HEIGHT, "AirForce"};
            Renderer AF_Renderer{};
            Controller AF_Controller{AF_Window.getWindow()};
            Font font{};
            VertexArray vao;
            Shader shader{"./../shaders/cubemap.vs", "./../shaders/cubemap.fs"};
            SkyBox AF_SkyBox{"./../skybox/night"};
            Grid AF_Grid{100};
    };
} // AirForce

#endif // AF_APP_H
