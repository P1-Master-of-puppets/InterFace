#include "controlSelectionScene.h"

ControlSelectionScene::ControlSelectionScene(QSize windowSize) :ApplicationScene(windowSize) {
#pragma region BackgroundSetup
	QPixmap* backgroundImage = new QPixmap(BACKGROUND_IMAGE_PATH);
	QPixmap filtreImage(FILTER_IMAGE_PATH);
	QPainter painter(backgroundImage);
	painter.drawPixmap(0, 0, filtreImage);
	painter.end();
	setBackground(backgroundImage->copy());
	delete backgroundImage;
#pragma endregion

	QPixmap optionButton(CONTROL_OPTION_IMAGE_PATH);
	QPixmap optionButtonGlow(CONTROL_OPTION_GLOW_IMAGE_PATH);

	Coordinate leftBar = ScreenMapper::fitImageInHorisontalForth(optionButton.width(), windowSize.width(), 1);
	Coordinate rightBar = ScreenMapper::fitImageInHorisontalForth(optionButton.width(), windowSize.width(), 2);
	leftBar.y += 100;
	rightBar.y += 100;

	_translateLeftButton = new ControlSelectionButton("Translate Left", optionButtonGlow, optionButton, leftBar);
	_translateLeftButton->setSettings(_inputSetting.translateLeft);
	QObject::connect(_translateLeftButton, &ToggledButton::clicked, this, &ControlSelectionScene::translateLeftOptionClicked);
	QObject::connect(_translateLeftButton, &ToggledButton::secondClicked, this, &ControlSelectionScene::translateLeftDeleteClicked);
	leftBar.y += 150;

	_translateRightButton = new ControlSelectionButton("Translate Right", optionButtonGlow, optionButton, leftBar);
	_translateRightButton->setSettings(_inputSetting.translateRight);
	QObject::connect(_translateRightButton, &ToggledButton::clicked, this, &ControlSelectionScene::translateRightOptionClicked);
	QObject::connect(_translateRightButton, &ToggledButton::secondClicked, this, &ControlSelectionScene::translateRightDeleteClicked);
	leftBar.y += 150;

	_rotateRightButton = new ControlSelectionButton("Rotate Right", optionButtonGlow, optionButton, leftBar);
	_rotateRightButton->setSettings(_inputSetting.rotateRight);
	QObject::connect(_rotateRightButton, &ToggledButton::clicked, this, &ControlSelectionScene::rotateRightOptionClicked);
	QObject::connect(_rotateRightButton, &ToggledButton::secondClicked, this, &ControlSelectionScene::rotateRightDeleteClicked);
	leftBar.y += 150;

	_rotateLeftButton = new ControlSelectionButton("Rotate Left", optionButtonGlow, optionButton, leftBar);
	_rotateLeftButton->setSettings(_inputSetting.rotateLeft);
	QObject::connect(_rotateLeftButton, &ToggledButton::clicked, this, &ControlSelectionScene::rotateLeftOptionClicked);
	QObject::connect(_rotateLeftButton, &ToggledButton::secondClicked, this, &ControlSelectionScene::rotateLeftDeleteClicked);

	_dropInstantButton = new ControlSelectionButton("Drop Instant", optionButtonGlow, optionButton, rightBar);
	_dropInstantButton->setSettings(_inputSetting.dropInstant);
	QObject::connect(_dropInstantButton, &ToggledButton::clicked, this, &ControlSelectionScene::dropInstantOptionClicked);
	QObject::connect(_dropInstantButton, &ToggledButton::secondClicked, this, &ControlSelectionScene::dropInstantDeleteClicked);
	rightBar.y += 150;

	_dropFasterButton = new ControlSelectionButton("Drop Faster", optionButtonGlow, optionButton, rightBar);
	_dropFasterButton->setSettings(_inputSetting.dropFaster);
	QObject::connect(_dropFasterButton, &ToggledButton::clicked, this, &ControlSelectionScene::dropFasterOptionClicked);
	QObject::connect(_dropFasterButton, &ToggledButton::secondClicked, this, &ControlSelectionScene::dropFasterDeleteClicked);
	rightBar.y += 150;

	_holdPieceButton = new ControlSelectionButton("Hold", optionButtonGlow, optionButton, rightBar);
	_holdPieceButton->setSettings(_inputSetting.holdPiece);
	QObject::connect(_holdPieceButton, &ToggledButton::clicked, this, &ControlSelectionScene::holdPieceOptionClicked);
	QObject::connect(_holdPieceButton, &ToggledButton::secondClicked, this, &ControlSelectionScene::holdPieceDeleteClicked);

	QPixmap _saveAndExit(EXIT_BUTTON_IMAGE_PATH);
	QPixmap _saveAndExitGlow(EXIT_BUTTON_GLOW_IMAGE_PATH);

	Coordinate center = ScreenMapper::fitImageInHorizontalMiddle(_saveAndExit.width(), windowSize.width());
	center.y = rightBar.y + 250;
	_saveAndExitButton = new ToggledButton(_saveAndExitGlow, _saveAndExit, center);
	QObject::connect(_saveAndExitButton, &ToggledButton::clicked, this, &ControlSelectionScene::exitPage);

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
	delete _buttonGroup;
}


