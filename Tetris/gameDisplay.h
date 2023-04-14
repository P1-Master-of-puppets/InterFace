#pragma once
#pragma once
#ifndef GAMEDISPLAY_H__
#define GAMEDISPLAY_H__
#include "colorArray2D.h"
#include "piece.h"
class GameDisplay
{
public:
	virtual void refreshUI(ColorArray2D* board, Piece* piece, Piece* holdPiece, Piece* nextPiece,
		int score, int tetris, int level, int lines) = 0;
};
#endif //GAMEDISPLAY_H__