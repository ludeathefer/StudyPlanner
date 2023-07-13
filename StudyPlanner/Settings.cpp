#include "Settings.h"

Settings::Settings(wxWindow* parent) : wxPanel(parent)
{

}

void Settings::Initialize()
{
	SetBackgroundColour(wxColour(84, 78, 111));
	wxBoxSizer* settingsSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* settingsText = new wxStaticText(this, wxID_STATIC, wxT("Settings"));
	wxFont* settingsFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	settingsText->SetFont(*settingsFont);
	settingsText->SetForegroundColour(wxColour(200, 200, 200));
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(settingsText, 0, wxALIGN_CENTER);
	settingsSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	this->SetSizer(settingsSizer);
}