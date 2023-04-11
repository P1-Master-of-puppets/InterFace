#pragma once
#ifndef CONTROL_H__
#define CONTROL_H__

class Control {
public:
	virtual bool getLeftTrigger() = 0;
	virtual bool getRightTrigger() = 0;
	virtual bool getJoyStickUp() = 0;
	virtual bool getJoyStickDown() = 0;
	virtual bool getJoystickLeft() = 0;
	virtual bool getJoyStickRight() = 0;
	virtual bool getJoyStickButton() = 0;
	virtual bool getAButton() = 0;
	virtual bool getBButton() = 0;
	virtual bool getMenuButton() = 0;
	virtual bool getInstantDrop() = 0;
};

#endif // !CONTROL_H__
