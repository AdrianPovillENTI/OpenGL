#include "GameController.h"

void GameController::ManageInputs(std::vector<GameObject*> _gameObjects)
{
    TimeManageInput();
    ToggleWireframe();
    ToggleObjects(_gameObjects);
}

void GameController::TimeManageInput()
{
    // PAUSA
    if (InputManager::Instance().GetKeyState(GLFW_KEY_SPACE) == KEY_DOWN)
        TimeManager::Instance().TogglePause();

    if (TimeManager::Instance().IsPaused())
        return;

    // VELOCIDAD
    if (InputManager::Instance().GetKeyState(GLFW_KEY_M) == KEY_DOWN)
        TimeManager::Instance().IncreaseSpeed();

    if (InputManager::Instance().GetKeyState(GLFW_KEY_N) == KEY_DOWN)
        TimeManager::Instance().DecreaseSpeed();
}

void GameController::ToggleWireframe()
{
    if (InputManager::Instance().GetKeyState(GLFW_KEY_1) == KEY_DOWN)
        GLManager::Instance().EnableWireframe();
}

void GameController::ToggleObjects(std::vector<GameObject*> gameObjects) {
    // ACTIVAR/DESACTIVAR
    if (InputManager::Instance().GetKeyState(GLFW_KEY_2) == KEY_DOWN)
        gameObjects[0]->SetActive(!gameObjects[0]->IsActive());

    if (InputManager::Instance().GetKeyState(GLFW_KEY_3) == KEY_DOWN)
        gameObjects[1]->SetActive(!gameObjects[1]->IsActive());

    if (InputManager::Instance().GetKeyState(GLFW_KEY_4) == KEY_DOWN)
        gameObjects[2]->SetActive(!gameObjects[2]->IsActive());
}