void ControlSelectionScene::translateLeftOptionClicked() {
	if (SceneManager::controller == nullptr)
		return;
	//Put menu all dark and wait for button
	ControllerInputOutput input = waitForInput();
	if (!_inputSetting.alreadyExist(input))
		_inputSetting.translateLeft.push_back(input);
	_translateLeftButton->setSettings(_inputSetting.translateLeft);
}

void ControlSelectionScene::translateRightOptionClicked() {
	if (SceneManager::controller == nullptr)
		return;
	ControllerInputOutput input = waitForInput();
	if (!_inputSetting.alreadyExist(input))
		_inputSetting.translateRight.push_back(input);
	_translateRightButton->setSettings(_inputSetting.translateRight);
}

void ControlSelectionScene::rotateRightOptionClicked() {
	if (SceneManager::controller == nullptr)
		return;
	ControllerInputOutput input = waitForInput();
	if (!_inputSetting.alreadyExist(input))
		_inputSetting.rotateRight.push_back(input);
	_rotateRightButton->setSettings(_inputSetting.rotateRight);
}

void ControlSelectionScene::rotateLeftOptionClicked() {
	if (SceneManager::controller == nullptr)
		return;
	ControllerInputOutput input = waitForInput();
	if (!_inputSetting.alreadyExist(input))
		_inputSetting.rotateLeft.push_back(input);
	_rotateLeftButton->setSettings(_inputSetting.rotateLeft);
}

void ControlSelectionScene::dropInstantOptionClicked() {
	if (SceneManager::controller == nullptr)
		return;
	ControllerInputOutput input = waitForInput();
	if (!_inputSetting.alreadyExist(input))
		_inputSetting.dropInstant.push_back(input);
	_dropInstantButton->setSettings(_inputSetting.dropInstant);
}

void ControlSelectionScene::dropFasterOptionClicked() {
	if (SceneManager::controller == nullptr)
		return;
	ControllerInputOutput input = waitForInput();
	if (!_inputSetting.alreadyExist(input))
		_inputSetting.dropFaster.push_back(input);
	_dropFasterButton->setSettings(_inputSetting.dropFaster);
}

void ControlSelectionScene::holdPieceOptionClicked() {
	if (SceneManager::controller == nullptr)
		return;
	ControllerInputOutput input = waitForInput();
	if (!_inputSetting.alreadyExist(input))
		_inputSetting.holdPiece.push_back(input);
	_holdPieceButton->setSettings(_inputSetting.holdPiece);
}

void ControlSelectionScene::translateLeftDeleteClicked()
{
	_inputSetting.translateLeft.clear();
	_translateLeftButton->setSettings(_inputSetting.translateLeft);
}

void ControlSelectionScene::translateRightDeleteClicked()
{
	_inputSetting.translateRight.clear();
	_translateRightButton->setSettings(_inputSetting.translateRight);
}

void ControlSelectionScene::rotateRightDeleteClicked()
{
	_inputSetting.rotateRight.clear();
	_rotateRightButton->setSettings(_inputSetting.rotateRight);
}

void ControlSelectionScene::rotateLeftDeleteClicked()
{
	_inputSetting.rotateLeft.clear();
	_rotateLeftButton->setSettings(_inputSetting.rotateLeft);
}

void ControlSelectionScene::dropInstantDeleteClicked()
{
	_inputSetting.dropInstant.clear();
	_dropInstantButton->setSettings(_inputSetting.dropInstant);
}

void ControlSelectionScene::dropFasterDeleteClicked()
{
	_inputSetting.dropFaster.clear();
	_dropFasterButton->setSettings(_inputSetting.dropFaster);
}

void ControlSelectionScene::holdPieceDeleteClicked()
{
	_inputSetting.holdPiece.clear();
	_holdPieceButton->setSettings(_inputSetting.holdPiece);
}

void ControlSelectionScene::exitPage()
{
	_inputSetting.writeSettings("settings.json");
	emit goToMainMenu();
}

ControllerInputOutput ControlSelectionScene::waitForInput()
{
	QPixmap backgroundImage = QPixmap(FILTER_IMAGE_PATH);
	QGraphicsPixmapItem* backgroundGraphics = new QGraphicsPixmapItem();
	backgroundGraphics->setPixmap(backgroundImage.scaled(_sceneSize));
	addItem(backgroundGraphics);

	SceneManager::controller->disableKeyboardEvent();
	ControllerInputOutput input = SceneManager::controller->getLastButtonPressed();
	SceneManager::controller->enableKeyBoardEvent();

	removeItem(backgroundGraphics);
	delete backgroundGraphics;
	return input;
}

void ControlSelectionScene::keyPressEvent(QKeyEvent* event)
{
	_buttonGroup->keyPressEvent(event);
}
