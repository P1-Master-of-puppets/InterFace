#pragma once
#ifndef QGAMECONTROLLER_H
#define QGAMECONTROLLER_H
#include "controller.h"
#include "QApplication"
#include "QKeyEvent"
#include "controllerEventHandler.h"

class QGameController : public Controller {
private:
	bool _sendQevent = false;
	ControllerEventHandler* _eventHandler;
public:
	QGameController(int cumport, int baudRate);
	void disableKeyboardEvent();
	void enableKeyBoardEvent();
	void changedLeftTrigger(bool value);
	void changedRightTrigger(bool value);
	void changedJoyStickUp(bool value);
	void changedJoyStickDown(bool value);
	void changedJoystickLeft(bool value);
	void changedJoyStickRight(bool value);
	void changedJoyStickButton(bool value);
	void changedAButton(bool value);
	void changedBButton(bool value);
	void changedMenuButton(bool value);
	void setSceneManager(ControllerEventHandler* eventHandler);
	void sendKeyBoardEvent(int eventKey);
};
#endif // !QGAMECONTROLLER_H
