#pragma once
#include <wx\wx.h>

class SidebarMenuItem : public wxPanel
{
	wxString label, imagePath;
	int index;
	void OnClick(wxMouseEvent& evt);
	void OnEnter(wxMouseEvent& evt);
	void OnExit(wxMouseEvent& evt);
	//wxDECLARE_EVENT_TABLE();

public:
	static int selected;
	SidebarMenuItem(wxWindow* parent, int _index, wxString _label, wxString _imagePath);
	void Initialize();
};

