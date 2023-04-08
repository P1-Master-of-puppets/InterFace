#include "maingamescene.h"

MainGameScene::MainGameScene(QString backgroundPath, QGraphicsView* mainView)
{
    background = new FullScreenRenderer(backgroundPath, this, QSize(mainView->width(), mainView->height()));

    QPixmap filter("assets/filtre.png");
    QPixmap scaledFilter = filter.scaled(QSize(mainView->width(), mainView->height()));
    GFilter = new QGraphicsPixmapItem();
    GFilter->setPixmap(scaledFilter);

    QPixmap control("assets/control_menu.png");
    //QPixmap scaledControl = control.scaled(QSize(control.width(), control.height())*2);
    GControl = new QGraphicsPixmapItem();
    GControl->moveBy(720,70);
    GControl->setPixmap(control);

    QPixmap reset("assets/reset.png");
    GReset = new QGraphicsPixmapItem();
    GReset->moveBy(720, 250);
    GReset->setPixmap(reset);

    QPixmap exit("assets/reset.png");
    GExit = new QGraphicsPixmapItem();
    GExit->moveBy(720, 430);
    GExit->setPixmap(exit);

    Coordinate dim = ScreenMapper::mapCoords(287, 92, this->width(), this->height());

    level = new TextRenderer(QString::number(1), this, ScreenMapper::mapCoords(228, 909, this->width(), this->height()), dim);
    tetris = new TextRenderer(QString::number(0), this, ScreenMapper::mapCoords(228, 708, this->width(), this->height()), dim);
    score = new TextRenderer(QString::number(0), this, ScreenMapper::mapCoords(228, 507, this->width(), this->height()), dim);

    monBoard = new BoardRenderer(this);
    gamePiece = new PieceRenderer(this);

    holdPiece = new PieceRenderer(this, ScreenMapper::mapCoords(247, 157, this->width(), this->height()) , ScreenMapper::mapCoords(250, 206, this->width(), this->height()));
    nextPiece = new PieceRenderer(this, ScreenMapper::mapCoords(1403, 261, this->width(), this->height()), ScreenMapper::mapCoords(255, 212, this->width(), this->height()));
}

void MainGameScene::refreshUI(ColorArray2D* _board, Piece* _piece, Piece* _holdPiece, Piece* _nextPiece, int score, int tetris, int level)
{
    updateBoard(_board);
    updatePiece(_piece);
    updateHoldPiece(_holdPiece);
    updateNextPiece(_nextPiece);
    updateScore(score);
    updateTetris(tetris);
    updateLevel(level);
}

void MainGameScene::updateBoard(ColorArray2D* _board)
{
    monBoard->renderBoard(_board);
}

void MainGameScene::updatePiece(Piece* _piece)
{
    gamePiece->renderPiece(_piece);
}

void MainGameScene::updateHoldPiece(Piece* _holdPiece)
{
    holdPiece->renderPiece(_holdPiece);
}

void MainGameScene::updateNextPiece(Piece* _nextPiece)
{
    nextPiece->renderPiece(_nextPiece);
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

void MainGameScene::keyPressEvent(QKeyEvent* event)
{
    RightL* piece = new RightL();

    updateHoldPiece(piece);
    updateNextPiece(piece);
    if (menuUp == false)
    {
        addItem(GFilter);
        addItem(GControl);
        addItem(GReset);
        addItem(GExit);
        menuUp = true;
    }
    else
    {
        removeItem(GFilter);
        removeItem(GControl);
        removeItem(GReset);
        removeItem(GExit);
        menuUp = false;
    }
}




