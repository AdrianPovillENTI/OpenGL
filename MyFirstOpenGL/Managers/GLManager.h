#pragma once
#include <glm.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 600
#define SCREEN_CENTER glm::vec2 ( WIDTH / 2.0f , HEIGHT / 2.0f )

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
    glm::vec2 GetMousePosition();
};