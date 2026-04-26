#include "FigureFactory.h"

Figure * FigureFactory::CreateCube ( )
{
    Figure * f = new Figure ( );

    f->vertices = {
        // BACK
        -0.5f,  0.5f, -0.5f,  0.5f,  0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,  0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f,

        // FRONT
        -0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f, -0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,  0.5f, -0.5f,  0.5f, -0.5f, -0.5f,  0.5f,

        // LEFT
        -0.5f,  0.5f,  0.5f, -0.5f,  0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f, -0.5f, -0.5f,  0.5f, -0.5f,  0.5f,  0.5f,

        // RIGHT
        0.5f,  0.5f,  0.5f,  0.5f,  0.5f, -0.5f,  0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,  0.5f, -0.5f,  0.5f,  0.5f,  0.5f,  0.5f,

        // TOP
        -0.5f,  0.5f, -0.5f,  0.5f,  0.5f, -0.5f, -0.5f,  0.5f,  0.5f,
        0.5f,  0.5f, -0.5f,  0.5f,  0.5f,  0.5f, -0.5f,  0.5f,  0.5f,

        // BOTTOM
        -0.5f, -0.5f, -0.5f,  0.5f, -0.5f, -0.5f, -0.5f, -0.5f,  0.5f,
        0.5f, -0.5f, -0.5f,  0.5f, -0.5f,  0.5f, -0.5f, -0.5f,  0.5f
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
        -0.5f,0.0f,-0.5f, 0.5f,0.0f,-0.5f, 0.5f,0.0f,0.5f,
        -0.5f,0.0f,-0.5f, 0.5f,0.0f,0.5f, -0.5f,0.0f,0.5f,

        -0.5f,0.0f,-0.5f, 0.5f,0.0f,-0.5f, 0.0f,1.0f,0.0f,
         0.5f,0.0f,-0.5f, 0.5f,0.0f,0.5f, 0.0f,1.0f,0.0f,
         0.5f,0.0f,0.5f, -0.5f,0.0f,0.5f, 0.0f,1.0f,0.0f,
        -0.5f,0.0f,0.5f, -0.5f,0.0f,-0.5f,0.0f,1.0f,0.0f
    };

    f->SetupMesh ( );
    return f;
}