#ifndef ADD_WRITE_STAT_H
#define ADD_WRITE_STAT_H


#include "Action.h"
#include "../Statements/WriteStat.h"


class AddWriteStat : public Action
{
private:
	Point Position;
	string RHS;

public:
	AddWriteStat(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif