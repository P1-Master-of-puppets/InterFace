#include "textRenderer.h"

void TextRenderer::updateText(int value)
{
    updateText(QString::number(value));
}

void TextRenderer::updateText(QString value)
{
    text = value;
    double previousWidth = boundingRect().width();
    setPlainText(text);
    moveBy(-(boundingRect().width() - previousWidth)/2,0);
}

void TextRenderer::remove()
{
    renderScene->removeItem(this);
}

TextRenderer::TextRenderer(QString setText, QGraphicsScene* setRenderScene, Coordinate corner, Coordinate dimensions) : text(setText), renderScene(setRenderScene)
{
    renderScene->addItem(this);

    QFont monospace(qApp->font().family(), renderScene->width() / 75);
    
    setPlainText(text);
    setDefaultTextColor(Qt::black);
    setFont(monospace);

    centerCoords.x = corner.x + dimensions.x / 2;
    centerCoords.y = corner.y + dimensions.y / 2;

    moveBy(centerCoords.x - boundingRect().width() / 2, centerCoords.y - boundingRect().height() / 2);

    updateText(text);
}

TextRenderer::TextRenderer(QString setText, QGraphicsScene* setRenderScene, Coordinate centerPosition) : text(setText), renderScene(setRenderScene), centerCoords(centerPosition)
{
    renderScene->addItem(this);
	//monospace.
    QFont monospace(qApp->font().family(), renderScene->width() / 75);

    setPlainText(text);
    setDefaultTextColor(Qt::black);
    setFont(monospace);

    moveBy(centerCoords.x - boundingRect().width()/2 , centerCoords.y - boundingRect().height()/2);

    updateText(text);
}

TextRenderer::~TextRenderer()
{
    renderScene->removeItem(this);
}
