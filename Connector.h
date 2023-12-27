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
	Point Start;	//Start point of the connector
	Point End;		//End point of the connector


	//////////////////////////////////////////////////////////////////////////////added
	int SrcID;			//the ID of source statement
	int DstID;			// the ID of destination statement
	int ConnType;		//the connection type -- it's always equal 0 except Condition statement = 1
	bool Selected;

	int Connector_ID;


public:
	Connector(Statement* Src, Statement* Dst);

	void		setSrcStat(Statement *Src);
	Statement*	getSrcStat();	
	void		setDstStat(Statement *Dst);
	Statement*	getDstStat();

	void setStartPoint(Point P);
	Point getStartPoint();

	void setEndPoint(Point P);
	Point getEndPoint();

	void Draw(Output* pOut) const;

	/// <summary>
	/// //////////////////////////////////////////////////////////////////////////////added
	/// </summary>
	/// <param name="s"></param>
	void SetSelected(bool s);
	bool IsSelected() const;
	bool IsOnConnect(Point P);

	void Load(ifstream& InFile);
	void Save(ofstream& OutFile);
	
	void Set_Connector_ID(int num);

};

#endif







