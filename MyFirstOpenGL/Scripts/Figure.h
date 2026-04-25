#pragma once
#include <vector>
#include <GL/glew.h>

class Figure
{
public:
    std::vector<GLfloat> vertices;

    GLuint vao = 0;
    GLuint vbo = 0;
    //Funcion que se encargara de configurar el VAO y VBO de la figura
    void SetupMesh ( );
    //Funcion que se encargara de dibujar la figura
    void Draw ( );
};