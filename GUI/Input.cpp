
#include "Input.h"
#include "Output.h"
#include "..\HelperFn.h"
#include <iostream>
using namespace std;

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point &P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}

string Input::GetString(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}


double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///TODO: add code to read a double value from the user and assign it to D
	string D;
	do {
		//pO->PrintMessage("Please enter a value: ");
		D = GetString(pO);
		if (IsValue(D)) {
			return stod(D);
		}
	} while (IsValue(D) == 0);
	
	//This function should make any needed validations on the entered text 
	// to make sure it is a double value (e.g. 12.5, -12.5, -23, -23., -23.0 �etc.).
	
	
	//Read a double value from the user
	
}

string Input::GetVariable(Output* pO) const {


	string D;
	do {
		pO->PrintMessage("Please enter a variable name: ");
		D = GetString(pO); // to include the space in the variable name
		if (IsVariable(D)) {
			return D;
		}
	} while (IsVariable(D) == 0);
}

string Input::GetArithOperator(Output* pO) const { 
	string D;
	do {
		pO->PrintMessage("Please enter an arithmetic operator: ");
		D = GetString(pO);
		if ((D == "+") || (D == "-") || (D == "*") || (D == "/")) {
			return D;
		}
	} while (true);
}

string Input::GetCompOperator(Output* pO) const {
	string D;
	do {
		pO->PrintMessage("Please enter a comparison operator: ");
		D = GetString(pO);
		if ((D == "==") || (D == "!=") || (D == ">") || (D == "<") || (D == ">=") || (D == "<=")) {
			return D;
		}
	} while (true);
}


ActionType Input::GetUserAction() const
{
	//This function reads the position where the user clicks to determine the desired action

	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_START: return ADD_START;
			case ITM_END: return ADD_END;
			case ITM_READ: return ADD_READ;
			case ITM_WRITE: return ADD_WRITE;
			case ITM_VALUE_ASSIGN: return ADD_VALUE_ASSIGN;
			case ITM_VARIABLE_ASSIGN: return ADD_VAR_ASSIGN;
			case ITM_OPERATOR_ASSIGN: return ADD_OPER_ASSIGN;
			case ITM_COND: return ADD_CONDITION;
			case ITM_ADD_CONNECTOR: return ADD_CONNECTOR;
			case ITM_SELECT: return SELECT;
			case ITM_DELETE: return DEL;
			case ITM_COPY: return COPY;
			case ITM_PASTE: return PASTE;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_SWITCH: return SWITCH_SIM_MODE;
			case ITM_EXIT: return EXIT;
			default: return DSN_TOOL;
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;
			else
				return OUTPUT_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MenuItemWidth);
			switch (ClickedItem)
			{
			case ITM_VALIDATE: return VALIDATE;
			case ITM_RUN: return RUN;
			case ITM_SWITCH_BACK: return SWITCH_DSN_MODE;

			}
		}
	}
}


Input::~Input()
{
}
