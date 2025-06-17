#include "AddStart.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <sstream>
using namespace std;


AddStart::AddStart(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddStart::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	pOut->PrintMessage("Start Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

}

void AddStart::Execute()
{
	ReadActionParameters();

	Start* pAssign = new Start(Position);

	pManager->AddStatement(pAssign);
}


