#pragma once

#include "GameObject.h"
#include "../GameController.h"
#include "ShaderProgram.h"
#include <vector>
#include "../Model.h"
#include <string>
#include "Camera.h"
class Game
{
private:
    std::vector<GameObject *> gameObjects;   // lista de objetos del juego
    std::vector<ShaderProgram> shaderPrograms; // shaders usados
    Camera camera;
    glm::vec3 sceneCenter = glm::vec3 ( 0.0f , 0.0f , 0.0f );
    GameController* controller;

public:
    Game ( );
    ~Game ( );

    void Start ( );              // crea objetos y los inicializa
    void Update ( float dt );     // lógica del juego (input + animaciones)
    void Render ( );             // dibuja los objetos
    

    //void AddObject ( GameObject * obj ); // añadir objetos manualmente
};