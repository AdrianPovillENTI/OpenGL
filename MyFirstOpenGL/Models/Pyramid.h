#pragma once
#include "../Scripts/GameObject.h"

class Pyramid : public GameObject
{
public:
    Pyramid ( );
    void Update ( float dt ) override;

    int GetColorState ( );
};