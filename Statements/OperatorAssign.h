#pragma once
#include "Statement.h"



class OperatorAssign:public Statement
{
private:
	string OPR;	
	string LHS;

	double FirstOperandVal; // value: first operand
	string FirstOperandVar; // varibale:  first operand
	double SecondOperandVal; // value:  second operand
	string SecondOperandVar; // variable :  second operand

	bool FirstOperandIsVar;
	bool SecondOperandIsVar;

	Connector* pOutConn;

	Point Inlet;	
	Point Outlet;

	virtual void UpdateStatementText();

public:
	OperatorAssign(Point Center, string LeftHS = "",string Operator = "", double FirstOperandVal = 0, double SecondOperandVal = 0, string FirstOperandVar = "", string SecondOperandVar = "", bool FirstOperandIsVar = false, bool SecondOperandIsVar = false);

	void setOPR(const string& O);
	void setLHS(const string& L);
	void setFirstOperandVal(const double& Val);
	void setFirstOperandVar(const string& Var);
	void setSecondOperandVal(const double& Val);
	void setSecondOperandVar(const string& Var);
	void setFirstOperandIsVar(bool IsVar);
	void setSecondOperandIsVar(bool IsVar);
	
	virtual void Draw(Output* pOut) const;

	unsigned short GetInputs(Point Inputs[3]) const;						//Gets the input points of the statement. Returns the number of inputs
	unsigned short GetOutputs(Point Outputs[3]) const;					//Gets the output points of the statement. Returns the number of outputs
	unsigned short GetOutputConnectors(Connector* pOutConn[3]) const;	//Gets the pointers to output connectors. Returns the number of output connectors
	void SetOutputConnector(Connector* pConn, short ConnNum);			//Sets a specific output connector. Connector number has a range of 0->1


	bool ConnCheck(void);


	string getFirstOperandVar();
	string getSecondOperandVar();
	bool getFirstOperandIsVar();
	bool getSecondOperandIsVar();

	void Save(ofstream &OutFile) const;	//Save the Statement parameters to a file
};

