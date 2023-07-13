#include "Syllabus.h"

Syllabus::Syllabus(wxWindow* parent) : wxPanel(parent)
{

}

void Syllabus::Initialize()
{
	SetBackgroundColour(wxColour(84, 78, 111));
	wxBoxSizer* syllabusSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* syllabusText = new wxStaticText(this, wxID_STATIC, wxT("Syllabus"));
	wxFont* syllabusFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	syllabusText->SetFont(*syllabusFont);
	syllabusText->SetForegroundColour(wxColour(200, 200, 200));
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(syllabusText, 0, wxALIGN_CENTER);
	syllabusSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	this->SetSizer(syllabusSizer);
}