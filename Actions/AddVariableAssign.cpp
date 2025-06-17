#include "AddVariableAssign.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <sstream>
using namespace std;


AddVariableAssign::AddVariableAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddVariableAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	//DONE: Ask the user in the status bar to enter the LHS and set the data member
	pOut->PrintMessage("Please enter the left hand side parameter (variable), then press enter");
	LHS = pIn->GetVariable(pOut);

	//DONE: Ask the user in the status bar to enter the RHS and set the data member
	pOut->PrintMessage("Please enter the right hand side parameter (variable), then press enter");
	RHS = pIn->GetVariable(pOut);

	//Note: You should validate the LHS and the RHS to be variable names
	//      Call the appropriate functions for this.
}

void AddVariableAssign::Execute()
{
	ReadActionParameters();

	VariableAssign* pAssign = new VariableAssign(Position, LHS, RHS);
	//DONE: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}


