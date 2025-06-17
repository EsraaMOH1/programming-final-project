#include "AddOperatorAssign.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <sstream>
using namespace std;



AddOperatorAssign::AddOperatorAssign(ApplicationManager* pAppManager) : Action(pAppManager)
{}

void AddOperatorAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Operator Assignment Statement: Click to add the statement");
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	//DONE: Ask the user in the status bar to enter the LHS and set the data member
	pOut->PrintMessage("Please enter the left hand side parameter (variable), then press enter");
	LHS = pIn->GetVariable(pOut);


	//Ask the user for the First Operand
	pOut->PrintMessage("Please enter the first operand of the right hand side (value or variable), then press enter");
	string input = pIn->GetString(pOut);
	
	while (INVALID_OP == ValueOrVariable(input))
	{
		pOut->PrintMessage("Please enter the a valid parameter (value or variable), then press enter");
		input = pIn->GetString(pOut);
	}
	unsigned short Flag = ValueOrVariable(input);
	if (VALUE_OP == Flag)
	{
		FirstOperandVal = StringToDouble(input);
		FirstOperandIsVar = false;
	}
	else if (VARIABLE_OP == Flag)
	{
		FirstOperandVar = input;
		FirstOperandIsVar = true;
	}


	//Ask the user for the Operator
	pOut->PrintMessage("Please enter an arithemetic operator, then press enter");
	OPR = pIn->GetArithOperator(pOut);


	//Ask the user for the Second Operand
	pOut->PrintMessage("Please enter the second operand of the right hand side (value or variable), then press enter");
	input = pIn->GetString(pOut);

	while (INVALID_OP == ValueOrVariable(input))
	{
		pOut->PrintMessage("Please enter the a valid parameter (value or variable), then press enter");
		input = pIn->GetString(pOut);
	}
	Flag = ValueOrVariable(input);
	if (VALUE_OP == Flag)
	{
		SecondOperandVal = StringToDouble(input);
		SecondOperandIsVar = false;
	}
	else if (VARIABLE_OP == Flag)
	{
		SecondOperandVar = input;
		SecondOperandIsVar = true;
	}
	
}

void AddOperatorAssign::Execute()
{
	ReadActionParameters();

	OperatorAssign* pAssign = new OperatorAssign(Position, LHS, OPR);

	pAssign->setFirstOperandIsVar(FirstOperandIsVar);
	pAssign->setSecondOperandIsVar(SecondOperandIsVar);
	if (false == FirstOperandIsVar)
	{
		pAssign->setFirstOperandVal(FirstOperandVal);
	}
	else
	{
		pAssign->setFirstOperandVar(FirstOperandVar);
	}
	if (false == SecondOperandIsVar)
	{
		pAssign->setSecondOperandVal(SecondOperandVal);
	}
	else
	{
		pAssign->setSecondOperandVar(SecondOperandVar);
	}

	pManager->AddStatement(pAssign); 
}