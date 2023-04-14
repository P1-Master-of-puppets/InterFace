#include "qGameController.h"

QGameController::QGameController(int cumport, int baudRate) : Controller(cumport, baudRate)
{

}

void QGameController::disableKeyboardEvent()
{
	_sendQevent = false;
}

void QGameController::enableKeyBoardEvent()
{
	_sendQevent = true;
}

void QGameController::changedLeftTrigger(bool value)
{
}

void QGameController::changedRightTrigger(bool value)
{
}

void QGameController::changedJoyStickUp(bool value)
{
	if (value)
		sendKeyBoardEvent(1);
}

void QGameController::changedJoyStickDown(bool value)
{
	if (value)
		sendKeyBoardEvent(2);
}

void QGameController::changedJoystickLeft(bool value)
{
	if (value)
		sendKeyBoardEvent(3);
}

void QGameController::changedJoyStickRight(bool value)
{
	if (value)
		sendKeyBoardEvent(4);
}

void QGameController::changedJoyStickButton(bool value)
{
}

void QGameController::changedAButton(bool value)
{
	if (value)
		sendKeyBoardEvent(5);
}

void QGameController::changedBButton(bool value)
{
	if (value)
		sendKeyBoardEvent(6);
}

void QGameController::changedMenuButton(bool value)
{
	if (value)
		sendKeyBoardEvent(7);
}

void QGameController::setSceneManager(ControllerEventHandler* eventHandler)
{
	_eventHandler = eventHandler;
}


/// Buttons 
void QGameController::sendKeyBoardEvent(int eventKey)
{
	bool sent = QMetaObject::invokeMethod(_eventHandler, "sendQevent", Qt::QueuedConnection, Q_ARG(int, eventKey));
}


