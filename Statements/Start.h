#ifndef _START_H
#define  _START_H

#include "Statement.h"

class Start : public Statement
{
private:
	string txt;

	Connector* pOutConn;

	Point Inlet;	//A point where connections enters this statement 
	//It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	//It's used as the (Start) point of the (Output) connector

	Point LeftCorner;	//left corenr of the statement block.


	virtual void UpdateStatementText();

public:
	Start(Point Lcorner, string text);

	virtual void Draw(Output* pOut) const;


	/// ////////////////////////////////////////////////////////////////////////////added
	virtual bool IsOnStat(Point P);   // check if the point in the statement area or not

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);

};

#endif
