#include "VariableAssign.h"
#include <sstream>
#include <fstream>

using namespace std;

VariableAssign::VariableAssign(Point Lcorner, string LeftHS, string RightHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void VariableAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void VariableAssign::setRHS(const string& R)
{
	RHS = R;
	UpdateStatementText();
}


void VariableAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void VariableAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " = " << RHS;
	Text = T.str();
}



/// 
/// //////////////////////////////////////////////////////////////////////////////// ADDED

bool VariableAssign::IsOnStat(Point P)
{
	if (P.x >= LeftCorner.x && P.x <= (LeftCorner.x + UI.ASSGN_WDTH))
		if (P.y >= LeftCorner.y && P.y <= (LeftCorner.y + UI.ASSGN_HI))
			return true;

	return false;

}
void VariableAssign::Save(ofstream& OutFile) {
	OutFile << "Variable_Assign Statement" << "    " << "Statement ID: " << ID << "    "
		<< "point_1_X : " << LeftCorner.x << "  " << "point_1_Y : " << LeftCorner.y << "    "
		<< "Left_Variable : " << LHS << "    " << "Right_Variable : " << RHS << endl;

}

void VariableAssign::Load(ifstream& InFile) {
	string temp;
	int ID;
	InFile >> temp;
	InFile >> temp;
	InFile >> temp;
	InFile >> ID;
	SetID(ID);
	InFile >> temp >> temp >> LeftCorner.x;
	InFile >> temp >> temp >> LeftCorner.y;
	InFile >> temp >> temp >> LHS;
	InFile >> temp >> temp >> RHS;
	UpdateStatementText();
}

