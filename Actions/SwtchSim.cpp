#include "SwtchSim.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <sstream>
using namespace std;


SwtchSim::SwtchSim(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void SwtchSim::ReadActionParameters()
{}

void SwtchSim::Execute()
{
	UI.AppMode = SIMULATION;
}


