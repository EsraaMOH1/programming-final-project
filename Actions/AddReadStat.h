#ifndef ADD_READ_STAT_H
#define ADD_READ_STAT_H


#include "Action.h"
#include "../Statements/ReadStat.h"


class AddReadStat : public Action
{
private:
	Point Position;	
	string RHS;

public:
	AddReadStat(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif