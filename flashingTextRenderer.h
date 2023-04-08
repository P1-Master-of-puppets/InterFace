#ifndef FLASHINGTEXTRENDERER_H
#define FLASHINGTEXTRENDERER_H

#include <QObject>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QFontDatabase>
#include <QGraphicsView>
#include "textRenderer.h"

class FlashingTextRenderer : public TextRenderer
{
   
public:
    //Centers the text in a box with up left corner and dimensions
    FlashingTextRenderer(QString setText, QGraphicsScene* setRenderScene, Coordinate corner, Coordinate dimensions, int flashDelay);

    //Places the text's center on centerPosition
    FlashingTextRenderer(QString setText, QGraphicsScene* setRenderScene, Coordinate centerPosition, int flashDelay);


private slots:

    void flashText();


private:
    void connectFlashingEvent(int flashDelay);
    bool showText;

};

#endif // FLASHINGTEXTRENDERER_H
