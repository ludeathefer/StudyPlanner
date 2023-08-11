#include "States.h"
#include "SidebarMenu.h"
#include "resource.h"

SidebarMenu::SidebarMenu(wxWindow* parent) : wxPanel(parent)
{
	sidebarMenuSizer = new wxBoxSizer(wxVERTICAL);
}

struct SidebarMenu::item {
	std::string itemLabel;
	int imageLabel;
};

std::vector<SidebarMenuItem*> SidebarMenu::items;

void SidebarMenu::Initialize()
{
	item itemArray[7] = {
		{"Dashboard", DASHBOARD_PNG},
		{"Calander", CALANDER_PNG},
		{"Syllabus", SYLLABUS_PNG},
		{"Assignment", ASSIGNMENT_PNG},
		{"Revision", REVISION_PNG},
		{"Internships", INTERNSHIPS_PNG},
		{"Settings", SETTINGS_PNG}
		
	};

	States::sidebarMenu = this;
	for (int i = 0; i < 7; i++) {
		items.push_back(new SidebarMenuItem(this, i, itemArray[i].itemLabel, itemArray[i].imageLabel));
		items[i]->Initialize();
		sidebarMenuSizer->Add(items[i], 0, wxEXPAND);
		if (i == 5) sidebarMenuSizer->AddStretchSpacer();
	};
	SetSizerAndFit(sidebarMenuSizer);
};

