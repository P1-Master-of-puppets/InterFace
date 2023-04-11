#pragma once
#pragma once
#ifndef GAMEDISPLAY_H__
#define GAMEDISPLAY_H__
#include "colorArray2D.h"
#include "piece.h"

class GameDisplay
{
public:
	virtual void refreshUI(ColorArray2D* _board, Piece* _piece, Piece* _holdPiece, Piece* _nextPiece,
		int score, int tetris, int level) = 0;
};
#endif //GAMEDISPLAY_H__

