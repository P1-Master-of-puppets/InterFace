#include "flashingtext.h"

FlashingText::FlashingText(QString setText, QGraphicsView* mainView) : text(setText)
{
    int id = QFontDatabase::addApplicationFont("assets/Quinquefive-K7qep.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont monospace(family, 16);

    showText = false;
    setPlainText(text);
    setDefaultTextColor(Qt::white);
    setFont(monospace);
    moveBy(mainView->width()/2 - boundingRect().width()/2 ,mainView->height() - boundingRect().height() - 25);


    QTimer* flashTimer = new QTimer();
    connect(flashTimer, &QTimer::timeout, this, &FlashingText::flashText);
    flashTimer->start(750);

}

void FlashingText::flashText()
{
    if(showText){
        setPlainText(text);
    }
    else{
        setPlainText(QString(""));
    }
    showText = !showText;
}
