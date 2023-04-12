#include "gameInformation.h"

GameInformation::GameInformation(ColorArray2D* board, Piece* piece, Piece* holdPiece, Piece* nextPiece, int score, int tetris, int level)
{
	this->board = board;
	this->piece = piece;
	this->holdPiece = holdPiece;
	this->nextPiece = nextPiece;
	this->score = score;
	this->tetris = tetris;
	this->level = level;
}
