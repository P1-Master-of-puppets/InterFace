
#pragma once
#ifndef INPUTSETTING_H__
#define INPUTSETTING_H__

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "controllerInputOutput.h"

class InputSetting {
public:
	InputSetting();
	bool readSettings(std::string fileName);
	bool writeSettings(std::string fileName);
	std::vector<ControllerInputOutput> translateLeft;
	std::vector<ControllerInputOutput> translateRight;
	std::vector<ControllerInputOutput> rotateRight;
	std::vector<ControllerInputOutput> rotateLeft;
	std::vector<ControllerInputOutput> dropInstant;
	std::vector<ControllerInputOutput> dropFaster;
	std::vector<ControllerInputOutput> holdPiece;
	bool accelerometer;
	bool vibration;
};

#endif // !SETTING_H__