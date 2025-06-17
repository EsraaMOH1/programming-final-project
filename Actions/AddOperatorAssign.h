
#ifndef ADD_OPERATOR_ASSIGN_H
#define ADD_OPERATOR_ASSIGN_H


#include "Action.h"
#include "../Statements/OperatorAssign.h"


class AddOperatorAssign : public Action
{
private:	
	Point Position;	

	string OPR;
	string LHS;

	double FirstOperandVal;
	string FirstOperandVar;
	double SecondOperandVal;
	string SecondOperandVar;

	bool FirstOperandIsVar;
	bool SecondOperandIsVar;

public:
	AddOperatorAssign(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif