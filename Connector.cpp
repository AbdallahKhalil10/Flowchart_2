#include "Connector.h"

#include <sstream>
#include <fstream>

using namespace std;


Connector::Connector(Statement* Src, Statement* Dst)	
//When a connector is created, it must have a source statement and a destination statement
//There are NO FREE connectors in the flowchart
{
	
	SrcStat = Src;
	DstStat = Dst;

	///////////////////////////////////////////////////////////////////////////////////////////////added
	ConnType = 0;
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

void Connector::Draw(Output* pOut) const
{
	///TODO: Call Output to draw a connector from SrcStat to DstStat on the output window
	pOut->DrawConnector(Start, End, Selected);
}






///////////////////////////////////////////////////////added


void Connector::Save(ofstream& OutFile) {

	OutFile << "Conncetor ID: " << Connector_ID << " Source: " << SrcStat << " Destination: " << DstStat << endl;
}


void Connector::Load(ifstream& InFile) {
	string temp;
	int ID;
	Statement* SORC;
	Statement* DEST;

	InFile >> temp >> ID >> temp >> (Statement * )SORC >> temp >> (Statement*) DEST;
	Set_Connector_ID(ID);
	setSrcStat(SORC);
	setDstStat(DEST);

}







void Connector::SetSelected(bool s)
{
	Selected = s;
}

bool Connector::IsSelected() const
{
	return Selected;
}




bool Connector::IsOnConnect(Point P)
{
	
		//up straight arrow
		if (End.y > Start.y && End.x == Start.x)
		{
			if (P.x <= Start.x + 10 &&P.x >= Start.x -10 && P.y >= Start.y && P.y <= End.y)
				return true;
			else 
			{
				return false;
			}
		}
	// down straight arrow
		else if (End.y < Start.y && End.x == Start.x)
		{
			if (P.x <= Start.x + 10 && P.x >= Start.x - 10 && P.y <= Start.y && P.y >= End.y)
				return true;
			else
			{
				return false;
			}
		}


	/// Down arrow to the right
		else if ((End.y > Start.y + 20 && End.x > Start.x) )
		{
			
			if ( (P.x >= Start.x  && P.x <= End.x && P.y <= Start.y +10 && P.y >= Start.y - 10) || (P.x >= End.x - 10 && P.x <= End.x + 10 && P.y >= Start.y && P.y <= End.y) )

				return true;
			else
			{
				return false;
			}


		}
		
	/// Down arrow to the left
		else if (End.y > Start.y + 20 && End.x < Start.x)
		{

			if ((P.x <= Start.x && P.x >= End.x && P.y <= Start.y + 10 && P.y >= Start.y - 10) || (P.x >= End.x - 10 && P.x <= End.x + 10 && P.y >= Start.y && P.y <= End.y))

				return true;
			else
			{
				return false;
			}


		}

		
	/*	/// Up arrow (not straight)
		else if ((End.y + 20 < Start.y && End.x > Start.x) || (End.y + 20 < Start.y && End.x < Start.x))
		{
		if ((P.x >= Start.x && P.x <= End.x && P.y == Start.y) || (P.x <= Start.x && P.x >= End.x && P.y == Start.y) || (P.y <= Start.y && P.y >= End.y && P.x == End.x))
			return true;
		}*/

		else {
			return false;
		}
}



void Connector::Set_Connector_ID(int num)
{
	Connector_ID = num;
}