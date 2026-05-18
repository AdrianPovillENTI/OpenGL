#include "GameController.h"

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

void GameController::CameraManageInput ( std::vector<GameObject *> & gameObjects , Camera & camera )
{
    // 0 = trollLeft
    // 1 = trollCenter
    // 2 = trollRight
    if ( gameObjects.size ( ) < 3 )
        return;

    // Tecla 1 -> plano general => troll izquierdo
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_1 ) == KEY_DOWN )
    {
        glm::vec3 leftPos = gameObjects [ 0 ]->GetTransform ( ).position;
        camera.ActivateWideShot ( leftPos );
    }

    // Tecla 2 -> plano detalle => troll derecho
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_2 ) == KEY_DOWN )
    {
        glm::vec3 rightPos = gameObjects [ 2 ]->GetTransform ( ).position;
        camera.ActivateDetailShot ( rightPos );
    }

    // Tecla 3 -> dolly zoom => troll central
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_3 ) == KEY_DOWN )
    {
        glm::vec3 centerPos = gameObjects [ 1 ]->GetTransform ( ).position;
        camera.ActivateDollyZoom ( centerPos );
    }

    // Tecla 0 -> volver Orbita
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_0 ) == KEY_DOWN )
    {
        camera.ActivateOrbit ( );
    }
}

void GameController::PlayerMove(Player* player)
{
    //W
    if (InputManager::Instance().GetKeyState(GLFW_KEY_W) == KEY_DOWN)
    {
        //MOVER ADELANTE
        player->GetTransform().position + glm::vec3(0, 0, 1);
    }
    //A
    if (InputManager::Instance().GetKeyState(GLFW_KEY_A) == KEY_DOWN)
    {
        //MOVER IZQUIERDA
        player->GetTransform().position + glm::vec3(-1, 0, 0);
    }
    //S
    if (InputManager::Instance().GetKeyState(GLFW_KEY_S) == KEY_DOWN)
    {
        //MOVER ABAJO
        player->GetTransform().position + glm::vec3(0, 0, -1);
    }
    //D
    if (InputManager::Instance().GetKeyState(GLFW_KEY_D) == KEY_DOWN)
    {
        //MOVER DERECHA
        player->GetTransform().position + glm::vec3(1, 0, 0);
    }
}
