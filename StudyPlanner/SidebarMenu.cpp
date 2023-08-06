#include "States.h"
#include "SidebarMenu.h"
#include "resource.h"

SidebarMenu::SidebarMenu(wxWindow* parent) : wxPanel(parent)
{
	sidebarMenuSizer = new wxBoxSizer(wxVERTICAL);
}

struct SidebarMenu::item {
	int index;
	std::string itemLabel;
	int imageLabel;
};

std::vector<SidebarMenuItem*> SidebarMenu::items;

void SidebarMenu::Initialize()
{
	item itemArray[6] = {
		{0, "Dashboard", DASHBOARD_PNG},
		{1, "Calander", CALANDER_PNG},
		{2, "Syllabus", SYLLABUS_PNG},
		{3, "Assignment", ASSIGNMENT_PNG},
		{4, "Revision", REVISION_PNG},
		{5, "Settings", SETTINGS_PNG},
		//{6, "Internships", INTERNSHIPS_PNG}
	};

	States::sidebarMenu = this;
	for (int i = 0; i < 6; i++) {
		items.push_back(new SidebarMenuItem(this, itemArray[i].index, itemArray[i].itemLabel, itemArray[i].imageLabel));
		items[i]->Initialize();
		sidebarMenuSizer->Add(items[i], 0, wxEXPAND);
		if (i == 4) sidebarMenuSizer->AddStretchSpacer();
	};
	SetSizerAndFit(sidebarMenuSizer);
};

