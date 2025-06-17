#pragma once
 
#include "Action.h"

//Delete Statement/connector Action
//This class is responsible for 
// 1 - Getting Assignment stat. coordinates from the user (one of the parameters of this action)

class Delete : public Action
{
private:
	// in the data members of the actions
	// we put the paramaters of the action
	// to be set in ReadActionParameters() then used in Execute()

	Point Position;	//Position where the user clicks to delte the statement/connector

public:
	Delete(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();


};



