#pragma once
#include "Managers/TimeManager.h"
#include "Managers/InputManager.h"
#include "Managers/GLManager.h"
#include "Scripts/GameObject.h"

class GameController
{
public:
	GameController() = default;
	void ManageInputs(std::vector<GameObject*> _gameObjects);

private:
	void TimeManageInput();
	void ToggleWireframe();
	void ToggleObjects(std::vector<GameObject*> gameObjects);
};