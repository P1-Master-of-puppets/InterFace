#include "pauseMenuRenderer.h"

PauseMenuRenderer::PauseMenuRenderer(ApplicationScene* renderScene) : _renderScene(renderScene)
{
	//Overlay filtre
	QPixmap overlayFilter(FILTER_IMAGE_PATH);
	_overlayFilterItem.setPixmap(overlayFilter.scaled(QSize(renderScene->width(), renderScene->height())));
	

	QPixmap resumeButton(START_BUTTON_IMAGE_PATH);
	QPixmap resumeButtonGlow(START_BUTTON_GLOW_IMAGE_PATH);

	QPixmap exitButton(EXIT_BUTTON_IMAGE_PATH);
	QPixmap exitButtonGlow(EXIT_BUTTON_GLOW_IMAGE_PATH);

	Coordinate center = ScreenMapper::fitImageInHorizontalMiddle(resumeButton.width(), _renderScene->width());

	_resumeButton = new ToggledButton(resumeButtonGlow, resumeButton, center);
	QObject::connect(_resumeButton, &ToggledButton::clicked,
		this, &PauseMenuRenderer::exitButtonClickedSlot);

	center.y += resumeButton.height() - 150;
	_exitButton = new ToggledButton(exitButtonGlow, exitButton, center);

	QObject::connect(_exitButton, &ToggledButton::clicked,
		this, &PauseMenuRenderer::resumeButtonClickedSlot);

	renderScene->addItem(&_overlayFilterItem);
	renderScene->addItem(_resumeButton);
	renderScene->addItem(_exitButton);


	_pauseButtonGroup = new ButtonGroup2D(2, 1);
	_pauseButtonGroup->setButton(0, 0, _resumeButton);
	_pauseButtonGroup->setButton(1, 0, _exitButton);

}

void PauseMenuRenderer::exitButtonClickedSlot() {
	dismiss();
	emit exitButtonClicked();
}

void PauseMenuRenderer::resumeButtonClickedSlot() {
	dismiss();
	emit resumeButtonClicked();
}

PauseMenuRenderer::~PauseMenuRenderer()
{
	dismiss();
	delete _pauseButtonGroup;
	delete _resumeButton;
	delete _exitButton;
}

void PauseMenuRenderer::dismiss()
{
	_renderScene->removeItem(_resumeButton);
	_renderScene->removeItem(_exitButton);
	_renderScene->removeItem(&_overlayFilterItem);
}

void PauseMenuRenderer::show() {
	_renderScene->addItem(_resumeButton);
	_renderScene->addItem(_exitButton);
	_renderScene->addItem(&_overlayFilterItem);
}


