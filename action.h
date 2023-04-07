#ifndef ACTION_H__
#define ACTION_H__

#include <vector>
#include "input.h"

class Action {

protected:
	std::vector<Input*> inputs = std::vector<Input*>();
	bool getCurrentState();
public:
	Action();
	virtual ~Action();
	virtual bool isActive() = 0;
	void resetInputs();
	//ça ne fonctionnera pas pour la manette, il va faloir la mettre statique
	void addInput(Input* input);
};

#endif // ! ACTION_H__
