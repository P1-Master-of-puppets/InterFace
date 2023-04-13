#include "controlSelectionScene.h"

ControlSelectionScene::ControlSelectionScene(QSize windowSize) :ApplicationScene(windowSize) {
	QPixmap background(BACKGROUND_IMAGE_PATH);
	setBackground(background);

	QPixmap optionButton(CONTROL_OPTION_IMAGE_PATH);
	QPixmap optionButtonGlow(CONTROL_OPTION_GLOW_IMAGE_PATH);

	Coordinate leftBar = ScreenMapper::fitImageInHorisontalForth(optionButton.width(), windowSize.width(), 1);
	Coordinate rightBar = ScreenMapper::fitImageInHorisontalForth(optionButton.width(), windowSize.width(), 2);

	_translateLeftButton = new ControlSelectionButton(optionButtonGlow, optionButton, leftBar);
	QObject::connect(_translateLeftButton, &ToggledButton::clicked, this, &ControlSelectionScene::translateLeftOptionClicked);
	leftBar.y += 150;

	_translateRightButton = new ControlSelectionButton(optionButtonGlow, optionButton, leftBar);
	QObject::connect(_translateRightButton, &ToggledButton::clicked, this, &ControlSelectionScene::translateRightOptionClicked);
	leftBar.y += 150;

	_rotateRightButton = new ControlSelectionButton(optionButtonGlow, optionButton, leftBar);
	QObject::connect(_rotateRightButton, &ToggledButton::clicked, this, &ControlSelectionScene::rotateRightOptionClicked);
	leftBar.y += 150;

	_rotateLeftButton = new ControlSelectionButton(optionButtonGlow, optionButton, leftBar);
	QObject::connect(_rotateLeftButton, &ToggledButton::clicked, this, &ControlSelectionScene::rotateLeftOptionClicked);
	rightBar.y += 150;

	_dropInstantButton = new ControlSelectionButton(optionButtonGlow, optionButton, rightBar);
	QObject::connect(_dropInstantButton, &ToggledButton::clicked, this, &ControlSelectionScene::dropInstantOptionClicked);
	rightBar.y += 150;

	_dropFasterButton = new ControlSelectionButton(optionButtonGlow, optionButton, rightBar);
	QObject::connect(_dropFasterButton, &ToggledButton::clicked, this, &ControlSelectionScene::dropFasterOptionClicked);
	rightBar.y += 150;

	_holdPieceButton = new ControlSelectionButton(optionButtonGlow, optionButton, rightBar);
	QObject::connect(_holdPieceButton, &ToggledButton::clicked, this, &ControlSelectionScene::holdPieceOptionClicked);
	rightBar.y += 250;

	QPixmap _saveAndExit(EXIT_BUTTON_IMAGE_PATH);
	QPixmap _saveAndExitGlow(EXIT_BUTTON_GLOW_IMAGE_PATH);

	_saveAndExitButton = new ToggledButton(_saveAndExitGlow, _saveAndExit, rightBar);

	addItem(_translateLeftButton);
	addItem(_translateRightButton);
	addItem(_rotateRightButton);
	addItem(_rotateLeftButton);
	addItem(_dropInstantButton);
	addItem(_dropFasterButton);
	addItem(_holdPieceButton);
	addItem(_saveAndExitButton);

	_buttonGroup = new ButtonGroup2D(4, 2);
	_buttonGroup->setButton(0, 0, _translateLeftButton);
	_buttonGroup->setButton(0, 1, _translateRightButton);
	_buttonGroup->setButton(0, 2, _rotateRightButton);
	_buttonGroup->setButton(0, 3, _rotateLeftButton);

	_buttonGroup->setButton(1, 0, _dropInstantButton);
	_buttonGroup->setButton(1, 1, _dropFasterButton);
	_buttonGroup->setButton(1, 2, _holdPieceButton);
	_buttonGroup->setButton(1, 3, _saveAndExitButton);
}

ControlSelectionScene::~ControlSelectionScene() {

}


void ControlSelectionScene::translateLeftOptionClicked() {

}

void ControlSelectionScene::translateRightOptionClicked() {

}

void ControlSelectionScene::rotateRightOptionClicked() {

}

void ControlSelectionScene::rotateLeftOptionClicked() {

}

void ControlSelectionScene::dropInstantOptionClicked() {

}

void ControlSelectionScene::dropFasterOptionClicked() {

}

void ControlSelectionScene::holdPieceOptionClicked() {

}