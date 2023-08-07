#include "Dashboard.h"
#include "Assets.h"
#include "CustomPanel.h"

Dashboard::Dashboard(wxWindow* parent) : wxPanel(parent) 
{

}

void Dashboard::Initialize()
{
	CustomPanel* round = new CustomPanel(this, wxDefaultPosition, wxSize(300, 300), wxBrush(SIDEBAR_COLOUR), 20, THEME_COLOUR);
	wxFont* round1Font = new wxFont(24, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont* round2Font = new wxFont(18, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxStaticText* roundText1 = new wxStaticText(round, wxID_STATIC, wxT("Assignments"));
	roundText1->SetBackgroundColour(SIDEBAR_COLOUR);
	roundText1->SetForegroundColour(TEXT_THEME_COLOUR);
	roundText1->SetFont(*round1Font);
	wxStaticText* roundText2 = new wxStaticText(round, wxID_STATIC, wxT("This Week"));
	roundText2->SetBackgroundColour(SIDEBAR_COLOUR);
	roundText2->SetForegroundColour(TEXT_THEME_COLOUR);
	roundText2->SetFont(*round2Font);
	wxBoxSizer* roundSizer = new wxBoxSizer(wxVERTICAL);
	roundSizer->Add(roundText1, 0, wxTOP | wxLEFT, 10);
	roundSizer->Add(roundText2, 0, wxLEFT, 10);
	round->SetSizer(roundSizer);

	SetBackgroundColour(THEME_COLOUR);
	wxBoxSizer* dashboardSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* dashboardText = new wxStaticText(this, wxID_STATIC, wxT("Dashboard"));
	wxFont* dashboardFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	dashboardText->SetFont(*dashboardFont);
	dashboardText->SetForegroundColour(TEXT_THEME_COLOUR);
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(dashboardText, 0, wxALIGN_CENTER);
	tempSizer->Add(round, 0, wxLEFT | wxALIGN_CENTER, 40);
	dashboardSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(dashboardSizer);
	Hide();
}