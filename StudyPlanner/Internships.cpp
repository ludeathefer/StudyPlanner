#include "Internships.h"
#include "Assets.h"
#include "RoundedRectangle.h"
#include <wx/wrapsizer.h>
#include "InternshipCard.h"

Internships::Internships(wxWindow* parent) : wxPanel(parent)
{

}

void Internships::Initialize()
{
	wxPanel* panel = new wxPanel(this);
	panel->SetBackgroundColour(wxColor(84, 78, 111));
	panel->SetDoubleBuffered(true);

	RoundedRectangle* searchBar = new RoundedRectangle(panel, wxSize(600, 50), TEXT_THEME_COLOUR, THEME_COLOUR, 20);
	auto searchResult = new wxScrolled<wxPanel>(panel, wxID_ANY, wxDefaultPosition, wxSize(500, 500));
	searchResult->SetBackgroundColour(wxColor(84, 78, 111));
	searchResult->SetDoubleBuffered(true);
	searchResult->SetScrollbar(wxVERTICAL, 10, 10, 10);
	searchResult->SetScrollRate(0, 10);
	//searchResult->ShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_NEVER);



	wxFont* titleFont = new wxFont(32, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	wxStaticText* titleText = new wxStaticText(panel, wxID_STATIC, "Internships", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	titleText->SetFont(*titleFont);
	titleText->SetForegroundColour(wxColour(233, 233, 233));


	wxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(panel, 2, wxEXPAND | wxALL, 0);
	wxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* resultSizer = new wxWrapSizer(wxHORIZONTAL);


	panelSizer->AddSpacer(50);
	panelSizer->Add(titleText, 0, wxEXPAND | wxALL, 20);
	panelSizer->Add(searchBar, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 20);
	panelSizer->Add(searchResult, 4, wxEXPAND | wxLEFT | wxTOP| wxBOTTOM, 20);


	for (unsigned i = 0; i < 10; i++) {
		//RoundedRectangle* resultItem = new RoundedRectangle(searchResult, wxSize(425, 250), SIDEBAR_COLOUR, THEME_COLOUR, 30);
		InternshipCard* resultItem = new InternshipCard(searchResult);
		resultSizer->Add(resultItem, 1, wxEXPAND| wxALL, 20 );
	}
	
	this->SetSizerAndFit(mainSizer);
	panel->SetSizer(panelSizer);
	searchResult->SetSizerAndFit(resultSizer);
	searchResult->Layout();


	Hide();
}