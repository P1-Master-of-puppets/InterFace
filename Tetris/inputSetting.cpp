#include "inputSetting.h"

InputSetting::InputSetting()
{
	if (!readSettings("settings.json")) {
		translateLeft.push_back(ControllerInputOutput::JoyStickLeft);
		translateRight.push_back(ControllerInputOutput::JoyStickRight);
		rotateLeft.push_back(ControllerInputOutput::BButton);
		rotateRight.push_back(ControllerInputOutput::AButton);
		dropInstant.push_back(ControllerInputOutput::JoyStickButton);
		dropFaster.push_back(ControllerInputOutput::JoyStickDown);
		holdPiece.push_back(ControllerInputOutput::LeftTrigger);
		holdPiece.push_back(ControllerInputOutput::RightTrigger);
		writeSettings("settings.json");
	}
}

bool InputSetting::readSettings(std::string fileName)
{
	std::ifstream fichier(fileName);
	nlohmann::json myJson;

	if (!fichier.is_open()) {
		return false;
	}

	myJson = nlohmann::json::parse(fichier);

	for (int i = 0; i < myJson["translateLeft"].get<std::vector<ControllerInputOutput>>().size(); i++) {
		translateLeft.push_back(myJson["translateLeft"][i]);
	}

	for (int i = 0; i < myJson["translateRight"].get<std::vector<ControllerInputOutput>>().size(); i++) {
		translateRight.push_back(myJson["translateRight"][i]);
	}

	for (int i = 0; i < myJson["rotateLeft"].get<std::vector<ControllerInputOutput>>().size(); i++) {
		rotateLeft.push_back(myJson["rotateLeft"][i]);
	}

	for (int i = 0; i < myJson["rotateRight"].get<std::vector<ControllerInputOutput>>().size(); i++) {
		rotateRight.push_back(myJson["rotateRight"][i]);
	}

	for (int i = 0; i < myJson["dropInstant"].get<std::vector<ControllerInputOutput>>().size(); i++) {
		dropInstant.push_back(myJson["dropInstant"][i]);
	}

	for (int i = 0; i < myJson["dropFaster"].get<std::vector<ControllerInputOutput>>().size(); i++) {
		dropFaster.push_back(myJson["dropFaster"][i]);
	}

	for (int i = 0; i < myJson["holdPiece"].get<std::vector<ControllerInputOutput>>().size(); i++) {
		holdPiece.push_back(myJson["holdPiece"][i]);
	}

	accelerometer = myJson["accelerometer"];
	vibration = myJson["vibration"];
	fichier.close();
	return true;
}

bool InputSetting::writeSettings(std::string fileName)
{
	std::ofstream fichier(fileName);
	nlohmann::json myJson;

	if (!fichier.is_open()) {
		return false;
	}

	myJson["translateLeft"] = translateLeft;
	myJson["translateRight"] = translateRight;
	myJson["rotateRight"] = rotateRight;
	myJson["rotateLeft"] = rotateLeft;
	myJson["dropInstant"] = dropInstant;
	myJson["dropFaster"] = dropFaster;
	myJson["holdPiece"] = holdPiece;
	myJson["accelerometer"] = accelerometer;
	myJson["vibration"] = vibration;

	fichier << myJson.dump(4);
	fichier.close();

	return true;
}

bool InputSetting::alreadyExist(ControllerInputOutput input)
{
	for (int i = 0; i < translateLeft.size(); i++)
	{
		if (translateLeft[i] == input)
			return true;
	}

	for (int i = 0; i < translateRight.size(); i++)
	{
		if (translateRight[i] == input)
			return true;
	}
	for (int i = 0; i < rotateRight.size(); i++)
	{
		if (rotateRight[i] == input)
			return true;
	}
	for (int i = 0; i < rotateLeft.size(); i++)
	{
		if (rotateLeft[i] == input)
			return true;
	}
	for (int i = 0; i < dropInstant.size(); i++)
	{
		if (dropInstant[i] == input)
			return true;
	}
	for (int i = 0; i < holdPiece.size(); i++)
	{
		if (holdPiece[i] == input)
			return true;
	}
	for (int i = 0; i < dropFaster.size(); i++)
	{
		if (dropFaster[i] == input)
			return true;
	}
	return false;
}
