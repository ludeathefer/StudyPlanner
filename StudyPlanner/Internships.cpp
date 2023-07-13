#include "Internships.h"

Internships::Internships(wxWindow* parent) : wxPanel(parent)
{

}

void Internships::Initialize()
{
	SetBackgroundColour(wxColour(84, 78, 111));
	wxBoxSizer* internshipsSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* internshipsText = new wxStaticText(this, wxID_STATIC, wxT("Internships"));
	wxFont* internshipsFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	internshipsText->SetFont(*internshipsFont);
	internshipsText->SetForegroundColour(wxColour(200, 200, 200));
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(internshipsText, 0, wxALIGN_CENTER);
	internshipsSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	this->SetSizer(internshipsSizer);
}