#include "maingamescene.h"

MainGameScene::MainGameScene(QString background, QGraphicsView* mainView)
{
    QPixmap monPixMap(background);
    QPixmap scaled = monPixMap.scaled(QSize(mainView->width(), mainView->height()));
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem();
    item->setPixmap(scaled);
    addItem(item);

    level = new TextCounter(QString::number(1), mainView, "level");
    tetris = new TextCounter(QString::number(0), mainView, "tetris");
    score = new TextCounter(QString::number(0), mainView, "score");

    addItem(level);
    addItem(tetris);
    addItem(score);

    monBoard = new BoardRenderer(this);
}

void MainGameScene::refreshUI(ColorArray2D* _board, int _piece, int _holdPiece, int _nextPiece, int score, int tetris, int level)
{
    updateBoard(_board);
    //updatePiece(_piece);
    //updateHoldPiece(_holdPiece);
    //updateNextPiece(_nextPiece);
    updateScore(score);
    updateTetris(tetris);
    updateLevel(level);
}

void MainGameScene::updateBoard(ColorArray2D* _board)
{
    monBoard->renderBoard(_board);
}

void MainGameScene::updateScore(int newScore)
{
    score->updateText(newScore);
}

void MainGameScene::updateTetris(int newTetris)
{
    tetris->updateText(newTetris);
}

void MainGameScene::updateLevel(int newLevel)
{
    level->updateText(newLevel);
}

void MainGameScene::keyPressEvent(QKeyEvent *event)
{
    ColorArray2D randomArray(10,22);

    for(int i = 0; i < 22; i++){
        for(int j = 0; j < 10; j++){
            randomArray.getGrid()[i][j] =  Color(mf.bounded(8));
        }
    }

    updateBoard(&randomArray);
}




