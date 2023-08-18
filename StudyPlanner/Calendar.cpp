#include "Calendar.h"

Calendar::Calendar(wxWindow* parent) : wxPanel(parent)
{

}

void Calendar::Initialize()
{
	SetBackgroundColour(wxColour(84, 78, 111));
	wxBoxSizer* calendarSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* calendarText = new wxStaticText(this, wxID_STATIC, wxT("Calendar"));
	wxFont* calendarFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	calendarText->SetFont(*calendarFont);
	calendarText->SetForegroundColour(wxColour(200, 200, 200));
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(calendarText, 0, wxALIGN_CENTER);
	calendarSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(calendarSizer);
	Hide();
}