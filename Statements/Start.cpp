#include "Start.h"
#include <sstream>
#include <fstream>

using namespace std;

Start::Start(Point Lcorner, string text)

{ 
	////////////////////////////////////////////////////////////////////////////////////////added
	StatName = "Start";


	txt = text;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

string Start::GetStartText() {
	return StatName;
}
Point Start::GetStartPoint() {
	return LeftCorner;
}



void Start::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawStartStopStatements(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}



//This function should be called when LHS or RHS changes
void Start::UpdateStatementText()
{

	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << txt;
	Text = T.str();

}



/// 
/// //////////////////////////////////////////////////////////////////////////////// ADDED

bool Start::IsOnStat(Point P)
{
	if (P.x >= LeftCorner.x && P.x <= (LeftCorner.x + UI.ASSGN_WDTH))
		if (P.y >= LeftCorner.y && P.y <= (LeftCorner.y + UI.ASSGN_HI))
			return true;

	return false;
}
void Start::Save(ofstream& OutFile) {
	OutFile << "Start Statement" << "    " << "Statement ID: " << ID << "    "
		<< "point_1_X : " << LeftCorner.x << "  " << "point_1_Y : " << LeftCorner.y << endl;
}


void Start::Load(ifstream& InFile) {
	string temp;
	int ID;
	InFile >> temp;
	InFile >> temp;
	InFile >> temp;
	InFile >> ID;
	SetID(ID);
	InFile >> temp >> temp >> LeftCorner.x;
	InFile >> temp >> temp >> LeftCorner.y;

}


void Start::setStatConnector(Connector* Conn)
{
	pOutConn = Conn;
}


Connector* Start::getStatConnector(int ConnType)
{
	return pOutConn;
}

Point Start::GetConnectorPoint(int Order)
{
	if (Order == 0)
		return Outlet;
	else
	{
		return Inlet;
	}

}


