#pragma once
#include <wx/wx.h>

class Sidebar : public wxPanel
{
	bool minimized;
public:
	Sidebar(wxWindow* parent, wxSize size);
	void Initialize();
};

