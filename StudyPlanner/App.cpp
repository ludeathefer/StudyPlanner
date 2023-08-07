#include "App.h"
#include "Mainframe.h"
#include "resource.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() 
{
	Mainframe* mainframe = new Mainframe("Study Planner");
	mainframe->Initialize();
	mainframe->SetIcon(wxICON(LOGO_ICO));
	mainframe->Show();
	return true;
}