//
// Created by kereem on 8/29/22.
//

#ifndef AF_CONTROLLER_H
#define AF_CONTROLLER_H

#include <GLFW/glfw3.h>

namespace AirForce {
    class Controller {
        public:
            Controller(GLFWwindow* window);
            Controller();
            static void PollKeys();

            static bool a;
            static bool& A;

            static bool w;
            static bool& W;
            static bool s;
            static bool& S;

            static bool d;
            static bool& D;

            static bool esc;
            static bool& ESC;

            static bool space;
            static bool& SPACE;

            static bool r_ctrl;
            static bool& R_CTRL;

            static bool l_ctrl;
            static bool& L_CTRL;

            static bool k;
            static bool& K;

            static GLFWwindow* m_Window;
    };

} // AirForce

#endif // AF_CONTROLLER_H
