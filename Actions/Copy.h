#include "Action.h"
class Statement;
//COPY Statement Action
//This class is responsible for 
// 1 - Getting Assignment stat. coordinates from the user (one of the parameters of this action)


class Copy : public Action
{
private:
	// in the data members of the actions
	// we put the paramaters of the action
	// to be set in ReadActionParameters() then used in Execute()


	Point Position;	//Position where the user clicks to copy the stat.
	Statement* selectedstat;
	ApplicationManager* pManger; //Pointer to application manager class
public:
	Copy(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add a copy assignemnt statement to the list of statements
	virtual void Execute();

};


