#include "Start.h"
#include <sstream>
using namespace std;

 Start::Start(Point Center)
 {
	 this->Center = Center;

	 pOutConn = NULL;	//No connectors yet

	 Outlet.x = Center.x;
	 Outlet.y = Center.y + UI.ASSGN_HI / 2;
 }



 void Start::UpdateStatementText(){}


 void Start::Draw(Output* pOut) const
 {
	 pOut->DrawStart(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Selected);
 }
 

unsigned short Start::GetInputs(Point Inputs[3]) const
{
	return 0;
}
unsigned short Start::GetOutputs(Point Outputs[3]) const
{
	Outputs[0] = Outlet;
	return 1;
}
unsigned short Start::GetOutputConnectors(Connector* pOutConn[3]) const
{
	pOutConn[0] = this->pOutConn;
	return 1;
}
void Start::SetOutputConnector(Connector* pConn, short ConnNum)
{
	if (0 == ConnNum)
	{
		pOutConn = pConn;
	}
	return;
}

bool Start::ConnCheck(void)
{
	if (pOutConn == NULL)
	{
		return true;            // return 1 if one or both of the connectors point to null
	}
}

void Start::Save(ofstream &OutFile) const
{
	OutFile << "START" << "\t" << ID << "\t" << Center.x << "\t" << Center.y << "\n";
}