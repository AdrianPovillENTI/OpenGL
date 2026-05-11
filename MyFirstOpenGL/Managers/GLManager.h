#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 600

class GLManager
{
private:
    GLFWwindow * window; // ventana principal


    bool wireframe;

    GLManager ( );

public:
    static GLManager & Instance ( );

    bool Init ( const char * title );
    void Clear ( ); // limpia pantalla
    void SwapBuffers ( ); // intercambia buffers
    void EnableWireframe();

    bool ShouldClose ( );

    GLFWwindow * GetWindow ( );
};