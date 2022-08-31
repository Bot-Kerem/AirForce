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
        shader.setVec3("albedo", material.albedo);
        shader.setVec3("lightPosition", light.position);
        shader.setVec3("lightColor", light.color);
        shader.setVec3("camPos", scene.camera.Position);
        shader.setFloat("metallic", material.metallic);
        shader.setFloat("roughness", material.roughness);
        shader.setFloat("ao", material.ao);
        AF_Sphere.draw();

        lShader.use();
        lShader.setMat4("view", &view);
        lShader.setMat4("proj", &perspective);
        lShader.setVec3("pos", light.position);
        lShader.setVec3("color", light.color);
        AF_Sphere.draw();

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
    }

    void Editor::drawGUI() {
        GUI::START();

        dockSpace();

        ImGui::ShowDemoWindow();

        scene.draw();

        ImGui::Begin("Object Properties");
        if(ImGui::TreeNode("Material")) {
            ImGui::Text("Albedo");
            ImGui::SameLine();
            ImGui::SliderFloat3("", (float *) &(material.albedo), 0, 1);
            ImGui::SameLine();
            if (ImGui::ColorButton("Material Albedo", ImVec4(material.albedo.x, material.albedo.y, material.albedo.z, 1.0f))) {
                ImGui::OpenPopup("material-color-edit");
            }

            if (ImGui::BeginPopup("material-color-edit")) {
                ImGui::ColorPicker3("", (float *) &(material.albedo),
                                    ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoSidePreview |
                                    ImGuiColorEditFlags_NoSmallPreview | ImGuiColorEditFlags_NoInputs);
                ImGui::EndPopup();
            }
            ImGui::Text("Metallic");
            ImGui::SameLine();
            ImGui::DragFloat("  ", &(material.metallic), 0.001f, 0.0f, 1.0f, "%.1f");
            ImGui::Text("Roughness");
            ImGui::SameLine();
            ImGui::DragFloat("   ", &(material.roughness), 0.001f, 0.0f, 1.0f, "%.1f");
            ImGui::Text("AO");
            ImGui::SameLine();
            ImGui::DragFloat("    ", &(material.ao), 0.001f, -1.0f, 1.0f, "%.1f");
            ImGui::TreePop();
        }
        if(ImGui::TreeNode("Light")) {
            ImGui::Text("Position");
            ImGui::SameLine();
            ImGui::SliderFloat3(" ", (float *) &(light.position), -10, 10);
            ImGui::Text("Color");
            ImGui::SameLine();
            ImGui::SliderFloat3("", (float *) &(light.color), 0, 1);
            ImGui::SameLine();
            if (ImGui::ColorButton("Light Color", ImVec4(light.color.x, light.color.y, light.color.z, 1.0f))) {
                ImGui::OpenPopup("light-color-edit");
            }

            if (ImGui::BeginPopup("light-color-edit")) {
                ImGui::ColorPicker3("", (float *) &(light.color),
                                    ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoSidePreview |
                                    ImGuiColorEditFlags_NoSmallPreview | ImGuiColorEditFlags_NoInputs);
                ImGui::EndPopup();
            }
            ImGui::TreePop();
        }

        ImGui::End();

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
