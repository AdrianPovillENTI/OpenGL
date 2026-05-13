#include "ShaderProgram.h"
#include <fstream>
#include <sstream>
#include <iostream>

ShaderProgram::ShaderProgram ( )
{
    std::string vertexCode;
    std::string cameraVertexCode;
    std::string fragmentCode;

    std::ifstream vShaderFile;
    std::ifstream cameraVertexShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.open ( VERTEX );
    cameraVertexShaderFile.open ( CAMERA_VERTEX );
    fShaderFile.open ( FRAGMENT );

    std::stringstream vStream , fStream, cvStream;

    vStream << vShaderFile.rdbuf ( );
    cvStream << cameraVertexShaderFile.rdbuf ( );
    fStream << fShaderFile.rdbuf ( );

    vertexCode = vStream.str ( );
    cameraVertexCode = cvStream.str ( );
    fragmentCode = fStream.str ( );

    const char * vCode = vertexCode.c_str ( );
    const char * cvCode = cameraVertexCode.c_str ( );
    const char * fCode = fragmentCode.c_str ( );

    //Crear vertex shader
    vertexShader = glCreateShader ( GL_VERTEX_SHADER );
    glShaderSource ( vertexShader , 1 , &vCode , NULL );
    glCompileShader ( vertexShader );

    //Crear camera vertex shader
    cameraVertexShader = glCreateShader ( GL_VERTEX_SHADER );
    glShaderSource (cameraVertexShader, 1 , &cvCode , NULL );
    glCompileShader (cameraVertexShader);

    //Crear fragment shader
    fragmentShader = glCreateShader ( GL_FRAGMENT_SHADER );
    glShaderSource ( fragmentShader , 1 , &fCode , NULL );
    glCompileShader ( fragmentShader );

    //Crear programa
    programID = glCreateProgram ( );
    glAttachShader ( programID , vertexShader );
    glAttachShader ( programID , cameraVertexShader);
    glAttachShader ( programID , fragmentShader );
    glLinkProgram ( programID );

    //limpiar shaders
    glDeleteShader ( vertexShader );
    glDeleteShader (cameraVertexShader);
    glDeleteShader ( fragmentShader );
}
ShaderProgram::~ShaderProgram ( )
{
}

GLuint ShaderProgram::GetID ( )
{
    return programID;
}

void ShaderProgram::Use ( )
{
    glUseProgram ( programID );
}