#ifndef WRITE_STAT_H
#define WRITE_STAT_H

#include "Statement.h"

class WriteStat : public Statement
{
private:
	string RHS;

	Connector* pOutConn;

	Point Inlet;
	Point Outlet;

	virtual void UpdateStatementText();

public:
	WriteStat(Point Center, string LeftHS = "");

	void setRHS(const string& L);

	virtual void Draw(Output* pOut) const;
	
	unsigned short GetInputs(Point Inputs[3]) const;					//Gets the input points of the statement. Returns the number of inputs
	unsigned short GetOutputs(Point Outputs[3]) const;					//Gets the output points of the statement. Returns the number of outputs
	unsigned short GetOutputConnectors(Connector* pOutConn[3]) const;	//Gets the pointers to output connectors. Returns the number of output connectors
	void SetOutputConnector(Connector* pConn, short ConnNum);			//Sets a specific output connector. Connector number has a range of 0->1

	bool ConnCheck(void);

	string getRHSVar();
	void Save(ofstream &OutFile) const;	//Save the Statement parameters to a file
};

#endif
