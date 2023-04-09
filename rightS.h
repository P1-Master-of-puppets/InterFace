#pragma once
#ifndef RightS_H__
#define RightS_H__

#include "piece.h"


class RightS : public Piece
{
public:
    RightS();
    ~RightS();
    bool rotateLeft(const ColorArray2D& board);
    bool rotateRight(const ColorArray2D& board);
private:
    bool rotateS(const ColorArray2D& board);
    bool isVertical;
};

#endif // RightS_H__