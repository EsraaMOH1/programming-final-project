#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class Validate :public Action
{
private:

public:
	Validate(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};

