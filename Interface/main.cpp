#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QScreen>
#include <QList>

#include "gamestartscene.h"
#include "maingamescene.h"
#include "mainGameLoopThread.h"
#include "gamemenuscene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ////Configures the windows sizes and properties (Fits different screens)
    QGraphicsView* mainView = new QGraphicsView();

    QList<QScreen*> screens = QGuiApplication::screens();
    mainView->setFixedSize(screens.first()->availableSize());
    mainView->showFullScreen();
    mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainView->setFrameStyle(QFrame::NoFrame);
    GameMenuScene* scene = new GameMenuScene(mainView);
    MainGameScene* mainGame = new MainGameScene(mainView);
    GameStartScene* startScene = new GameStartScene(mainGame, mainView);

    startScene->setSceneRect(mainView->rect());

    mainView->setScene(scene);

    mainView->show();

    return a.exec();
}
