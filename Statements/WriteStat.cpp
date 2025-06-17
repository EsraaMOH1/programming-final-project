#include "WriteStat.h"
#include <sstream>
using namespace std;



WriteStat::WriteStat(Point Center, string LeftHS)
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

void WriteStat::setRHS(const string& L)
{
	RHS = L;
	UpdateStatementText();
}


void WriteStat::Draw(Output* pOut) const
{
	pOut->DrawInputOutput(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, "Write: " + Text, Selected);
}


void WriteStat::UpdateStatementText()
{
	ostringstream T;
	T << RHS;
	Text = T.str();
}


unsigned short WriteStat::GetInputs(Point Inputs[3]) const
{
	Inputs[0] = Inlet;
	return 1;
}
unsigned short WriteStat::GetOutputs(Point Outputs[3]) const
{
	Outputs[0] = Outlet;
	return 1;
}
unsigned short WriteStat::GetOutputConnectors(Connector* pOutConn[3]) const
{
	pOutConn[0] = this->pOutConn;
	return 1;
}
void WriteStat::SetOutputConnector(Connector* pConn, short ConnNum)
{
	if (0 == ConnNum)
	{
		pOutConn = pConn;
	}
	return;
}

bool WriteStat::ConnCheck(void)
{
	if (pOutConn == NULL)
	{
		return true;            // return 1 if one or both of the connectors point to null
	}
}
string WriteStat::getRHSVar()
{
	return RHS;
}


void WriteStat::Save(ofstream &OutFile) const
{
	OutFile << "WRITE" << "\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << RHS << "\n";
}