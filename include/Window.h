//
// Created by kereem on 8/25/22.
//

#ifndef AF_WINDOW_H
#define AF_WINDOW_H

#include <string>

struct GLFWwindow;

namespace AirForce {

    class Window {
        public:
            static void init();

            Window(int width, int height, std::string title);

            Window(const Window &) = delete;
            Window operator=(const Window &) = delete;

            GLFWwindow* getWindow();

            void swapBuffers();
            static void pollEvents();

        bool isClosed();

    private:
            GLFWwindow* m_Window;

    };

} // AirForce

#endif // AF_WINDOW_H
