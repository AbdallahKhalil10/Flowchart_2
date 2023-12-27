#ifndef PASTE_H
#define PASTE_H

#include "Action.h"
#include "AddStart.h"
#include "AddEnd.h"
#include "AddValueAssign.h"
#include "AddVariableAssign.h"
#include "AddOperatorAssign.h"
#include "AddReadAssign.h"
#include "AddWriteAssign.h"
#include "AddConditionalAssign.h"
#include "..\Statements\Statement.h"


class Paste : public Action
{
private:

	Statement* state;

public:
	Paste(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

#endif
