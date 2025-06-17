#ifndef SWTCH_DSGN_H
#define SWTCH_DSGN_H


#include "Action.h"


class SwtchDsgn : public Action
{
private:

public:
	SwtchDsgn(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif