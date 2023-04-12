#include "pieceRenderer.h"

PieceRenderer::PieceRenderer(QGraphicsScene* scene) : gameScene(scene)
{
	//Sets position varibales
	position = ScreenMapper::mapCoords(695, 10, scene->width(), scene->height());
	pieceWidth = ScreenMapper::mapCoords(0, 53, 0, scene->height()).y;
	absolute = false;

	singleColors[0] = (new QPixmap("assets/TransBlock.png"))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[1] = (new QPixmap("assets/CyanBlock.png"))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[2] = (new QPixmap("assets/YellowBlock.png"))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[3] = (new QPixmap("assets/PurpleBlock.png"))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[4] = (new QPixmap("assets/GreenBlock.png"))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[5] = (new QPixmap("assets/BlueBlock.png"))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[6] = (new QPixmap("assets/RedBlock.png"))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[7] = (new QPixmap("assets/OrangeBlock.png"))->scaled(QSize(pieceWidth, pieceWidth));
	
	pixels = new QGraphicsPixmapItem * [maxPieceSize];

	for (int i = 0; i < maxPieceSize; i++) {
		pixels[i] = new QGraphicsPixmapItem[maxPieceSize];
	}

	for (int i = 0; i < maxPieceSize; i++) {
		for (int j = 0; j < maxPieceSize; j++) {
			pixels[i][j].setPixmap(singleColors[0]);
			gameScene->addItem(&pixels[i][j]);
		}
	}

}

PieceRenderer::PieceRenderer(QGraphicsScene* scene, Coordinate setCorner, Coordinate setDimensions) : PieceRenderer(scene)
{
	corner = setCorner;
	dimensions = setDimensions;
	absolute = true;
}

PieceRenderer::~PieceRenderer()
{
	for (int i = 0; i < maxPieceSize; i++) {
		for (int j = 0; j < maxPieceSize; j++) {
			gameScene->removeItem(&pixels[i][j]);
		}
	}

	for (int i = 0; i < maxPieceSize; i++) {
		delete[] pixels[i];
	}

	delete pixels;
}

void PieceRenderer::renderPiece(Piece* _piece)
{

	if (absolute) {
		renderPieceAbsolute(_piece);
	}
	else {
		renderPieceRelative(_piece);
	}
}

void PieceRenderer::renderPieceRelative(Piece* _piece)
{
	for (int i = 0; i < maxPieceSize; i++) {
		for (int j = 0; j < maxPieceSize; j++) {

			if (j < _piece->getPiece()->getWidth() && i < _piece->getPiece()->getHeight()) {
				pixels[i][j].setPos(position.x + _piece->getCoordinate().x * pieceWidth + pieceWidth * j,
					position.y + _piece->getCoordinate().y * pieceWidth + pieceWidth * i - 2 * pieceWidth);
				pixels[i][j].setPixmap(singleColors[int(_piece->getPiece()->getGrid()[i][j])]);
			}
			else {
				pixels[i][j].setPixmap(singleColors[0]);
			}

		}
	}
}

void PieceRenderer::renderPieceAbsolute(Piece* _piece)
{
	position.x = corner.x + (dimensions.x - _piece->getPiece()->getWidth() * pieceWidth) / 2;
	position.y = corner.y + (dimensions.y - _piece->getPiece()->getHeight() * pieceWidth) / 2;

	for (int i = 0; i < maxPieceSize; i++) {
		for (int j = 0; j < maxPieceSize; j++) {

			if (j < _piece->getPiece()->getWidth() && i < _piece->getPiece()->getHeight()) {
				pixels[i][j].setPos(position.x + pieceWidth * j, position.y + pieceWidth * i);
				pixels[i][j].setPixmap(singleColors[int(_piece->getPiece()->getGrid()[i][j])]);
			}
			else {
				pixels[i][j].setPixmap(singleColors[0]);
			}

		}
	}
}


