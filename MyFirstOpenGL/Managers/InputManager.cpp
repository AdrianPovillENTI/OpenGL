#include "InputManager.h"

InputManager::InputManager ( )
{
    // Inicializamos todas las teclas como no pulsadas
    for ( int i = 0; i < 1024; i++ )
    {
        keys [ i ] = KEY_IDLE;
    }
}

InputManager & InputManager::Instance ( )
{
    static InputManager instance;
    return instance;
}

void InputManager::Init ( GLFWwindow * win )
{
    window = win;
}

void InputManager::Update ( )
{
    for ( int i = 0; i < 1024; i++ )
    {
        bool isPressed = glfwGetKey ( window , i ) == GLFW_PRESS;

        switch ( keys [ i ] )
        {
            case KEY_IDLE:
                if ( isPressed )
                    keys [ i ] = KEY_DOWN; // acaba de pulsarse
                break;

            case KEY_DOWN:
                if ( isPressed )
                    keys [ i ] = KEY_HOLD; // sigue presionada
                else
                    keys [ i ] = KEY_UP;   // se soltó rápido
                break;

            case KEY_HOLD:
                if ( !isPressed )
                    keys [ i ] = KEY_UP;   // se soltó
                break;

            case KEY_UP:
                if ( isPressed )
                    keys [ i ] = KEY_DOWN; // se vuelve a pulsar
                else
                    keys [ i ] = KEY_IDLE; // vuelve a reposo
                break;
        }
    }
}

KeyState InputManager::GetKeyState ( int key )
{
    return keys [ key ];
}