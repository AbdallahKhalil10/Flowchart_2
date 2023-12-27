#include "ApplicationManager.h"
#include "Actions\AddValueAssign.h"
#include "Actions\AddVariableAssign.h"
#include "Actions\AddOperatorAssign.h"
#include "Actions\AddStart.h"
#include "Actions\AddEnd.h"
#include "Actions\AddReadAssign.h"
#include "Actions\AddWriteAssign.h"
#include "Actions\AddConditionalAssign.h"
#include "Actions\Save.h"
#include "Actions\Load.h"
#include "Actions\Copy.h"
#include "Actions\Paste.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Actions\Select.h"
#include "Actions\AddConnector.h"



//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	Unique_ID = 0;
	Connector_Unique_ID = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	pClipboard = NULL;

	//////////////////////////////////////////////////////////////added
	pSelectedConn = NULL; 
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//


ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
		case ADD_VALUE_ASSIGN:
			pAct = new AddValueAssign(this);
			break;
		case ADD_VAR_ASSIGN:
			pAct = new AddVariableAssign(this);
			break;
		case ADD_OPER_ASSIGN:
			pAct = new AddOperatorAssign(this);
			break;
		case ADD_START:
			pAct = new AddStart(this);
			break;
		case ADD_END:
			pAct = new AddEnd(this);
			break;
		case ADD_READ:
			pAct = new AddReadAssign(this);
			break;
		case ADD_WRITE:
			pAct = new AddWriteAssign(this);
			break;
		case ADD_CONDITION:
			pAct = new AddConditionalAssign(this);
			break;	
		case SWITCH_SIM_MODE:
			pOut->ClearToolBar();
			pOut->CreateSimulationToolBar();
			break;
		case SWITCH_DSN_MODE:
			pOut->ClearToolBar();
			pOut->CreateDesignToolBar();
			break;
		case SAVE:
			pAct = new Save(this);
			break;
		case LOAD:
			pAct = new Load(this);
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case PASTE:
			pAct = new Paste(this);
			break;
		case SELECT:
			pAct = new Select(this);
			break;
		case ADD_CONNECTOR:
			pAct = new AddConnector(this);
			break;

		case EXIT:
			break;
		
		case STATUS:
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}



//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//


int ApplicationManager::GetStatementCount() {
	return StatCount;
}

void ApplicationManager::ClearStatementList() {
	for (int i = 0; i < StatCount; i++)
		delete StatList[i];
	StatCount = 0;
}
int ApplicationManager::GetConnectorCount() {
	return ConnCount;
}
Statement* ApplicationManager::GetStatementList(int j)
{
	return StatList[j];
}
Connector* ApplicationManager::GetConnectorList(int j)
{
	return ConnList[j];
}

//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	
	if (StatCount < MaxCount) {
		Unique_ID++;
		pStat->SetID(Unique_ID);
		StatList[StatCount++] = pStat;
	}


	
}




////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL

	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities
	
	for (int i = 0; i < StatCount; i++)
		if (StatList[i]->IsOnStat(P))
			return StatList[i];
	
	return NULL;
	
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement *ApplicationManager::GetClipboard() const
{	return pClipboard;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement *pStat)
{	pClipboard = pStat;	}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//


//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<ConnCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}









/////////////////////////////////////////////////////////////////////////////////////////  Added


void ApplicationManager::SetConnector(Connector* pConn)
{
	if (ConnCount < MaxCount)
		Connector_Unique_ID++;
	    pConn->Set_Connector_ID(Connector_Unique_ID);
		ConnList[ConnCount++] = pConn;

}



//returns the connector that is 
Connector* ApplicationManager::GetConnector(Point P) const
{

	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i]->IsOnConnect(P))
			return ConnList[i];

	return NULL;
}


Connector* ApplicationManager::GetSelectedConnector() const
{
	return pSelectedConn;
}

void ApplicationManager::SetSelectedConnector(Connector* pConn)
{
	pSelectedConn = pConn;
}




void ApplicationManager::UnSelect()
{
	if (GetSelectedStatement() != NULL)
	{

		GetSelectedStatement()->SetSelected(false);
		SetSelectedStatement(NULL);

	}
	
	else if (GetSelectedConnector() != NULL)
	{
		GetSelectedConnector()->SetSelected(false);
		SetSelectedConnector(NULL);

	}
	

	UpdateInterface();

}











