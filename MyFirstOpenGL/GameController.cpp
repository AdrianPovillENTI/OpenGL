#include "GameController.h"

void GameController::ManageInputs ( std::vector<GameObject *> & gameObjects , Camera & camera , float dt )
{
    TimeManageInput ( );
    ToggleWireframe ( );
    CameraManageInput ( gameObjects , camera );

    // La cámara se actualiza cada frame según su modo actual
    camera.Update ( dt );
}

void GameController::TimeManageInput ( )
{
    // PAUSA
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_SPACE ) == KEY_DOWN )
        TimeManager::Instance ( ).TogglePause ( );

    if ( TimeManager::Instance ( ).IsPaused ( ) )
        return;

    // VELOCIDAD GLOBAL DEL TIEMPO
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_M ) == KEY_DOWN )
        TimeManager::Instance ( ).IncreaseSpeed ( );

    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_N ) == KEY_DOWN )
        TimeManager::Instance ( ).DecreaseSpeed ( );
}

void GameController::ToggleWireframe ( )
{
    // Como 1,2,3 están reservadas para cámara según la práctica,
    // movemos el wireframe a otra tecla.
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_F1 ) == KEY_DOWN )
        GLManager::Instance ( ).EnableWireframe ( );
}

void GameController::CameraManageInput ( std::vector<GameObject *> & gameObjects , Camera & camera )
{
    // 0 = trollLeft
    // 1 = trollCenter
    // 2 = trollRight
    if ( gameObjects.size ( ) < 3 )
        return;

    // Tecla 1 -> plano general al troll izquierdo
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_1 ) == KEY_DOWN )
    {
        glm::vec3 leftPos = gameObjects [ 0 ]->GetTransform ( ).position;
        camera.ActivateWideShot ( leftPos );
    }

    // Tecla 2 -> plano detalle al troll derecho
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_2 ) == KEY_DOWN )
    {
        glm::vec3 rightPos = gameObjects [ 2 ]->GetTransform ( ).position;
        camera.ActivateDetailShot ( rightPos );
    }

    // Tecla 3 -> dolly zoom al troll central
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_3 ) == KEY_DOWN )
    {
        glm::vec3 centerPos = gameObjects [ 1 ]->GetTransform ( ).position;
        camera.ActivateDollyZoom ( centerPos );
    }

    // Tecla 0 -> volver manualmente a órbita
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_0 ) == KEY_DOWN )
    {
        camera.ActivateOrbit ( );
    }
}