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
    /*
        0 = trollLeft
        1 = trollCenter
        2 = trollRight
    */
    if ( gameObjects.size ( ) < 3 )
        return;

    std::cout <<
        GLManager::Instance().GetMousePosition().x << "||" <<
        GLManager::Instance().GetMousePosition().y << std::endl;

    // Tecla 1 -> plano general => troll izquierdo
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_W ) == KEY_HOLD )
    {

        camera.ActivateWideShot(glm::vec3(0, 0, 0));
        std::cout << "Pressed W and moved" << camera.GetPosition().x << "|" << camera.GetPosition().y << "|" << camera.GetPosition().z << std::endl;
        //camera.MoveCameraForward(camera.GetPosition() + glm::vec3(0,0,122));
        curPos += glm::vec3(0, 0, 0.25f);
        camera.SetPosition(curPos);
    }
    if ( InputManager::Instance ( ).GetKeyState ( GLFW_KEY_S ) == KEY_HOLD )
    {

        camera.ActivateWideShot(glm::vec3(0, 0, 0));
        std::cout << "Pressed W and moved" << camera.GetPosition().x << "|" << camera.GetPosition().y << "|" << camera.GetPosition().z << std::endl;
        //camera.MoveCameraForward(camera.GetPosition() + glm::vec3(0,0,122));
        curPos += glm::vec3(0, 0, -0.25f);
        camera.SetPosition(curPos);
    }

    //// Tecla 2 -> plano detalle => troll derecho
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