#include "AddReadAssign.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddReadAssign::AddReadAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddReadAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Read Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Please enter the variable value: ");
	read = pIn->GetString(pOut);
	


	//TODO: Ask the user in the status bar to enter the LHS and set the data member

	//TODO: Ask the user in the status bar to enter the RHS and set the data member

	//Note: You should validate the LHS to be variable name and RHS to be a value
	//      Call the appropriate functions for this.
}

void AddReadAssign::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;
<<<<<<< HEAD
	
=======

<<<<<<< Updated upstream
=======
>>>>>>> 3875352db6736c20257dbc78a6ad25f645c80d68
>>>>>>> Stashed changes
	Read* pAssign = new Read(Corner, read);
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}

