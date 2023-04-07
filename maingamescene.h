#ifndef MAINGAMESCENE_H
#define MAINGAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QRandomGenerator>
#include <QKeyEvent>
#include "textcounter.h"
#include "boardrenderer.h"
#include "pieceRenderer.h"
#include "colorArray2D.h"
#include "piece.h"
#include "rightL.h"


class MainGameScene : public QGraphicsScene
{

public:
    MainGameScene(QString background, QGraphicsView* mainView);

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
    TextCounter* level;
    TextCounter* tetris;
    TextCounter* score;

    BoardRenderer* monBoard;

    PieceRenderer* gamePiece;
    PieceRenderer* holdPiece;
    PieceRenderer* nextPiece;

    Coordinate holdPieceCoords = { 0,0 };
    Coordinate nextPieceCoords = { 0,0 };



};

#endif // MAINGAMESCENE_H