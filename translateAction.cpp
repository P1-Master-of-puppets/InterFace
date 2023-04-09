#include "translateAction.h"

using namespace std::chrono;

TranslateAction::TranslateAction() : HoldAction(100)
{
	initialInterval = 500;
	lastInput = high_resolution_clock::now() - milliseconds(initialInterval);
	initialPress = true;
}

TranslateAction::TranslateAction(int setInitialInterval, int setInterval) : HoldAction(setInterval), initialInterval(setInitialInterval)
{
	initialPress = true;
	lastInput = high_resolution_clock::now() - milliseconds(initialInterval);
}

TranslateAction::~TranslateAction()
{
}

bool TranslateAction::isActive()
{
	bool currentState = getCurrentState();
	if (currentState && !lastButtonState) {
		lastButtonState = true;
		lastInput = high_resolution_clock::now();
		return true;
	}

	if (currentState && lastButtonState &&
		milliseconds(initialInterval) < high_resolution_clock::now() - lastInput &&
		initialPress) {
		lastInput = high_resolution_clock::now();
		initialPress = false;
		return true;
	}
	else if (currentState && lastButtonState &&
		milliseconds(interval) < high_resolution_clock::now() - lastInput &&
		!initialPress) {
		lastInput = high_resolution_clock::now();
		return true;
	}

	if (!currentState && lastButtonState) {
		initialPress = true;
		lastButtonState = false;
	}

	return false;
}
