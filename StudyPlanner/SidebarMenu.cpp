#include "SidebarMenu.h"
#include "SidebarMenuItem.h"

SidebarMenu::SidebarMenu(wxWindow* parent) : wxPanel(parent)
{

}

void SidebarMenu::Initialize()
{
	wxBoxSizer* sidebarMenuSizer = new wxBoxSizer(wxVERTICAL);
	SidebarMenuItem* dashboard = new SidebarMenuItem(this, 0, wxT("Dashboard"), wxT("C:/Games/StudyPlanner-main/StudyPlanner/assets/img/dashboard.png"));
	SidebarMenuItem* calander = new SidebarMenuItem(this, 1, wxT("Calander"), wxT("C:/Games/StudyPlanner-main/StudyPlanner/assets/img/calander.png"));
	SidebarMenuItem* syllabus = new SidebarMenuItem(this, 2, wxT("Syllabus"), wxT("C:/Games/StudyPlanner-main/StudyPlanner/assets/img/syllabus.png"));
	SidebarMenuItem* assignment = new SidebarMenuItem(this, 3, wxT("Assignment"), wxT("C:/Games/StudyPlanner-main/StudyPlanner/assets/img/assignment.png"));
	SidebarMenuItem* revision = new SidebarMenuItem(this, 4, wxT("Revision"), wxT("C:/Games/StudyPlanner-main/StudyPlanner/assets/img/revision.png"));
	//SidebarMenuItem* internships = new SidebarMenuItem(this, 5, wxT("Internships"), wxT("assets/img/internships.png"));
	SidebarMenuItem* settings = new SidebarMenuItem(this, 6, wxT("Settings"), wxT("C:/Games/StudyPlanner-main/StudyPlanner/assets/img/settings.png"));

	dashboard->Initialize();
	calander->Initialize();
	syllabus->Initialize();
	assignment->Initialize();
	revision->Initialize();
	//internships->Initialize();
	settings->Initialize();

	int vPadding = 12;
	sidebarMenuSizer->Add(dashboard, 0, wxTOP | wxBOTTOM, vPadding);
	sidebarMenuSizer->Add(calander, 0, wxTOP | wxBOTTOM, vPadding);
	sidebarMenuSizer->Add(syllabus, 0, wxTOP | wxBOTTOM, vPadding);
	sidebarMenuSizer->Add(assignment, 0, wxTOP | wxBOTTOM, vPadding);
	sidebarMenuSizer->Add(revision, 0, wxTOP | wxBOTTOM, vPadding);
	//sidebarMenuSizer->Add(internships, 0, wxTOP | wxBOTTOM, vPadding);
	sidebarMenuSizer->AddStretchSpacer();
	sidebarMenuSizer->Add(settings, 0, wxTOP | wxBOTTOM, 2 * vPadding);

	SetSizerAndFit(sidebarMenuSizer);
};
