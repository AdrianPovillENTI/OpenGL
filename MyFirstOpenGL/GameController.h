#pragma once

#include "Managers/TimeManager.h"
#include "Managers/InputManager.h"
#include "Managers/GLManager.h"
#include "Scripts/GameObject.h"
#include "Scripts/Camera.h"
#include <vector>

class GameController
{
public:
    GameController ( ) = default;

    void ManageInputs ( std::vector<GameObject *> & gameObjects , Camera & camera , float dt );

private:
    void TimeManageInput ( );
    void ToggleWireframe ( );
    void CameraManageInput ( std::vector<GameObject *> & gameObjects , Camera & camera );
};