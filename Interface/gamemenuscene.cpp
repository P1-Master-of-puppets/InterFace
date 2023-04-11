#include "gamemenuscene.h"

GameMenuScene::GameMenuScene(QGraphicsView* mainView)
{

#pragma region BackgroundSetup
	QPixmap* backgroundImage = new QPixmap(BACKGROUND_IMAGE_PATH);
	QPixmap filtreImage(FILTER_IMAGE_PATH);
	QPainter painter(backgroundImage);

	painter.drawPixmap(0, 0, filtreImage);
	painter.end();
	_background = new FullScreenRenderer(backgroundImage->copy(), this, QSize(mainView->width(), mainView->height()));
	setSceneRect(mainView->rect());
	delete backgroundImage;
#pragma endregion
	
	QPixmap startButton(START_BUTTON_IMAGE_PATH);
	QPixmap startButtonGlow(START_BUTTON_GLOW_IMAGE_PATH);
	Coordinate center = RendererHelper::fitImageInHorizontalMiddle(startButton.width(), mainView->width());
	
	_startButton = new ToggledButton(1,startButtonGlow, startButton, center, this);
	_startButton->show();
}

GameMenuScene::~GameMenuScene()
{
}