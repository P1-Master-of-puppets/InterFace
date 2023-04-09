#pragma once
#ifndef LEFTS_H__
#define LEFTS_H__

#include "piece.h"

class LeftS : public Piece
{
public:
    LeftS();
    ~LeftS();
    bool rotateLeft(const ColorArray2D& board);
    bool rotateRight(const ColorArray2D& board);

private:
    bool rotateS(const ColorArray2D& board);
    bool isVertical;
};

#endif // LEFTS_H__
