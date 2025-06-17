#ifndef ADD_COND_ASSIGN_H
#define ADD_COND_ASSIGN_H


#include "Action.h"
#include "../Statements/CondStat.h"


class AddCondition : public Action
{
private:
	Point Position;	

	string LHS;
	string OPR;

	double RHSVal;
	string RHSVar;
	bool RHSIsVar;

public:
	AddCondition(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};

#endif