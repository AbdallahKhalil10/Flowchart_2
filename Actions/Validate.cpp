#include "Validate.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
#include <fstream>
#include <string>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Validate::Validate(ApplicationManager* pAppManager) :Action(pAppManager)
{
}


void Validate::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	

	 start_stat_count=0 ;
	 end_stat_count=0 ;
	 conditional_stat_count = 0;
	 output_connectors_count = 0; // number of output connectors that must be so the chart will be valid
	
	 int StatCount= pManager->GetStatementCount();
	 int ConnCount= pManager->GetConnectorCount();

	 
	for (int i = 0; i < StatCount; i++)
	{
		Statement *Stat=pManager->GetStatementList(i);

		if (Stat->GetStatmentName() == "Start") { start_stat_count++;  }
		else if (Stat->GetStatmentName() == "End") { end_stat_count++; }
		else if (Stat->GetStatmentName() == "Conditional") { conditional_stat_count++; } 
	
		if(Stat->GetStatmentName() == "Conditional"){ output_connectors_count += 2; }// condition statements should have 2 output connectors
		else if (Stat->GetStatmentName() == "End"){ } //do nothing because End statement Doesn't have output connector
		else {
			output_connectors_count += 1;
		}

	}

	if (StatCount == 0) {
		IS_VALID = false;
		pOut->PrintMessage("Error:there is no statements !");
	
	}
	else if (start_stat_count != 1 || end_stat_count != 1) //Chart MUST have exactly one Start and one End statements
	{
		IS_VALID = false;
		pOut->PrintMessage("Error:Chart MUST have exactly one Start and one End statements");
	}

	else if (output_connectors_count > ConnCount) //Chart MUST be  fully and correctly connected
	{
		IS_VALID = false;
		pOut->PrintMessage("Error: Incorrect number of the output connectors");
	}

	else {
		IS_VALID = true;
		pOut->PrintMessage("Validation Is Done successfully !");
	}


}

void Validate::Execute()
{

	
	ReadActionParameters();


}

