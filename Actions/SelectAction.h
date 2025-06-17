#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H
#include "Action.h"
class Connector;
class Statement;

class SelectAction : public Action
{
private:
	Point Position;
	Statement* SelectedStatement = NULL;
	Statement* PrevSelcStat = NULL;
	Connector* SelectedConnector = nullptr;


public:
	SelectAction(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif