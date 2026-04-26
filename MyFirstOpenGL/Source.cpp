#include <iostream>

#include "Managers/GLManager.h"
#include "Scripts/Game.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Managers/InputManager.h"

int main ( )
{
    // Inicializar OpenGL y ventana
    if ( !GLManager::Instance ( ).Init ( 800 , 600 , "OpenGL Practice" ) )
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
        game.Update ( 0.0f ); // dt ya lo calcula TimeManager

        // Render (dibujar)
        game.Render ( );

        // Mostrar frame
        GLManager::Instance ( ).SwapBuffers ( );
    }

    return 0;
}