#include "Dashboard.h"

Dashboard::Dashboard(wxWindow* parent) : wxPanel(parent) 
{

}

void Dashboard::Initialize()
{
	SetBackgroundColour(wxColour(84, 78, 111));
	wxBoxSizer* dashboardSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* dashboardText = new wxStaticText(this, wxID_STATIC, wxT("Dashboard"));
	wxFont* dashboardFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	dashboardText->SetFont(*dashboardFont);
	dashboardText->SetForegroundColour(wxColour(200, 200, 200));
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(dashboardText, 0, wxALIGN_CENTER);
	dashboardSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(dashboardSizer);
	Hide();
}