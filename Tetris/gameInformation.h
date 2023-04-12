#ifndef GAMEINFORMATION_H
#define GAMEINFORMATION_H

#include "colorArray2D.h"
#include "piece.h"

class GameInformation
{
public:
	GameInformation(ColorArray2D* board, Piece* piece, Piece* holdPiece, Piece* nextPiece,
		int score, int tetris, int level);

	ColorArray2D* board;
	Piece* piece;
	Piece* holdPiece;
	Piece* nextPiece;

	int score;
	int tetris;
	int level;
};
#endif // !GAMEINFORMATION_H
