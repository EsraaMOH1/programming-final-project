#include "AddWriteStat.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <sstream>
using namespace std;


AddWriteStat::AddWriteStat(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddWriteStat::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Write Statement: Click to add the statement");
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	//DONE: Ask the user in the status bar to enter the RHS and set the data member
	pOut->PrintMessage("Please enter a variable or a message to print, then press enter");
	RHS = pIn->GetString(pOut);
}

void AddWriteStat::Execute()
{
	ReadActionParameters();

	WriteStat* pAssign = new WriteStat(Position, RHS);

	pManager->AddStatement(pAssign);
}