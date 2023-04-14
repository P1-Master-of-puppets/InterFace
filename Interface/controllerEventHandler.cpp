#include "controllerEventHandler.h"

void ControllerEventHandler::sendQevent(int eventType)
{
	QKeyEvent* key = nullptr;

	switch (eventType)
	{
	case 1:
		key = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Up, Qt::NoModifier, "Enter", false, 0);
		break;
	case 2:
		key = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Down, Qt::NoModifier, "Enter", false, 0);
		break;
	case 3:
		key = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Left, Qt::NoModifier, "Enter", false, 0);
		break;
	case 4:
		key = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Right, Qt::NoModifier, "Enter", false, 0);
		break;
	case 5:
		key = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier, "Enter", false, 0);
		break;
	case 6:
		key = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Delete, Qt::NoModifier, "Enter", false, 0);
		break;
	case 7:
		key = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_M, Qt::NoModifier, "Enter", false, 0);
		break;
	default:
		break;
	}
	QCoreApplication::postEvent(_view, key);
}

void ControllerEventHandler::setGraphicsView(QGraphicsView* keyboardEvent)
{
	_view = keyboardEvent;
}
