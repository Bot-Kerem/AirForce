//editor->scene.camera.processKeyboard();
// Created by kereem on 8/28/22.
//

#ifndef AF_RENDERSCENE_H
#define AF_RENDERSCENE_H

#include <memory>
#include "Renderer/Framebuffer.h"
#include <imgui.h>
#include "Utils/Camera.h"

namespace AirForce {
    class RenderScene {
        public:
            RenderScene();

            void draw();
            void start();
            void end();

            bool isFocused() const;
            bool isHovered() const;

            static RenderScene* getCurrentScene();

            glm::mat4 getPerspective() const;
            Camera camera{};
        private:
            static RenderScene* s_CurrentScene;
            bool m_Focus = false;
            bool m_Hover = false;
            ImVec2 m_RenderSize{0.0f, 0.0f};
            std::unique_ptr<Framebuffer> m_Frame;
    };

} // AirForce

#endif // AF_RENDERSCENE_H
