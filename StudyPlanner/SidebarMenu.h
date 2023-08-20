#pragma once
#include <wx/wx.h>
#include "SidebarMenuItem.h"

class SidebarMenu : public wxPanel
{
	struct item;
public:
	SidebarMenu(wxWindow* parent);
	wxBoxSizer* sidebarMenuSizer;
	void Initialize();
	static std::vector<SidebarMenuItem*> items;
};

