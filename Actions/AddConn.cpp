#include "AddConn.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <sstream>
using namespace std;


AddConn::AddConn(ApplicationManager* pAppManager) :Action(pAppManager)
{}


void AddConn::ReadActionParameters()
{
	bool IsStatement = false;
	bool HasEmptyOutput = false;
	bool HasInput = false;
	Point Click;
	Point PointArr[3];
	Connector* ConnArr[3];
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Please click on the source statement");
	while (false == IsStatement || false == HasEmptyOutput)
	{
		pIn->GetPointClicked(Click);
		pSourceStatement = pManager->GetStatement(Click);
		
		if (NULL != pSourceStatement)
		{
			IsStatement = true;
			int NumConn = pSourceStatement->GetOutputConnectors(ConnArr);
			for (int i = 0; i < NumConn; i++)
			{
				HasEmptyOutput = false;
				if (NULL == ConnArr[i])
				{
					HasEmptyOutput = true;
					break;
				}
			}
			if (false == HasEmptyOutput)
			{
				pOut->PrintMessage("Please click on a statement that has an available output");
			}
		}
		else
		{
			pOut->PrintMessage("Please click on a statement");
			IsStatement = false;
		}
	}
	
	IsStatement = false;
	pOut->PrintMessage("Please click on the destination statement");
	while (false == IsStatement || false == HasInput)
	{
		pIn->GetPointClicked(Click);
		pDestinationStatement = pManager->GetStatement(Click);

		if (NULL != pSourceStatement)
		{
			IsStatement = true;
			HasInput = pDestinationStatement->GetInputs(PointArr);
			if (false == HasInput)
			{
				pOut->PrintMessage("Please click on a statement that can have an input");
			}
		}
		else
		{
			pOut->PrintMessage("Please click on a statement");
			IsStatement = false;
		}
	}

	pSourceStatement->GetOutputConnectors(ConnArr);
	pSourceStatement->GetOutputs(PointArr);
	if (NULL == ConnArr[0])
	{
		Start = PointArr[0];
	}
	else
	{
		Start = PointArr[1];
	}
	pDestinationStatement->GetInputs(PointArr);
	End = PointArr[0];
}

void AddConn::Execute()
{
	Connector* ConnArr[3];

	ReadActionParameters();

	Connector* pConn = new Connector(pSourceStatement, pDestinationStatement, Start, End);
	pManager->AddConnector(pConn);

	pSourceStatement->GetOutputConnectors(ConnArr);
	if (NULL == ConnArr[0])
	{
		pSourceStatement->SetOutputConnector(pConn, 0);
	}
	else
	{
		pSourceStatement->SetOutputConnector(pConn, 1);
	}
}