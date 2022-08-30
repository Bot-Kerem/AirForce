//
// Created by kereem on 8/25/22.
//

#include "Editor.h"

#include "GUI/Gui.h"

#include <imgui.h>
#include "Renderer/VertexBuffer.h"
#include "Utils/Clock.h"

namespace AirForce {
    void Editor::init() {
        Window::init();
    }

    Editor::Editor() = default;

    void Editor::run() {
        build();
        while(!AF_Window.isClosed()){
            Window::pollEvents();
            Clock::clock();
            Controller::PollKeys();
            //AF_Renderer.clear();
            draw();
            AF_Window.swapBuffers();
        }
    }

    void Editor::draw() {
        drawGUI();

        scene.start();
        AF_Renderer.clear();

        glm::mat4 view = scene.camera.getViewMatrix();
        glm::mat4 perspective = scene.getPerspective();

        AF_Grid.draw();

        shader.use();
        shader.setMat4("view", &view);
        shader.setMat4("proj", &perspective);
        vao.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        AF_SkyBox.draw();

        Font::start();
        font.RenderText("BIG DICK MOTHER FUCKER!", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
        Font::end();

        scene.end();
    }

    void Editor::build() {
        AF_Window.setUserPointer(&scene);
        Renderer::clearColor(0.25f, 0.25f, 0.25f, 1.0f);
        GUI::init(AF_Window.getWindow());
        Font::init();
        Font::startLoading();
        font.load("/usr/share/fonts/adobe-source-code-pro/SourceCodePro-BoldIt.otf");
        Font::doneLoading();
        SkyBox::init();
        Grid::init();
        Renderer::setViewportSize(800, 800);
        Renderer::enableDepthTesting();

        const float size = 1.0f;
        float vert[] = {
                size, 0,
                -size, 0,
                0.0f, size * 2,
                };


        VertexBuffer vbo;
        vbo.bind();
        VertexBuffer::bufferData(&vert[0] ,sizeof(vert));

        vao.bind();
        VertexArray::vertexAttrib(0, 2, sizeof(float) * 2, nullptr);
    }

    void Editor::drawGUI() {
        GUI::START();

        dockSpace();

        ImGui::ShowDemoWindow();

        scene.draw();

        ImGui::Begin("Scene Properties");
        if(ImGui::TreeNode("Camera")) {
            ImGui::Text("Speed");
            ImGui::SameLine();
            ImGui::InputFloat(" ", &(scene.camera.MovementSpeed));
            if(ImGui::TreeNode("View Distance")) {
                ImGui::Text("Minimum");
                ImGui::SameLine();
                ImGui::DragFloat("  ", &(scene.camera.MinDistance), 0.1f, 0.1f, FLT_MAX, "%.1f");
                ImGui::Text("Maximum");
                ImGui::SameLine();
                ImGui::DragFloat(" ", &(scene.camera.MaxDistance), 0.1f, 0.1f, FLT_MAX, "%.1f");

                ImGui::TreePop();
            }
            ImGui::TreePop();
        }
        if(ImGui::TreeNode("Grid")) {
            ImGui::Text("Size");
            ImGui::SameLine();
            ImGui::SliderInt(" ", &(AF_Grid.Size), 0, 1000);
            ImGui::Text("Color");
            ImGui::SameLine();
            ImGui::SliderFloat3("", (float *) &(AF_Grid.Color), 0, 1);
            ImGui::SameLine();
            if (ImGui::ColorButton("Grid Color", ImVec4(AF_Grid.Color.x, AF_Grid.Color.y, AF_Grid.Color.z, 1.0f))) {
                ImGui::OpenPopup("grid-color-edit");
            }

            if (ImGui::BeginPopup("grid-color-edit")) {
                ImGui::ColorPicker3("", (float *) &(AF_Grid.Color),
                                    ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoSidePreview |
                                    ImGuiColorEditFlags_NoSmallPreview | ImGuiColorEditFlags_NoInputs);
                ImGui::EndPopup();
            }
            ImGui::TreePop();
        }

        ImGui::End();

        GUI::END();
    }

    void Editor::dockSpace() {
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);

        ImGui::Begin("DockSpace");
        ImGuiIO& io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f));
        }
        ImGui::End();
    }
} // AirForce
