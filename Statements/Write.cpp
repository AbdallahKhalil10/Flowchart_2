#include "Write.h"
#include <sstream>

using namespace std;

Write::Write(Point Lcorner, string text)

{
	txt = text;

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




void Write::setText(const string& R1)
{

	txt = R1;
	UpdateStatementText();
}



void Write::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawReadWriteStatement(RightCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}



//This function should be called when LHS or RHS changes
void Write::UpdateStatementText()
{

	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << "Write  " << txt;
	Text = T.str();

}



/// 
/// //////////////////////////////////////////////////////////////////////////////// ADDED

bool Write::IsOnStat(Point P)
{
	if (P.x >= LeftCorner.x && P.x <= (LeftCorner.x + UI.ASSGN_WDTH))
		if (P.y >= LeftCorner.y && P.y <= (LeftCorner.y + UI.ASSGN_HI))
			return true;

	return false;
}