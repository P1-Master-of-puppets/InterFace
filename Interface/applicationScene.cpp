#include "applicationScene.h"

ApplicationScene::ApplicationScene(QSize size, QObject* parent) : QGraphicsScene(parent)
{
	_background = new QGraphicsPixmapItem();
	_sceneSize = size;
}

ApplicationScene::~ApplicationScene()
{
	removeItem(_background);
	delete _background;
}

void ApplicationScene::setBackground(QPixmap image)
{
	_background->setPixmap(image.scaled(_sceneSize));
	addItem(_background);
}