#include "Game.h"
#include "../Managers/InputManager.h"
#include "../Managers/TimeManager.h"
#include "../Managers/GLManager.h"
#include "../Scripts/FigureFactory.h"

Game::Game ( ) { }

Game::~Game ( )
{
    for ( auto obj : gameObjects )
        delete obj;
}

void Game::Start ( )
{
    //CREAR SHADER
    shaderPrograms.push_back ( ShaderProgram ( "vertex.glsl" , "fragment.glsl" ) );

    // Crear objetos
    GameObject * cube = new GameObject ( );
    cube->figure = FigureFactory::CreateCube ( );
    cube->GetTransform ( ).position.x = -0.5f;

    GameObject * ortho = new GameObject ( );
    ortho->figure = FigureFactory::CreateOrthoedro ( );
    ortho->GetTransform ( ).position.x = 0.0f;

    GameObject * pyramid = new GameObject ( );
    pyramid->figure = FigureFactory::CreatePyramid ( );
    pyramid->GetTransform ( ).position.x = 0.5f;

    gameObjects.push_back ( cube );
    gameObjects.push_back ( ortho );
    gameObjects.push_back ( pyramid );

    // Inicializar input
    InputManager::Instance ( ).Init ( GLManager::Instance ( ).GetWindow ( ) );
}
void Game::Update ( float dt )
{
    InputManager::Instance ( ).Update ( );
    TimeManager::Instance ( ).Update ( glfwGetTime ( ) );

    float time = TimeManager::Instance ( ).GetTime ( );
    float delta = TimeManager::Instance ( ).GetDeltaTime ( );

    // PAUSA
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_SPACE ) == KEY_DOWN )
        TimeManager::Instance ( ).TogglePause ( );

    if ( TimeManager::Instance ( ).IsPaused ( ) )
        return;

    // VELOCIDAD
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_M ) == KEY_DOWN )
        TimeManager::Instance ( ).IncreaseSpeed ( );

    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_N ) == KEY_DOWN )
        TimeManager::Instance ( ).DecreaseSpeed ( );

    for(int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[0]->Update(TimeManager::Instance().GetDeltaTime());
    }

    // ANIMACIONES
    // CUBE
    gameObjects [ 0 ]->GetTransform ( ).position.y = sin ( time ) * 0.5f;
    gameObjects [ 0 ]->GetTransform ( ).rotation.y += 50.0f * delta;

    // ORTHO
    gameObjects [ 1 ]->GetTransform ( ).rotation.z += 50.0f * delta;
    float scale = sin ( time ) + 1.5f;
    gameObjects [ 1 ]->GetTransform ( ).scale = { 1.0, scale, 1.0 };

    // PYRAMID
    gameObjects [ 2 ]->GetTransform ( ).position.y = sin ( time ) * 0.5f;
    gameObjects [ 2 ]->GetTransform ( ).rotation.x += 50.0f * delta;
    gameObjects [ 2 ]->GetTransform ( ).rotation.y += 50.0f * delta;

    // ACTIVAR/DESACTIVAR
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_2 ) == KEY_DOWN )
        gameObjects [ 0 ]->SetActive ( !gameObjects [ 0 ]->IsActive ( ) );

    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_3 ) == KEY_DOWN )
        gameObjects [ 1 ]->SetActive ( !gameObjects [ 1 ]->IsActive ( ) );

    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_4 ) == KEY_DOWN )
        gameObjects [ 2 ]->SetActive ( !gameObjects [ 2 ]->IsActive ( ) );
}

void Game::Render ( )
{
    shaderPrograms [ 0 ].Use ( );

    for ( GameObject * obj : gameObjects )
    {
        if ( !obj->IsActive ( ) )
            continue;

        // GENERAR MATRIZ
        obj->CreateModelMatrix ( );

        // ENVIAR MATRIZ AL SHADER
        glUniformMatrix4fv (
            glGetUniformLocation ( shaderPrograms [ 0 ].GetID ( ) , "model" ) ,
            1 ,
            GL_FALSE ,
            glm::value_ptr ( obj->figure->model )
        );

        // DIBUJAR
        obj->figure->Draw ( );
    }
}