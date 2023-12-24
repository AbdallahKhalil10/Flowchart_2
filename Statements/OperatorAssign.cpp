#include "OperatorAssign.h"
#include <sstream>

using namespace std;

OperatorAssign::OperatorAssign(Point Lcorner, string LeftHS, string RightHS1, string Op, string RightHS2)

{
	LHS = LeftHS;
	RHS1 = RightHS1;
	OP = Op;
	RHS2 = RightHS2;

	UpdateStatementText();
	LeftCorner = Lcorner;

	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void OperatorAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}


void OperatorAssign::setRHS1(const string& R1)
{

	RHS1 = R1;
	UpdateStatementText();
}


void OperatorAssign::setOperator(const string& Op)
{

	if (Op == "+" || Op == "-" || Op == "*" || Op == "/")
		OP = Op;

	UpdateStatementText();
}


void OperatorAssign::setRHS2(const string& R2)
{
	RHS2 = R2;
	UpdateStatementText();
}



/// 
/// //////////////////////////////////////////////////////////////////////////////// ADDED

bool OperatorAssign::IsOnStat(Point P)
{
	if (P.x >= LeftCorner.x && P.x <= (LeftCorner.x + UI.ASSGN_WDTH))
		if (P.y >= LeftCorner.y && P.y <= (LeftCorner.y + UI.ASSGN_HI))
			return true;

	return false;

}



void OperatorAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}



//This function should be called when LHS or RHS changes
void OperatorAssign::UpdateStatementText()
{

	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " = " << RHS1 << OP << RHS2;
	Text = T.str();

}