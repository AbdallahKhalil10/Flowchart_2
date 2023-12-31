#ifndef STATEMENT_H
#define STATEMENT_H

#include "..\defs.h"
#include "..\Connector.h"
//class Output;
#include "..\GUI\Output.h"

class ApplicationManger;

//Base class for all Statements
class Statement
{
protected:
	int ID;			//Each Statement has an ID --> must be unique
	string Text;	//Statement text (e.g.  "X = 5" OR "salary > 3000" and so on)
	bool Selected;	//true if the statement is selected on the folwchart


	
	
	/// //////////////////////////////////////////////////////////////////////////////////////////added
	string StatName;// name of statement 
	////////////////////////////////////////////////////////////////////////////////////////////
	

	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	Statement();
	void SetSelected(bool s);
	bool IsSelected() const;
	void SetID(int num);
	virtual void Save(ofstream& OutFile) = 0;
	virtual void Load(ifstream& InFile) =0;

	virtual void Draw(Output* pOut) const  = 0 ;	//Draw the statement
	

	

	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type

	//virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file
	//virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file

	//virtual void Edit() = 0;		//Edit the Statement parameter

	//virtual void Simulate();	//Execute the statement in the simulation mode

	//[BONUS] virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file


	///TODO: Add more functions if needed


	//////////////////////////////////////////////////////////////////////////////////////////////////////////added

	virtual bool IsOnStat(Point P) = 0;  // check if the point in the statement area or not

	virtual void setStatConnector(Connector* Conn) = 0;

	virtual Connector* getStatConnector(int ConnType) = 0;	//get the exit connector of the statement

	virtual Point GetConnectorPoint(int Order) = 0;//get connection point if order=0 > return inlet  ,order=1 > return outlet

	string GetStatmentName();

	void Set_Connector_ID(int num);

	///////////////////////////////////

	

};

#endif