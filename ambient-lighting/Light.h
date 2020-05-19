#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>


class Light{
public:
    Light();

   Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity);
 
    void useLight(GLfloat ambientIntensityLocation, GLfloat ambientColorLocation);
    ~Light();

private:
    glm::vec3 color;
    GLfloat ambientIntensity;
};

Light::Light()
{
    color = glm::vec3(1.0f, 1.0f, 1.0f);
    ambientIntensity = 1.0f;
}

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity)
{
    color = glm::vec3(red, green, blue);
    ambientIntensity = aIntensity;
}

void Light::useLight(GLfloat ambientIntensityLocation, GLfloat ambientColorLocation)
{
    glUniform3f(ambientColorLocation, color.x, color.y, color.z);
    glUniform1f(ambientIntensityLocation, ambientIntensity);
}

Light::~Light()
{

}