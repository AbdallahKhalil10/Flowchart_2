#ifndef LOAD_H
#define LOAD_H

#include "Action.h"
#include "..\Statements\Statement.h"


class Load : public Action
{
private:

	Statement* state;
    Connector* conn;
	string FileName;

public:
	Load(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif
