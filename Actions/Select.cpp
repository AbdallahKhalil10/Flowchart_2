
#include "Select.h"

#include "..\Statements\Statement.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

Select::Select(ApplicationManager* pAppManager) :Action(pAppManager)
{
	Stat = NULL; Conn = NULL;
}


void Select::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	
	pOut->PrintMessage("SELECT STATEMENT");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	Stat = pManager->GetStatement(Position);
	//Conn = pManager->GetConnector(Position);
	pManager->UnSelect();
	if (Stat != NULL)
	{
		pManager->SetSelectedStatement(Stat);
		Stat->SetSelected(true);
	}
	/*
	else if (Conn != NULL)
	{
		pManager->SetSelectedConnector(Conn);
		Conn->SetSelected(true);
	}
	*/
}
void Select::Execute()
{
	ReadActionParameters();


	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	if (Stat != NULL)
		//pOut->PrintMessage("selected");
		Stat->PrintInfo(pOut);
	else
		pOut->PrintMessage("Nothing selected");
		//pOut->ClearStatusBar();
}