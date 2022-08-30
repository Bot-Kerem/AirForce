//
// Created by kereem on 8/28/22.
//

#include "RenderScene.h"
#include "Renderer/Renderer.h"
#include "GUI/Text.h"

#include <imgui.h>
#include "Utils/Clock.h"
#include "Utils/Controller.h"

namespace AirForce {
    RenderScene* RenderScene::s_CurrentScene = nullptr;

    void RenderScene::draw() {

        ImGui::Begin("Render Scene");

        ImGui::BeginChild("Render Frame");

        const ImVec2 contentSize = ImGui::GetWindowSize();
        if(contentSize.x != m_RenderSize.x || contentSize.y != contentSize.y){
            m_RenderSize = contentSize;
            m_Frame = std::make_unique<Framebuffer>((int)m_RenderSize.x, (int)m_RenderSize.y);
            Renderer::setViewportSize(m_RenderSize.x, m_RenderSize.y);
            Font::updateFramebuffer(m_RenderSize.x, m_RenderSize.y);
        }
        ImGui::Image((ImTextureID)(m_Frame->getRenderImage()), contentSize, ImVec2(0, 1), ImVec2(1, 0));

        m_Focus = ImGui::IsWindowFocused();
        m_Hover = ImGui::IsItemHovered();
        if(m_Focus) {
            if(Controller::W)
                camera.processKeyboard(Camera::FORWARD, Clock::deltaTime);
            if(Controller::S)
                camera.processKeyboard(Camera::BACKWARD, Clock::deltaTime);
            if(Controller::A)
                camera.processKeyboard(Camera::LEFT, Clock::deltaTime);
            if(Controller::D)
                camera.processKeyboard(Camera::RIGHT, Clock::deltaTime);
            if(Controller::SPACE)
                camera.Position.y += Clock::deltaTime * camera.MovementSpeed;
            }



        ImGui::EndChild();

        ImGui::End();
    }

    RenderScene::RenderScene() = default;

    void RenderScene::start() {
        m_Frame->start();
        s_CurrentScene = this;
    }

    void RenderScene::end() {
        m_Frame->end();
    }

    bool RenderScene::isFocused() const {
        return m_Focus;
    }

    bool RenderScene::isHovered() const {
        return m_Hover;
    }
    RenderScene *RenderScene::getCurrentScene() {
        return s_CurrentScene;
    }

    glm::mat4 RenderScene::getPerspective() const {
        return glm::perspective(glm::radians(camera.Zoom), m_RenderSize.x / m_RenderSize.y, camera.MinDistance, camera.MaxDistance);
    }
} // AirForce
