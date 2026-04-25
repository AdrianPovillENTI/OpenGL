#pragma once
#include "../Scripts/GameObject.h"
class Cube : public GameObject
{
private:
    float angle = 0.0f;
    float movementSpeed = 0.1f;
    float rotationSpeed = 0.1f;
public:
    Cube ( );
    void Update ( float dt ) override;
    void Draw(GLuint program) override;
};
