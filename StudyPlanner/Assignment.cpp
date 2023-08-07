#include "Assignment.h"
#include "Assets.h"

Assignment::Assignment(wxWindow* parent) : wxPanel(parent)
{

}

void Assignment::Initialize()
{
	SetBackgroundColour(THEME_COLOUR);
	wxBoxSizer* assignmentSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* assignmentText = new wxStaticText(this, wxID_STATIC, wxT("Assignment"));
	wxFont* assignmentFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	assignmentText->SetFont(*assignmentFont);
	assignmentText->SetForegroundColour(TEXT_THEME_COLOUR);
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(assignmentText, 0, wxALIGN_CENTER);
	assignmentSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(assignmentSizer);
	Hide();
}