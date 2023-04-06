#include "gamestartscene.h"

GameStartScene::GameStartScene(QGraphicsScene* next, QGraphicsView* view) :
    mainView(view), nextScene(next)
{
    //Initialise variable
    monText = new FlashingText(QString("Press any key..."), mainView);

    //Load "assets/loadingScreen.png" as a background
    QString fileName = "assets/loadingScreen.png";
    QPixmap monPixMap(fileName);
    QPixmap scaled = monPixMap.scaled(QSize(mainView->width(), mainView->height()));
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem();
    item->setPixmap(scaled);
    addItem(item);
    addItem(monText);


}

GameStartScene::GameStartScene(QGraphicsScene *next, QGraphicsView *view, QString fileName):
    mainView(view), nextScene(next)
{
    //Load "assets/loadingScreen.png" as a background
    QPixmap monPixMap(fileName);
    QPixmap scaled = monPixMap.scaled(QSize(mainView->width(), mainView->height()));
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem();
    item->setPixmap(scaled);
    addItem(item);
}

void GameStartScene::keyPressEvent(QKeyEvent *event)
{
    anyKeyPressed();
}

GameStartScene::~GameStartScene()
{
    //Delete required
}

void GameStartScene::anyKeyPressed()
{
    //Loads the next scene onto the view
    mainView->setScene(nextScene);
}
