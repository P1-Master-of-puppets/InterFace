#ifndef HOLDACTION_H__
#define HOLDACTION_H__
#include "action.h"
#include <chrono>

using namespace std::chrono;

class HoldAction : public Action
{
protected:
	high_resolution_clock::time_point lastInput;
	bool lastButtonState = false;
	int interval;

public:
	HoldAction();
	HoldAction(int setInterval);
	virtual ~HoldAction();
	virtual bool isActive();
};
#endif // ! HOLDACTION_H__
