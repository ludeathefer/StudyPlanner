#include "RoundedButton.h"
#include "Assets.h"
#include "Internships.h"
#include "States.h"

RoundedButton::RoundedButton(wxWindow* parent, wxSize buttonSize, std::string label, int a):  RoundedRectangle(parent, buttonSize, FOCUS_COLOR, SIDEBAR_COLOUR, 15)
{
	buttonText= new wxButton(this, wxID_ANY, label,
		wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT | wxALIGN_BOTTOM | wxNO_BORDER );
	buttonText->SetForegroundColour(TEXT_THEME_COLOUR);
	buttonText->SetBackgroundColour(FOCUS_COLOR);
	wxFont* buttonTextFont = new wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	buttonText->SetFont(*buttonTextFont);
	wxBoxSizer* sizer2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(sizer2, 0, wxALIGN_CENTER);
	sizer2->Add(buttonText, 0, wxALIGN_BOTTOM);

	buttonText->Bind(wxEVT_BUTTON, [this](wxCommandEvent& evt) {
		
		if (States::selectedPage == 1) {
			Internships::page = 1;
			States::internships->Initialize();
			States::selectedPage = 0;
		}
		else if (States::selectedPage == 2) {
			Internships::page = 1;
			States::internships->Initialize();
			States::selectedPage = 0;
		}
		});
	this->SetSizerAndFit(sizer);
	
}
