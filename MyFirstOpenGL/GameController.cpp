#include "GameController.h"
#include <iostream>
void GameController::ManageInputs ( std::vector<GameObject *> & gameObjects , Camera & camera , float dt )
{
    TimeManageInput ( );
    ToggleWireframe ( );
    CameraManageInput ( gameObjects , camera );

    camera.Update ( dt );
}

void GameController::TimeManageInput ( )
{
    // PAUSA
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_SPACE ) == KEY_DOWN )
        TimeManager::Instance ( ).TogglePause ( );

    if ( TimeManager::Instance ( ).IsPaused ( ) )
        return;
}

void GameController::ToggleWireframe ( )
{
    // WIREFRAME
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_F1 ) == KEY_DOWN )
        GLManager::Instance ( ).EnableWireframe ( );
}
glm::vec3 curPos;
void GameController::CameraManageInput ( std::vector<GameObject *> & gameObjects , Camera & camera )
{
    float dt = TimeManager::Instance ( ).GetDeltaTime ( );

    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_W ) == KEY_HOLD )
    {
        camera.MoveForward ( dt );
    }

    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_S ) == KEY_HOLD )
    {
        camera.MoveBackward ( dt );
    }

    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_A ) == KEY_HOLD )
    {
        camera.MoveLeft ( dt );
    }

    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_D ) == KEY_HOLD )
    {
        camera.MoveRight ( dt );
    }

}