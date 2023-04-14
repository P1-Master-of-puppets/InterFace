#include "gamemenuscene.h"

GameMenuScene::GameMenuScene(QSize windowSize) : ApplicationScene(windowSize)
{
#pragma region BackgroundSetup
	QPixmap* backgroundImage = new QPixmap(BACKGROUND_IMAGE_PATH);
	QPixmap filtreImage(FILTER_IMAGE_PATH);
	QPainter painter(backgroundImage);
	painter.drawPixmap(0, 0, filtreImage);
	painter.end();
	setBackground(backgroundImage->copy());
	delete backgroundImage;
#pragma endregion


	QPixmap startButton(START_BUTTON_IMAGE_PATH);
	QPixmap startButtonGlow(START_BUTTON_GLOW_IMAGE_PATH);

	QPixmap exitButton(EXIT_BUTTON_IMAGE_PATH);
	QPixmap exitButtonGlow(EXIT_BUTTON_GLOW_IMAGE_PATH);

	QPixmap controlButton(CONTROL_BUTTON_IMAGE_PATH);
	QPixmap controlButtonGlow(CONTROL_BUTTON_GLOW_IMAGE_PATH);

	Coordinate center = ScreenMapper::fitImageInHorizontalMiddle(startButton.width(), windowSize.width());

	ToggledButton* _startButton = new ToggledButton(startButtonGlow, startButton, center);
	QObject::connect(_startButton, &ToggledButton::clicked,
		this, &GameMenuScene::startButtonClicked);

	center.y += startButton.height() - 150;
	ToggledButton* _controlButton = new ToggledButton(controlButtonGlow, controlButton, center);

	QObject::connect(_controlButton, &ToggledButton::clicked,
		this, &GameMenuScene::controlButtonClicked);

	center.y += startButton.height() - 150;
	ToggledButton* _exitButton = new ToggledButton(exitButtonGlow, exitButton, center);
	QObject::connect(_exitButton, &ToggledButton::clicked,
		this, &GameMenuScene::exitButtonClicked);

	addItem(_startButton);
	addItem(_controlButton);
	addItem(_exitButton);

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
	emit exitApplication();
}

void GameMenuScene::controlButtonClicked() {
	emit goToControlSetup();
}

void GameMenuScene::startButtonClicked() {
	emit goToLevelSelect();
}

void GameMenuScene::keyPressEvent(QKeyEvent* event)
{
	_buttonGroup->keyPressEvent(event);
}
