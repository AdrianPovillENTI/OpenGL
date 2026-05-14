#include "Textures.h"
#include <iostream>
#include "stb_image.h"
Textures::Textures ( )
{
    // Crear identificador de textura
    glGenTextures ( 1 , &textureID );

    // Enlazar la textura actual
    glBindTexture ( GL_TEXTURE_2D , textureID );

    // Configuración básica de filtrado y wrapping
    glTexParameteri ( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );
    glTexParameteri ( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );
    glTexParameteri ( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );
    glTexParameteri ( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );

    // Un único pixel blanco: R=255, G=255, B=255, A=255
    unsigned char whitePixel [ ] = { 255, 255, 255, 255 };

    // Subimos esa textura blanca a la GPU
    glTexImage2D (
        GL_TEXTURE_2D ,
        0 ,
        GL_RGBA ,
        1 ,
        1 ,
        0 ,
        GL_RGBA ,
        GL_UNSIGNED_BYTE ,
        whitePixel
    );

    glBindTexture ( GL_TEXTURE_2D , 0 );
}

Textures::Textures ( const std::string & path )
{
    // Generamos un identificador para la textura en OpenGL
    glGenTextures ( 1 , &textureID );

    // Enlazamos la textura 2D actual
    glBindTexture ( GL_TEXTURE_2D , textureID );

    // Configuración de repeat horizontal
    glTexParameteri ( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );

    // Configuración de repeat vertical
    glTexParameteri ( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );

    // Filtro cuando la textura se ve más pequeña
    glTexParameteri ( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR_MIPMAP_LINEAR );

    // Filtro cuando la textura se ve más grande
    glTexParameteri ( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );

    int width , height , channels;

    // Volteamos la imagen en Y porque OpenGL y muchas imágenes
    // no usan el mismo origen de coordenadas.
    stbi_set_flip_vertically_on_load ( true );

    // Cargamos la imagen desde disco
    unsigned char * data = stbi_load ( path.c_str ( ) , &width , &height , &channels , 0 );

    if ( !data )
    {
        std::cerr << "No se pudo cargar la textura: " << path << std::endl;
        return;
    }

    // Elegimos el formato según el número de canales
    GLenum format = GL_RGB;

    if ( channels == 1 ) format = GL_RED;
    else if ( channels == 3 ) format = GL_RGB;
    else if ( channels == 4 ) format = GL_RGBA;

    // Enviamos la textura a la GPU
    glTexImage2D (
        GL_TEXTURE_2D ,
        0 ,
        format ,
        width ,
        height ,
        0 ,
        format ,
        GL_UNSIGNED_BYTE ,
        data
    );

    // Generamos mipmaps
    glGenerateMipmap ( GL_TEXTURE_2D );

    // Liberamos la memoria de la imagen cargada
    stbi_image_free ( data );

    // Desenlazamos la textura
    glBindTexture ( GL_TEXTURE_2D , 0 );
}

void Textures::Bind ( GLuint textureUnit ) 
{
    // Activamos la unidad de textura deseada
    glActiveTexture ( GL_TEXTURE0 + textureUnit );

    // Enlazamos esta textura a esa unidad
    glBindTexture ( GL_TEXTURE_2D , textureID );
}

GLuint Textures::GetID ( ) 
{
    return textureID;
}