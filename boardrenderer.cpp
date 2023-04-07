#include "boardrenderer.h"

BoardRenderer::BoardRenderer(QGraphicsScene* scene): gameScene(scene)
{
    //Sets position varibales
    corner.x = 0.36197916 * scene->width();
    corner.y = 0.00925925 * scene->height();
    pieceWidth = 0.0491 * gameScene->height();
;
    singleColors[0] = (new QPixmap("assets/TransBlock.png"))->scaled(QSize(pieceWidth,pieceWidth));
    singleColors[1] = (new QPixmap("assets/CyanBlock.png"))->scaled(QSize(pieceWidth,pieceWidth));
    singleColors[2] = (new QPixmap("assets/YellowBlock.png"))->scaled(QSize(pieceWidth,pieceWidth));
    singleColors[3] = (new QPixmap("assets/PurpleBlock.png"))->scaled(QSize(pieceWidth,pieceWidth));
    singleColors[4] = (new QPixmap("assets/GreenBlock.png"))->scaled(QSize(pieceWidth,pieceWidth));
    singleColors[5] = (new QPixmap("assets/BlueBlock.png"))->scaled(QSize(pieceWidth,pieceWidth));
    singleColors[6] = (new QPixmap("assets/RedBlock.png"))->scaled(QSize(pieceWidth,pieceWidth));
    singleColors[7] = (new QPixmap("assets/OrangeBlock.png"))->scaled(QSize(pieceWidth,pieceWidth));


    mapPixel = new QGraphicsPixmapItem*[boardHeight];
    for (int i = 0; i < boardHeight; i++){
        mapPixel[i] = new QGraphicsPixmapItem[boardWidth];
    }

    for(int i = 2; i < boardHeight; i++){
        for(int j = 0; j < boardWidth; j++){
            mapPixel[i][j].moveBy(corner.x + j*pieceWidth, corner.y + (i-2)*pieceWidth);
            mapPixel[i][j].setPixmap(singleColors[0]);
            gameScene->addItem(&mapPixel[i][j]);
        }
    }

}

void BoardRenderer::renderBoard(ColorArray2D* _board)
{

    for(int i = 2; i < boardHeight; i++){
        for(int j = 0; j < boardWidth; j++){
            if(mapPixel[i][j].pixmap().cacheKey() != singleColors[int(_board->getGrid()[i][j])].cacheKey() ){
                mapPixel[i][j].setPixmap(singleColors[int(_board->getGrid()[i][j])]);
            }
        }
    }

}

