#pragma once

#ifndef ADD_OPERATOR_ASSIGN_H
#define ADD_OPEARATOR_ASSIGN_H

#include "Action.h"
#include "..\Statements\OperatorAssign.h"

//Add Value Assignment Statement Action
//This class is responsible for 
// 1 - Getting Assignment stat. coordinates from the user (one of the parameters of this action)
// 2 - Getting the LHS and RHS of the statement from the user (some of the parameters of this action)
// 3 - Creating an object of Assignment class and passing it parameters
// 4 - Adding the created object to the list of statements of the application manager
class AddOperatorAssign : public Action
{
private:
	// in the data members of the actions
	// we put the paramaters of the action
	// to be set in ReadActionParameters() then used in Execute()

	Point Position;
	string LHS;
	string oper;
	string first_operand;
	string second_operand;
	//Position where the user clicks to add the stat.
	//TODO: you should add LHS and RHS of the assignment statement as parameters

public:
	AddOperatorAssign(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

#endif
