#include "Dashboard.h"
#include "Assets.h"
#include "RoundedRectangle.h"
#include "PieChart.h"

Dashboard::Dashboard(wxWindow* parent) : wxPanel(parent) 
{

}

void Dashboard::Initialize()
{
	SetBackgroundColour(THEME_COLOUR);
	wxBoxSizer* dashboardSizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* dashboardText = new wxStaticText(this, wxID_STATIC, wxT("Dashboard"));
	wxFont* dashboardFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	dashboardText->SetFont(*dashboardFont);
	dashboardText->SetForegroundColour(TEXT_THEME_COLOUR);

	RoundedRectangle* round = new RoundedRectangle(this, wxSize(300, 300), SIDEBAR_COLOUR, THEME_COLOUR, 10);
	std::vector <float> data = { 25, 30, 5, 40 };
	std::vector <wxString> dataLabel = { "Done", "Pending", "Missed", "Random"};
	PieChart* pie = new PieChart(round, 75, SIDEBAR_COLOUR, data, dataLabel, wxString("LOREM IPSUM"));

	wxBoxSizer* tempSizer = new wxBoxSizer(wxVERTICAL);
	tempSizer->Add(dashboardText, 0, wxALIGN_CENTER);
	tempSizer->Add(round, 0, wxTOP | wxALIGN_CENTER, 40);
	dashboardSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(dashboardSizer);
	Hide();
}