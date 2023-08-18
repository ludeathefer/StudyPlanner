#pragma once
#include <wx/wx.h>

class Mainframe : public wxFrame 
{
public:
	Mainframe(const wxString& title);
	void Initialize();
	void ChangePage();
	void ShowSidebar();
	void OnWindowClosed(wxCloseEvent& evt);//, int i);

	

};

