#pragma once
#include "Figure.h"
#include "../Model.h"
#include <string>
class FigureFactory
{
    public:
    FigureFactory ( ) = default;
    ~FigureFactory ( ) = default;
    static Figure * CreateCube ( );
    static Model LoadOBJModel ( const std::string & filePath );

};

