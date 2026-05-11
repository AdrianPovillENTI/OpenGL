#include <iostream>

#include "Managers/GLManager.h"
#include "Scripts/Game.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Managers/InputManager.h"
#include "Managers/TimeManager.h"

int main ( )
{
    // Inicializar OpenGL y ventana
    if ( !GLManager::Instance ( ).Init ( "OpenGL Practice" ) )
    {
        std::cout << "Error inicializando OpenGL\n";
        return -1;
    }

    // Crear juego
    Game game;
    game.Start ( );

    // Loop principal
    while ( !GLManager::Instance ( ).ShouldClose ( ) )
    {
        // Limpiar pantalla
        GLManager::Instance ( ).Clear ( );

        // Update (lógica del juego)
        game.Update ( TimeManager::Instance().GetDeltaTime() ); 

        // Render (dibujar)
        game.Render ( );

        // Mostrar frame
        GLManager::Instance ( ).SwapBuffers ( );
    }

    return 0;
}