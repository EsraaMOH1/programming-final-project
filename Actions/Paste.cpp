#include "Paste.h"
//#include "..\Statements"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\ValueAssign.h"
#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Paste::Paste(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Paste::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Paste a Statement: Click to Paste a statement");
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

}

void Paste::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

		//a function to get the copied statemtent from clipboard
	Statement* copiedstat = pManager->GetClipboard();

	if (copiedstat != nullptr)
	{
	//	copiedstat->Paste();

		string LHS;
		double RHS;


		ValueAssign* pAssign = new ValueAssign(Position, LHS="",  RHS=0);

		//pManager->AddStatement(copiedstat);
		pManager->AddStatement(pAssign);

		pOut->PrintMessage("Statement is pasted");

	}
	else
	{
		pOut->PrintMessage("Can't paste a statement. Make sure to first copy a statement to clipboard.");
	}

	/*//Output* pOut = pManager->GetOutput();

	//a function to get the copied statemtent from clipboard
	Statement* copiedstat = pManager->GetClipboard();

	if (copiedstat != nullptr)
	{

		pManager->AddStatement(copiedstat);

		pManager->GetOutput()->PrintMessage("Statement is pasted");

	}
	else
	{
		pManager->GetOutput()->PrintMessage("Can't paste a statement. Make sure to first copy a statement to clipboard.");
	}*/



}

