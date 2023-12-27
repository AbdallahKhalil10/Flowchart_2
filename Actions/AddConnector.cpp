

#include "AddConnector.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddConnector::AddConnector(ApplicationManager* pAppManager) :Action(pAppManager)
{
	ConnType = 0;
}

void AddConnector::ReadActionParameters()
{
	double branch;
	Point P;
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	Statement* test_stat;


	do {
		pOut->PrintMessage("Click on the first statement"); //connect the connector with the first selected statement
		pIn->GetPointClicked(Position);
		test_stat= pManager->GetStatement(Position);
		
	} while (pManager->GetStatement(Position) == NULL || test_stat->GetStatmentName() == "End"); //  END statment cannot be selected as first statment
	
	pOut->ClearStatusBar();
	SrcStat = pManager->GetStatement(Position);
	
	///////////////////////////////////////

	do {
		pOut->PrintMessage("Click on the Second statement"); //connect the connector with the second selected statement
		pIn->GetPointClicked(Position);
		test_stat = pManager->GetStatement(Position);
	
	} while (pManager->GetStatement(Position) == NULL || test_stat->GetStatmentName() == "Start"); //  Start statment cannot be selected as second statment
	
	pOut->ClearStatusBar();
	DstStat = pManager->GetStatement(Position);
	
	


	if (SrcStat->GetStatmentName() == "Conditional")
	{
		ConnType = 1; //the connection type -- it's always equal 0 except Condition statement = 1
		do {
			
			pOut->PrintMessage("Enter (1:YES branch, 2:NO branch)");
			branch = pIn->GetValue(pOut);

		} while (branch != 1 && branch != 2);


		if (branch == 1) 
		{
			Start = SrcStat->GetConnectorPoint(3); //outlet point for yes branch
		}
		else if(branch == 2)
		{
			Start = SrcStat->GetConnectorPoint(4); //outlet point for no branch
		}

	}
	
	else 
	{
		ConnType = 0;
		Start = SrcStat->GetConnectorPoint(0); //GetConnectorPoint(0) is the outlet point of the first statement(not conditional)
	}

	End = DstStat->GetConnectorPoint(1);   //GetConnectorPoint(1) is the inlet point of the second statement
	

}



void AddConnector::Execute()
{
	ReadActionParameters();

	Connector* pConnect = new Connector(SrcStat, DstStat);

	pConnect->setStartPoint(Start);
	pConnect->setEndPoint(End);

	//pConnect->setSrcID(SrcStat->GetID());
	//pConnect->setDstID(DstStat->GetID());
	//pConnect->setConnType(ConnType);

	pManager->SetConnector(pConnect);

	//SrcStat->setStatConnector(pConnect);

	//pManager->setEditedDesign(true);

	//pManager->UndoRedo();
}