#include "Syllabus.h"
#include "Assets.h"

Syllabus::Syllabus(wxWindow* parent) : wxPanel(parent)
{

}

void Syllabus::Initialize()
{
	SetBackgroundColour(THEME_COLOUR);
	wxBoxSizer* syllabusSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* syllabusText = new wxStaticText(this, wxID_STATIC, wxT("Syllabus"));
	wxFont* syllabusFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	syllabusText->SetFont(*syllabusFont);
	syllabusText->SetForegroundColour(TEXT_THEME_COLOUR);
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(syllabusText, 0, wxALIGN_CENTER);
	syllabusSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(syllabusSizer);
	Hide();
}