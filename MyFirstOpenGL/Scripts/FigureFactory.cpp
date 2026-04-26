#include "FigureFactory.h"

// Els vértex han estat definits amb ChatGPT

Figure * FigureFactory::CreateCube ( )
{
    Figure * f = new Figure ( );

    f->vertices = {
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

    f->SetupMesh ( );
    return f;
}

Figure * FigureFactory::CreateOrthoedro ( )
{
    return CreateCube ( );
}

Figure * FigureFactory::CreatePyramid ( )
{
    Figure * f = new Figure ( );

    f->vertices = {
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

    f->SetupMesh ( );
    return f;
}