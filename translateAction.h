#ifndef TRANSLATEACTION_H__
#define TRANSLATEACTION_H__

#include "holdAction.h"

class TranslateAction : public HoldAction
{
private: 
	int initialInterval;
	bool initialPress;
public:
	TranslateAction();
	TranslateAction(int setInitialInterval, int setInterval);
	~TranslateAction();
	bool isActive();
};
#endif // ! TRANSLATEACTION_H__