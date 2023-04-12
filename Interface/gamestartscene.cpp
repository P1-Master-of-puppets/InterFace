#include "gamestartscene.h"

GameStartScene::GameStartScene(MainGameScene* next, QGraphicsView* view) :
    mainView(view), nextScene(next)
{

    //Intialise le background
    splashScreen = new FullScreenRenderer(QString(LOADING_SCREEN_IMAGE_PATH), this, QSize(view->width(), view->height()));

    //Initialise variable
    monText = new FlashingTextRenderer(QString("Press any key to start..."), this, ScreenMapper::mapCoords(960, 1020, this->width(), this->height()), 750);
}

void GameStartScene::keyPressEvent(QKeyEvent *event)
{
    MainGameLoopThread* thread = new MainGameLoopThread(nextScene);
    mainView->setScene(nextScene);
}

GameStartScene::~GameStartScene()
{
    removeItem(monText);
    removeItem(splashScreen);

    delete monText;
    delete splashScreen;
}