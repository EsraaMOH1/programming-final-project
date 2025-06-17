#include "Output.h"


#define TRIANGLE_VERTICES_CNT		3u
#define DIAMOND_VERTICES_CNT		4u
#define PARALLELOGRAM_VERTICES_CNT	4u
#define INV_TAN_60					0.577F


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1200;
	UI.height = 620;
	UI.wx = 15;
	UI.wy = 15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y)
{
	return new window(w, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//DONE: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode
	
	//fill the tool bar 
		
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem

	//DONE: Prepare images for each menu item and add it to the list

	string MenuItemImages[DSN_ITM_CNT];

	MenuItemImages[ITM_START] = "images\\resizedJPGs\\StatStart.jpg";
	MenuItemImages[ITM_END] = "images\\resizedJPGs\\StatEnd.jpg";
	MenuItemImages[ITM_VALUE_ASSIGN] = "images\\resizedJPGs\\StatAssignVal.jpg";
	MenuItemImages[ITM_VARIABLE_ASSIGN] = "images\\resizedJPGs\\StatAssignVar.jpg";
	MenuItemImages[ITM_OPERATOR_ASSIGN] = "images\\resizedJPGs\\StatAssignOp.jpg";
	MenuItemImages[ITM_COND] = "images\\resizedJPGs\\StatCond.jpg";
	MenuItemImages[ITM_READ] = "images\\resizedJPGs\\StatRead.jpg";
	MenuItemImages[ITM_WRITE] = "images\\resizedJPGs\\StatWrite.jpg";

	MenuItemImages[ITM_CONNECTOR] = "images\\resizedJPGs\\Connector.jpg";

	MenuItemImages[ITM_SELECT] = "images\\resizedJPGs\\Select.jpg";
	MenuItemImages[ITM_EDIT] = "images\\resizedJPGs\\Edit.jpg";
	MenuItemImages[ITM_DEL] = "images\\resizedJPGs\\Delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\resizedJPGs\\Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\resizedJPGs\\Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\resizedJPGs\\Paste.jpg";

	MenuItemImages[ITM_SAVE] = "images\\resizedJPGs\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\resizedJPGs\\Load.jpg";

	MenuItemImages[ITM_SWITCH_SIM] = "images\\resizedJPGs\\SwitchSim.jpg";
	
	MenuItemImages[ITM_EXIT] = "images\\resizedJPGs\\Exit.jpg";

	//Clear simulation toolbar
	ClearToolBar();

	//Draw menu item one image at a time
	for (int i = 0; i < DSN_ITM_CNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////
//DONE: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	UI.AppMode = SIMULATION;	//Design Mode

	//fill the tool bar 

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem

	//DONE: Prepare images for each menu item and add it to the list

	string MenuItemImages[SIM_ITM_CNT];

	MenuItemImages[ITM_VALIDATE] = "images\\resizedJPGs\\Validate.jpg";
	MenuItemImages[ITM_RUN] = "images\\resizedJPGs\\Run.jpg";

	MenuItemImages[ITM_SWITCH_DSN] = "images\\resizedJPGs\\SwitchDsgn.jpg";

	//Clear design toolbar
	ClearToolBar();

	//Draw menu item one image at a time
	for (int i = 0; i < SIM_ITM_CNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(WHITE, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight = 50);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Center, int width, int height, string Text, bool Selected)
{
	//Getting vertices
	Point UpperLeft, LowerRight;

	UpperLeft.x = Center.x - width / 2;
	UpperLeft.y = Center.y - height / 2;

	LowerRight.x = UpperLeft.x + width;
	LowerRight.y = UpperLeft.y + height;

	//if stat is selected, it should be highlighted
	if (Selected)
	{
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	}
	else
	{
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	}

	//Draw the statement block rectangle
	pWind->DrawRectangle(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(UpperLeft.x + width/8, Center.y - 9, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawCondition(Point Center, int width, int height, string Text, bool Selected)
{
	//Getting vertices
	Point UpperCenter, LowerCenter, CenterLeft, CenterRight;

	UpperCenter.x = LowerCenter.x = Center.x;
	UpperCenter.y = Center.y - height / 2;
	LowerCenter.y = UpperCenter.y + height;

	CenterLeft.y = CenterRight.y = Center.y;
	CenterLeft.x = Center.x - width / 2;
	CenterRight.x = CenterLeft.x + width;

	//if stat is selected, it should be highlighted
	if (Selected)
	{
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	}
	else
	{
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	}

	//Draw the statement block diamond
	int XCoords[DIAMOND_VERTICES_CNT] = { CenterLeft.x, UpperCenter.x, CenterRight.x, LowerCenter.x };
	int YCoords[DIAMOND_VERTICES_CNT] = { CenterLeft.y, UpperCenter.y, CenterRight.y, LowerCenter.y };
	pWind->DrawPolygon(XCoords, YCoords, DIAMOND_VERTICES_CNT);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(CenterLeft.x + width / 3, Center.y - 9, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawStart(Point Center, int width, int height, bool Selected)
{
	//Getting vertices
	Point UpperLeft, LowerRight;

	UpperLeft.x = Center.x - width / 2;
	UpperLeft.y = Center.y - height / 2;

	LowerRight.x = UpperLeft.x + width;
	LowerRight.y = UpperLeft.y + height;

	//if stat is selected, it should be highlighted
	if (Selected)
	{
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	}
	else
	{
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	}

	//Draw the statement block oval
	pWind->DrawEllipse(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Center.x - 21, Center.y - 9, "Start");
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawEnd(Point Center, int width, int height, bool Selected)
{
	//Getting vertices
	Point UpperLeft, LowerRight;

	UpperLeft.x = Center.x - width / 2;
	UpperLeft.y = Center.y - height / 2;

	LowerRight.x = UpperLeft.x + width;
	LowerRight.y = UpperLeft.y + height;

	//if stat is selected, it should be highlighted
	if (Selected)
	{
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	}
	else
	{
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	}

	//Draw the statement block oval
	pWind->DrawEllipse(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Center.x - 15, Center.y - 9, "End");
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawInputOutput(Point Center, int width, int height, string Text, bool Selected)
{
	//Getting vertices
	Point UpperLeft, UpperRight, LowerLeft, LowerRight;

	UpperLeft.y = UpperRight.y = Center.y - height / 2;
	LowerLeft.y = LowerRight.y = UpperLeft.y + height;

	int XOffset = height * INV_TAN_60;
	LowerLeft.x = Center.x - width / 2;
	UpperLeft.x = LowerLeft.x + XOffset;
	UpperRight.x = LowerLeft.x + width;
	LowerRight.x = UpperRight.x - XOffset;

	//if stat is selected, it should be highlighted
	if (Selected)
	{
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	}
	else
	{
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	}

	//Draw the statement block diamond
	int XCoords[PARALLELOGRAM_VERTICES_CNT] = { UpperLeft.x, UpperRight.x, LowerRight.x, LowerLeft.x };
	int YCoords[PARALLELOGRAM_VERTICES_CNT] = { UpperLeft.y, UpperRight.y, LowerRight.y, LowerLeft.y };
	pWind->DrawPolygon(XCoords, YCoords, PARALLELOGRAM_VERTICES_CNT);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(UpperLeft.x, Center.y - 9, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawConnector(Point Start, Point End, bool Selected)
{
	//if stat is selected, it should be highlighted
	if (Selected)
	{
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
		pWind->SetBrush(UI.HighlightColor);
	}
	else
	{
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
		pWind->SetBrush(UI.DrawColor);
	}
		
	//Drawing Tail
	int MidPointY = (Start.y + End.y) / 2;
	pWind->DrawLine(Start.x, Start.y, Start.x, MidPointY);	//Vertical Tail
	pWind->DrawLine(Start.x, MidPointY, End.x, MidPointY);	//Horizontal Tail
	pWind->DrawLine(End.x, MidPointY, End.x, End.y - 9);	//Vertical Head
	
	//Down Facing Triangle
	int XCoords[TRIANGLE_VERTICES_CNT];
	int YCoords[TRIANGLE_VERTICES_CNT];
	XCoords[0] = End.x;
	XCoords[1] = End.x - 4;
	XCoords[2] = End.x + 4;
	YCoords[0] = End.y;
	YCoords[1] = End.y - 8;
	YCoords[2] = End.y - 8;
	pWind->DrawTriangle(XCoords[0], YCoords[0], XCoords[1], YCoords[1], XCoords[2], YCoords[2]);
}

//DONE: Add similar functions for drawing all other statements.
//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
//		Decide the parameters that should be passed to each of them
	
//DONE: Add DrawConnector function

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
