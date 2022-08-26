//
// Created by kereem on 8/25/22.
//

#include "Editor.h"

namespace AirForce {
    void Editor::init() {
        Window::init();
    }

    Editor::Editor() {
    }

    void Editor::run() {
        while(!AF_Window.isClosed()){
            Window::pollEvents();

            AF_Window.swapBuffers();
        }
    }
} // AirForce