#include "SwtchDsgn.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <sstream>
using namespace std;


SwtchDsgn::SwtchDsgn(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void SwtchDsgn::ReadActionParameters()
{}

void SwtchDsgn::Execute()
{
	UI.AppMode = DESIGN;
}


