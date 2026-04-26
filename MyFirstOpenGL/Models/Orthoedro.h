#pragma once
#include "../Scripts/GameObject.h"

class Orthoedro : public GameObject
{
private:
    float scaleSpeed;
public:
    Orthoedro ( );
    void Update ( float dt ) override;
    void Draw(GLuint program) override;
};