#include "gamestartscene.h"

GameStartScene::GameStartScene(MainGameScene* next, QGraphicsView* view) :
    mainView(view), nextScene(next)
{

    //Intialise le background
    splashScreen = new FullScreenRenderer(QString("assets/loadingScreen.png"), this, QSize(view->width(), view->height()));

    //Initialise variable
    monText = new FlashingTextRenderer(QString("Press any key to start..."), this, ScreenMapper::mapCoords(960, 1020, this->width(), this->height()), 750);
}

GameStartScene::GameStartScene(MainGameScene *next, QGraphicsView *view, QString fileName):
    mainView(view), nextScene(next)
{
    //Intialise le background
    splashScreen = new FullScreenRenderer(QString("assets/loadingScreen.png"), this, QSize(view->width(), view->height()));

    //Initialise variable
    monText = new FlashingTextRenderer(QString("Press any key to start..."), this, ScreenMapper::mapCoords(960, 1020, this->width(), this->height()), 750);
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
    MainGameLoopThread* thread = new MainGameLoopThread(nextScene);
    mainView->setScene(nextScene);
}
