//
// Created by kereem on 8/29/22.
//

#include "Utils/Camera.h"


AirForce::Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch):m_Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM), MinDistance(MIN_DISTANCE), MaxDistance(MAX_DISTANCE) {
    Position = position;
    m_WorldUp = up;
    m_Yaw = yaw;
    m_Pitch = pitch;
    updateCameraVectors();
}

glm::mat4 AirForce::Camera::getViewMatrix() {
    return glm::lookAt(Position, Position + m_Front, m_Up);
}

void AirForce::Camera::processKeyboard(AirForce::Camera::AF_CAMERA_DIRECTION direction, float deltaTime) {
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
        Position += m_Front * velocity;
    if (direction == BACKWARD)
        Position -= m_Front * velocity;
    if (direction == LEFT)
        Position -= m_Right * velocity;
    if (direction == RIGHT)
        Position += m_Right * velocity;
}

void AirForce::Camera::processMouseMovement(float xOffset, float yOffset, bool constrainPitch) {
    xOffset *= MouseSensitivity;
    yOffset *= MouseSensitivity;

    m_Yaw   += xOffset;
    m_Pitch += yOffset;

    if (constrainPitch)
    {
        if (m_Pitch > 89.0f)
            m_Pitch = 89.0f;
        if (m_Pitch < -89.0f)
            m_Pitch = -89.0f;
    }

    updateCameraVectors();
}

void AirForce::Camera::processMouseScroll(float yOffset) {
    Zoom -= (float)yOffset;
    if (Zoom < 1.0f)
        Zoom = 1.0f;
    if (Zoom > 45.0f)
        Zoom = 45.0f;
}

void AirForce::Camera::updateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    front.y = sin(glm::radians(m_Pitch));
    front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_Front = glm::normalize(front);

    m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
    m_Up    = glm::normalize(glm::cross(m_Right, m_Front));
}

AirForce::Camera *AirForce::Camera::getActiveCamera() {
    return s_ActiveCamera;
}

void AirForce::Camera::setActiveCamera(AirForce::Camera *camera) {
    s_ActiveCamera = camera;
}

AirForce::Camera* AirForce::Camera::s_ActiveCamera = nullptr;