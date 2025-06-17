#include "ReadStat.h"
#include <sstream>
using namespace std;



ReadStat::ReadStat(Point Center, string LeftHS)
{
	RHS = LeftHS;

	UpdateStatementText();

	this->Center = Center;

	pOutConn = NULL;	//No connectors yet

	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;

	Outlet.x = Inlet.x;
	Outlet.y = Inlet.y + UI.ASSGN_HI;
}

void ReadStat::setRHS(const string& L)
{
	RHS = L;
	UpdateStatementText();
}


void ReadStat::Draw(Output* pOut) const
{
	pOut->DrawInputOutput(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, "Read: " + Text, Selected);
}


void ReadStat::UpdateStatementText()
{
	ostringstream T;
	T << RHS;
	Text = T.str();
}


unsigned short ReadStat::GetInputs(Point Inputs[3]) const
{
	Inputs[0] = Inlet;
	return 1;
}
unsigned short ReadStat::GetOutputs(Point Outputs[3]) const
{
	Outputs[0] = Outlet;
	return 1;
}
unsigned short ReadStat::GetOutputConnectors(Connector* pOutConn[3]) const
{
	pOutConn[0] = this->pOutConn;
	return 1;
}
void ReadStat::SetOutputConnector(Connector* pConn, short ConnNum)
{
	if (0 == ConnNum)
	{
		pOutConn = pConn;
	}
	return;
}

bool ReadStat::ConnCheck(void)
{
	if (pOutConn == NULL)
	{
		return true;            // return 1 if one or both of the connectors point to null
	}
}

string ReadStat::getRHSVar()
{
	return RHS;
}

void ReadStat::Save(ofstream &OutFile) const
{
	OutFile << "READ" << "\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << RHS << "\n";
}