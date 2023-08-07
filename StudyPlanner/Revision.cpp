#include "Revision.h"
#include "Assets.h"

Revision::Revision(wxWindow* parent) : wxPanel(parent)
{

}

void Revision::Initialize()
{
	SetBackgroundColour(THEME_COLOUR);
	wxBoxSizer* revisionSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* revisionText = new wxStaticText(this, wxID_STATIC, wxT("Revision"));
	wxFont* revisionFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	revisionText->SetFont(*revisionFont);
	revisionText->SetForegroundColour(TEXT_THEME_COLOUR);
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(revisionText, 0, wxALIGN_CENTER);
	revisionSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(revisionSizer);
	Hide();
}