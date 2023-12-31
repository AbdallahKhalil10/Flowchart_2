#ifndef _OPERATORASSIGN_H
#define  _OPERATORASSIGN_H

#include "Statement.h"

class OperatorAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS1;
	string OP;
	string RHS2;

	Connector* pOutConn;

	Point Inlet;	//A point where connections enters this statement 
	//It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	//It's used as the (Start) point of the (Output) connector

	Point LeftCorner;	//left corenr of the statement block.


	virtual void UpdateStatementText();

public:
	OperatorAssign(Point Lcorner, string LeftHS, string RightHS1, string Op, string RightHS2);

	void setLHS(const string& L);
	void setRHS1(const string& R1);
	void setOperator(const string& Op);
	void setRHS2(const string& R2);


	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);

	/// ////////////////////////////////////////////////////////////////////////////added
	virtual bool IsOnStat(Point P);   // check if the point in the statement area or not

	void setStatConnector(Connector* Conn);

	virtual Connector* getStatConnector(int ConnType);

	virtual Point GetConnectorPoint(int Order);



	string getLHS();
	string getRHS1();
	string getOperator();
	string getRHS2();


};

#endif