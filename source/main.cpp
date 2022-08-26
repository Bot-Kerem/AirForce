#include "Editor.h"
#include <stdexcept>
#include <iostream>
int main() {
    try{
        AirForce::Editor::init();
        AirForce::Editor app;
        app.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
