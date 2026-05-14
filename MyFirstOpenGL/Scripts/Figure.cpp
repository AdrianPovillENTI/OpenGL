#include "Figure.h"

Figure::Figure ( const std::vector<float> & vertexs , const std::vector<float> & uvs )
{
    vertices = vertexs;

    glGenVertexArrays ( 1 , &vao );

    SetupMesh ( );

    if ( !uvs.empty ( ) )
    {
        SetupUVS ( uvs );
    }

    UnlinkGroups ( );
}
void Figure::SetupMesh ( )
{
    glBindVertexArray ( vao );

    glGenBuffers ( 1 , &vbo );
    glBindBuffer ( GL_ARRAY_BUFFER , vbo );

    glBufferData ( GL_ARRAY_BUFFER ,
                   vertices.size ( ) * sizeof ( GLfloat ) ,
                   vertices.data ( ) ,
                   GL_STATIC_DRAW );

    glVertexAttribPointer ( 0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof ( GLfloat ) , ( void * ) 0 );
    glEnableVertexAttribArray ( 0 );
}
void Figure::SetupUVS(const std::vector<float>& uvs)
{
    //Abrimos VAO Y uvVBO
    glGenBuffers(1, &uvVBO);

    //Definimos VAO activo
    glBindVertexArray(vao);

    //Definimos los VBOs activos
    glBindBuffer(GL_ARRAY_BUFFER, uvVBO);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(float), uvs.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray ( 1 );

}
void Figure::SetupNormals(const std::vector<float> normals)
{
}
void Figure::UnlinkGroups() 
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
void Figure::Draw ( )
{
    glBindVertexArray ( vao );
    glDrawArrays ( GL_TRIANGLES , 0 , vertices.size ( ) / 3 );
    glBindVertexArray ( 0 );
}