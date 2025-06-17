#ifndef DEFS_H
#define DEFS_H

//This file contains some global constants and definitions to be used in the project.

enum MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

// DONEBUTREVISE: Add any action type here
enum ActionType // The actions supported
{
	//Deisgn Menue Actions
	ADD_START, //Add start statement
	ADD_END,   //Add end statement
	ADD_VALUE_ASSIGN, //Add value assignment statement
	ADD_VAR_ASSIGN,	  //Add variable assignment statement
	ADD_OPER_ASSIGN,  //Add operator assignment statement
	ADD_CONDITION,    //Add a conditional statement (for if and while-loop statements)
	ADD_READ,  //Add read statement
	ADD_WRITE, //Addd write statemetn

	ADD_CONNECTOR, //Add a connector between two statements

	SELECT,		//Select a statement, a connector
	EDIT_STAT,	//Edit a statement

	DEL,				//Delete a figure
	COPY,				//Copy a figure
	CUT,				//Cut a figure
	PASTE,				//Paste a figure

	SAVE,				//Save the whole graph to a file
	LOAD,				//Load a graph from a file

	SWITCH_SIM_MODE,	//Switch to simulatiom mode

	// Simulation Menu Actions
	//DONE: ADD THE ACTIONS OF SIMULATION MODE
	VALIDATE,
	RUN,

	SWITCH_DSN_MODE,	//Switch to Design mode

	// Common Actions
	EXIT,				//Exit the application

	DRAWING_AREA,		//A click on the drawing area
	OUTPUT_AREA,		//A click on the output area
	DSN_TOOL,			//A click on an empty place in the design tool bar
	SMN_TOOL,			//A click on an empty place in the simulation tool bar

	STATUS 		   //A click on the status bar
};

// DONEBUTREVISE: you should add more items
enum DesignMenuItem //The items of the design menu --> THE ORDER MATTERS
{
	//Note: Items are ordered here as they appear in menu
	//If you change the menu items order, change the order here too

	//DONE: Add more items names here

	ITM_START,				//start statement
	ITM_END,				//end statement
	ITM_VALUE_ASSIGN,		//value assignment statement
	ITM_VARIABLE_ASSIGN,	//variable assignment statement
	ITM_OPERATOR_ASSIGN,	//operator assignment statement
	ITM_COND,				//conditional statement
	ITM_READ,				//I/p statement
	ITM_WRITE,				//O/p statement

	ITM_CONNECTOR,  		//connector

	ITM_SELECT,
	ITM_EDIT,
	ITM_DEL,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,

	ITM_SAVE,
	ITM_LOAD,

	ITM_SWITCH_SIM,

	ITM_EXIT,				//Exit

	DSN_ITM_CNT		//no. of design menu items ==> This should be the last line in this enum
};

// DONEBUTREVISE: you should add more items if needed
enum SimMenuItem //The items of the simulation menu
{
	//Note: Items are ordered here as they appear in menu

	//DONE:Add more items names here

	ITM_VALIDATE,
	ITM_RUN,			//Run

	ITM_SWITCH_DSN,

	SIM_ITM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
};


#ifndef NULL
	#define NULL 0
#endif

#endif