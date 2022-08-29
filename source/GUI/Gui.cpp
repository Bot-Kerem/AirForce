//
// Created by kereem on 8/26/22.
//

#include "GUI/Gui.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>

void AirForce::GUI::init(GLFWwindow* window, AirForce::GUI::AF_GUI_STYLE Theme) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    switchTheme(Theme);

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowPadding = ImVec2(3, 3);
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

}

void AirForce::GUI::switchTheme(AirForce::GUI::AF_GUI_STYLE Theme) {
    switch (Theme) {
        case AF_STYLE_DARK:
            ImGui::StyleColorsDark();
            break;
        case AF_STYLE_LIGHT:
            ImGui::StyleColorsLight();
            break;
        case AF_STYLE_CLASSIC:
            ImGui::StyleColorsClassic();
            break;
        default:
            ImGui::StyleColorsDark();
    }
}

void AirForce::GUI::START() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void AirForce::GUI::END() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // if (ImGuiConfigFlags_ViewportsEnable){
    GLFWwindow* backup_current_context = glfwGetCurrentContext();
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
    glfwMakeContextCurrent(backup_current_context);
    // }

}

void AirForce::GUI::Terminate() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}


