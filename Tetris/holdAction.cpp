#include "holdAction.h"

using namespace std::chrono;

HoldAction::HoldAction()
{
	interval = 100;
    lastInput = high_resolution_clock::now() - milliseconds(interval);
}

HoldAction::HoldAction(int setInterval) : interval(setInterval)
{
    lastInput = high_resolution_clock::now() - milliseconds(interval);
}

HoldAction::~HoldAction()
{
}

bool HoldAction::isActive()
{
    bool currentState = getCurrentState();
    if (currentState && !lastButtonState) {
        lastButtonState = true;
        lastInput = high_resolution_clock::now();
        return true;
    }

    if (currentState && lastButtonState &&
        milliseconds(interval) < high_resolution_clock::now() - lastInput ) {
        lastInput = high_resolution_clock::now();
        return true;
    }

    if (!currentState && lastButtonState) {
        lastButtonState = false;
    }

    return false;
}
