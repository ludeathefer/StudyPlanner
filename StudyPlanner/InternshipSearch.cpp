#include "InternshipSearch.h"
#include "Assets.h"
#include "RoundedRectangle.h"
#include <wx/wrapsizer.h>
#include "InternshipCard.h"
#include <wx/srchctrl.h>
#include "Internships.h"
#include "States.h"



InternshipSearch::InternshipSearch(wxPanel* parent) : wxPanel(parent)
{
}

void InternshipSearch::Initialize(MeroJob &mero)
{
	mainSearchPage = new wxPanel(this);
	mainSearchPage->SetBackgroundColour(wxColor(84, 78, 111));
	mainSearchPage->SetDoubleBuffered(true);

	RoundedRectangle* searchBar = new RoundedRectangle(mainSearchPage, wxSize(600, 50), wxColor(255, 255, 255), THEME_COLOUR, 20);
	auto searchbox = new wxSearchCtrl(searchBar, wxID_ANY, "", wxDefaultPosition, wxSize(600, 40), wxNO_BORDER | wxTE_PROCESS_ENTER);
	searchResult = new wxScrolled<wxPanel>(mainSearchPage, wxID_ANY, wxDefaultPosition, wxSize(500, 500));
	searchResult->SetBackgroundColour(wxColor(84, 78, 111));
	searchResult->SetDoubleBuffered(true);



	wxFont* titleFont = new wxFont(32, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	wxStaticText* titleText = new wxStaticText(mainSearchPage, wxID_STATIC, "Internships", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	titleText->SetFont(*titleFont);
	titleText->SetForegroundColour(wxColour(233, 233, 233));


	mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(mainSearchPage, 1, wxEXPAND | wxTOP, 25);
	panelSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* searchBarSizer = new wxBoxSizer(wxVERTICAL);
	resultSizer = new wxWrapSizer(wxHORIZONTAL);


	panelSizer->AddSpacer(50);
	panelSizer->Add(titleText, 0, wxEXPAND | wxALL, 20);
	panelSizer->Add(searchBar, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 20);
	panelSizer->Add(searchResult, 4, wxEXPAND | wxLEFT | wxTOP | wxBOTTOM, 20);

	searchBarSizer->Add(searchbox, 1, wxEXPAND | wxALL, 15);


	for (int i = 0; i < 6; i++) {
		resultItem[i] = new InternshipCard(searchResult, mero);
		resultSizer->Add(resultItem[i], 1, wxEXPAND | wxALL, 20);

	}
	searchResult->Hide();
	resultSizer->Layout();
	panelSizer->Layout();
	mainSizer->Layout();


	searchResult->SetDoubleBuffered(true);

	this->SetSizerAndFit(mainSizer);
	mainSearchPage->SetSizer(panelSizer);
	searchResult->SetSizerAndFit(resultSizer);

	searchBar->SetSizer(searchBarSizer);



	searchbox->Bind(wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN, [this, &mero](wxCommandEvent& event) {
		this->OnSearchButton(event, mero);
		});

	Hide();
}

void InternshipSearch::OnSearchButton(wxCommandEvent & event, MeroJob &m)
{

	searchResult->Hide();
	resultSizer->Layout();
	panelSizer->Layout();
	mainSizer->Layout();

	m.RetrieveResults(event.GetString().ToStdString());

	LoadSearchResults(m.GetResults(), m);


}

void InternshipSearch::LoadSearchResults(const std::vector<JobCard>&industrycards, MeroJob &m)
{
	int i = 0;
	for (const JobCard& industrycard : industrycards) {
		resultItem[i]->setData(industrycard.name,
			"https://merojob.com" + industrycard.job_url, industrycard.company, "https://merojob.com" + industrycard.company_url,
			industrycard.location, industrycard.image, industrycard.deadline);
		i++;
	}
	m.ClearElements();
	searchResult->GetParent()->GetSizer()->Show(searchResult);
	searchResult->Layout();
	resultSizer->Layout();
	mainSizer->Layout();
}

