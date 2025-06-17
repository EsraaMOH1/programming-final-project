#include "AddReadStat.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <sstream>
using namespace std;


AddReadStat::AddReadStat(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddReadStat::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Read Statement: Click to add the statement");
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	//DONE: Ask the user in the status bar to enter the RHS and set the data member
	pOut->PrintMessage("Please enter a variable to read into, then press enter");
	RHS = pIn->GetVariable(pOut);
}

void AddReadStat::Execute()
{
	ReadActionParameters();

	ReadStat* pAssign = new ReadStat(Position, RHS);

	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}