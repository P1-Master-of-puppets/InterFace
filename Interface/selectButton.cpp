#include "selectButton.h"

SelectButton::SelectButton(ApplicationScene* renderScene, Coordinate centerCoords, QGraphicsItem* parent)
{
	_level = 0;
	QPixmap selectImage(LEVEL_SELECTION_GLOW_IMAGE_PATH);
	setPixmap(selectImage);
	Coordinate a = ScreenMapper::fitImageInHorizontalMiddle(selectImage.width(), renderScene->width());
	setPos(a.x, a.y+180);
	renderScene->addItem(this);
	_levelText = new TextRenderer(QString("."), renderScene, centerCoords);
	_levelText->updateText(_level);
}


SelectButton::~SelectButton()
{
}

void SelectButton::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Enter ||
		event->key() == Qt::Key_Return) {
		GameSoundPlayer::playSelect();
		emit levelSelected(_level);
	}
	else if (event->key() == Qt::Key_Right) {
		GameSoundPlayer::playTic();
		_level++;
		if (_level > 9)
			_level = 9;
		_levelText->updateText(_level);
	}
	else if (event->key() == Qt::Key_Left) {
		GameSoundPlayer::playTic();
		_level--;
		if (_level < 0)
			_level = 0;
		_levelText->updateText(_level);
	}
}
