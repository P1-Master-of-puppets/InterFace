#pragma once
#ifndef SINGLEINPUTACTION_H__
#define SINGLEINPUTACTION_H__

#include <chrono>
#include "action.h"

using namespace std::chrono;

class SingleInputAction : public Action
{
private:
	bool lastButtonState = false;
public:
	SingleInputAction();
	virtual ~SingleInputAction();
	virtual bool isActive();
};
#endif // ! SINGLEINPUTACTION_H__