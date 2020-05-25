#pragma once

#include "Light.h"

class DirectionalLight : public Light{
public: 
    DirectionalLight();
    ~DirectionalLight();

    DirectionalLight(GLfloat red, GLfloat green, GLfloat blue, 
        GLfloat aIntensity,GLfloat dIntensity,
        GLfloat xDir, GLfloat yDir, GLfloat zDir) ;
 
    void useLight(GLfloat ambientIntensityLocation, GLfloat ambientColorLocation, GLfloat diffuseIntensityLocation, GLfloat direcitonLocation);


private:
        glm::vec3 direction;
};

DirectionalLight::DirectionalLight() : Light()
{
    direction = glm::vec3(0.0f, -1.0f, 0.0f);
}

DirectionalLight::DirectionalLight(GLfloat red, GLfloat green, GLfloat blue, 
        GLfloat aIntensity,GLfloat dIntensity,
        GLfloat xDir, GLfloat yDir, GLfloat zDir) : Light(red, green, blue, aIntensity, dIntensity)
{
    direction = glm::vec3(xDir, yDir, zDir);
}

void DirectionalLight::useLight(GLfloat ambientIntensityLocation, GLfloat ambientColorLocation, GLfloat diffuseIntensityLocation, GLfloat directionLocation)
{
	glUniform3f(ambientColorLocation, color.x, color.y, color.z);
	glUniform1f(ambientIntensityLocation, ambientIntensity);

	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
	glUniform1f(diffuseIntensityLocation, diffuseIntensity);
}


DirectionalLight::~DirectionalLight()
{

}