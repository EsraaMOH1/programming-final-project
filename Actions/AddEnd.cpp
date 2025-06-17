#include "AddEnd.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <sstream>
using namespace std;


AddEnd::AddEnd(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddEnd::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	pOut->PrintMessage("End Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

}

void AddEnd::Execute()
{
	ReadActionParameters();

	End* pAssign = new End(Position);

	pManager->AddStatement(pAssign);
}


