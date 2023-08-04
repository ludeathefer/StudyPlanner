#include "App.h"
#include "Mainframe.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() 
{
	//#ifdef _WINDOWS
	//	AddFontResource("Inter-Regular.ttf");
	//#endif
	Mainframe* mainframe = new Mainframe("Study Planner");
	mainframe->Initialize();
	mainframe->Show();
	return true;
}