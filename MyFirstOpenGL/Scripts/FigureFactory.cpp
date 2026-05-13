
#include "FigureFactory.h"
#include <GL/glew.h>
#include <glm.hpp>
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

    std::vector<GLfloat> uvs =
    {

    };

    return new Figure(vertices, uvs);
}

Figure * FigureFactory::CreateOrthoedro ( )
{
    return CreateCube ( );
}

Figure * FigureFactory::CreatePyramid ( )
{

    std::vector<GLfloat> vertices =
    {
        // BASE (quadrat)
    -0.15f, -0.15f, -0.15f,   0.15f, -0.15f, -0.15f,  -0.15f, -0.15f,  0.15f,
     0.15f, -0.15f, -0.15f,   0.15f, -0.15f,  0.15f,  -0.15f, -0.15f,  0.15f,

     // FRONT
     -0.15f, -0.15f,  0.15f,   0.15f, -0.15f,  0.15f,   0.0f,   0.2f,   0.0f,

     // RIGHT
      0.15f, -0.15f,  0.15f,   0.15f, -0.15f, -0.15f,   0.0f,   0.2f,   0.0f,

      // BACK
       0.15f, -0.15f, -0.15f,  -0.15f, -0.15f, -0.15f,   0.0f,   0.2f,   0.0f,

       // LEFT
       -0.15f, -0.15f, -0.15f,  -0.15f, -0.15f,  0.15f,   0.0f,   0.2f,   0.0f
    };

    std::vector<GLfloat> uvs =
    {

    };

    Figure* f = new Figure(vertices, uvs);
    return f;
}