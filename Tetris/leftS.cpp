#include "leftS.h"

LeftS::LeftS() : Piece(3, 3)
{
    isVertical = false;
    (*_array)[1][0] = Color::Red;
    (*_array)[1][1] = Color::Red;
    (*_array)[2][1] = Color::Red;
    (*_array)[2][2] = Color::Red;
    _coordinate.y = 1;
}

LeftS::~LeftS()
{
}

bool LeftS::rotateS(const ColorArray2D& board){
    if(isVertical){
        if(Piece::rotateLeft(board)){
            isVertical = false;
            return true;
        }
    }
    else{
        if(Piece::rotateRight(board)){
            isVertical = true;
            return true;
        }
    }

    return false;
}

bool LeftS::rotateLeft(const ColorArray2D& board){
    return rotateS(board);
}

bool LeftS::rotateRight(const ColorArray2D& board){
    return rotateS(board);
}

