#pragma once

#include "GameObject.h"
#include "../Model.h"
#include "Textures.h"
#include <glm.hpp>

class ModelObject : public GameObject
{
private:
    Model model;
    Textures texture;
    glm::vec3 tintColor;

public:
    ModelObject (
        const Model model ,
        const Textures texture ,
        glm::vec3 position = glm::vec3 ( 0.0f ) ,
        glm::vec3 scale = glm::vec3 ( 1.0f ) ,
        glm::vec3 rotation = glm::vec3 ( 0.0f ) ,
        glm::vec3 tintColor = glm::vec3 ( 1.0f )
    );

    void Draw ( GLuint program ) override;
};