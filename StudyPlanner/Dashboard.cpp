#include "Dashboard.h"
#include "Assets.h"
#include "RoundedRectangle.h"
#include "PieChart.h"
#include "LineGraph.h"

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

	RoundedRectangle* roundPie = new RoundedRectangle(this, wxSize(300, 300), SIDEBAR_COLOUR, THEME_COLOUR, 32);
	std::vector <float> data = { 30, 10, 40, 20 };
	std::vector <wxString> dataLabel = { "Done", "Pending", "Missed", "Random" };
	PieChart* pie = new PieChart(roundPie, data, dataLabel, wxString("TASKS THIS WEEK"));

	RoundedRectangle* roundLine = new RoundedRectangle(this, wxSize(500, 500), SIDEBAR_COLOUR, THEME_COLOUR, 32);
	std::vector <float> dataX = { 30, 10, 40, 20 };
	std::vector <float> dataY = { 90, 100, 45, 60, 70, 80, 90, 95, 80, 150, 125, 120 };
	LineGraph* line = new LineGraph(roundLine, dataX, dataY, wxString("Syllabus"));

	wxBoxSizer* tempTempSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* tempSizer = new wxBoxSizer(wxVERTICAL);
	tempTempSizer->Add(roundPie, 0, wxRIGHT | wxALIGN_CENTER, 40);
	tempTempSizer->Add(roundLine, 0, wxALIGN_CENTER);
	tempSizer->Add(dashboardText, 0, wxALIGN_CENTER);
	tempSizer->Add(tempTempSizer, 0, wxTOP | wxALIGN_CENTER, 40);
	dashboardSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(dashboardSizer);
	Hide();
};