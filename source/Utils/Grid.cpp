//
// Created by kereem on 8/30/22.
//

#include "Utils/Grid.h"
#include "RenderScene.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

AirForce::Shader* AirForce::Grid::m_Shader = nullptr;

void AirForce::Grid::draw() const {
    m_Shader->use();
    m_Shader->setMat4("view", (glm::mat4*)glm::value_ptr(RenderScene::getCurrentScene()->camera.getViewMatrix()));
    m_Shader->setMat4("proj", (glm::mat4*)glm::value_ptr(RenderScene::getCurrentScene()->getPerspective()));
    m_Shader->setMat4("rotate", (glm::mat4*)(glm::value_ptr(glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f)))));
    m_Shader->setVec3("color", Color);
    m_Shader->setInt("size", Size );
    glDrawArrays(GL_LINES, 0, Size * 2);
    m_Shader->setMat4("rotate", (glm::mat4*)(glm::value_ptr(glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)))));
    glDrawArrays(GL_LINES, 0, Size * 2);
}

void AirForce::Grid::init() {
    m_Shader = new Shader{"./../shaders/grid.vs", "./../shaders/grid.fs"};
}

AirForce::Grid::Grid(int Size): Size(Size) {

}
