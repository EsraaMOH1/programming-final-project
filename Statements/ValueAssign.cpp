#include "ValueAssign.h"
#include <sstream>

using namespace std;

ValueAssign::ValueAssign(Point Center, string LeftHS, double RightHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
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

void ValueAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void ValueAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}


void ValueAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}


//This function should be called when LHS or RHS changes
void ValueAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T<<LHS<<" = "<<RHS;	
	Text = T.str();	 
}


unsigned short ValueAssign::GetInputs(Point Inputs[3]) const
{
	Inputs[0] = Inlet;
	return 1;
}
unsigned short ValueAssign::GetOutputs(Point Outputs[3]) const
{
	Outputs[0] = Outlet;
	return 1;
}
unsigned short ValueAssign::GetOutputConnectors(Connector* pOutConn[3]) const
{
	pOutConn[0] = this->pOutConn;
	return 1;
}
void ValueAssign::SetOutputConnector(Connector* pConn, short ConnNum)
{
	if (0 == ConnNum)
	{
		pOutConn = pConn;
	}
	return;
}

bool ValueAssign::ConnCheck(void)
{
	if (pOutConn == NULL)
	{
		return true;            // return 1 if one or both of the connectors point to null
	}

}

string ValueAssign::getLHS()
{
	return LHS;
}

void ValueAssign::Save(ofstream &OutFile) const
{
	OutFile << "VAL_ASSIGN" << "\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << LHS << "\t" << RHS << "\n";
}