#include "Game.h"
#include "../Managers/InputManager.h"
#include "../Managers/TimeManager.h"
#include "../Managers/GLManager.h"
#include "../GeometryModels/Cube.h"
#include "../GeometryModels/Pyramid.h"
#include "../GeometryModels/Orthoedro.h"

Game::Game ( ) { }

Game::~Game ( )
{
    for ( auto obj : gameObjects )
        delete obj;

    delete controller;
}

void Game::Start ( )
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    //CREAR SHADER
    shaderPrograms.push_back ( ShaderProgram ( ) );

    controller = new GameController();
    // Crear objetos
    Cube * cube = new Cube (glm::vec3(-0.5f, 0.0f, 0.0f) /*Le pasamos una position*/);
    Orthoedro * ortho = new Orthoedro ();
    Pyramid* pyramid = new Pyramid(glm::vec3(0.5f, 0.0f, 0.0f));

    gameObjects.push_back ( cube );
    gameObjects.push_back ( ortho );
    gameObjects.push_back ( pyramid );

    // Inicializar input
    InputManager::Instance ( ).Init ( GLManager::Instance ( ).GetWindow ( ) );
}


void Game::Update ( float dt )
{
    glfwPollEvents();

    InputManager::Instance ( ).Update ( );
    TimeManager::Instance ( ).Update ( glfwGetTime ( ) );

    float time = TimeManager::Instance ( ).GetTime ( );

    for(int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->Update(dt);
    }

    controller->ManageInputs(gameObjects);
}

void Game::Render ( )
{
    shaderPrograms [ 0 ].Use ( );

    for ( GameObject * obj : gameObjects )
    {
        if ( !obj->IsActive ( ) )
            continue;

        obj->Draw(shaderPrograms[0].GetID());
    }
}