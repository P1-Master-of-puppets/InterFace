#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QScreen>
#include <QList>


#include "gamestartscene.h"
#include "maingamescene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Configures the windows sizes and properties (Fits different screens)
    QGraphicsView* mainView = new QGraphicsView();

    QList<QScreen*> screens = QGuiApplication::screens();
    mainView->setFixedSize(screens.first()->availableSize());
    mainView->showFullScreen();
    mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    MainGameScene* mainGame = new MainGameScene(QString("assets/background.png"), mainView);
    GameStartScene* startScene = new GameStartScene(mainGame, mainView);

    startScene->setSceneRect(mainView->rect());

    mainView->setScene(startScene);

    mainView->show();

    return a.exec();
}
