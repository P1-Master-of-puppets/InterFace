#include "input.h"

Input::Input(Control* control, FunctionPtr function)
{
	_control = control;
	_function = function;
}

bool Input::getInput()
{;
	return (_control->*_function)();
}
