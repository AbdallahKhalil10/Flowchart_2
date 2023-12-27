#ifndef _READ_H
#define  _READ_H

#include "Statement.h"

class Read : public Statement
{
private:
	string txt;

	Connector* pOutConn;

	Point Inlet;	//A point where connections enters this statement 
	//It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	//It's used as the (Start) point of the (Output) connector

	Point LeftCorner;	//left corenr of the statement block.
	Point RightCorner;  //Right corenr of the statement block.


	virtual void UpdateStatementText();

public:
	Read(Point Lcorner, string text);
	void setText(const string& R1);

	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);

	/// ////////////////////////////////////////////////////////////////////////////added
	virtual bool IsOnStat(Point P);   // check if the point in the statement area or not
	void setStatConnector(Connector* Conn);
	virtual Connector* getStatConnector(int ConnType);
	virtual Point GetConnectorPoint(int Order);
};

#endif