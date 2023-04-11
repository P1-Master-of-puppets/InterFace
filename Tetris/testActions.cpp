#include "testActions.h"

void TestActions::testerSingleInput()
{
	Controller* keyboard = new Controller(7, 115200);
	SingleInputAction monAction;
	monAction.addInput(new Input(keyboard, &Control::getAButton));


	while (1) {

		if (monAction.isActive()) {
			std::cout << "Input" << std::endl;
		}
	}

	delete keyboard;
}

void TestActions::testerHold()
{
	Keyboard* keyboard = new Keyboard();
	HoldAction monAction;
	monAction.addInput(new Input(keyboard, &Control::getInstantDrop));


	while (1) {

		if (monAction.isActive()) {
			std::cout << "Input" << std::endl;
		}
	}
	delete keyboard;
}

void TestActions::testerTranslate()
{
	Keyboard* keyboard = new Keyboard();
	TranslateAction monAction;
	monAction.addInput(new Input(keyboard, &Control::getInstantDrop));


	while (1) {

		if (monAction.isActive()) {
			std::cout << "Input" << std::endl;
		}
	}
	delete keyboard;
}
