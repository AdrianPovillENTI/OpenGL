#pragma once
#include <GL/glew.h>

#define VERTEX "Vertex.glsl"
#define FRAGMENT "Fragment.glsl"

class ShaderProgram
{
private:
    GLuint programID = 0;
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;

public:
    ShaderProgram ( );
    ~ShaderProgram ( );

    GLuint GetID ( );
    void Use ( );
};