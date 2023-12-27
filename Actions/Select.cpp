
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
	Conn = pManager->GetConnector(Position);

	

    if (Stat != NULL)
	{
		if (Stat->IsSelected() == false) 
		{
			pManager->UnSelect();
			pManager->SetSelectedStatement(Stat);
			Stat->SetSelected(true);
		}
		else if (Stat->IsSelected() != false) /// if the statment is already selected it will be unselected
		{
			Stat->SetSelected(false);
			pManager->UnSelect();
		}
	 }

	else if (Conn != NULL)
	{

		if (Conn->IsSelected() == false)
		{
			pManager->UnSelect();
			pManager->SetSelectedConnector(Conn);
			Conn->SetSelected(true);
		}
		else if (Conn->IsSelected() != false)  
		{
			Conn->SetSelected(false);
			pManager->UnSelect();
		}

	}
	
	else {
		pManager->UnSelect();
	}
	
}
void Select::Execute()
{
	ReadActionParameters();


	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	if (Stat != NULL) {
		
		pOut->PrintMessage(Stat->GetStatmentName());
	
	}

	else if (Conn != NULL) {

		pOut->PrintMessage("Connector is selected");

	}
	else
	{
		pOut->PrintMessage("Nothing selected");
	
	}
}