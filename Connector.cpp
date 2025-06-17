#include "Connector.h"
#include "Statements/Statement.h"

Connector::Connector(Statement* Src, Statement* Dst, Point S, Point E)	
//When a connector is created, it must have a source statement and a destination statement
//There are NO FREE connectors in the flowchart
{
	SrcStat = Src;
	DstStat = Dst;
	Start = S;
	End = E;
	Selected = false;
}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}


void Connector::setStartPoint(Point P)
{	Start = P;	}

Point Connector::getStartPoint()
{	return Start;	}

void Connector::setEndPoint(Point P)
{	End = P;	}

Point Connector::getEndPoint()
{	return End;	}

void Connector::SetSelectedConn(bool s)
{
	Selected = s;
}

bool Connector::IsSelectedConn() const
{
	return Selected;
}

void Connector::Draw(Output* pOut) const
{
	pOut->DrawConnector(Start, End, Selected);
	///DONE: Call Output to draw a connector from SrcStat to DstStat on the output window
}


bool Connector::IsPointIncluded(Point P)
{
	Point TopLeft = getStartPoint();
	Point BottomRight = getEndPoint();

	return (P.x >= TopLeft.x && P.x <= BottomRight.x && P.y >= TopLeft.y && P.y <= BottomRight.y);
}

void Connector::Save(ofstream& OutFile) const
{
	Connector* pConn[2];
	unsigned short NumConn = 0;
	OutFile << SrcStat->GetID() << "\t";
	OutFile << DstStat->GetID() << "\t";
	NumConn = SrcStat->GetOutputConnectors(pConn);

	if (1 == NumConn)
	{
		OutFile << 0 << "\n";
	}
	else
	{
		if (this == pConn[0])
		{
			OutFile << 1 << "\n";
		}
		else
		{
			OutFile << 2 << "\n";
		}
	}
}