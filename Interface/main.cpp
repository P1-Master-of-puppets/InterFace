#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QScreen>
#include <QList>
#include "assets.h"

#include "sceneManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    int id = QFontDatabase::addApplicationFont(FONT_PATH);
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont _font(family, 8);
    qApp->setFont(_font);

    ////Configures the windows sizes and properties (Fits different screens)
    QGraphicsView* mainView = new QGraphicsView();
    QList<QScreen*> screens = QGuiApplication::screens();
    mainView->setFixedSize(screens.first()->availableSize());
    mainView->showFullScreen();
    mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainView->setFrameStyle(QFrame::NoFrame);
    
    SceneManager mainManager(mainView);
    mainView->show();

    return a.exec();
}
