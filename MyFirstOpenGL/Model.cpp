#include "Model.h"
#include <iostream>

Model::Model ( const std::vector<float> & vertex , const std::vector<float> & uvs , const std::vector<float> & normals )
{
    // Número real de vértices
    this->numVertex = vertex.size ( ) / 3;

    // Crear VAO
    glGenVertexArrays ( 1 , &this->VAO );
    glBindVertexArray ( this->VAO );

    // POSICIONES
    glGenBuffers ( 1 , &this->VBO );
    glBindBuffer ( GL_ARRAY_BUFFER , this->VBO );
    glBufferData ( GL_ARRAY_BUFFER , vertex.size ( ) * sizeof ( float ) , vertex.data ( ) , GL_STATIC_DRAW );

    // Atributo 0 = posición
    glVertexAttribPointer ( 0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof ( float ) , ( void * ) 0 );
    glEnableVertexAttribArray ( 0 );

    // UVs
    if ( !uvs.empty ( ) )
    {
        glGenBuffers ( 1 , &this->uvVBO );
        glBindBuffer ( GL_ARRAY_BUFFER , this->uvVBO );
        glBufferData ( GL_ARRAY_BUFFER , uvs.size ( ) * sizeof ( float ) , uvs.data ( ) , GL_STATIC_DRAW );

        // Atributo 1 = coordenadas de textura
        glVertexAttribPointer ( 1 , 2 , GL_FLOAT , GL_FALSE , 2 * sizeof ( float ) , ( void * ) 0 );
        glEnableVertexAttribArray ( 1 );
    }

    // Desvincular
    glBindBuffer ( GL_ARRAY_BUFFER , 0 );
    glBindVertexArray ( 0 );
}

void Model::Render ( ) const
{
    glBindVertexArray ( this->VAO );
    glDrawArrays ( GL_TRIANGLES , 0 , numVertex );
    glBindVertexArray ( 0 );
}