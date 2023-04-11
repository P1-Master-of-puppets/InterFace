#pragma once
#ifndef LONGBAR_H__
#define LONGBAR_H__

#include "piece.h"

class LongBar : public Piece
{
public:
    LongBar();
    ~LongBar();
    
    bool rotateLeft(const ColorArray2D& board);
    bool rotateRight(const ColorArray2D& board);

private:
    bool vertical;
    bool rotateBar(const ColorArray2D& board);
};

#endif // LONGBAR_H__
