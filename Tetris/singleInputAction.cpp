#include "singleInputAction.h"

SingleInputAction::SingleInputAction()
{
}

SingleInputAction::~SingleInputAction()
{
}

bool SingleInputAction::isActive()
{
    bool currentState = getCurrentState();
    if (currentState && !lastButtonState) {
        lastButtonState = true;
        return true;
    }

    if (!currentState && lastButtonState) {
        lastButtonState = false;
    }

    return false;
}
