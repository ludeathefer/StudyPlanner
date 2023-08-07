#include "Calendar.h"
#include "Assets.h"

Calendar::Calendar(wxWindow* parent) : wxPanel(parent)
{

}

void Calendar::Initialize()
{
	SetBackgroundColour(THEME_COLOUR);
	wxBoxSizer* calendarSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* calendarText = new wxStaticText(this, wxID_STATIC, wxT("Calendar"));
	wxFont* calendarFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	calendarText->SetFont(*calendarFont);
	calendarText->SetForegroundColour(TEXT_THEME_COLOUR);
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(calendarText, 0, wxALIGN_CENTER);
	calendarSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(calendarSizer);
	Hide();
}