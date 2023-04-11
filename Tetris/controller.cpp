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
		_leftTrigger = buffer[1] == '1';
		_lastInput = ControllerInputOutput::LeftTrigger;
		return;
	case 'R':
		_rightTrigger = buffer[1] == '1';
		_lastInput = ControllerInputOutput::RightTrigger;
		return;
	case 'J':
		updateJoystickValues(buffer[1]);
		return;
	case 'A':
		_aButton = buffer[1] == '1';
		_lastInput = ControllerInputOutput::AButton;
		return;
	case 'B':
		_bButton = buffer[1] == '1';
		_lastInput = ControllerInputOutput::BButton;
		return;
	case 'M':
		_menuButton = buffer[1] == '1';
		return;
	case 'G':
		_joyStickButton = buffer[1] == '1';
		_lastInput = ControllerInputOutput::JoyStickButton;
		return;
	case 'Y':
		_fastDrop = true;
		return;
	default:
		break;
	}
}

void Controller::updateJoystickValues(char value) {
	_joyStickUp = value == 'U';
	_joyStickDown = value == 'D';
	_joystickLeft = value == 'L';
	_joyStickRight = value == 'R';
	switch (value)
	{
	case 'U':
		_lastInput = ControllerInputOutput::JoyStickUp;
		break;
	case 'D':
		_lastInput = ControllerInputOutput::JoyStickDown;
		break;
	case 'L':
		_lastInput = ControllerInputOutput::JoyStickLeft;
		break;
	case 'R':
		_lastInput = ControllerInputOutput::JoyStickRight;
		break;
	}
}

Controller::Controller(int cumport, int baudRate)
{
	_comport = cumport;
	_baudRate = baudRate;
	std::string port = "COM" + std::to_string(_comport);
	_arduino = new SerialPort(port.c_str(), _baudRate);
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
