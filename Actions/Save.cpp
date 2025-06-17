#include "Save.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <sstream>
#include <fstream>
using namespace std;


Save::Save(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Save::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Please provide a file name, then press enter");
	FileName = pIn->GetString(pOut);
}

void Save::Execute()
{
	ReadActionParameters();
	ofstream OutFile(FileName + ".txt");
	pManager->SaveAll(OutFile);
	OutFile.close();
}