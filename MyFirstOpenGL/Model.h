#pragma once
#include <vector>
#include <GL/glew.h>

class Model
{
private:
    GLuint VAO = 0;
    GLuint VBO = 0;
    GLuint uvVBO = 0;
    GLuint normalsVBO = 0;

    int numVertex = 0;

public:
    Model ( ) = default;
    Model ( const std::vector<float> & vertex , const std::vector<float> & uvs , const std::vector<float> & normals );

    void Render ( ) const;
};