#include "Delete.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Delete::Delete(ApplicationManager* pAppManager) :Action(pAppManager)
{
	state = NULL;
}

void Delete::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please select Statement/Connector to Delete");
	pIn->GetPointClicked(P);

	state = pManager->GetStatement(P);
	Conn = pManager->GetConnector(P);


	if (state != NULL)
	{

		for (int i = 0; i < pManager->GetStatementCount(); i++)
		{
			if (pManager->GetStatementList(i) == state)
			{
				pManager->DeleteStatement(i);
			}

		}
			
	}

	if (Conn != NULL)
	{

		for (int i = 0; i < pManager->GetConnectorCount(); i++)
		{
			if (pManager->GetConnectorList(i) == Conn)
			{
				pManager->DeleteConnector(i);
			}

		}

	}
	 
	else {

		pOut->PrintMessage("Nothing selected to Delete");
	}


}

void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();


}





