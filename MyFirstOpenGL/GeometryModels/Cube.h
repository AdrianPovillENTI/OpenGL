#pragma once
#include "../Scripts/GameObject.h"

class Cube : public GameObject
{
public:
    const float MOVEMENT_LIMIT = 0.5f;
private:
    float movementSpeed;
    float rotationSpeed;

public:
    Cube(glm::vec3 _pos);
    void Update ( float dt ) override;
    void Draw(GLuint program) override;
};
