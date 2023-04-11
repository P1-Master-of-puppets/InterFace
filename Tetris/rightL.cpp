#include "rightL.h"

RightL::RightL() : Piece(3, 3)
{
    (*_array)[2][0] = Color::Orange;
    (*_array)[1][0] = Color::Orange;
    (*_array)[1][1] = Color::Orange;
    (*_array)[1][2] = Color::Orange;
    _coordinate.y = 2;
}

RightL::~RightL()
{
}
