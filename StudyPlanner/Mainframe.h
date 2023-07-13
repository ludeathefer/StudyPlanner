#pragma once
#include <wx/wx.h>

class Mainframe : public wxFrame 
{
	//void OnClick(wxMouseEvent&);
public:
	Mainframe(const wxString& title);
	void Initialize();
};

