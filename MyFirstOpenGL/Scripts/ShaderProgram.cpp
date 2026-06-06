#include "ShaderProgram.h"
#include <fstream>
#include <sstream>
#include <iostream>

ShaderProgram::ShaderProgram ( )
{
    std::string vertexCode;
    std::string geometryCode;
    std::string fragmentCode;

    std::ifstream vShaderFile;
    std::ifstream gShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.open ( VERTEX );
    gShaderFile.open ( GEOMETRY );
    fShaderFile.open ( FRAGMENT );

    std::stringstream vStream , gStream, fStream;

    vStream << vShaderFile.rdbuf ( );
    gStream << gShaderFile.rdbuf ( );
    fStream << fShaderFile.rdbuf ( );

    vertexCode = vStream.str ( );
    geometryCode = gStream.str ( );
    fragmentCode = fStream.str ( );

    const char * vCode = vertexCode.c_str ( );
    const char * gCode = geometryCode.c_str ( );
    const char * fCode = fragmentCode.c_str ( );

    //Crear vertex shader
    vertexShader = glCreateShader ( GL_VERTEX_SHADER );
    glShaderSource ( vertexShader , 1 , &vCode , NULL );
    glCompileShader ( vertexShader );

    geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
    glShaderSource(geometryShader, 1, &gCode, NULL);
    glCompileShader(geometryShader);
    //Crear fragment shader
    fragmentShader = glCreateShader ( GL_FRAGMENT_SHADER );
    glShaderSource ( fragmentShader , 1 , &fCode , NULL );
    glCompileShader ( fragmentShader );

    //Crear programa
    programID = glCreateProgram ( );
    glAttachShader ( programID , vertexShader );
    glAttachShader ( programID , geometryShader );
    glAttachShader ( programID , fragmentShader );
    glLinkProgram ( programID );

    //limpiar shaders
    glDeleteShader ( vertexShader );
    glDeleteShader ( geometryShader );
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