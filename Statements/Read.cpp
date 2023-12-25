#include "Read.h"
#include <sstream>
#include <fstream>

using namespace std;

Read::Read(Point Lcorner, string text)

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




void Read::setText(const string& R1)
{

	txt = R1;
	UpdateStatementText();
}



void Read::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawReadWriteStatement(RightCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}



//This function should be called when LHS or RHS changes
void Read::UpdateStatementText()
{

	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << "READ  " << txt;
	Text = T.str();

}




/// 
/// //////////////////////////////////////////////////////////////////////////////// ADDED

bool Read::IsOnStat(Point P)
{
	if (P.x >= LeftCorner.x && P.x <= (LeftCorner.x + UI.ASSGN_WDTH))
		if (P.y >= LeftCorner.y && P.y <= (LeftCorner.y + UI.ASSGN_HI))
			return true;

	return false;

}
void Read::Save(ofstream& OutFile) {
	OutFile << "Read Statement" << "    " << "Statement ID: " << ID << "    "
		<< "point_1_X : " << LeftCorner.x << "  " << "point_1_Y : " << LeftCorner.y << "    "
		<< "point_2_X : " << RightCorner.x << "  " << "point_2_Y : " << RightCorner.y << endl;

}