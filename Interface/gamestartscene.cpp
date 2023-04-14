#include "gamestartscene.h"

GameStartScene::GameStartScene(QSize windowSize, QGraphicsView* applicationView, QObject* parent) : ApplicationScene(windowSize, parent)
{
	applicationView->grabKeyboard();
	_applicationView = applicationView;
	setBackground(QPixmap(LOADING_SCREEN_IMAGE_PATH));
	//Initialise variable
	monText = new FlashingTextRenderer(QString("Press any key to start..."), this, ScreenMapper::mapCoords(960, 1020, this->width(), this->height()), 750);
}

void GameStartScene::keyPressEvent(QKeyEvent* event)
{
	emit goToMainMenu();
}

GameStartScene::~GameStartScene()
{
	removeItem(monText);
	delete monText;
}