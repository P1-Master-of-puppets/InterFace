#ifndef GAME_ACTIONS_H__
#define GAME_ACTIONS_H__

#include <chrono>
#include "action.h"
#include "holdAction.h"
#include "singleInputAction.h"
#include "translateAction.h"
#include "inputSetting.h"
#include "keyboard.h"
#include "controller.h"
#include "controllerInputOutput.h"

using namespace std::chrono;

class GameActions
{
private:
	TranslateAction translateLeftAction;
	TranslateAction translateRightAction;
	SingleInputAction rotateRightAction;
	SingleInputAction rotateLeftAction;
	HoldAction dropFasterAction;
	SingleInputAction dropInstantAction;
	SingleInputAction menuAction;
	SingleInputAction holdPieceAction;

	Control* _controller;
	Control* _keyboard;

	void initKeyboardSettings();
public:
	GameActions(Controller* controller, Keyboard* keyboard);
	GameActions(Keyboard* keyboard);
	~GameActions();
	bool translateLeft();
	bool translateRight();
	bool rotateRight();
	bool rotateLeft();
	bool dropFaster();
	bool dropInstant();
	bool menu();
	bool holdPiece();
	void addInputsToAction(Action* action, std::vector<ControllerInputOutput> controls);
	void loadSettings(InputSetting setting);

};

#endif