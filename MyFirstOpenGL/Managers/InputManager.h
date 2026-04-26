#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
enum KeyState
{
    KEY_IDLE ,
    KEY_DOWN ,
    KEY_HOLD ,
    KEY_UP
};
#define KEY(key) InputManager::Instance().GetKeyState(key)
class InputManager
{
private:
    GLFWwindow * window;

    KeyState keys [ 1024 ]; // estado de cada tecla

    InputManager ( );

public:
    static InputManager & Instance ( );

    void Init ( GLFWwindow * win );
    void Update ( );

    KeyState GetKeyState ( int key );
};