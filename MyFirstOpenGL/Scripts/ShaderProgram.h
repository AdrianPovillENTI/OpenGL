#pragma once
#include <GL/glew.h>

class ShaderProgram
{
    //Para almacenar el ID del programa de shader
	GLuint programID;

	GLuint vertexShader = 0;
	GLuint geometryShader = 0;
	GLuint fragmentShader = 0;
public:

	ShaderProgram ( );
	~ShaderProgram ( );
	GLuint GetID ( );
};

