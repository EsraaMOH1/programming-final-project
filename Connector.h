#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "GUI\UI_Info.h"
#include "GUI\output.h"
class Statement;

class Connector	//a connector that connects two statements (Source & Destination)
{
private:
	Statement *SrcStat;	//The source statement of the connector
	Statement *DstStat;	//The destination statement of the connector
	Point Start;		//Start point of the connector
	Point End;			//End point of the connector
	bool Selected;		//Whether the connector is selected

public:
	Connector(Statement* Src, Statement* Dst, Point S, Point E);

	void		setSrcStat(Statement *Src);
	Statement*	getSrcStat();	
	void		setDstStat(Statement *Dst);
	Statement*	getDstStat();

	void setStartPoint(Point P);
	Point getStartPoint();

	void setEndPoint(Point P);
	Point getEndPoint();

	void SetSelectedConn(bool s);
	bool IsSelectedConn() const;

	void Draw(Output* pOut) const;

	Point getTopLeft();
	Point getBottomRight();

	bool IsPointIncluded(Point P);

	void Save(ofstream& OutFile) const;	//Save the Connector parameters to a file
};

#endif