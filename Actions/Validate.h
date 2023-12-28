#ifndef VALIDATE_H
#define VALIDATE_H

#include "Action.h"
#include "..\Statements\Statement.h"


class Validate : public Action
{
private:

	bool IS_VALID;

	int start_stat_count ;
	int end_stat_count ;
	int conditional_stat_count ;
	int output_connectors_count ; // number of output connectors that must be so the chart will be valid


public:
	Validate(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif
