#include "VariableAssign.h"
#include <sstream>
using namespace std;

VariableAssign::VariableAssign(Point Center, string LeftHS, string RightHS)
{
	
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	this->Center = Center;

	pOutConn = NULL;	//No connectors yet

	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;

	Outlet.x = Inlet.x;
	Outlet.y = Inlet.y + UI.ASSGN_HI;
}

void VariableAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void VariableAssign::setRHS(const string& R)
{
	RHS = R;
	UpdateStatementText();
}


void VariableAssign::Draw(Output* pOut) const
{
	pOut->DrawAssign(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}



void VariableAssign::UpdateStatementText()
{
	ostringstream T;
	T << LHS << " = " << RHS;
	Text = T.str();
}


unsigned short VariableAssign::GetInputs(Point Inputs[3]) const
{
	Inputs[0] = Inlet;
	return 1;
}
unsigned short VariableAssign::GetOutputs(Point Outputs[3]) const
{
	Outputs[0] = Outlet;
	return 1;
}
unsigned short VariableAssign::GetOutputConnectors(Connector* pOutConn[3]) const
{
	pOutConn[0] = this->pOutConn;
	return 1;
}
void VariableAssign::SetOutputConnector(Connector* pConn, short ConnNum)
{
	if (0 == ConnNum)
	{
		pOutConn = pConn;
	}
	return;
}

bool VariableAssign::ConnCheck(void)
{
	if (pOutConn == NULL)
	{
		return true;            // return 1 if one or both of the connectors point to null
	}
}

string VariableAssign::getLHS()
{
	return LHS;
}
string VariableAssign::getRHSVar()
{
	return RHS;
}

void VariableAssign::Save(ofstream &OutFile) const
{
	OutFile << "VAR_ASSIGN" << "\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << LHS << "\t" << RHS << "\n";
}