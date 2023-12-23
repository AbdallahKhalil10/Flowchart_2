#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1400;  // was 1200
	UI.height = 620;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50; // was 50
	UI.ToolBarHeight = 50;    
	UI.MenuItemWidth = 80;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;



	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode

	//fill the tool bar 

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem
	string MenuItemImages[DSN_ITM_CNT];
	MenuItemImages[ITM_START] = "../images/Start.jpg";
	MenuItemImages[ITM_END] = "../images/End.jpg";
	MenuItemImages[ITM_READ] = "../images/Read.jpg";
	MenuItemImages[ITM_WRITE] = "../images/Write.jpg";
	MenuItemImages[ITM_VALUE_ASSIGN] = "../images/ValueAssign.jpg";
	MenuItemImages[ITM_VARIABLE_ASSIGN] = "../images/VariableAssign.jpg";
	MenuItemImages[ITM_OPERATOR_ASSIGN] = "../images/OperatorAssign.jpg";
	MenuItemImages[ITM_COND] = "../images/Condition.jpg";
	MenuItemImages[ITM_ADD_CONNECTOR] = "../images/AddConnector.jpg";
	MenuItemImages[ITM_SELECT] = "../images/Select.jpg";
	MenuItemImages[ITM_DELETE] = "../images/Delete.jpg";
	MenuItemImages[ITM_COPY] = "../images/Copy.jpg";
	MenuItemImages[ITM_PASTE] = "../images/Paste.jpg";
	MenuItemImages[ITM_SAVE] = "../images/Savee.jpg";
	MenuItemImages[ITM_LOAD] = "../images/Load.jpg";
	MenuItemImages[ITM_SWITCH] = "../images/Switch.jpg";
	MenuItemImages[ITM_EXIT] = "../images/Exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list


	//Draw menu item one image at a time
	for (int i = 0; i < DSN_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	string MenuItemImages[SIM_ITM_CNT];
	MenuItemImages[ITM_VALIDATE] = "../images/Validate.jpg";
	MenuItemImages[ITM_RUN] = "../images/Run.jpg";
	MenuItemImages[ITM_SWITCH_BACK] = "../images/SwitchBack.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < SIM_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	///TODO: add code to create the simulation tool bar
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar()
{
	pWind->SetPen(WHITE, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}


void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/4, Left.y + height/4, Text);
}

void Output::DrawStartStopStatements(Point Left, int width, int height, string Text, bool Selected) {

	if (Selected) {
		pWind->SetPen(UI.HighlightColor, 3);
	}
	else {
		pWind->SetPen(UI.DrawColor, 3);
	}

	//Draw the statement oval shape
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 3, Left.y + height / 3, Text);

}

void Output::DrawReadWriteStatement(Point Right, int width, int height, string Text, bool Selected) {

	int x[4] = { Right.x + 100, (Right.x + 100) - width + 25 , (Right.x + 100) - width , (Right.x + 100) - 25 };
	int y[4] = { Right.y, Right.y, Right.y + height, Right.y + height };

	if (Selected) {
		pWind->SetPen(UI.HighlightColor, 3);
	}
	else {
		pWind->SetPen(UI.DrawColor, 3);
	}

	//Draw the statement parallelogram shape
	pWind->DrawPolygon(x, y, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString((Right.x + 60) - width / 2, Right.y + height / 4, Text);

}

void Output::DrawConditionalStatement(Point Right, int width, int height, string Text, bool Selected) {

	int x[4] = { Right.x + 100, (Right.x + 100) - width / 2, (Right.x + 100) - width, (Right.x + 100) - width / 2 };
	int y[4] = { (Right.y+40) - height/2, (Right.y+40), (Right.y+40) - height/2, (Right.y+40) - height };

	if (Selected) {
		pWind->SetPen(UI.HighlightColor, 3);
	}
	else {
		pWind->SetPen(UI.DrawColor, 3);
	}

	//Draw the statement diamond shape
	pWind->DrawPolygon(x, y, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString((Right.x + 92) - width/2 , Right.y, Text);

}


void Output::DrawConnector(Point left, Point right, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the line
	pWind->DrawLine(left.x, left.y, right.x, right.y);

	//Draw the arrow triangle 
	pWind->DrawTriangle(right.x, right.y + 10, right.x, right.y - 10, right.x + 10, right.y, FILLED);
	//DrawTriangle(X_fo2, Y_fo2, X_ta7t, Y_ta7t, X_RIGHT, Y_RIGHT)
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
