#pragma once
#ifndef TESTACTIONS_H__
#define TESTACTIONS_H__

#include <windows.h>
#include <iostream>
#include "translateAction.h"
#include "holdAction.h"
#include "singleInputAction.h"
#include "keyboard.h"
#include "controller.h"
#include <vector>

class TestActions {
public:
	void testerSingleInput();
	void testerHold();
	void testerTranslate();
};



#endif

