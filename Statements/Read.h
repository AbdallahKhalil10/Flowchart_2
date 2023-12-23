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
<<<<<<< Updated upstream
	void setText(const string& R1);
=======
<<<<<<< HEAD

	void Read::setText(const string& R1);
=======
	void setText(const string& R1);
>>>>>>> 3875352db6736c20257dbc78a6ad25f645c80d68
>>>>>>> Stashed changes

	virtual void Draw(Output* pOut) const;

};

#endif