#include "Save.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
#include <fstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Save::Save(ApplicationManager* pAppManager) :Action(pAppManager)
{
	state = NULL;

}

void Save::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please enter your file name: ");
	FileName = pIn->GetString(pOut);
	pOut->ClearStatusBar();
}

void Save::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ofstream saved_file{ FileName };

	saved_file << pManager->GetStatementCount() << endl;
	for (int i = 0; i < pManager->GetStatementCount(); i++)
	{
		state = pManager->GetStatementList(i);
		state->Save(saved_file);
	}
	/*saved_file << pManager->GetConnectorCount() << endl;
	for (int i = 0; i < pManager->GetConnectorCount(); i++)
	{
		Conn = pManager->GetConnectorList(i);
		Conn->Save(saved_file);
	}*/
	pOut->PrintMessage("Saved Successfully !!");
	saved_file.close();
}

