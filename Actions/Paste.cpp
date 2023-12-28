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
			//Start* copied_statement = dynamic_cast<Start*>(state);
			Statement* NewStatement = new Start(P, "Start");
			pManager->AddStatement(NewStatement);
		}
		else if (dynamic_cast<End*>(state))
		{
			//End* copied_statement = dynamic_cast<End*>(state);
			Statement* NewStatement = new End(P, "End");
			pManager->AddStatement(NewStatement);
		}
		else if (dynamic_cast<ValueAssign*>(state))
		{
			ValueAssign* copied_statement = dynamic_cast<ValueAssign*>(state);
			Statement* NewStatement = new ValueAssign(P, copied_statement->getLHS(), copied_statement->getRHS());
			pManager->AddStatement(NewStatement);

		}
		else if (dynamic_cast<VariableAssign*>(state))
		{
			VariableAssign* copied_statement = dynamic_cast<VariableAssign*>(state);
			Statement* NewStatement = new VariableAssign(P, copied_statement->getLHS(), copied_statement->getRHS());
			pManager->AddStatement(NewStatement);

		}
		else if (dynamic_cast<OperatorAssign*>(state))
		{
			OperatorAssign* copied_statement = dynamic_cast<OperatorAssign*>(state);
			Statement* NewStatement = new OperatorAssign(P, copied_statement->getLHS(), copied_statement->getRHS1(), copied_statement->getOperator(), copied_statement->getRHS2());
			pManager->AddStatement(NewStatement);
		}
		else if (dynamic_cast<Read*>(state))
		{
			Read* copied_statement = dynamic_cast<Read*>(state);
			Statement* NewStatement = new Read(P, copied_statement->getText());
			pManager->AddStatement(NewStatement);
		}
		else if (dynamic_cast<Write*>(state))
		{
			Write* copied_statement = dynamic_cast<Write*>(state);
			Statement* NewStatement = new Write(P, copied_statement->getText());
			pManager->AddStatement(NewStatement);

		}
		else if (dynamic_cast<Conditional*>(state))
		{
			Conditional* copied_statement = dynamic_cast<Conditional*>(state);
			Statement* NewStatement = new Conditional(P, copied_statement->getLHS(), copied_statement->getOperator(), copied_statement->getRHS());
			pManager->AddStatement(NewStatement);
		}
	}
	pOut->PrintMessage("Pasted Successfully !!");

}