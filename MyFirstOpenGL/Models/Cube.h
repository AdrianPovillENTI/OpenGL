#pragma once
#include "../Scripts/GameObject.h"
class Cube : public GameObject
{
public:
    Cube ( );
    void Update ( float dt ) override;
};
