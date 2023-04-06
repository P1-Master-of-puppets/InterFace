#include "textcounter.h"

TextCounter::TextCounter(QString setText, QGraphicsView* mainView, QString role): text(setText)
{
    int id = QFontDatabase::addApplicationFont("assets/Quinquefive-K7qep.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont monospace(family, mainView->width()/75);

    setPlainText(text);
    setDefaultTextColor(Qt::black);
    setFont(monospace);

    double XScaleFactor = 0.1953125;
    double XScaledOffset = mainView->width() * XScaleFactor - boundingRect().width()/2;

    double YScaleFactor[3] = {0.71018518, 0.89629629, 0.52407407};
    double YScaledOffset = boundingRect().height()/2;

    if(role == "tetris"){
        moveBy(XScaledOffset, mainView->height() * YScaleFactor[0] - YScaledOffset);
    }
    else if(role == "level"){
        moveBy(XScaledOffset, mainView->height() * YScaleFactor[1] - YScaledOffset);
    }
    else if(role == "score"){
        moveBy(XScaledOffset, mainView->height() * YScaleFactor[2] - YScaledOffset);
    }


}

void TextCounter::updateText(int value)
{
    updateText(QString::number(value));
}

void TextCounter::updateText(QString value)
{
    text = value;
    double previousWidth = boundingRect().width();
    setPlainText(text);
    moveBy(-(boundingRect().width() - previousWidth)/2,0);
}
