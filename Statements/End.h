#ifndef END_H
#define END_H
#include "Statement.h"

class End : public Statement
{
private:


	Connector* pOutConn;

	Point Inlet;

	virtual void UpdateStatementText();

public:
	End(Point Center);
	
	virtual void Draw(Output* pOut) const;

	unsigned short GetInputs(Point Inputs[3]) const;						//Gets the input points of the statement. Returns the number of inputs
	unsigned short GetOutputs(Point Outputs[3]) const;					//Gets the output points of the statement. Returns the number of outputs
	unsigned short GetOutputConnectors(Connector* pOutConn[3]) const;	//Gets the pointers to output connectors. Returns the number of output connectors
	void SetOutputConnector(Connector* pConn, short ConnNum);			//Sets a specific output connector. Connector number has a range of 0->1

	void Save(ofstream &OutFile) const;	//Save the Statement parameters to a file
};

#endif