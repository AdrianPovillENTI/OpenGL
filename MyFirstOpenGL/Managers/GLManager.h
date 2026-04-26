#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class GLManager
{
private:
    GLFWwindow * window; // ventana principal

    int width;
    int height;

    GLManager ( );

public:
    static GLManager & Instance ( );

    bool Init ( int w , int h , const char * title );
    void Clear ( ); // limpia pantalla
    void SwapBuffers ( ); // intercambia buffers

    bool ShouldClose ( );

    GLFWwindow * GetWindow ( );
};