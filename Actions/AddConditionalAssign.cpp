#include "AddConditionalAssign.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddConditionalAssign::AddConditionalAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddConditionalAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Conditional Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Please enter the variable to be compared: ");
	first_Conditional_operand = pIn->GetString(pOut);
	pOut->PrintMessage("Please enter the comparison operator: ");
	comp = pIn->GetCompOperator(pOut);
	pOut->PrintMessage("Please enter a the variable or the value to be compared: ");
	second_Conditional_operand = pIn->GetString(pOut);



	//TODO: Ask the user in the status bar to enter the LHS and set the data member

	//TODO: Ask the user in the status bar to enter the RHS and set the data member

	//Note: You should validate the LHS to be variable name and RHS to be a value
	//      Call the appropriate functions for this.
}

void AddConditionalAssign::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Conditional* pAssign = new Conditional(Corner, first_Conditional_operand, comp, second_Conditional_operand);
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}

