#include "Validate.h"

//constructor: set the ApplicationManager pointer inside this action
Validate::Validate(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Validate::ReadActionParameters()
{
	// Empty implementation
}

void Validate::Execute()
{
	pManager->App_Validate(); // Call the validate function in the application manager
}

