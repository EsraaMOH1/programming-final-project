#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"

#include "Statements\Statement.h"
class Input;
class Output;


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxCount = 200 };	//Max no of statements/connectors in a single flowchart

private:
	int StatCount;		//Actual number of statements
	int ConnCount;		//Actual number of connectors
	Statement* StatList[MaxCount];	//List of all statements (Array of pointers)
	Connector* ConnList[MaxCount];	//List of all connectors (Array of pointers)

	Statement *pSelectedStat; //a pointer to the last selected statement
	                          //you can set and get this pointer
	Connector* pSelectedConn; //a pointer to the last selected connector (Esraa added this pointer)
	                          //you can set and get this pointer

	Statement *pClipboard;    //a pointer to the last copied/cut statement
	                          //you can set and get this pointer

	int Start_Count;
	int End_Count;

	//bool Selected;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// == Actions Related Functions ==
	ActionType GetUserAction() const; //Reads the input command from the user 
	                                  //and returns the corresponding action type
	void ExecuteAction(ActionType) ;  //Creates an action and executes it
	
	// == Statements/Connector Management Functions ==
	void AddStatement(Statement* pStat);    //Adds a new Statement to the Flowchart
	Statement *GetStatement(Point P) const;	//Searches for a statement where point P belongs
	                                        //TODO: Complete its implementation 
	                                        //      WITHOUT breaking class responsibilities

	void AddConnector(Connector* pConn);    //DONE:Adds a new Connector to the Flowchart
	Connector *GetConnector(Point P) const;	//DONE:search for a Connector where point P belongs

	// Note: you should use the following 4 functions 
	//       in order not to break class responsibilities (especially in copy, cut and paste)
	Statement *GetSelectedStatement() const;	 //Returns the selected Statement
	Connector* GetSelectedConnector() const;     //DONE:Returns the selected connector (Esraa added this func. to use in delete clas) 
	void SetSelectedStatement(Statement *pStat); //Set the Statement selected by the user
	void SetSelectedConnector(Connector* pConn); //DONE:Set the connector selected by the user (Esraa added this func. to use in delete clas)
	Statement *GetClipboard() const;	         //Returns the Clipboard
	void SetClipboard(Statement *pStat);         //Set the Clipboard
	//bool IsSelected(); //Rana added this fn.
	



	// == Interface Management Functions ==
	Input *GetInput() const;        //Return pointer to the input
	Output *GetOutput() const;      //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	
	void App_Validate();
	void SaveAll(ofstream &OutFile) const;
};

#endif