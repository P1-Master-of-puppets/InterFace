#include "thomas.h"

Thomas::Thomas() : Piece(3, 3)
{
    (*_array)[1][0] = Color::Purple;
    (*_array)[1][1] = Color::Purple;
    (*_array)[1][2] = Color::Purple;
    (*_array)[2][1] = Color::Purple;
    _coordinate.y = 1;
}

Thomas::~Thomas()
{
}
