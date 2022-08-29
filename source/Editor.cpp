//
// Created by kereem on 8/25/22.
//

#include "Editor.h"

#include "GUI/Gui.h"

#include <imgui.h>
#include "Renderer/VertexBuffer.h"
#include <GLFW/glfw3.h>

namespace AirForce {
    void Editor::init() {
        Window::init();
    }

    Editor::Editor() = default;

    void Editor::run() {
        build();
        while(!AF_Window.isClosed()){
            Window::pollEvents();
            deltaTime = glfwGetTime() - lastTime;
            lastTime =  glfwGetTime();

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
        shader.use();
        shader.setMat4("view", &perspective);
        shader.setMat4("proj", &view);

        vao.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        Font::start();
        font.RenderText("BIG DICK MOTHER FUCKER!", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
        Font::end();
        scene.end();
    }

    void Editor::build() {
        AF_Window.setUserPointer(this);
        Renderer::clearColor(0.25f, 0.25f, 0.25f, 1.0f);
        GUI::init(AF_Window.getWindow());
        Font::init();
        Font::startLoading();
        font.load("/usr/share/fonts/adobe-source-code-pro/SourceCodePro-BoldIt.otf");
        Font::doneLoading();
        Renderer::setViewportSize(800, 800);

        const float size = 0.2f;
        float vert[] = {
                size, -size,
                -size, -size,
                0.0f, size,
                };


        VertexBuffer vbo;
        vbo.bind();
        VertexBuffer::bufferData(&vert[0] ,sizeof(vert));

        vao.bind();
        VertexArray::vertexAttrib(0, 2, sizeof(float) * 2, (void*)0);
    }

    void Editor::drawGUI() {
        GUI::START();

        dockSpace();

        ImGui::ShowDemoWindow();

        scene.draw();

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
