#include "Settings.h"
#include "Assets.h"
#include "ProgressBar.h"

Settings::Settings(wxWindow* parent) : wxPanel(parent)
{

}

void Settings::Initialize()
{
	//ProgressBar* pb = new ProgressBar(this, wxSize(500, 20), *wxWHITE, THEME_COLOUR, 10, 50);
	SetBackgroundColour(THEME_COLOUR);
	wxBoxSizer* settingsSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* settingsText = new wxStaticText(this, wxID_STATIC, wxT("Settings"));
	wxFont* settingsFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	settingsText->SetFont(*settingsFont);
	settingsText->SetForegroundColour(TEXT_THEME_COLOUR);
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(settingsText, 0, wxALIGN_CENTER);
	//tempSizer->Add(pb, 0, wxALIGN_CENTER);
	settingsSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(settingsSizer);
	Hide();
}