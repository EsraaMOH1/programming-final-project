#include "CondStat.h"
#include <sstream>
using namespace std;


CondStat::CondStat(Point Center, string LeftHS, string Operator, double RHSVal, string RHSVar, bool RHSIsVar)
{
	
	LHS = LeftHS;
	OPR = Operator;

	this->RHSVal = RHSVal;
	this->RHSVar = RHSVar;
	this->RHSIsVar = RHSIsVar;

	UpdateStatementText();

	this->Center = Center;

	pOutConn1 = NULL;	
	pOutConn2 = NULL;

	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;

	Outlet1.x = Inlet.x - UI.ASSGN_WDTH / 2;
	Outlet1.y = Center.y;

	Outlet2.x = Outlet1.x + UI.ASSGN_WDTH;
	Outlet2.y = Center.y;
}


void CondStat::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void CondStat::setOPR(const string& O)
{
	OPR = O;
	UpdateStatementText();
}

void CondStat::setRHSVal(const double& Val)
{
	RHSVal = Val;
	UpdateStatementText();
}

void CondStat::setRHSVar(const string& Var)
{
	RHSVar = Var;
	UpdateStatementText();
}

void CondStat::setRHSIsVar(bool IsVar)
{
	RHSIsVar = IsVar;
	UpdateStatementText();
}


void CondStat::Draw(Output* pOut) const
{ 	
	pOut->DrawCondition(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}


void CondStat::UpdateStatementText()
{
	//Build the statement text
	ostringstream T;
	T << LHS << " " << OPR << " ";
	
	if (RHSIsVar)
	{
		T << RHSVar;
	}
	else
	{
		T << RHSVal;
	}
	Text = T.str();
}


unsigned short CondStat::GetInputs(Point Inputs[3]) const
{
	Inputs[0] = Inlet;
	return 1;
}
unsigned short CondStat::GetOutputs(Point Outputs[3]) const
{
	Outputs[0] = Outlet1;
	Outputs[1] = Outlet2;
	return 2;
}
unsigned short CondStat::GetOutputConnectors(Connector* pOutConn[3]) const
{
	pOutConn[0] = pOutConn1;
	pOutConn[1] = pOutConn2;
	return 2;
}
void CondStat::SetOutputConnector(Connector* pConn, short ConnNum)
{
	if (0 == ConnNum)
	{
		pOutConn1 = pConn;
	}
	else if	(1 == ConnNum)
	{
		pOutConn2 = pConn;
	}
	return;
}

bool CondStat::ConnCheck(void)
{
	if (pOutConn2 == NULL || pOutConn1 == NULL)
	{
		return true;            // return 1 if one or both of the connectors point to null
	}
}
string CondStat::getLHS()
{
	return LHS;
}
bool CondStat::getRHSIsVar()
{
	return RHSIsVar;
}
string CondStat::getRHSVar()
{
	return RHSVar;
}

void CondStat::Save(ofstream &OutFile) const
{
	OutFile << "CONDITION" << "\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << LHS << "\t";
	OutFile << OPR << "\t";
	if (true == RHSIsVar)
	{
		OutFile << RHSVar << "\t" << "\n";
	}
	else
	{
		OutFile << RHSVal << "\t" << "\n";
	}
}