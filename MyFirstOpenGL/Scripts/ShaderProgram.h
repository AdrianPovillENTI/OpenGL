#pragma once
#include <GL/glew.h>
#define VERTEX "vertex.glsl"
#define CAMERA_VERTEX "cameraVertexShader.glsl"
#define FRAGMENT "fragment.glsl"
class ShaderProgram
{
private:
    GLuint programID;

    GLuint cameraVertexShader = 0;
    GLuint vertexShader = 0;
    GLuint geometryShader = 0;
    GLuint fragmentShader = 0;

public:
    ShaderProgram ( );    
    ~ShaderProgram ( );

    GLuint GetID ( );

    void Use ( ); 
};