#pragma once

#include <GL/glew.h>


class Material{
public:
    Material();
    Material(GLfloat sIntensity, GLfloat shine);

    void UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);


    ~Material();

private:
    // How much light should be on the object
    GLfloat specularIntensity;
    GLfloat shininess; // how light reflects off the objects


};

// Initial Constructor
Material::Material()
{
    specularIntensity = 0.0f;
    shininess = 0.0f;
}

// Override constructor
Material::Material(GLfloat sIntensity, GLfloat shine)
{
    specularIntensity = sIntensity;
    shininess = shine;
}

void Material::UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation)
{
    // Pass in  light location and object shine
    glUniform1f(specularIntensityLocation, specularIntensity);
    glUniform1f(shininessLocation, shininess);

    // Postion of Camera
}

Material::~Material()
{

}