//
// Created by kereem on 8/25/22.
//

#ifndef AF_APP_H
#define AF_APP_H

#include "Window.h"

namespace AirForce {

    class Editor {
        public:
            const int HEIGHT = 600;
            const int WIDTH = 800;
            Editor();

                void run();
            static void init();
        private:
            Window AF_Window{WIDTH, HEIGHT, "AirForce"};
    };

} // AirForce

#endif // AF_APP_H
