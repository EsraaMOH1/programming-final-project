#include "Exit.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <sstream>
using namespace std;


Exit::Exit(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Exit::ReadActionParameters()
{}

void Exit::Execute()
{
	// Nothing is needed here
}


