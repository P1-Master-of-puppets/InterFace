#include "maingamescene.h"

MainGameScene::MainGameScene(QString background, QGraphicsView* mainView)
{
    QPixmap monPixMap(background);
    QPixmap scaled = monPixMap.scaled(QSize(mainView->width(), mainView->height()));
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem();
    item->setPixmap(scaled);
    addItem(item);

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

    level = new TextCounter(QString::number(1), mainView, "level");
    tetris = new TextCounter(QString::number(0), mainView, "tetris");
    score = new TextCounter(QString::number(0), mainView, "score");

    addItem(level);
    addItem(tetris);
    addItem(score);

    monBoard = new BoardRenderer(this);
    gamePiece = new PieceRenderer(this);

    Coordinate holdPieceCoords = { 0.12916666*mainView->width(), 0.14629629*mainView->height()};
    Coordinate holdPieceDim = { 0.12916666 * mainView->width(), 0.18981481 * mainView->height() };
    
    
    Coordinate nextPieceCoords = { 0.73072916*mainView->width(), 0.24166666*mainView->height() };
    Coordinate nextPieceDim = { 0.1328125 * mainView->width(),  0.19629629 * mainView->height() };


    holdPiece = new PieceRenderer(this, holdPieceCoords, holdPieceDim);
    nextPiece = new PieceRenderer(this, nextPieceCoords, nextPieceDim);
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




