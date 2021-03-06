#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>



class Light{
public:
    Light();

   Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity);
 
    void useLight(GLfloat ambientIntensityLocation, GLfloat ambientColorLocation, GLfloat diffuseIntensityLocation);
    ~Light();

protected:
    glm::vec3 color;
    // Universal light around the world
    GLfloat ambientIntensity;

    GLfloat diffuseIntensity;
};

Light::Light()
{
    color = glm::vec3(1.0f, 1.0f, 1.0f);
    ambientIntensity = 1.0f;
    diffuseIntensity = 0.0f;
}

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity)
{
    color = glm::vec3(red, green, blue);
    ambientIntensity = aIntensity;

    diffuseIntensity = dIntensity;
}

void Light::useLight(GLfloat ambientIntensityLocation, GLfloat ambientColorLocation, GLfloat diffuseIntensityLocation)
{
    glUniform3f(ambientColorLocation, color.x, color.y, color.z);
    glUniform1f(ambientIntensityLocation, ambientIntensity);
    glUniform1f(diffuseIntensityLocation, diffuseIntensity);
}

Light::~Light()
{

}