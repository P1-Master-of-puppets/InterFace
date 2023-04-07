#ifndef INPUT_H__
#define INPUT_H__

#include "control.h"
typedef bool  (Control::* FunctionPtr)();
class Input {
private:
	Control* _control;
	FunctionPtr _function;
public:
	Input(Control* control, FunctionPtr function);
	bool getInput();
};

#endif // !INPUT_H__
