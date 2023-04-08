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

class GameStartScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GameStartScene(QGraphicsScene* next, QGraphicsView* view);

    GameStartScene(QGraphicsScene* next, QGraphicsView* view, QString filePath);

    void keyPressEvent(QKeyEvent *event);

    ~GameStartScene();

private:

    void anyKeyPressed();
    QGraphicsView* mainView;
    QGraphicsScene* nextScene;
    FlashingTextRenderer* monText;
    FullScreenRenderer* splashScreen;


};

#endif // GAMESTARTSCENE_H
