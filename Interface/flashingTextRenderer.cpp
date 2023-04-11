#include "flashingTextRenderer.h"


FlashingTextRenderer::FlashingTextRenderer(QString setText, QGraphicsScene* setRenderScene, Coordinate corner, Coordinate dimensions, int flashDelay) :
    TextRenderer(setText, setRenderScene, corner, dimensions)
{
    setDefaultTextColor(Qt::white);
    showText = false;
    connectFlashingEvent(flashDelay);
}

FlashingTextRenderer::FlashingTextRenderer(QString setText, QGraphicsScene* setRenderScene, Coordinate centerPosition, int flashDelay) : 
   TextRenderer(setText, setRenderScene, centerPosition)
{
    setDefaultTextColor(Qt::white);
    showText = false;
    connectFlashingEvent(flashDelay);
}

void FlashingTextRenderer::connectFlashingEvent(int flashDelay) {
    QTimer* flashTimer = new QTimer();
    connect(flashTimer, &QTimer::timeout, this, &FlashingTextRenderer::flashText);
    flashTimer->start(flashDelay);
}

void FlashingTextRenderer::flashText()
{
    if(showText){
        setPlainText(text);
    }
    else{
        setPlainText(QString(""));
    }
    showText = !showText;
}
