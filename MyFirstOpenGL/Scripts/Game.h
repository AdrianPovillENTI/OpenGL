#pragma once

#include "GameObject.h"
#include "ShaderProgram.h"
#include <vector>

class Game
{
private:
    std::vector<GameObject *> gameObjects;   // lista de objetos del juego
    std::vector<ShaderProgram> shaderPrograms; // shaders usados

public:
    Game ( );
    ~Game ( );

    void Start ( );              // crea objetos y los inicializa
    void Update ( float dt );     // lógica del juego (input + animaciones)
    void Render ( );             // dibuja los objetos

    void AddObject ( GameObject * obj ); // añadir objetos manualmente
};