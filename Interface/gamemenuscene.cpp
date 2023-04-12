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

	QPixmap exitButton(EXIT_BUTTON_IMAGE_PATH);
	QPixmap exitButtonGlow(EXIT_BUTTON_GLOW_IMAGE_PATH);

	QPixmap controlButton(CONTROL_BUTTON_IMAGE_PATH);
	QPixmap controlButtonGlow(CONTROL_BUTTON_GLOW_IMAGE_PATH);

	Coordinate center = RendererHelper::fitImageInHorizontalMiddle(startButton.width(), mainView->width());

	ToggledButton* _startButton = new ToggledButton(startButtonGlow, startButton, center, this);
	QObject::connect(_startButton, &ToggledButton::clicked,
		this, &GameMenuScene::startButtonClicked);

	center.y += startButton.height() - 150;
	ToggledButton* _controlButton = new ToggledButton(controlButtonGlow, controlButton, center, this);

	QObject::connect(_controlButton, &ToggledButton::clicked,
		this, &GameMenuScene::controlButtonClicked);

	center.y += startButton.height() - 150;
	ToggledButton* _exitButton = new ToggledButton(exitButtonGlow, exitButton, center, this);
	QObject::connect(_startButton, &ToggledButton::clicked,
		this, &GameMenuScene::exitButtonClicked);

	_buttonGroup = new ButtonGroup2D(3, 1);
	_buttonGroup->setButton(0, 0, _startButton);
	_buttonGroup->setButton(1, 0, _controlButton);
	_buttonGroup->setButton(2, 0, _exitButton);
}

GameMenuScene::~GameMenuScene()
{
	delete _buttonGroup;
}


void GameMenuScene::exitButtonClicked() {
	int i = 0;
}

void GameMenuScene::controlButtonClicked() {
	int i = 0;
}

void GameMenuScene::startButtonClicked() {
	int i = 0;
}