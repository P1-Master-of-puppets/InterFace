#include "action.h"

bool Action::getCurrentState()
{
	for (int i = 0; i < inputs.size(); i++) {
		if (inputs[i]->getInput())
			return true;
	}
	
	return false;
}

Action::Action()
{
}

Action::~Action()
{
	resetInputs();
}

void Action::resetInputs()
{
	for (int i = 0; i < inputs.size(); i++)
	{
		delete inputs[i];
	}
	inputs.clear();
}

void Action::addInput(Input* input)
{
	inputs.push_back(input);
}
