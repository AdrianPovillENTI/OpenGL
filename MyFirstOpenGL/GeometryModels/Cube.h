#pragma once

#include "../Scripts/GameObject.h"
#include "../Scripts/Textures.h"
#include <glm.hpp>

class Cube : public GameObject
{
private:
    const float MOVEMENT_LIMIT = 0.5f;
    float rotationSpeed = 0.0f;
    float movementSpeed = 0.0f;
    Textures texture;

public:
    Cube ( glm::vec3 _pos );

    void Update ( float dt ) override;

    void Draw ( GLuint program ) override;
};