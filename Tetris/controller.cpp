#include "controller.h"

void Controller::readThread()
{
	std::string input;

	int maxValue = 2;
	while (_isRunning)
	{
		char charBuffer[2];
		// This will read 
		int bufferSize = _arduino->readSerialPort(charBuffer, maxValue);
		input.append(charBuffer, bufferSize);
		//Make sure we only send 2 char at a time. Otherwise we might skip data and it will become extra weird
		if (input.length() >= 2)
		{
			char inputs[2];
			inputs[0] = input[0];
			inputs[1] = input[1];
			input.erase(0, 2);
			updateControllerValues(inputs);
		}
	}
}

void Controller::updateControllerValues(char buffer[]) {
	switch (buffer[0])
	{
	case 'L':
		setLeftTrigger(buffer[1] == '1');
		return;
	case 'R':
		setRightTrigger(buffer[1] == '1');
		return;
	case 'J':
		updateJoystickValues(buffer[1]);
		return;
	case 'A':
		setAButton(buffer[1] == '1');
		return;
	case 'B':
		setBButton(buffer[1] == '1');
		return;
	case 'M':
		setMenuButton(buffer[1] == '1');
		return;
	case 'G':
		setJoyStickButton(buffer[1] == '1');
		return;
	case 'Y':
		_fastDrop = true;
		return;
	default:
		break;
	}
}

void Controller::updateJoystickValues(char value) {
	setJoyStickUp(value == 'U');
	setJoyStickDown(value == 'D');
	setJoystickLeft(value == 'L');
	setJoyStickRight(value == 'R');
}

void Controller::setLeftTrigger(bool value)
{
	if (value)
		_lastInput = ControllerInputOutput::LeftTrigger;
	_leftTrigger = value;
	changedLeftTrigger(value);
}

void Controller::setRightTrigger(bool value)
{
	if (value)
		_lastInput = ControllerInputOutput::RightTrigger;
	_rightTrigger = value;
	changedRightTrigger(value);
}

void Controller::setJoyStickUp(bool value)
{
	if (value)
		_lastInput = ControllerInputOutput::JoyStickUp;
	_joyStickUp = value;
	changedJoyStickUp(value);
}

void Controller::setJoyStickDown(bool value)
{
	if (value)
		_lastInput = ControllerInputOutput::JoyStickDown;
	_joyStickDown = value;
	changedJoyStickDown(value);
}

void Controller::setJoystickLeft(bool value)
{
	if (value)
		_lastInput = ControllerInputOutput::JoyStickLeft;
	_joystickLeft = value;
	changedJoystickLeft(value);
}

void Controller::setJoyStickRight(bool value)
{
	if (value)
		_lastInput = ControllerInputOutput::JoyStickRight;
	_joyStickRight = value;
	changedJoyStickRight(value);
}

void Controller::setJoyStickButton(bool value)
{
	if (value)
		_lastInput = ControllerInputOutput::JoyStickButton;
	_joyStickButton = value;
	changedJoyStickButton(value);
}

void Controller::setAButton(bool value)
{
	if (value)
		_lastInput = ControllerInputOutput::AButton;
	_aButton = value;
	changedAButton(value);
}

void Controller::setBButton(bool value)
{
	if (value)
		_lastInput = ControllerInputOutput::BButton;
	_bButton = value;
	changedBButton(value);
}

void Controller::setMenuButton(bool value)
{
	_menuButton = value;
	changedMenuButton(value);
}

Controller::Controller(int cumport, int baudRate)
{
	_comport = cumport;
	_baudRate = baudRate;
	std::string port = "COM" + std::to_string(_comport);
	_arduino = new SerialPort(port.c_str(), _baudRate);
	if (!_arduino->isConnected())
		return;

	_isRunning = true;
	_communicationThread = std::thread(&Controller::readThread, this);
}

Controller::~Controller()
{
	_isRunning = false;
	// Wait for the thread to finish before destroying the object
	_communicationThread.join();
	delete _arduino;
}

