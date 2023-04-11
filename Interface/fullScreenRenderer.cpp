#include "fullScreenRenderer.h"

FullScreenRenderer::FullScreenRenderer(QPixmap image, QGraphicsScene* setScene, QSize backgroundSize) : renderScene(setScene)
{
	setPixmap(image.scaled(backgroundSize));
	renderScene->addItem(this);
}

void FullScreenRenderer::remove()
{
	renderScene->removeItem(this);
}
