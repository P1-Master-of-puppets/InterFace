#include "fullScreenRenderer.h"

FullScreenRenderer::FullScreenRenderer(QString fileName, QGraphicsScene* setScene,QSize backgroundSize) : renderScene(setScene)
{
	QPixmap monPixmap(fileName);
	QPixmap scaled = monPixmap.scaled(backgroundSize);
	setPixmap(scaled);
	renderScene->addItem(this);
}

void FullScreenRenderer::remove()
{
	renderScene->removeItem(this);
}
