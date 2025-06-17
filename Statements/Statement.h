#ifndef STATEMENT_H
#define STATEMENT_H

#include "..\defs.h"
#include "..\Connector.h"
//class Output;
#include "..\GUI\Output.h"
#include <fstream>
using namespace std;

//Base class for all Statements
class Statement
{
protected:
	int ID;				//Each Statement has an ID --> must be unique
	static int LastID;	//The last set ID
	string Text;		//Statement text (e.g.  "X = 5" OR "salary > 3000" and so on)
	bool Selected;		//true if the statement is selected on the folwchart
	Point Center;		//Center of the statement block.

	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	Statement();
	void SetSelected(bool s);
	bool IsSelected() const;
	virtual Point GetCenter() const;

	virtual void Draw(Output* pOut) const  = 0 ;								//Draw the statement

	virtual unsigned short GetInputs(Point Inputs[3]) const = 0;					//Gets the input points of the statement. Returns the number of inputs
	virtual unsigned short GetOutputs(Point Outputs[3]) const = 0;					//Gets the output points of the statement. Returns the number of outputs
	virtual unsigned short GetOutputConnectors(Connector* pOutConn[3]) const = 0;	//Gets the pointers to output connectors. Returns the number of output connectors
	virtual void SetOutputConnector(Connector* pConn, short ConnNum) = 0;			//Sets a specific output connector. Connector number has a range of 0->1
	

	Point getTopLeft();
	Point getBottomRight();

	bool IsPointIncluded(Point P);

	virtual bool ConnCheck(void);  // to check on the connectors of statemnets 

	virtual string getLHS();
	virtual bool getRHSIsVar();
	virtual string getRHSVar();

	virtual string getFirstOperandVar();
	virtual string getSecondOperandVar();
	virtual bool getFirstOperandIsVar();
	virtual bool getSecondOperandIsVar();

	int GetID();


	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type

	virtual void Save(ofstream &OutFile) const = 0;	//Save the Statement parameters to a file
	//virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file

	//virtual void Edit() = 0;		//Edit the Statement parameter

	//virtual void Simulate();	//Execute the statement in the simulation mode

	//[BONUS] virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file


	///TODO: Add more functions if needed

};

#endif