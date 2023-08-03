#include "Mainframe.h"
#include "States.h"
#include "Sidebar.h"
#include "Dashboard.h"
#include "Calendar.h"
#include "Syllabus.h"
#include "Assignment.h"
#include "Revision.h"
#include "Settings.h"
//#include "Internships.h"

Mainframe::Mainframe(const wxString& title): wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER)
{

}	

wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
wxBoxSizer* page = new wxBoxSizer(wxHORIZONTAL);

Sidebar* sidebar;
Dashboard* dashboard;
Calendar* calendar;
Syllabus* syllabus;
Assignment* assignment;
Revision* revision;
Settings* settings;
//Internships* internships;

void Mainframe::Initialize() {
	Maximize();
	//CreateStatusBar();
	States::mainframe = this;

	SetMinSize(wxGetDisplaySize());

	sidebar = new Sidebar(this);
	sidebar->Initialize();

	dashboard = new Dashboard(this);
	calendar = new Calendar(this);
	syllabus = new Syllabus(this);
	assignment = new Assignment(this);
	revision = new Revision(this);
	settings = new Settings(this);
	//internships = new Internships(this);

	dashboard->Initialize();
	calendar->Initialize();
	syllabus->Initialize();
	assignment->Initialize();
	revision->Initialize();
	settings->Initialize();
	//internships->Initialize();

	sizer->Add(sidebar, 3, wxEXPAND | wxALL, 0);
	//ShowSidebar();
	ChangePage();
	SetSizer(sizer);
	Show();
}

void Mainframe::ShowSidebar() {
	if (States::minimizedSidebar) sizer->GetItem(size_t(0))->SetProportion(1);
	else sizer->GetItem(size_t(0))->SetProportion(3);
	sizer->Layout();
}

void Mainframe::ChangePage() {
	switch (States::selectedWindow) {
	case 0:
		if (sizer->GetItemCount() > 1) { sizer->Hide(1); sizer->Remove(1); }
		sizer->Add(dashboard, 12, wxEXPAND | wxALL, 0);
		dashboard->Show();
		break;	
	case 1:
		if (sizer->GetItemCount() > 1) { sizer->Hide(1); sizer->Remove(1); }
		sizer->Add(calendar, 12, wxEXPAND | wxALL, 0);
		calendar->Show();
		break;
	case 2:
		if (sizer->GetItemCount() > 1) { sizer->Hide(1); sizer->Remove(1); }
		sizer->Add(syllabus, 12, wxEXPAND | wxALL, 0);
		syllabus->Show();
		break;
	case 3:
		if (sizer->GetItemCount() > 1) { sizer->Hide(1); sizer->Remove(1); }
		sizer->Add(assignment, 12, wxEXPAND | wxALL, 0);
		assignment->Show();
		break;
	case 4:
		if (sizer->GetItemCount() > 1) { sizer->Hide(1); sizer->Remove(1); }
		sizer->Add(revision, 12, wxEXPAND | wxALL, 0);
		revision->Show();
		break;
	case 6:
		if (sizer->GetItemCount() > 1) { sizer->Hide(1); sizer->Remove(1); }
		sizer->Add(settings, 12, wxEXPAND | wxALL, 0);
		settings->Show();
		break;
	//case 5:
	//	if (sizer->GetItemCount() > 1) { sizer->Hide(1); sizer->Remove(1); }
	//	sizer->Add(internships, 1, wxEXPAND | wxALL, 0);
	//	internships->Show();
	//	break;
	default:
		break;
	};
	sizer->Layout();
};

