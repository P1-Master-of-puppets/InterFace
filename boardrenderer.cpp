#include "boardrenderer.h"

BoardRenderer::BoardRenderer(QGraphicsScene* scene): gameScene(scene)
{
    int scaleTo = 53;
    singleColors[0] = (new QPixmap("assets/TransBlock.png"))->scaled(QSize(scaleTo,scaleTo));
    singleColors[1] = (new QPixmap("assets/CyanBlock.png"))->scaled(QSize(scaleTo,scaleTo));
    singleColors[2] = (new QPixmap("assets/YellowBlock.png"))->scaled(QSize(scaleTo,scaleTo));
    singleColors[3] = (new QPixmap("assets/PurpleBlock.png"))->scaled(QSize(scaleTo,scaleTo));
    singleColors[4] = (new QPixmap("assets/GreenBlock.png"))->scaled(QSize(scaleTo,scaleTo));
    singleColors[5] = (new QPixmap("assets/BlueBlock.png"))->scaled(QSize(scaleTo,scaleTo));
    singleColors[6] = (new QPixmap("assets/RedBlock.png"))->scaled(QSize(scaleTo,scaleTo));
    singleColors[7] = (new QPixmap("assets/OrangeBlock.png"))->scaled(QSize(scaleTo,scaleTo));


    itemMap = new QGraphicsPixmapItem*[boardHeight];
    for (int i = 0; i < boardHeight; i++){
        itemMap[i] = new QGraphicsPixmapItem[boardWidth];
    }

    for(int i = 2; i < boardHeight; i++){
        for(int j = 0; j < boardWidth; j++){
            itemMap[i][j].moveBy(695 + j*scaleTo, (i-2)*scaleTo + 10);
            itemMap[i][j].setPixmap(singleColors[0]);
            gameScene->addItem(&itemMap[i][j]);
        }
    }


}

void BoardRenderer::renderBoard(ColorArray2D* _board)
{

    for(int i = 2; i < boardHeight; i++){
        for(int j = 0; j < boardWidth; j++){
            if(itemMap[i][j].pixmap().cacheKey() != singleColors[int(_board->getGrid()[i][j])].cacheKey() ){
                itemMap[i][j].setPixmap(singleColors[int(_board->getGrid()[i][j])]);
            }
        }
    }

}

