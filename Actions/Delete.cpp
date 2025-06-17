#include "Delete.h"

#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Delete::Delete(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Delete::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Delete a Statement/connector: Click to delete a statement/connector");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

}

void Delete::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();


	//a function to get the selected statemtent 
	Statement* selectedstat = pManager->GetSelectedStatement();
	//a function to get the selected connector 
	Connector* selectedConnector = pManager->GetSelectedConnector();

	if (selectedstat != nullptr) {
		pManager->SetSelectedStatement(NULL);

		pManager->GetOutput()->PrintMessage("Statement is Deleted.");
	}
	else {
		pManager->GetOutput()->PrintMessage("Can't delete a statement. Make sure to select a statement properly.");
	}
	if (selectedConnector != nullptr) {
		pManager->SetSelectedConnector(NULL);

		pManager->GetOutput()->PrintMessage("Connector is Deleted.");
	}
	else {
		pManager->GetOutput()->PrintMessage("Can't delete a connector. Make sure to select a connector properly.");
	}

}

