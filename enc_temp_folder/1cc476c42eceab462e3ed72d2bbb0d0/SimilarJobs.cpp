#include "SimilarJobs.h"
#include "Assets.h"


SimilarJobs::SimilarJobs(wxWindow* parent) : RoundedRectangle(parent, wxSize(300, 100), SIDEBAR_COLOUR, THEME_COLOUR, 30)
{
	auto panel = new RoundedRectangle(this, wxSize(299, 99), SIDEBAR_COLOUR, THEME_COLOUR, 1);
	panel->SetBackgroundColour(SIDEBAR_COLOUR);
	wxPanel* textcontentContainer = new wxPanel(panel);
	textcontentContainer->SetBackgroundColour(SIDEBAR_COLOUR);


	resultTitleFont = new wxFont(11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	resultContentFont = new wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT);


	resultTitleText = new wxHyperlinkCtrl(textcontentContainer, wxID_STATIC, "Machine Learning Engineer", "");
	resultTitleText->SetFont(*resultTitleFont);
	resultTitleText->SetForegroundColour(*wxWHITE);
	resultTitleText->SetBackgroundColour(SIDEBAR_COLOUR);

	companyName = new wxHyperlinkCtrl(textcontentContainer, wxID_STATIC, "Smart Data Solutions", "");
	companyName->SetFont(*resultContentFont);
	companyName->SetForegroundColour(*wxWHITE);
	companyName->SetBackgroundColour(SIDEBAR_COLOUR);

	deadline = new wxStaticText(textcontentContainer, wxID_STATIC, "Apply 2 days from now");
	deadline->SetFont(*resultContentFont);
	deadline->SetForegroundColour(*wxWHITE);
	deadline->SetBackgroundColour(SIDEBAR_COLOUR);

	wxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(panel, 2, wxEXPAND | wxALL, 2);
	wxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
	textSizer = new wxBoxSizer(wxVERTICAL);
	panelSizer->Add(textcontentContainer, 3, wxEXPAND | wxALL, 8);

	textSizer->Add(resultTitleText, 0, wxALL, 1);
	textSizer->Add(companyName, 0, wxALL, 1);
	textSizer->Add(deadline, 0, wxALL, 1);

	this->SetSizerAndFit(mainSizer);
	panel->SetSizer(panelSizer);
	textcontentContainer->SetSizerAndFit(textSizer);

}

void SimilarJobs::setData(std::string jobTitle, std::string jobLink, std::string companyTitle, std::string companyLink, std::string appdeadline)
{
	this->companyName->SetLabel(companyTitle);
	this->companyName->SetURL(companyTitle);
	this->resultTitleText->SetLabel(jobTitle);
	this->resultTitleText->SetURL(jobLink);
	this->deadline->SetLabel(appdeadline);
	textSizer->Layout();
}
