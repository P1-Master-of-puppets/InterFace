#include "gameActions.h"

void GameActions::initKeyboardSettings()
{
	translateLeftAction.addInput(new Input(_keyboard, &Control::getJoystickLeft));
	translateRightAction.addInput(new Input(_keyboard, &Control::getJoyStickRight));
	rotateLeftAction.addInput(new Input(_keyboard, &Control::getLeftTrigger));
	rotateRightAction.addInput(new Input(_keyboard, &Control::getRightTrigger));
	dropFasterAction.addInput(new Input(_keyboard, &Control::getAButton));
	dropInstantAction.addInput(new Input(_keyboard, &Control::getJoyStickButton));
	menuAction.addInput(new Input(_keyboard, &Control::getMenuButton));
	holdPieceAction.addInput(new Input(_keyboard, &Control::getBButton));
}

GameActions::GameActions(Controller* controller, Keyboard* keyboard)
{
	_controller = controller;
	_keyboard = keyboard;
	initKeyboardSettings();
	InputSetting settingTemps;
	loadSettings(settingTemps);
}

GameActions::GameActions(Keyboard* keyboard)
{
	_controller = nullptr;
	_keyboard = keyboard;
	initKeyboardSettings();
}

GameActions::~GameActions()
{
}

void GameActions::initAllActions()
{
	translateLeft();
	translateRight();
	rotateRight();
	rotateLeft();
	dropFaster();
	dropInstant();
	menu();
	holdPiece();
}

bool GameActions::translateLeft()
{
	return translateLeftAction.isActive();
}

bool GameActions::translateRight()
{
	return translateRightAction.isActive();
}

bool GameActions::rotateRight()
{
	return rotateRightAction.isActive();
}

bool GameActions::rotateLeft()
{
	return rotateLeftAction.isActive();
}

bool GameActions::dropFaster()
{
	return dropFasterAction.isActive();
}

bool GameActions::dropInstant()
{
	return dropInstantAction.isActive();
}

bool GameActions::menu()
{
	return menuAction.isActive();
}

void GameActions::addInputsToAction(Action* action, std::vector<ControllerInputOutput> newSettings)
{
	for (int i = 0; i < newSettings.size(); i++)
	{
		action->addInput(new Input(_controller, Controller::controllerInputOutPutToFunctionPointer(newSettings[i])));
	}
}

void GameActions::loadSettings(InputSetting setting)
{
	if (_controller == nullptr)
		return;

	addInputsToAction(&translateLeftAction, setting.translateLeft);
	addInputsToAction(&translateRightAction, setting.translateRight);
	addInputsToAction(&rotateLeftAction, setting.rotateLeft);
	addInputsToAction(&rotateRightAction, setting.rotateRight);
	addInputsToAction(&dropFasterAction, setting.dropFaster);
	addInputsToAction(&dropInstantAction, setting.dropInstant);
	addInputsToAction(&holdPieceAction, setting.holdPiece);
}

bool GameActions::holdPiece()
{
	return holdPieceAction.isActive();
}
