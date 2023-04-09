#pragma once
#ifndef GAMESTARTSCENE_H
#define GAMESTARTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QDebug>

#include "flashingTextRenderer.h"
#include "fullScreenRenderer.h"
#include "screenMapper.h"
#include "mainGameLoopThread.h"

class GameStartScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GameStartScene(MainGameScene* next, QGraphicsView* view);

    GameStartScene(MainGameScene* next, QGraphicsView* view, QString filePath);

    void keyPressEvent(QKeyEvent *event);

    ~GameStartScene();

private:

    void anyKeyPressed();
    QGraphicsView* mainView;
    MainGameScene* nextScene;
    FlashingTextRenderer* monText;
    FullScreenRenderer* splashScreen;


};

#endif // GAMESTARTSCENE_H
