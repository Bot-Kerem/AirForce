//
// Created by kereem on 8/29/22.
//

#ifndef AF_CAMERA_H
#define AF_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

const float YAW             = -90.0f;
const float PITCH           =  0.0f;
const float SPEED           =  5.0f;
const float SENSITIVITY     =  0.1f;
const float ZOOM            =  45.0f;
const float MIN_DISTANCE    =  0.1f;
const float MAX_DISTANCE    =  100.0f;

namespace AirForce {

    class Camera {
        public:
            enum AF_CAMERA_DIRECTION {
                FORWARD,
                BACKWARD,
                LEFT,
                RIGHT
            };

            glm::vec3 Position;
            glm::vec3 m_Front;
            glm::vec3 m_Up;
            glm::vec3 m_Right;
            glm::vec3 m_WorldUp;

            float m_Yaw;
            float m_Pitch;

            float MovementSpeed;
            float MouseSensitivity;
            float Zoom;
            float MinDistance;
            float MaxDistance;

            explicit Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
            ~Camera() = default;

            glm::mat4 getViewMatrix();

            void processKeyboard(AF_CAMERA_DIRECTION direction, float deltaTime);

            void processMouseMovement(float xOffset, float yOffset, bool constrainPitch = true);

            void processMouseScroll(float yOffset);

            static Camera* getActiveCamera();
            static void setActiveCamera(Camera* camera);

        private:
            void updateCameraVectors();
            static Camera* s_ActiveCamera;


    };
};

#endif // AF_CAMERA_H
