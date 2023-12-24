#include "Conditional.h"
#include <sstream>

using namespace std;

Conditional::Conditional(Point Lcorner, string LeftHS, string Op, string RightHS)
{

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

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
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
	if (P.x >= LeftCorner.x && P.x <= (LeftCorner.x + UI.ASSGN_WDTH))
		if (P.y >= LeftCorner.y && P.y <= (LeftCorner.y + UI.ASSGN_HI))
			return true;

	return false;

}