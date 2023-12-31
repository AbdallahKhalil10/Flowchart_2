#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "Statement.h"

//Value Assignment statement class
//The value assignment statement assigns a value to a variable
class Conditional : public Statement
{
private:
	string LHS;	//Left Handside of the assignment
	string RHS;	//Right Handside
	string OP; //operator ==,>=,<=,<,>,!=


	Connector* pOutConn;	//Value Assignment Stat. has one Connector to next statement
							//Each statement type in flowchart has a predefined number of (output) connectors
							//For example, conditional statement always has 2 output connectors

							//Note: We don't need to keep track with input connectors
							//      Whenever we want to iterate on all statements of the flowchart
							//      we will begin with start statement then its output connector
							//      then the connector's destination statement and so on (follow the connectors)

	Point Inlet;	//A point where connections enters this statement 
					//It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
					//It's used as the (Start) point of the (Output) connector

	Point LeftCorner;
	Point RightCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	Conditional(Point Lcorner, string LeftHS, string Op, string RightHS);

	void setLHS(const string& L);
	void setRHS(const string& R);
	void setOperator(const string& Op);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);

	virtual void Draw(Output* pOut) const;

	/// ////////////////////////////////////////////////////////////////////////////added
	virtual bool IsOnStat(Point P);   // check if the point in the statement area or not
	void setStatConnector(Connector* Conn);
	virtual Connector* getStatConnector(int ConnType);
	virtual Point GetConnectorPoint(int Order);

	//////////////////////////////////////////////////////


	string getLHS();
	
	string getRHS();

	string getOperator();
	

};

#endif