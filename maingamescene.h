#ifndef MAINGAMESCENE_H
#define MAINGAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QRandomGenerator>
#include "textcounter.h"
#include "boardrenderer.h"
#include "colorArray2D.h"

class MainGameScene : public QGraphicsScene
{

public:
    MainGameScene(QString background, QGraphicsView* mainView);

    void refreshUI(ColorArray2D* _board, int _piece, int _holdPiece, int _nextPiece,
                   int score, int tetris, int level);

    void updateBoard(ColorArray2D* _board);
    void updatePiece(int _piece);
    void updateHoldPiece(int _holdPiece);
    void updateNextPiece(int _nextPiece);

    void updateScore(int newScore);
    void updateTetris(int newTetris);
    void updateLevel(int newLevel);

    void keyPressEvent(QKeyEvent *event);

private:
    TextCounter* level;
    TextCounter* tetris;
    TextCounter* score;

    BoardRenderer* monBoard;

    QRandomGenerator mf;


};

#endif // MAINGAMESCENE_H
