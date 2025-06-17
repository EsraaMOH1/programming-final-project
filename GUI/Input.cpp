
#include "Input.h"
#include "Output.h"
#include <math.h>


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}


void Input::GetPointClicked(Point& P) const
{
	pWind->FlushMouseQueue();
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}

string Input::GetString(Output* pO) const
{
	string Label;
	char Key;

	pWind->FlushKeyQueue();

	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///DONE: add code to read a double value from the user and return it

	//This function should make any needed validations on the entered text 
	//to make sure it is a double value (e.g. 12.5, -12.5, -23, -23., -23.0 etc.).

	//Defining variables
	string input;
	double Value = 0;
	bool IsNegative = false;
	
	//Read a double value from the user
	input = GetString(pO);

	//Make sure the value is valid
	while (!IsValue(input))
	{
		pO->PrintMessage("Please enter a valid value, then press enter");
		input = GetString(pO);
	}

	return StringToDouble(input);
}

string Input::GetVariable(Output* pO) const
{
	string input;

	//Read a variable name from the user
	input = GetString(pO);

	while (!IsVariable(input))
	{
		pO->PrintMessage("Please enter a valid variable name, then press enter");
		input = GetString(pO);
	}
	return input;
}

string Input::GetArithOperator(Output* pO) const
{
	string input;

	while (true)
	{
		input = GetString(pO);

		if ('\0' != input[0])
		{
			if (('+' == input[0] || '-' == input[0] || '*' == input[0] || '/' == input[0]) && ('\0' == input[1]))
			{
				break;
			}
		}pO->PrintMessage("Please enter a valid arithmetic operator, then press enter");
	}
	return input;
}

string Input::GetCompOperator(Output* pO) const
{
	string input;

	while (true)
	{
		input = GetString(pO);
		
		if ('\0' != input[0])
		{
			if ('\0' == input[1])
			{
				if (input[0] == '<' || input[0] == '>')
				{
					break;
				}
			}
			else if ('\0' == input[2])
			{
				if (('<' == input[0] || '>' == input[0] || '!' == input[0] || '=' == input[0]) && ('=' == input[1]))
				{
					break;
				}
			}
		}
		pO->PrintMessage("Please enter a valid comparator operator, then press enter");
	}
	return input;
}

ActionType Input::GetUserAction() const
{
	//This function reads the position where the user clicks to determine the desired action

	Point P;
	GetPointClicked(P);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (P.y >= 0 && P.y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (P.x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_VALUE_ASSIGN: return ADD_VALUE_ASSIGN;
			case ITM_VARIABLE_ASSIGN: return ADD_VAR_ASSIGN;
			case ITM_OPERATOR_ASSIGN: return ADD_OPER_ASSIGN;
			case ITM_READ: return ADD_READ;
			case ITM_WRITE: return ADD_WRITE;
			case ITM_START: return ADD_START;
			case ITM_END: return ADD_END;
			case ITM_COND: return ADD_CONDITION;
			case ITM_CONNECTOR: return ADD_CONNECTOR;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_DEL: return DEL;
			case ITM_SELECT: return SELECT;
			case ITM_EDIT: return EDIT_STAT;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_EXIT: return EXIT;
			case ITM_SWITCH_SIM: return SWITCH_SIM_MODE;
			default: return DSN_TOOL;
			}
		}

		//[2] User clicks on the drawing area
		if (P.y >= UI.ToolBarHeight && P.y < UI.height - UI.StatusBarHeight)
		{
			if (P.x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;
			else
				return OUTPUT_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{
		if (P.y >= 0 && P.y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (P.x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_VALIDATE: return VALIDATE;
			case ITM_RUN: return RUN;
			case ITM_EXIT: return EXIT;
			case ITM_SWITCH_DSN: return SWITCH_DSN_MODE;
			default: return SMN_TOOL;
			}
		}


		//DONEBUTREVISE: This should be changed after creating the compelete simulation bar 
		//return SWITCH_DSN_MODE;	// THIS SHOULD BE CHANGED
	}
}


Input::~Input()
{}
