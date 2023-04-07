#ifndef PIECERENDERER_H
#define PIECERENDERER_H
#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include "piece.h"
#include "coordinate.h"

class PieceRenderer
{
public:
	PieceRenderer(QGraphicsScene* scene);
	PieceRenderer(QGraphicsScene* scene, Coordinate setCorner, Coordinate setDimensions);

	void renderPiece(Piece* _piece);

private:

	void renderPieceAbsolute(Piece* _piece);
	void renderPieceRelative(Piece* _piece);


	Coordinate corner;
	Coordinate dimensions;
	Coordinate position;
	bool absolute;
	double pieceWidth;

	QGraphicsScene* gameScene;
	QGraphicsPixmapItem** pixels;
	QPixmap singleColors[8];
	const int maxPieceSize = 4;
};


#endif // !PIECERENDERER_H





