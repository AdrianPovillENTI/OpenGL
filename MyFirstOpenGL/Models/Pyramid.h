#pragma once
#include "../Scripts/GameObject.h"

class Pyramid : public GameObject
{
private:
    float movementSpeed;
public:
    Pyramid(glm::vec3 _pos);
    void Update ( float dt ) override;
    void Draw(GLuint program) override;
    // Ya está la logica en el shader -> int GetColorState ( );
};