#pragma once
#include <GL/glew.h>

class ShaderProgram
{
private:
    GLuint programID;

    GLuint vertexShader = 0;
    GLuint geometryShader = 0;
    GLuint fragmentShader = 0;

public:
    ShaderProgram ( const char * vertexPath ,const char * fragmentPath );    
    ~ShaderProgram ( );

    GLuint GetID ( );

    void Use ( ); 
};