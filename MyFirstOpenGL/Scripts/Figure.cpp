#include "Figure.h"

void Figure::SetupMesh ( )
{
    glGenVertexArrays ( 1 , &vao );
    glBindVertexArray ( vao );

    glGenBuffers ( 1 , &vbo );
    glBindBuffer ( GL_ARRAY_BUFFER , vbo );

    glBufferData ( GL_ARRAY_BUFFER ,
                   vertices.size ( ) * sizeof ( GLfloat ) ,
                   vertices.data ( ) ,
                   GL_STATIC_DRAW );

    glVertexAttribPointer ( 0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof ( GLfloat ) , ( void * ) 0 );
    glEnableVertexAttribArray ( 0 );

    glBindBuffer ( GL_ARRAY_BUFFER , 0 );
    glBindVertexArray ( 0 );
}
void Figure::Draw ( )
{
    glBindVertexArray ( vao );
    glDrawArrays ( GL_TRIANGLES , 0 , vertices.size ( ) / 3 );
    glBindVertexArray ( 0 );
}