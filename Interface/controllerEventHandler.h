#ifndef CONTROLLEREVENTHANDLER_H
#define CONTROLLEREVENTHANDLER_H
#include <QApplication>
#include <QKeyEvent>
#include <QGraphicsView>

class ControllerEventHandler : public QObject {
	Q_OBJECT
private :
	QGraphicsView* _view;
public:
	ControllerEventHandler() {}
	void setGraphicsView(QGraphicsView* keyboardEvent);
public slots:
	void sendQevent(int eventType);
};

#endif // !CONTROLLEREVENTHANDLER_H
