#include "Statement.h"

Statement::Statement()	
{ 
	//TODO: set the ID with a unique value
	Text = "";
	Selected = false;

	
	/// /////////////////////////////////////////////////////////////////////////ADDED
	StatName = "";
	
	
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }





/// ///////////////////////////////////////////////////////////////////added

string Statement::GetStatmentName()
{
	return StatName;

}

void Statement::SetID(int num)
{
	ID = num;
}




