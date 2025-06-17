#ifndef SAVE_H
#define SAVE_H


#include "Action.h"


class Save : public Action
{
private:
	string FileName;

public:
	Save(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif