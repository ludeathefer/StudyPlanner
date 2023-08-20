#pragma once
#include "Mainframe.h"
#include "SidebarMenu.h"
#include "resource.h"
#include <wx/mstream.h>
class States
{
	public:
	static wxBitmap LoadPNGFromResource(int resourceID, const wxString& resourceType);
	static int selectedWindow;
	static bool minimizedSidebar;
	static Mainframe* mainframe;
	static SidebarMenu* sidebarMenu;
};

