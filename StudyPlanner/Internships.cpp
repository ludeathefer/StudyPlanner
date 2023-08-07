#include "Internships.h"
#include "Assets.h"

Internships::Internships(wxWindow* parent) : wxPanel(parent)
{

}

void Internships::Initialize()
{
	SetBackgroundColour(THEME_COLOUR);
	wxBoxSizer* internshipsSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* internshipsText = new wxStaticText(this, wxID_STATIC, wxT("Internships"));
	wxFont* internshipsFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	internshipsText->SetFont(*internshipsFont);
	internshipsText->SetForegroundColour(TEXT_THEME_COLOUR);
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(internshipsText, 0, wxALIGN_CENTER);
	internshipsSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(internshipsSizer);
	Hide();
}