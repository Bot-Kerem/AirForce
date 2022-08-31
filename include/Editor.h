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

#include "Graphics/Sphere.h"
#include "Renderer/Shader.h"
#include "Utils/Controller.h"
#include "Utils/SkyBox.h"
#include "Utils/Grid.h"

struct Material {
    glm::vec3 albedo{0};
    float metallic{0};
    float roughness{1};
    float ao{1};
};

struct Light {
    glm::vec3 position{0};
    glm::vec3 color{0};
};

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
            Sphere AF_Sphere{32, 32};
            Shader shader{"./../shaders/cubemap.vs", "./../shaders/cubemap.fs"};
            Shader lShader{"./../shaders/light.vs", "./../shaders/light.fs"};
            SkyBox AF_SkyBox{"./../skybox/night"};
            Grid AF_Grid{100};
            Material material{};
            Light light{};


    };
} // AirForce

#endif // AF_APP_H
