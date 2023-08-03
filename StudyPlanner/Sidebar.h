#pragma once
#include <wx/wx.h>

class Sidebar : public wxPanel
{
	void OnClick(wxMouseEvent& evt);
public:
	Sidebar(wxWindow* parent);
	void Initialize();
};

