#ifndef FLASHINGTEXT_H
#define FLASHINGTEXT_H

#include <QObject>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QFontDatabase>
#include <QGraphicsView>

class FlashingText : public QGraphicsTextItem
{
    Q_OBJECT

public:
    FlashingText(QString setText, QGraphicsView* mainView);


private slots:

    void flashText();


private:
    QString text;
    bool showText;
    QGraphicsScene* scene;

};

#endif // FLASHINGTEXT_H
