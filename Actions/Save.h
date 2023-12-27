#ifndef SAVE_H
#define SAVE_H

#include "Action.h"
#include "..\Statements\Statement.h"


class Save : public Action
{
private:

	Statement* state;
	Connector* Conn;
	string FileName;

public:
	Save(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

#endif
