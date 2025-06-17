#ifndef VALUE_ASSIGN_H
#define VALUE_ASSIGN_H

#include "Statement.h"

//Value Assignment statement class
//The value assignment statement assigns a value to a variable
class ValueAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	double RHS;	//Right Handside (Value)
	
	Connector *pOutConn;	//Value Assignment Stat. has one Connector to next statement
	                        //Each statement type in flowchart has a predefined number of (output) connectors
	                        //For example, conditional statement always has 2 output connectors

	                        //Note: We don't need to keep track with input connectors
	                        //      Whenever we want to iterate on all statements of the flowchart
	                        //      we will begin with start statement then its output connector
	                        //      then the connector's destination statement and so on (follow the connectors)

	Point Inlet;	//A point where connections enters this statement 
	                //It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	                //It's used as the (Start) point of the (Output) connector

	virtual void UpdateStatementText();
	
public:
	ValueAssign(Point Center, string LeftHS="", double RightHS=0);
	
	void setLHS(const string &L);
	void setRHS(double R);

	virtual void Draw(Output* pOut) const;

	unsigned short GetInputs(Point Inputs[3]) const;						//Gets the input points of the statement. Returns the number of inputs
	unsigned short GetOutputs(Point Outputs[3]) const;					//Gets the output points of the statement. Returns the number of outputs
	unsigned short GetOutputConnectors(Connector* pOutConn[3]) const;	//Gets the pointers to output connectors. Returns the number of output connectors
	void SetOutputConnector(Connector* pConn, short ConnNum);			//Sets a specific output connector. Connector number has a range of 0->1

	bool ConnCheck(void);
	string getLHS();
	
	void Save(ofstream &OutFile) const;	//Save the Statement parameters to a file
};

#endif