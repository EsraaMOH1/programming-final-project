#ifndef COND_ASSIGN_H
#define COND_ASSIGN_H


#include "Statement.h"


class CondStat : public Statement
{
private:
	string LHS;
	string OPR;

	double RHSVal;
	string RHSVar;
	bool RHSIsVar;


	Connector* pOutConn1;
	Connector* pOutConn2;

	Point Inlet;
	Point Outlet1;
	Point Outlet2;

	virtual void UpdateStatementText();

public:
	CondStat(Point Center, string LeftHS = "", string Operator = "", double RHSVal = 0, string RHSVar = "", bool RHSIsVar = false);

	void setLHS(const string& L);
	void setOPR(const string& O);
	void setRHSVal(const double& Val);
	void setRHSVar(const string& Var);
	void setRHSIsVar(bool IsVar);

	virtual void Draw(Output* pOut) const;

	unsigned short GetInputs(Point Inputs[3]) const;						//Gets the input points of the statement. Returns the number of inputs
	unsigned short GetOutputs(Point Outputs[3]) const;					//Gets the output points of the statement. Returns the number of outputs
	unsigned short GetOutputConnectors(Connector* pOutConn[3]) const;	//Gets the pointers to output connectors. Returns the number of output connectors
	void SetOutputConnector(Connector* pConn, short ConnNum);			//Sets a specific output connector. Connector number has a range of 0->1

	virtual bool ConnCheck(void);
	virtual string getLHS();
	virtual bool getRHSIsVar();
	virtual string getRHSVar();
	
	void Save(ofstream &OutFile) const;	//Save the Statement parameters to a file
};

#endif