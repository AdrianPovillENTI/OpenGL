#pragma once
#include "Figure.h"
class FigureFactory
{
    public:
    FigureFactory ( ) = default;
    ~FigureFactory ( ) = default;
    static Figure * CreatePyramid ( );
    static Figure * CreateOrthoedro ( );
    static Figure * CreateCube ( );
};

