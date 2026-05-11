#pragma once
#include <vector>
#include <GL/glew.h>
#include "ShaderProgram.h"
#include <glm.hpp>

class Figure
{
public:
    std::vector<GLfloat> vertices;

    GLuint vao = 0;
    GLuint vbo = 0;
    GLuint uvVBO = 0;

    glm::mat4 model;

public:
    Figure(const std::vector<float>& vertexs, const std::vector<float>& uvs/*, const std::vector<float>& normals*/);
    //Funcion que se encargara de configurar el VAO y VBO de la figura
    void SetupMesh ( );
    void SetupUVS (const std::vector<float>& uvs);
    void SetupNormals (const std::vector<float> normals);
    //Funcion que se encargara de dibujar la figura
    void Draw ( );
    //Desvinculacion de VAO o VBOs
    void UnlinkGroups();
};