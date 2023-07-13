#include "Mainframe.h"
#include "Sidebar.h"
#include "Dashboard.h"

Mainframe::Mainframe(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{

}	

void Mainframe::Initialize() {
	Center(); 
	Maximize();
	CreateStatusBar();

	Sidebar* sidebar = new Sidebar(this, wxSize(GetClientSize().GetWidth() * 0.25f, 600));
	sidebar->Initialize();

	Dashboard* dashboard = new Dashboard(this);
	dashboard->Initialize();

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	sizer->Add(sidebar, 0, wxEXPAND | wxALL, 0);
	sizer->Add(dashboard, 1, wxEXPAND | wxALL, 0);
	SetSizerAndFit(sizer);
	Show();
}