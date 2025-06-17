#include "Statement.h"


int Statement::LastID = 0;


Statement::Statement()	
{ 
	//DONE: set the ID with a unique value
	ID = LastID + 1;
	LastID++;
	Text = "";
	Selected = false;		
}


Point Statement::GetCenter() const
{
	return Center;
}

int Statement::GetID()
{
	return ID;
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }


Point Statement::getTopLeft()
{
	int x = Center.x - UI.ASSGN_WDTH / 2;
	int y = Center.y - UI.ASSGN_HI / 2;
	return Point(x, y);
}


Point Statement::getBottomRight()
{
	int x = Center.x + UI.ASSGN_WDTH / 2;
	int y = Center.y + UI.ASSGN_HI / 2;
	return Point(x, y);
}


bool Statement::IsPointIncluded(Point P)
{
	Point TopLeft = getTopLeft();
	Point BottomRight = getBottomRight();

	return (P.x >= TopLeft.x && P.x <= BottomRight.x && P.y >= TopLeft.y && P.y <= BottomRight.y);

}

string Statement::getLHS()
{
	return "0" ;
}
bool Statement::getRHSIsVar()
{
	return 0;
}
string Statement::getRHSVar()
{
	return "0" ;
}

string Statement::getFirstOperandVar()
{
	return "0" ;
}
string Statement::getSecondOperandVar()
{
	return "0";
}
bool Statement::getFirstOperandIsVar()
{
	return 0;
}
bool Statement::getSecondOperandIsVar()
{
	return 0;
}
bool Statement::ConnCheck(void)
{
	return 0;
}
