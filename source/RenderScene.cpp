//
// Created by kereem on 8/28/22.
//

#include "RenderScene.h"
#include "Renderer/Renderer.h"
#include "GUI/Text.h"

#include <imgui.h>

namespace AirForce {
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
        ImGui::EndChild();

        ImGui::End();
    }

    RenderScene::RenderScene(){

    }

    void RenderScene::start() {
        m_Frame->start();
    }

    void RenderScene::end() {
        m_Frame->end();
    }

    bool RenderScene::isFocused() {
        return m_Focus;
    }

    glm::mat4 RenderScene::getPerspective() {
        return glm::perspective(glm::radians(camera.Zoom), m_RenderSize.x / m_RenderSize.y, 0.1f, 100.0f);
    }
} // AirForce
