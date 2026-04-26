#pragma once
#include "../Scripts/GameObject.h"
class Cube : public GameObject
{
private:
    float movementSpeed;
    float rotationSpeed;

public:
    Cube(glm::vec3 _pos);
    void Update ( float dt ) override;
    void Draw(GLuint program) override;
};
