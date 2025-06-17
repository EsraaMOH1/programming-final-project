#ifndef SWTCH_SIM_H
#define SWTCH_SIM_H


#include "Action.h"


class SwtchSim : public Action
{
private:

public:
	SwtchSim(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif