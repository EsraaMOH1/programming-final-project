#include "ApplicationManager.h"
#include "Actions\AddValueAssign.h"
#include "Actions\AddVariableAssign.h"
#include "Actions\AddOperatorAssign.h"
#include "Actions\AddEnd.h"
#include "Actions\AddStart.h"
#include "Actions\AddCondition.h"
#include "Actions\AddReadStat.h"
#include "Actions\AddWriteStat.h"
#include "Actions\AddConn.h"
#include "Actions\Copy.h"
#include "Actions\Paste.h"
#include "Actions\Delete.h"
#include "Actions\Validate.h"
#include "Actions\SwtchSim.h"
#include "Actions\SwtchDsgn.h"
#include "Actions\Exit.h"
#include "Actions\SelectAction.h"
#include "Actions\Save.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

#include <iostream>
#include <typeinfo>
#include <string>
#include <fstream>
using namespace std;



//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	pClipboard = NULL;
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//


ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
		case ADD_VALUE_ASSIGN:
			pAct = new AddValueAssign(this);
			break;

		case ADD_VAR_ASSIGN:
			pAct = new AddVariableAssign(this);
			break;

		case ADD_START:
			pAct = new AddStart(this);
			break;

		case ADD_END:
			pAct = new AddEnd(this);
			break;

		case ADD_OPER_ASSIGN:
			pAct = new AddOperatorAssign(this);
			break;

		case ADD_CONDITION:
			pAct = new AddCondition(this);
			break;

		case ADD_READ:
			pAct = new AddReadStat(this);
			break;

		case ADD_WRITE:
			pAct = new AddWriteStat(this);
			break;

		case ADD_CONNECTOR:
			pAct = new AddConn(this);
			break; 

		case SELECT:
			pAct = new SelectAction(this);
			break;

		case COPY:
			pAct = new Copy(this);

			break;
		case PASTE:
			pAct = new Paste(this);
			break;

		case DELETE:
			pAct = new Delete(this);
			break;

		case SAVE:
			pAct = new Save(this);
			break;

		case SWITCH_SIM_MODE:
			pAct = new SwtchSim(this);
			break;

		case SWITCH_DSN_MODE:
			pAct = new SwtchDsgn(this);
			break;

		case EXIT:
			pAct = new Exit(this);
			break;

		case VALIDATE:
			pAct = new Validate(this);
			break;
		
		case STATUS:
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}



//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//


//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
	
}

////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL

	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities
	
	Point Center;

	for (int i = 0; i < StatCount; i++)
	{
		Center = StatList[i]->GetCenter();
		if ((P.x >= Center.x - UI.ASSGN_WDTH / 2) && (P.x <= Center.x + UI.ASSGN_WDTH / 2) && (P.y >= Center.y - UI.ASSGN_HI / 2) && (P.y <= Center.y + UI.ASSGN_HI / 2))
		{
			return StatList[i];
		}
	}
	return NULL;


	/*
	for (int i = 0; i < StatCount; ++i)
	{
		Statement* currentStatement = StatList[i];

		// Check if point P is inside the bounding box of the current statement
		if (currentStatement->IsPointIncluded(P))
		{
			return currentStatement;
		}
	}
     return NULL;
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL

	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities*/
}


//Add a connector to the list of connectors
void ApplicationManager::AddConnector(Connector* pConn) {
	if (ConnCount < MaxCount)
		ConnList[ConnCount++] = pConn;
}

////////////////////////////////////////////////////////////////////////////////////
Connector* ApplicationManager:: GetConnector(Point P) const
{
	for (int i = 0; i < ConnCount; ++i)
	{
		Connector* currentConnector = ConnList[i];

		// Check if point P is inside the bounding box of the current statement
		if (currentConnector->IsPointIncluded(P))
		{
			return currentConnector;
		}
	}
	return NULL;
	//If this point P(x,y) belongs to a connector return a pointer to it.
	//otherwise, return NULL

	///Add your code here to search for a connector given a point P(x,y)	
	///WITHOUT breaking class responsibilities
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Returns the selected connector
Connector* ApplicationManager::GetSelectedConnector() const {
	return pSelectedConn;
}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;  }

/*bool ApplicationManager::IsSelected()
{
	return Selected;
}*/


////////////////////////////////////////////////////////////////////////////////////
//Set the statement connector by the user
void ApplicationManager::SetSelectedConnector(Connector* pConn) {
	pSelectedConn = pConn;
}

////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement *ApplicationManager::GetClipboard() const
{	return pClipboard;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement* pStat)
{
	pClipboard = pStat;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//


//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		pOut->CreateDesignToolBar();
	}
	else						//application is in simulation mode
	{
		pOut->CreateSimulationToolBar();
	}
	//pOut->ClearStatusBar();
	

	//Draw all statements
	for (int i = 0; i < StatCount; i++)
		StatList[i]->Draw(pOut);

	//Draw all connections
	for (int i = 0; i < ConnCount; i++)
		ConnList[i]->Draw(pOut);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////

//Validation Function
void ApplicationManager::App_Validate()
{
	int j = 0; // to use in the last check
	string LHS[200];
	string RHS;

	int ID;
	bool ID_Found = 0;
	bool Is_Valid = 1;
	bool RHS_Found = 1;


	/********************check on the number of statemnets and connecters, can't excceed MaxCount***************************/

	if (StatCount > MaxCount || ConnCount > MaxCount)
	{
		Is_Valid = 0;
		pOut->PrintMessage("Invalid chart,Number of statemnets must not exceed 200");

	}

	/************************************* check on the Start***********************************/
	/************************************* there have to be exactly one Start******************************/

	for (int i = 0; i < StatCount; i++)
	{
		if (typeid(*(StatList[i])) == typeid(Start))
		{
			Start_Count++;
		}
	}
	if (Start_Count != 1)
	{
		Is_Valid = 0;
		pOut->PrintMessage("Invalid chart,Invalid Number of start statemnets ");
	}

	/************************************* check on the End*************************************/
	/************************************* there have to be exactly one End ******************************/
	for (int i = 0; i < StatCount; i++)
	{
		if (typeid(*(StatList[i])) == typeid(End))
		{
			End_Count++;
		}
	}
	if (End_Count != 1)
	{
		Is_Valid = 0;
		pOut->PrintMessage("Invalid chart,Invalid Number of End statemnets");
	}

	/*******************************Check if each connector has a source and a destination statement correctly connected*************************************/
	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i]->getSrcStat() == NULL)
		{
			Is_Valid = 0;
			pOut->PrintMessage("Invalid chart,Chart is not fully connected ");
		}
		if (ConnList[i]->getDstStat() == NULL)
		{
			Is_Valid = 0;
			pOut->PrintMessage("Invalid chart,Chart is not fully connected ");
		}
		//ConnList[i]->getSrcStat(); // this line gets the source statemnet of the connector 
		//ConnList[i]->getDstStat(); // this line gets the Destination statemnet of the connector 
	}

	/*************************************Check if each statement's output connector doesn't point to NULL*************************************/
	for (int i = 0; i < StatCount; i++)
	{
		if (((StatList[i])->ConnCheck()) )       // true if the one or both of the pointers point to NULL
		{
			Is_Valid = 0;
			pOut->PrintMessage("Invalid chart,Wrong number of connectors statemnet");
		}
		//ConnList[i]->getSrcStat(); // this line gets the source statemnet of the connector 
		//ConnList[i]->getDstStat(); // this line gets the Destination statemnet of the connector 
	}

	/*************************************Check that Each variable is initialized before being used *************************************/

	for (int i = 0; i < StatCount; i++)
	{

		if (typeid(*(StatList[i])) != typeid(Start) && typeid(*(StatList[i])) != typeid(End))
		{
			LHS[j] = (StatList[i]->getLHS());
			j++;
		}
	}

	for (int i = 0; i < StatCount; i++)
	{
		if (typeid(*(StatList[i])) == typeid(OperatorAssign))
		{
			if (StatList[i]->getFirstOperandIsVar()) // TRUE IF THE RHS IS VARIABLE
			{
				RHS = StatList[i]->getFirstOperandVar();

				for (int j = 0; j < StatCount; j++)
				{
					if (RHS != LHS[j])
					{
						RHS_Found = 0;
					}
				}
				if (RHS_Found == 0)
				{
					Is_Valid = 0;
					pOut->PrintMessage("Invalid chart,Uninitialised Variable");
				}

			}

			if (StatList[i]->getSecondOperandIsVar()) // TRUE IF THE RHS IS VARIABLE
			{
				RHS = StatList[i]->getSecondOperandVar();

				for (int j = 0; j < StatCount; j++)
				{
					if (RHS != LHS[j])
					{
						RHS_Found = 0;
					}
				}
				if (RHS_Found == 0)
				{
					Is_Valid = 0;
					pOut->PrintMessage("Invalid chart,Uninitialised Variable");
				}
			}

			else if (typeid(*(StatList[i])) != typeid(Start) && typeid(*(StatList[i])) != typeid(End))
			{
				if (StatList[i]->getRHSIsVar()) // TRUE IF THE RHS IS VARIABLE
				{
					RHS = StatList[i]->getRHSVar();

					for (int j = 0; j < StatCount; j++)
					{
						if (RHS != LHS[j])
						{
							RHS_Found = 0;

						}
					}
					if (RHS_Found == 0)
					{
						Is_Valid = 0;
						pOut->PrintMessage("Invalid chart,Uninitialised Variable");
					}
				}

			}

		}
		/************************************Check that Each statement has an input connector *************************************/
		for (int i = 0; i < StatCount; i++)
		{
		
		
			if (typeid(*(StatList[i])) != typeid(Start))
			{
				ID = StatList[i]->GetID();
				for (int w = 0; w < ConnCount; w++)
				{
					if (ID == (ConnList[i]->getDstStat())->GetID())
					{
						ID_Found = 1;
					}
				}
			}
		}
		if (!(ID_Found)) //TRUE IF ID_FOUND=0
		{
			Is_Valid = 0;
			pOut->PrintMessage("Invalid chart,Unconnected statement");
		}
		/************************************Check on the flag *************************************/
		if (Is_Valid == 1)
		{
			pOut->PrintMessage("Valid Chart");

		}
	}
}


void ApplicationManager::SaveAll(ofstream &OutFile) const
{
	OutFile << StatCount << "\n";
	for (int i = 0; i < StatCount; i++)
	{
		StatList[i]->Save(OutFile);
	}
	OutFile << ConnCount << "\n";
	for (int i = 0; i < ConnCount; i++)
	{
		ConnList[i]->Save(OutFile);
	}
}


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
}
