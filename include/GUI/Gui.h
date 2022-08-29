//
// Created by kereem on 8/26/22.
//

#ifndef AF_GUI_H
#define AF_GUI_H

struct GLFWwindow;

namespace AirForce::GUI
{
    enum AF_GUI_STYLE{
        AF_STYLE_DARK = 0,
        AF_STYLE_LIGHT = 1,
        AF_STYLE_CLASSIC = 2
    };

    void switchTheme(AF_GUI_STYLE Theme);
    void init(GLFWwindow* window, AF_GUI_STYLE Theme = AF_STYLE_DARK);

    void START();
    void END();
    void Terminate();
};


#endif // AF_GUI_H
