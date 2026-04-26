#include "GLManager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLManager::GLManager ( )
{
    window = nullptr;
    width = 800;
    height = 600;
}

GLManager & GLManager::Instance ( )
{
    static GLManager instance;
    return instance;
}

bool GLManager::Init ( int w , int h , const char * title )
{
    width = w;
    height = h;

    if ( !glfwInit ( ) )
    {
        std::cout << "Error al iniciar GLFW\n";
        return false;
    }

    glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR , 3 );
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR , 3 );
    glfwWindowHint ( GLFW_OPENGL_CORE_PROFILE , GLFW_OPENGL_CORE_PROFILE );

    window = glfwCreateWindow ( width , height , title , NULL , NULL );
    if ( !window )
    {
        std::cout << "Error al crear ventana\n";
        glfwTerminate ( );
        return false;
    }

    glfwMakeContextCurrent ( window );

    // Inicializar GLEW
    glewExperimental = true;
    if ( glewInit ( ) != GLEW_OK )
    {
        std::cout << "Error al inicializar GLEW\n";
        return false;
    }

    // Ajustar viewport
    glViewport ( 0 , 0 , width , height );

    // Activar profundidad
    glEnable ( GL_DEPTH_TEST );

    return true;
}

void GLManager::Clear ( )
{
    glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void GLManager::SwapBuffers ( )
{
    glfwSwapBuffers ( window );
    glfwPollEvents ( );
}

bool GLManager::ShouldClose ( )
{
    return glfwWindowShouldClose ( window );
}

GLFWwindow * GLManager::GetWindow ( )
{
    return window;
}