bool Controller::getLeftTrigger()
{
	return _leftTrigger;
}

bool Controller::getRightTrigger()
{
	return _rightTrigger;
}

bool Controller::getJoyStickUp()
{
	return _joyStickUp;
}

bool Controller::getJoyStickDown()
{
	return _joyStickDown;
}

bool Controller::getJoystickLeft()
{
	return _joystickLeft;
}

bool Controller::getJoyStickRight()
{
	return _joyStickRight;
}

bool Controller::getJoyStickButton()
{
	return _joyStickButton;
}

bool Controller::getAButton()
{
	return _aButton;
}

bool Controller::getBButton()
{
	return _bButton;
}

bool Controller::getMenuButton()
{
	return _menuButton;
}

bool Controller::getInstantDrop()
{
	bool temp = _fastDrop;
	_fastDrop = false;
	return temp;
}

void Controller::vibrate(int milliseconds)
{
	if (milliseconds > 254 || milliseconds < 0)
		return;
	milliseconds++;
	char data[2];
	data[0] = 'V';
	//We send value + 1 because 0 is considered as \0 in char (end of string character)
	data[1] = milliseconds;
	_arduino->writeSerialPort(data, 2);
}

void Controller::updateSevenSegment(int twoDigitNumber)
{
	if (twoDigitNumber > 99 || twoDigitNumber < 0)
		return;
	twoDigitNumber++;
	char data[2];
	data[0] = 'S';
	//We send value + 1 because 0 is considered as \0 in char (end of string character)
	data[1] = twoDigitNumber;
	_arduino->writeSerialPort(data, 2);
}

void Controller::updateThreatIndicator(int threatLevel)
{
	if (threatLevel > 3 || threatLevel < 0)
		return;
	threatLevel++;
	char data[2];
	data[0] = 'T';
	//We send value + 1 because 0 is considered as \0 in char (end of string character)
	data[1] = threatLevel;
	_arduino->writeSerialPort(data, 2);
}

ControllerInputOutput Controller::getLastButtonPressed()
{
	_lastInput = ControllerInputOutput::None;

	// Wait for an other thread to change the value
	while (_lastInput == ControllerInputOutput::None)
	{
		//Put a sleep not to overload the CPU
		Sleep(5);
	}
	return _lastInput;
}

FunctionPtr Controller::controllerInputOutPutToFunctionPointer(ControllerInputOutput setting)
{
	switch (setting)
	{
	case ControllerInputOutput::LeftTrigger:
		return &Control::getLeftTrigger;
	case ControllerInputOutput::RightTrigger:
		return &Control::getRightTrigger;
	case ControllerInputOutput::JoyStickUp:
		return &Control::getJoyStickUp;
	case ControllerInputOutput::JoyStickDown:
		return &Control::getJoyStickDown;
	case ControllerInputOutput::JoyStickLeft:
		return &Control::getJoystickLeft;
	case ControllerInputOutput::JoyStickRight:
		return &Control::getJoyStickRight;
	case ControllerInputOutput::JoyStickButton:
		return &Control::getJoyStickButton;
	case ControllerInputOutput::AButton:
		return &Control::getAButton;
	case ControllerInputOutput::BButton:
		return &Control::getBButton;
	case ControllerInputOutput::Menu:
		return &Control::getMenuButton;
	default:
		break;
	}
	return FunctionPtr();
}

bool Controller::getIsRunning() {
	return _isRunning;
}

void Controller::changedLeftTrigger(bool value)
{
}

void Controller::changedRightTrigger(bool value)
{
}

void Controller::changedJoyStickUp(bool value)
{
}

void Controller::changedJoyStickDown(bool value)
{
}

void Controller::changedJoystickLeft(bool value)
{
}

void Controller::changedJoyStickRight(bool value)
{
}

void Controller::changedJoyStickButton(bool value)
{
}

void Controller::changedAButton(bool value)
{
}

void Controller::changedBButton(bool value)
{
}

void Controller::changedMenuButton(bool value)
{
}