#pragma once
#include "../Scripts/GameObject.h"

class Pyramid : public GameObject
{
private:
    float movementSpeed = 0.1f;
public:
    Pyramid ( );
    void Update ( float dt ) override;
    void Draw(GLuint program) override;
    // Ya está la logica en el shader -> int GetColorState ( );
};