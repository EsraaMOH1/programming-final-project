#include "SelectAction.h"
#include "../ApplicationManager.h"

SelectAction::SelectAction(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void SelectAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Click on a statement or a connector to select it.");
	pIn->GetPointClicked(Position);
	SelectedStatement = pManager->GetStatement(Position);
	
	if (!SelectedStatement) 
	{
		SelectedConnector = pManager->GetConnector(Position);
	}
	
	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	if (SelectedStatement)
	{
		if (PrevSelcStat != SelectedStatement)
		{
			if (PrevSelcStat)
			{
				pOut->PrintMessage("Click on a statement or a connector to select it.");
				PrevSelcStat->SetSelected(false);
			}
			pManager->SetSelectedStatement(SelectedStatement);
			SelectedStatement->SetSelected(!SelectedStatement->IsSelected());
			SelectedStatement = PrevSelcStat;
		}
	}


	else if (SelectedConnector)
	{
		pManager->SetSelectedConnector(SelectedConnector);
		SelectedConnector->SetSelectedConn(!SelectedConnector->IsSelectedConn());

	}
}