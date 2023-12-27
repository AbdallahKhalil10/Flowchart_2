#include "Conditional.h"
#include <sstream>
#include <fstream>

using namespace std;

Conditional::Conditional(Point Lcorner, string LeftHS, string Op, string RightHS)
{

	////////////////////////////////////////////////////////////////////////////////////////added
	StatName = "Conditional";

	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	LHS = LeftHS;
    OP = Op;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;
	RightCorner.x = Lcorner.x + UI.ASSGN_WDTH;
	RightCorner.y = Lcorner.y;

	pOutConn = NULL;	//No connectors yet


}

void Conditional::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void Conditional::setRHS(const string& R)
{
	RHS = R;
	UpdateStatementText();
}

void Conditional::setOperator(const string& Op)
{

	if (Op == "==" || Op == "!=" || Op == "<" || Op == ">" || Op == "<=" || Op == ">=")
		OP = Op;

	UpdateStatementText();
}


void Conditional::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw conditional statement 	
	pOut->DrawConditionalStatement(RightCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void Conditional::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << OP << RHS;
	Text = T.str();
}





/// 
/// //////////////////////////////////////////////////////////////////////////////// ADDED


bool Conditional::IsOnStat(Point P)
{
	if( (P.x< RightCorner.x ) && (P.x >(RightCorner.x ) - UI.ASSGN_WDTH) &&( P.y < (RightCorner.y + 40)) &&( P.y > (RightCorner.y + 40) - UI.ASSGN_HI) )
	return true;

return false;


}




void Conditional::Save(ofstream & OutFile) {
	OutFile << "Conditional Statement" << "    " << "Statement ID: " << ID << "    "
		<< "point_1_X : " << LeftCorner.x << "  " << "point_1_Y : " << LeftCorner.y << "    "
		<< "point_2_X : " << RightCorner.x << "  " << "point_2_Y : " << RightCorner.y << "    "
		<< "Left_operator : " << LHS << "    " << "Comparison_operator : " << OP << "    " << "Right_operator : " << RHS << endl;

}


void Conditional::Load(ifstream& InFile) {
	string temp;
	int ID;
	InFile >> temp;
	InFile >> temp;
	InFile >> temp;
	InFile >> ID;
	SetID(ID);
	InFile >> temp >> temp >> LeftCorner.x;
	InFile >> temp >> temp >> LeftCorner.y;
	InFile >> temp >> temp >> RightCorner.x;
	InFile >> temp >> temp >> RightCorner.y;
	InFile >> temp >> temp >> LHS;
	InFile >> temp >> temp >> OP;
	InFile >> temp >> temp >> RHS;
	UpdateStatementText();

}

void Conditional::setStatConnector(Connector* Conn)
{
	pOutConn = Conn;
}


Connector* Conditional::getStatConnector(int ConnType)
{
	return pOutConn;
}


Point Conditional::GetConnectorPoint(int Order)
{
	if (Order == 3)  //outlet point for Yes branch
	{
		Outlet.x = LeftCorner.x;
		Outlet.y = (LeftCorner.y + 40) - (UI.ASSGN_HI / 2);
		return Outlet;
	}
	else if  (Order==4) //outlet point for no branch 
	{
		Outlet.x = RightCorner.x;
		Outlet.y = (LeftCorner.y + 40) - (UI.ASSGN_HI / 2);
		return Outlet;
	}
	else 
	{
		Inlet.x = (RightCorner.x) - UI.ASSGN_WDTH / 2;
		Inlet.y = (LeftCorner.y + 40) - UI.ASSGN_HI;
		return Inlet;
	}

}