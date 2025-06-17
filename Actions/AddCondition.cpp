#include "AddCondition.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include <sstream>
using namespace std;


AddCondition::AddCondition(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddCondition::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Conditional Statement: Click to add the statement");
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	//DONE: Ask the user in the status bar to enter the LHS and set the data member
	pOut->PrintMessage("Please enter the left hand side parameter (variable), then press enter");
	LHS = pIn->GetVariable(pOut);

	//Ask the user for the Operator
	pOut->PrintMessage("Please enter a comparator operator, then press enter");
	OPR = pIn->GetCompOperator(pOut);

	//DONE: Ask the user in the status bar to enter the RHS and set the data member
	pOut->PrintMessage("Please enter the right hand side parameter (value or variable), then press enter");
	string input = pIn->GetString(pOut);

	while (INVALID_OP == ValueOrVariable(input))
	{
		pOut->PrintMessage("Please enter the a valid parameter (value or variable), then press enter");
		input = pIn->GetString(pOut);
	}
	unsigned short Flag = ValueOrVariable(input);
	if (VALUE_OP == Flag)
	{
		RHSVal = StringToDouble(input);
		RHSIsVar = false;
	}
	else if (VARIABLE_OP == Flag)
	{
		RHSVar = input;
		RHSIsVar = true;
	}
}

void AddCondition::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block

	CondStat* pAssign = new CondStat(Position, LHS, OPR);
	
	pAssign->setRHSIsVar(RHSIsVar);
	if (false == RHSIsVar)
	{
		pAssign->setRHSVal(RHSVal);
	}
	else
	{
		pAssign->setRHSVar(RHSVar);
	}

	pManager->AddStatement(pAssign);
}

