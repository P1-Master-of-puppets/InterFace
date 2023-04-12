#pragma once
#ifndef MAINGAMESCENE_H
#define MAINGAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QRandomGenerator>
#include <QKeyEvent>
#include <QObject>

#include "gameSceneSignals.h"

#include "screenMapper.h"
#include "textRenderer.h"
#include "fullScreenRenderer.h"
#include "boardrenderer.h"
#include "pieceRenderer.h"
#include "colorArray2D.h"
#include "piece.h"
#include "assets.h"
#include "gameDisplay.h"

class MainGameScene : public GameDisplay, public GameSceneSignals
{

public:
    MainGameScene(QSize viewSize);
    ~MainGameScene();
    void refreshUI(ColorArray2D* _board, Piece* _piece, Piece* _holdPiece, Piece* _nextPiece,
                   int score, int tetris, int level);

    void updateBoard(ColorArray2D* _board);
    void updatePiece(Piece* _piece);
    void updateHoldPiece(Piece* _holdPiece);
    void updateNextPiece(Piece* _nextPiece);

    void updateScore(int newScore);
    void updateTetris(int newTetris);
    void updateLevel(int newLevel);

    void keyPressEvent(QKeyEvent *event);

private:
    TextRenderer* level;
    TextRenderer* tetris;
    TextRenderer* score;

    BoardRenderer* monBoard;

    PieceRenderer* gamePiece;
    PieceRenderer* holdPiece;
    PieceRenderer* nextPiece;

    FullScreenRenderer* background;


    //QGraphicsPixmapItem * GFilter;
    //QGraphicsPixmapItem* GControl;
    //QGraphicsPixmapItem* GReset;
    //QGraphicsPixmapItem* GExit;
    //bool menuUp = false;
};

#endif // MAINGAMESCENE_H
