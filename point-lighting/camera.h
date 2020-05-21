#pragma once

#include <GL/glew.h>

#include <glm/gtc/matrix_transform.hpp>

#include <GLFW/glfw3.h>

class camera
{
public:
    camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch,
        GLfloat startMoveSpeed, GLfloat startTurnSpeed);

    camera();
    void keyControl(bool* keys, GLfloat deltaTime);

    void mouseControl(GLfloat xChange, GLfloat yChange);

    glm::mat4 calculateViewMatrix();

    glm::vec3 getCameraPosition();

    ~camera();

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    
    GLfloat yaw;
    GLfloat pitch;

    GLfloat movementSpeed;
    GLfloat turnSpeed;

    void update();
};

camera::camera()
{

}

camera::camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch,
    GLfloat startMoveSpeed, GLfloat startTurnSpeed)
{
    position = startPosition;
    worldUp = startUp;
    yaw = startYaw;
    pitch = startPitch;
    front = glm::vec3(0.0f, 0.0f, -1.0f);

    movementSpeed = startMoveSpeed;
    turnSpeed = startTurnSpeed;

    update();
}

void camera::update()
{
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(front);

    right = glm::normalize(glm::cross(front, worldUp));

    up = glm::normalize(glm::cross(right, front));


}

void camera::keyControl(bool* keys, GLfloat deltaTime)
{
    GLfloat velocity = movementSpeed * deltaTime;

    if (keys[GLFW_KEY_W])
    {
        position += front * velocity;
    }

    if (keys[GLFW_KEY_S])
    {
        position -= front * velocity;
    }

        if (keys[GLFW_KEY_A])
    {
        position -= right * velocity;
    }

        if (keys[GLFW_KEY_D])
    {
        position += right * velocity;
    }
}

void camera::mouseControl(GLfloat xChange, GLfloat yChange)
{
    xChange *= turnSpeed;
    yChange *= turnSpeed;

    yaw += xChange;
    pitch += yChange;

    if (pitch > 89.0f)
    {
        pitch = 89.0f;
    }

    if (pitch < -89.0f)
    {
        pitch = -89.0f;
    }

    update();
}

glm::mat4 camera::calculateViewMatrix()
{
    return glm::lookAt(position, position + front, up);
}

glm::vec3 camera::getCameraPosition()
{
    return position;
}

camera::~camera()
{

}