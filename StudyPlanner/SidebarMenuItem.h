#pragma once
#include <wx/wx.h>

class SidebarMenuItem : public wxPanel
{
	wxString label;
	int imageId;
	int index;
	wxStaticText* itemTitleText;
	wxFont* itemTitleFont;
	wxBoxSizer* sidebarMenuItemSizer;
	void OnClick(wxMouseEvent& evt);
	static void OnClickStatic();
public:
	SidebarMenuItem(wxWindow* parent, int _index, wxString _label, int _imageId);
	void Initialize();
	static void SizeChange();
};
