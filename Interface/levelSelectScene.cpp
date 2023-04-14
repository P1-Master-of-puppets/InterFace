#include "levelSelectScene.h"

LevelSelectScene::LevelSelectScene(QSize windowSize, QGraphicsView* applicationView) : ApplicationScene(windowSize)
{
	applicationView->grabKeyboard();
	QPixmap* backgroundImage = new QPixmap(BACKGROUND_IMAGE_PATH);
	QPixmap filtreImage(FILTER_IMAGE_PATH);
	QPainter painter(backgroundImage);
	painter.drawPixmap(0, 0, filtreImage);
	painter.end();
	setBackground(backgroundImage->copy());
	delete backgroundImage;

	QPixmap selectButton(LEVEL_SELECTION_GLOW_IMAGE_PATH);

	_levelSelection = new SelectButton(this, ScreenMapper::mapCoords(960, 540, windowSize.width(), windowSize.height()));
	QObject::connect(_levelSelection, &SelectButton::levelSelected, this, &LevelSelectScene::levelSelected);

}

void LevelSelectScene::keyPressEvent(QKeyEvent* event) {
	_levelSelection->keyPressEvent(event);
}

LevelSelectScene::~LevelSelectScene()
{
	delete _levelSelection;
}

void LevelSelectScene::levelSelected(int level) {
	emit goToMainGame(level);
}
