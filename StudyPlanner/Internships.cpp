#include "Internships.h"
#include "Assets.h"
#include "RoundedRectangle.h"
#include <wx/wrapsizer.h>
#include "InternshipCard.h"
#include <wx/srchctrl.h>

Internships::Internships(wxWindow* parent) : wxPanel(parent)
{
	

}

void Internships::Initialize()
{
	wxPanel* panel = new wxPanel(this);
	panel->SetBackgroundColour(wxColor(84, 78, 111));
	panel->SetDoubleBuffered(true);

	RoundedRectangle* searchBar = new RoundedRectangle(panel, wxSize(600, 50), wxColor(255,255,255), THEME_COLOUR, 20);
	auto searchbox = new wxSearchCtrl(searchBar, wxID_ANY, "", wxDefaultPosition, wxSize(600, 40), wxNO_BORDER | wxTE_PROCESS_ENTER);
	searchResult = new wxScrolled<wxPanel>(panel, wxID_ANY, wxDefaultPosition, wxSize(500, 500));
	searchResult->SetBackgroundColour(wxColor(84, 78, 111));
	searchResult->SetDoubleBuffered(true);
	searchResult->SetScrollRate(0, 50);

	

	wxFont* titleFont = new wxFont(32, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	wxStaticText* titleText = new wxStaticText(panel, wxID_STATIC, "Internships", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	titleText->SetFont(*titleFont);
	titleText->SetForegroundColour(wxColour(233, 233, 233));


	wxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(panel, 2, wxEXPAND | wxTOP, 25);
	wxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* searchBarSizer = new wxBoxSizer(wxVERTICAL);
	resultSizer = new wxWrapSizer(wxHORIZONTAL);


	panelSizer->AddSpacer(50);
	panelSizer->Add(titleText, 0, wxEXPAND | wxALL, 20);
	panelSizer->Add(searchBar, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 20);
	panelSizer->Add(searchResult, 4, wxEXPAND | wxLEFT | wxTOP| wxBOTTOM, 20);

	searchBarSizer->Add(searchbox, 1, wxEXPAND | wxALL , 15);


	//for (unsigned i = 0; i < 10; i++) {
		//InternshipCard* resultItem = new InternshipCard(searchResult);
		//resultSizer->Add(resultItem, 1, wxEXPAND| wxALL, 20 );
	//}
	
	this->SetSizerAndFit(mainSizer);
	panel->SetSizer(panelSizer);
	searchResult->SetSizerAndFit(resultSizer);
	searchResult->Layout();
	searchBar->SetSizer(searchBarSizer);


	searchbox->Connect(wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN, wxCommandEventHandler(Internships::OnSearchButton), NULL, this);


	Hide();
}

void Internships::OnSearchButton(wxCommandEvent& event)
{
	/* Yo part hera ta ekchoti*/
	int i = 0;
	for (const IndustryCard& industrycard : m.GetResults()) {
		resultSizer->Detach(resultItem[i]);
		resultItem[i]->DestroyChildren();
		delete resultItem[i];
		resultSizer->Layout();
		
		i++;
	}
	resultSizer->Clear(true);
	/* Yaha samma*/
	m.RetrieveResults(event.GetString().ToStdString());
	LoadSearchResults(m.GetResults());
}

void Internships::LoadSearchResults(const std::vector<IndustryCard>& industrycards)
{

	int i = 0;
	for (const IndustryCard& industrycard : industrycards) {
			resultItem[i] = new InternshipCard(searchResult, industrycard.name,
				"https://merojob.com"+ industrycard.job_url, industrycard.company, "https://merojob.com"+industrycard.company_url,
									industrycard.location, industrycard.image, industrycard.deadline);

		resultSizer->Add(resultItem[i], 1, wxEXPAND | wxALL, 20);
		
		i++;
	}
	resultSizer->Layout();
	searchResult->SetDoubleBuffered(true);
	searchResult->SetScrollRate(0, 50);
}
