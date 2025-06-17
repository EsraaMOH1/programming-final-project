#include "Copy.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Copy::Copy(ApplicationManager* pAppManager) :Action(pAppManager)
{
}

void Copy::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Copy a Statement: Click to copy a statement");
	pIn->GetPointClicked(Position);
	selectedstat = pManager->GetSelectedStatement();
	pOut->ClearStatusBar();
}

void Copy::Execute()      ///the professor suggested that this function return a statement not void
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	//a function to get the selected statemtent


	if (selectedstat != nullptr) 
	{
		Statement* copiedstat = selectedstat;
		pManager->SetClipboard (copiedstat);
		pOut->PrintMessage("Statement is copied to clipboard.");
		selectedstat = nullptr;
	}
	else 
	{
		pOut->PrintMessage("Can't copy a statement to clipboard.Make sure to select a statement properly.");
	}
}



