#pragma once
#ifndef HOLDACTION_H__
#define HOLDACTION_H__

#include <chrono>
#include "action.h"


class HoldAction : public Action
{
protected:
	std::chrono::high_resolution_clock::time_point lastInput;
	bool lastButtonState = false;
	int interval;

public:
	HoldAction();
	HoldAction(int setInterval);
	virtual ~HoldAction();
	virtual bool isActive();
};
#endif // ! HOLDACTION_H__
