
#include "FigureFactory.h"
#include <GL/glew.h>
#include <glm.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
// Els vértex han estat definits amb ChatGPT

Figure * FigureFactory::CreateCube ( )
{

    std::vector<GLfloat> vertices =
    {
        // BACK
    -0.15f,  0.15f, -0.15f,   0.15f,  0.15f, -0.15f,  -0.15f, -0.15f, -0.15f,
     0.15f,  0.15f, -0.15f,   0.15f, -0.15f, -0.15f,  -0.15f, -0.15f, -0.15f,

     // FRONT
     -0.15f,  0.15f,  0.15f,   0.15f,  0.15f,  0.15f,  -0.15f, -0.15f,  0.15f,
      0.15f,  0.15f,  0.15f,   0.15f, -0.15f,  0.15f,  -0.15f, -0.15f,  0.15f,

      // LEFT
      -0.15f,  0.15f,  0.15f,  -0.15f,  0.15f, -0.15f,  -0.15f, -0.15f, -0.15f,
      -0.15f, -0.15f, -0.15f,  -0.15f, -0.15f,  0.15f,  -0.15f,  0.15f,  0.15f,

      // RIGHT
       0.15f,  0.15f,  0.15f,   0.15f,  0.15f, -0.15f,   0.15f, -0.15f, -0.15f,
       0.15f, -0.15f, -0.15f,   0.15f, -0.15f,  0.15f,   0.15f,  0.15f,  0.15f,

       // TOP
       -0.15f,  0.15f, -0.15f,   0.15f,  0.15f, -0.15f,  -0.15f,  0.15f,  0.15f,
        0.15f,  0.15f, -0.15f,   0.15f,  0.15f,  0.15f,  -0.15f,  0.15f,  0.15f,

        // BOTTOM
        -0.15f, -0.15f, -0.15f,   0.15f, -0.15f, -0.15f,  -0.15f, -0.15f,  0.15f,
         0.15f, -0.15f, -0.15f,   0.15f, -0.15f,  0.15f,  -0.15f, -0.15f,  0.15f
    };

    return new Figure(vertices);
}
Model FigureFactory::LoadOBJModel ( const std::string & filePath )
{
    std::ifstream file ( filePath );
    if ( !file.is_open ( ) )
    {
        std::cerr << "PutaVidaTete ha petado porque no puede abrir el archivo: " << filePath << std::endl;
        std::exit ( EXIT_FAILURE );
    }
    //Variables para lectura del fitxer
    std::string line;
    std::stringstream ss;
    std::string prefix;
    glm::vec3 tmpVec3;
    glm::vec2 tmpVec2;

    //Variables element del model
    std::vector <float> vertexs;
    std::vector <float> vertexNormal;
    std::vector <float> textureCoords;

    //Variables temporals per a fer el sort de faces
    std::vector<float> tmpVertexs;
    std::vector<float> tmpNormals;
    std::vector<float> tmpTextures;
    std::vector<float> tmpFaces;

    // recorrem l'arxiu línea per línea
    while ( std::getline ( file , line ) )
    {
        //per cada línea extraiem el prefix
        ss.clear ( );
        ss.str ( line ); // Llegeix fins trobar un espai
        ss >> prefix;

        //filtrem el prefix
        if ( prefix == "v" )
        { // Si es un vertex

            ss >> tmpVec3.x >> tmpVec3.y >> tmpVec3.z;
            //Asumim que treballem amb 3D
            tmpVertexs.push_back ( tmpVec3.x );
            tmpVertexs.push_back ( tmpVec3.y );
            tmpVertexs.push_back ( tmpVec3.z );

        }
        else if ( prefix == "vt" )
        { // Si es una textura
            ss >> tmpVec2.x >> tmpVec2.y;
            tmpTextures.push_back ( tmpVec2.x );
            tmpTextures.push_back ( tmpVec2.y );

        }
        else if ( prefix == "vn" )
        { // Si es una normal
            ss >> tmpVec3.x >> tmpVec3.y >> tmpVec3.z;
            //Asumim que treballem amb 3D
            tmpNormals.push_back ( tmpVec3.x );
            tmpNormals.push_back ( tmpVec3.y );
            tmpNormals.push_back ( tmpVec3.z );

        }
        else if ( prefix == "f" )
        { // Si es una cara
            int vertexData;
            short counter = 0;

            // Obtenim els valors fins a un espai
            while ( ss >> vertexData )
            {
                // En ordre cada num segueix el patró vertex/uv/normal = 3 valors
                switch ( counter )
                {
                    case 0:
                        // Si es un vertex, l'emmagatzemo -1 per l'offset
                        vertexs.push_back ( tmpVertexs [ ( vertexData - 1 ) * 3 ] );
                        vertexs.push_back ( tmpVertexs [ ( vertexData - 1 ) * 3 + 1 ] );
                        vertexs.push_back ( tmpVertexs [ ( vertexData - 1 ) * 3 + 2 ] );
                        ss.ignore ( 1 , '/' );
                        counter++;
                        break;
                    case 1:
                        // Si es un vertex, l'emmagatzemo -1 per l'offset
                        textureCoords.push_back ( tmpTextures [ ( vertexData - 1 ) * 2 ] );
                        textureCoords.push_back ( tmpTextures [ ( vertexData - 1 ) * 2 + 1 ] );
                        ss.ignore ( 1 , '/' );
                        counter++;
                        break;
                    case 2:
                        // Si es un vertex, l'emmagatzemo -1 per l'offset
                        vertexNormal.push_back ( tmpNormals [ ( vertexData - 1 ) * 3 ] );
                        vertexNormal.push_back ( tmpNormals [ ( vertexData - 1 ) * 3 + 1 ] );
                        vertexNormal.push_back ( tmpNormals [ ( vertexData - 1 ) * 3 + 2 ] );
                        ss.ignore ( 1 , '/' );// Si el char es '/' l'ignora
                        counter = 0;
                        break;
                }
            }
        }
    }

    return Model ( vertexs , textureCoords , vertexNormal );
}


