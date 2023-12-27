#include "Paste.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Paste::Paste(ApplicationManager* pAppManager) :Action(pAppManager)
{
	state = NULL;
}

void Paste::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please select the point to paste in: ");
	pIn->GetPointClicked(P);

	state = pManager->GetStatement(P);

	if (state != NULL) {
		pOut->PrintMessage("Can not paste in this location");
	}


}

void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (state == NULL) {
		state = pManager->GetClipboard();
		if (state == NULL) {
			pOut->PrintMessage("Nothing has been copied");
			return;
		}
		if (dynamic_cast<Start*>(state))
		{
			/*Start* copied_statement = dynamic_cast<Start*>(state);
			Statement* NewStatement = new Start(copied_statement.GetStartText, copied_statement.GetStartPoint);
			pManager->AddStatement(NewStatement);*/
		}
		else if (dynamic_cast<End*>(state))
		{
			
		}
		else if (dynamic_cast<ValueAssign*>(state))
		{
			
		}
		else if (dynamic_cast<VariableAssign*>(state))
		{
		
		}
		else if (dynamic_cast<OperatorAssign*>(state))
		{
		
		}
		else if (dynamic_cast<Read*>(state))
		{
			
		}
		else if (dynamic_cast<Write*>(state))
		{
			
		}
		else if (dynamic_cast<Conditional*>(state))
		{
			
		}
	}
	//pOut->PrintMessage("Pasted Successfully !!");

}