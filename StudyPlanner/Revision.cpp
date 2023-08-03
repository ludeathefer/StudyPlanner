#include "Revision.h"

Revision::Revision(wxWindow* parent) : wxPanel(parent)
{

}

void Revision::Initialize()
{
	SetBackgroundColour(wxColour(84, 78, 111));
	wxBoxSizer* revisionSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* revisionText = new wxStaticText(this, wxID_STATIC, wxT("Revision"));
	wxFont* revisionFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	revisionText->SetFont(*revisionFont);
	revisionText->SetForegroundColour(wxColour(200, 200, 200));
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(revisionText, 0, wxALIGN_CENTER);
	revisionSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(revisionSizer);
	Hide();
}