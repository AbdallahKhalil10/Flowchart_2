#include "Load.h"
#include "..\Statements\Conditional.h"
#include "..\Statements\Start.h"
#include "..\Statements\End.h"
#include "..\Statements\Read.h"
#include "..\Statements\Write.h"
#include "..\Statements\ValueAssign.h"
#include "..\Statements\VariableAssign.h"
#include "..\Statements\OperatorAssign.h"
#include "..\Connector.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
#include <fstream>
#include <string>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Load::Load(ApplicationManager* pAppManager) :Action(pAppManager)
{
	state = NULL;
	conn = NULL; //////////////added 

}

void Load::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please enter your file name: ");
	FileName = pIn->GetString(pOut);
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();

}

void Load::Execute()
{
	Output* pOut = pManager->GetOutput();
	string line;
	ReadActionParameters();
	ifstream saved_file{ FileName };
	int count_statement;
	int count_connector;
	int connector_ID;
	string statement_name;
	Point temp_point;
	Statement * temp_stat=NULL;
	temp_point.x = -1;
	temp_point.y = -1;
	
	string temp = "";

	pManager->ClearStatementList();
	saved_file >> count_statement;
	for (int i = 0; i < count_statement; i++) {
		saved_file >> statement_name;
		if (statement_name == "Conditional") {
			Conditional* st = new Conditional(temp_point,temp,temp,temp);
			st->Load(saved_file);
			pManager->AddStatement(st);
		}
		else if (statement_name == "Start") {
			Start* st = new Start(temp_point, "Start");
			st->Load(saved_file);
			pManager->AddStatement(st);
		}
		else if (statement_name == "End") {
			End* st = new End(temp_point, "End");
			st->Load(saved_file);
			pManager->AddStatement(st);
		}
		else if (statement_name == "Read") {
			Read* st = new Read(temp_point, temp);
			st->Load(saved_file);
			pManager->AddStatement(st);
		}
		else if (statement_name == "Write") {
			Write* st = new Write(temp_point, temp);
			st->Load(saved_file);
			pManager->AddStatement(st);
		}
		else if (statement_name == "Value_Assign") {
			ValueAssign* st = new ValueAssign(temp_point, temp);
			st->Load(saved_file);
			pManager->AddStatement(st);
		}
		else if (statement_name == "Variable_Assign") {
			VariableAssign* st = new VariableAssign(temp_point, temp);
			st->Load(saved_file);
			pManager->AddStatement(st);
		}
		else if (statement_name == "Operator_Assign") {
			OperatorAssign* st = new OperatorAssign(temp_point, temp, temp, temp, temp);
			st->Load(saved_file);
			pManager->AddStatement(st);
		}

	}

	saved_file >> count_connector;
	for (int i = 0; i < count_connector; i++) {
		saved_file >> connector_ID;

		Connector* Conn = new Connector(temp_stat, temp_stat);
		Conn->Load(saved_file);
		pManager->SetConnector(Conn);
	}

	pOut->PrintMessage("Loaded Successfully!!");
	saved_file.close();

}

