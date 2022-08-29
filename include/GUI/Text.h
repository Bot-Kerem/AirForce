#ifndef AF_TEXT_H
#define AF_TEXT_H

#include "glad/glad.h"

#include <ft2build.h>
#include FT_FREETYPE_H"freetype/freetype.h"

#include <map>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer/Shader.h"
#include "glad/glad.h"
namespace AirForce{
    struct Character {
        unsigned int TextureID;
        glm::ivec2   Size;
        glm::ivec2   Bearing;
        unsigned int Advance;
    };

    class Font{
        public:
            Font(std::string fontPath);
            Font();

            static void start();
            static void end();

            void load(std::string fontPath);

            static void updateFramebuffer(float width, float height);
            static FT_Library ft;
            FT_Face face;
            void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);

            static void init();
            static void startLoading();
            static void doneLoading();

        private:
            unsigned int VAO, VBO;
            std::map<GLchar, Character> Characters;
            static Shader shader;
    };
}

#endif
