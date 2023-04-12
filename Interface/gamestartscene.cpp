#include "gamestartscene.h"

GameStartScene::GameStartScene(QSize mainView)
{

    //Intialise le background
    splashScreen = new FullScreenRenderer(QString(LOADING_SCREEN_IMAGE_PATH), this, mainView);

    //Initialise variable
    monText = new FlashingTextRenderer(QString("Press any key to start..."), this, ScreenMapper::mapCoords(960, 1020, this->width(), this->height()), 750);
}

void GameStartScene::keyPressEvent(QKeyEvent *event)
{
    emit goToMainGame();
}

GameStartScene::~GameStartScene()
{
    removeItem(monText);
    removeItem(splashScreen);

    delete monText;
    delete splashScreen;
}