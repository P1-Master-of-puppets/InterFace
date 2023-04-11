#ifndef TEXTCOUNTER_H
#define TEXTCOUNTER_H


#include <QObject>
#include <QString>
#include <QGraphicsTextItem>
#include <QFont>
#include <QFontDatabase>
#include <QGraphicsView>

class TextCounter : public QGraphicsTextItem
{
public:
    TextCounter(QString setText, QGraphicsView* mainView, QString role);

    void updateText(int value);
    void updateText(QString value);


private:
    QString text;
};

#endif // TEXTCOUNTER_H
