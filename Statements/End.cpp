#include "End.h"
#include <sstream>
using namespace std;

End::End(Point Center)
{
	this->Center = Center;

	pOutConn = NULL;	//No connectors yet

	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;
}



void End::UpdateStatementText() {}


void End::Draw(Output* pOut) const
{
	pOut->DrawEnd(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Selected);
}


unsigned short End::GetInputs(Point Inputs[3]) const
{
	Inputs[0] = Inlet;
	return 1;
}
unsigned short End::GetOutputs(Point Outputs[3]) const
{
	return 0;
}
unsigned short End::GetOutputConnectors(Connector* pOutConn[3]) const
{
	return 0;
}
void End::SetOutputConnector(Connector* pConn, short ConnNum)
{
	return;
}

void End::Save(ofstream &OutFile) const
{
	OutFile << "END" << "\t" << ID << "\t" << Center.x << "\t" << Center.y << "\n";
}
