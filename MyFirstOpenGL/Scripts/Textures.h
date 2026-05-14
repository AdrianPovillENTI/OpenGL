#pragma once
#include <GL/glew.h>
#include <string>

class Textures
{
private:
    GLuint textureID = 0;

public:
    Textures ( );
    Textures ( const std::string & path );

   // Activa esta textura en una unidad de textura concreta.
   // textureUnit indica en qué "slot" de textura la vamos a poner.
   //   0 -> GL_TEXTURE0
   //   1 -> GL_TEXTURE1
   // Esto es útil porque un shader para poder usar varias texturas a la vez.
    void Bind ( GLuint textureUnit = 0 );
    GLuint GetID ( );
};