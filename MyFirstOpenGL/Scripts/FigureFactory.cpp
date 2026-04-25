#include "FigureFactory.h"

Figure * CreateCube ( )
{
    Figure * f = new Figure ( );

    f->vertices = {
        // BACK
        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        // FRONT
        -0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

         0.5f,  0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        // LEFT
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

        // RIGHT
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,

         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

         // TOP
         -0.5f,  0.5f, -0.5f,
          0.5f,  0.5f, -0.5f,
         -0.5f,  0.5f,  0.5f,

          0.5f,  0.5f, -0.5f,
          0.5f,  0.5f,  0.5f,
         -0.5f,  0.5f,  0.5f,

         // BOTTOM
         -0.5f, -0.5f, -0.5f,
          0.5f, -0.5f, -0.5f,
         -0.5f, -0.5f,  0.5f,

          0.5f, -0.5f, -0.5f,
          0.5f, -0.5f,  0.5f,
         -0.5f, -0.5f,  0.5f
    };

    f->SetupMesh ( );
    return f;
}

Figure * CreateOrthoedro ( )
{
    return CreateCube ( ); // se diferencia por su escala
}

Figure * CreatePyramid ( )
{
    Figure * f = new Figure ( );

    f->vertices = {
        // Base (cuadrado)
        -0.5f, 0.0f, -0.5f,
         0.5f, 0.0f, -0.5f,
         0.5f, 0.0f,  0.5f,

        -0.5f, 0.0f, -0.5f,
         0.5f, 0.0f,  0.5f,
        -0.5f, 0.0f,  0.5f,

        // Cara 1
        -0.5f, 0.0f, -0.5f,
         0.5f, 0.0f, -0.5f,
         0.0f, 1.0f,  0.0f,

         // Cara 2
          0.5f, 0.0f, -0.5f,
          0.5f, 0.0f,  0.5f,
          0.0f, 1.0f,  0.0f,

          // Cara 3
           0.5f, 0.0f,  0.5f,
          -0.5f, 0.0f,  0.5f,
           0.0f, 1.0f,  0.0f,

           // Cara 4
           -0.5f, 0.0f,  0.5f,
           -0.5f, 0.0f, -0.5f,
            0.0f, 1.0f,  0.0f
    };

    f->SetupMesh ( );
    return f;
}