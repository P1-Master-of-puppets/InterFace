#pragma once
#ifndef BOARDRENDERER_H
#define BOARDRENDERER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include "colorArray2D.h"
#include "coordinate.h"
#include "screenMapper.h"
#include "rendererhelper.h"
#include "assets.h"

class BoardRenderer
{
public:
	BoardRenderer(QGraphicsScene* scene);
	~BoardRenderer();

	void renderBoard(ColorArray2D* _board);

private:
	Coordinate corner;
	double pieceWidth;

	QGraphicsScene* gameScene;
	QPixmap singleColors[8];

	QGraphicsPixmapItem** mapPixel;

	const int boardWidth = 10;
	const int boardHeight = 22;
};

#endif // BOARDRENDERER_H
