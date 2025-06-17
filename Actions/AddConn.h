#ifndef ADD_CONN_H
#define ADD_CONN_H


#include "Action.h"
#include "../Statements/CondStat.h"


class AddConn : public Action
{
private:
	Statement* pSourceStatement;
	Statement* pDestinationStatement;
	Point Start;	//Start point of the connector
	Point End;		//End point of the connector

public:
	AddConn(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif