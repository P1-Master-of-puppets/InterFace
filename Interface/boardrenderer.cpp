#include "boardrenderer.h"

BoardRenderer::BoardRenderer(QGraphicsScene* scene) : gameScene(scene)
{
	//Sets position varibales
	corner = ScreenMapper::mapCoords(695, 10, scene->width(), scene->height());
	pieceWidth = ScreenMapper::mapCoords(0, 53, 0, scene->height()).y;
	
	singleColors[0] = (new QPixmap(TRANSPARANT_BLOCK_IMAGE_PATH))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[1] = (new QPixmap(CYAN_BLOCK_IMAGE_PATH))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[2] = (new QPixmap(YELLOW_BLOCK_IMAGE_PATH))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[3] = (new QPixmap(PURPLE_BLOCK_IMAGE_PATH))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[4] = (new QPixmap(GREEN_BLOCK_IMAGE_PATH))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[5] = (new QPixmap(BLUE_BLOCK_IMAGE_PATH))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[6] = (new QPixmap(RED_BLOCK_IMAGE_PATH))->scaled(QSize(pieceWidth, pieceWidth));
	singleColors[7] = (new QPixmap(ORANGE_BLOCK_IMAGE_PATH))->scaled(QSize(pieceWidth, pieceWidth));


	mapPixel = new QGraphicsPixmapItem * [boardHeight];
	for (int i = 0; i < boardHeight; i++) {
		mapPixel[i] = new QGraphicsPixmapItem[boardWidth];
	}

	for (int i = 2; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			mapPixel[i][j].moveBy(corner.x + j * pieceWidth, corner.y + (i - 2) * pieceWidth);
			mapPixel[i][j].setPixmap(singleColors[0]);
			gameScene->addItem(&mapPixel[i][j]);
		}
	}

}

BoardRenderer::~BoardRenderer()
{
	for (int i = 0; i < boardHeight; i++) {
		delete[] mapPixel[i];
	}

	delete mapPixel;
}

void BoardRenderer::renderBoard(ColorArray2D* _board)
{

	for (int i = 2; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			if (mapPixel[i][j].pixmap().cacheKey() != singleColors[int(_board->getGrid()[i][j])].cacheKey()) {
				mapPixel[i][j].setPixmap(singleColors[int(_board->getGrid()[i][j])]);
			}
		}
	}

}

