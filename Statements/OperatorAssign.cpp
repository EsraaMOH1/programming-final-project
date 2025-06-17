#include "OperatorAssign.h"
#include <sstream>
using namespace std;



OperatorAssign::OperatorAssign(Point Center, string LeftHS, string Operator, double FirstOperandVal, double SecondOperandVal, string FirstOperandVar, string SecondOperandVar, bool FirstOperandIsVar, bool SecondOperandIsVar)
{
	LHS = LeftHS;
	OPR = Operator;

	this->FirstOperandVal = FirstOperandVal;
	this->SecondOperandVal = SecondOperandVal;

	this->FirstOperandVar = FirstOperandVar;
	this->SecondOperandVar = SecondOperandVar;

	this->FirstOperandIsVar = FirstOperandIsVar;
	this->SecondOperandIsVar = SecondOperandIsVar;


	UpdateStatementText();

	this->Center = Center;

	pOutConn = NULL;

	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;

	Outlet.x = Inlet.x;
	Outlet.y = Inlet.y + UI.ASSGN_HI;
}

void OperatorAssign::setOPR(const string& O)
{
	OPR = O;
	UpdateStatementText();
}

void OperatorAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}


void OperatorAssign::setFirstOperandVal(const double& Val)
{
	FirstOperandVal = Val;
	UpdateStatementText();
}

void OperatorAssign::setFirstOperandVar(const string& Var)
{
	FirstOperandVar = Var;
	UpdateStatementText();
}

void OperatorAssign::setSecondOperandVal(const double& Val)
{
	SecondOperandVal = Val;
	UpdateStatementText();
}

void OperatorAssign::setSecondOperandVar(const string& Var)
{
	SecondOperandVar = Var;
	UpdateStatementText();
}

void OperatorAssign::setFirstOperandIsVar(bool IsVar)
{
	FirstOperandIsVar = IsVar;
	UpdateStatementText();
}

void OperatorAssign::setSecondOperandIsVar(bool IsVar)
{
	SecondOperandIsVar = IsVar;
	UpdateStatementText();
}



void OperatorAssign::Draw(Output* pOut) const
{
	
	pOut->DrawAssign(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


void OperatorAssign::UpdateStatementText()
{
	//Build the statement text
	ostringstream T;
	T << LHS << " = ";
	if (FirstOperandIsVar)
	{
		T << FirstOperandVar;
	}
	else
	{
		T << FirstOperandVal;
	}
	T << " " << OPR << " ";
	if (SecondOperandIsVar)
	{
		T << SecondOperandVar;
	}
	else
	{
		T << SecondOperandVal;
	}
	Text = T.str();
}


unsigned short OperatorAssign::GetInputs(Point Inputs[3]) const
{
	Inputs[0] = Inlet;
	return 1;
}
unsigned short OperatorAssign::GetOutputs(Point Outputs[3]) const
{
	Outputs[0] = Outlet;
	return 1;
}
unsigned short OperatorAssign::GetOutputConnectors(Connector* pOutConn[3]) const
{
	pOutConn[0] = this->pOutConn;
	return 1;
}
void OperatorAssign::SetOutputConnector(Connector* pConn, short ConnNum)
{
	if (0 == ConnNum)
	{
		pOutConn = pConn;
	}
	return;
}

bool OperatorAssign::ConnCheck(void)
{
	if (pOutConn == NULL)
	{
		return true;            // return 1 if one or both of the connectors point to null
	}
}

string OperatorAssign::getFirstOperandVar()
{
	return FirstOperandVar;
}
string OperatorAssign::getSecondOperandVar()
{
	return SecondOperandVar;
}
bool OperatorAssign::getFirstOperandIsVar()
{
	return FirstOperandIsVar;
}
bool OperatorAssign::getSecondOperandIsVar()
{
	return SecondOperandIsVar;
}


void OperatorAssign::Save(ofstream &OutFile) const
{
	OutFile << "OP_ASSIGN" << "\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << LHS << "\t";
	if (true == FirstOperandIsVar)
	{
		OutFile << FirstOperandVar << "\t";
	}
	else
	{
		OutFile << FirstOperandVal << "\t";
	}
	OutFile << OPR << "\t";
	if (true == SecondOperandIsVar)
	{
		OutFile << SecondOperandVar << "\t" << "\n";
	}
	else
	{
		OutFile << SecondOperandVal << "\t" << "\n";
	}
}