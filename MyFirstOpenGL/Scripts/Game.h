#pragma once
#include "GameObject.h"
#include "ShaderProgram.h"
#include <vector>

class Game
{
private:
    std::vector<GameObject *> gameObjects;
    std::vector<ShaderProgram> shaderPrograms;

public:
    Game ( );
    ~Game ( );

    void Start ( );
    void Update ( float dt );
    void Render ( );

    void AddObject ( GameObject * obj );
};