#include "Copy.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Copy::Copy(ApplicationManager* pAppManager) :Action(pAppManager)
{
	state = NULL;
}

void Copy::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please select the statement to be copied: ");
	pIn->GetPointClicked(P);

	state = pManager->GetStatement(P);

	if (state == NULL) {
		pOut->PrintMessage("Nothing has been selected");
	}

}

void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (state != NULL) {
		pManager->SetClipboard(state);
		pOut->PrintMessage("Copied Successfully !!");
	}
	

}