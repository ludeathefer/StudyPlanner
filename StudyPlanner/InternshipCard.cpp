#include "InternshipCard.h"
#include "wx/wx.h"
#include <wx/hyperlink.h>
#include "Assets.h"
#include "RoundedButton.h"
#include "Internships.h"
#include "InternshipMoreDetails.h"
#include "Mainframe.h"
#include "States.h"




InternshipCard::InternshipCard(wxWindow* parent, MeroJob &m) : RoundedRectangle(parent, wxSize(425, 240), SIDEBAR_COLOUR, THEME_COLOUR, 30)
{
	
	auto panel = new RoundedRectangle(this, wxSize(400, 235), SIDEBAR_COLOUR, THEME_COLOUR, 1);
	panel->SetBackgroundColour(SIDEBAR_COLOUR);
	wxPanel* infoContainer = new wxPanel(panel, wxID_ANY, wxDefaultPosition, wxSize(390, 235));
	infoContainer->SetBackgroundColour(SIDEBAR_COLOUR);
	wxPanel* textcontentContainer = new wxPanel(infoContainer);
	textcontentContainer->SetBackgroundColour(SIDEBAR_COLOUR);
	wxPanel* buttonContainer = new wxPanel(textcontentContainer, wxID_ANY, wxDefaultPosition, wxSize(390, 50));

	
	MoreDetails = new RoundedButton(buttonContainer, wxSize(180, 40), "More Details", 1);
	CompanyDetails = new RoundedButton(buttonContainer, wxSize(180, 40), "Company Page", 2);

	MoreDetails->buttonText->Bind(wxEVT_BUTTON, [this, &m](wxCommandEvent& event) {
		this->onButtonClick(event, m);
		});	CompanyDetails->buttonText->Bind(wxEVT_BUTTON, [this, &m](wxCommandEvent& event) {
		this->onButtonClick(event, m);
		});


	resultTitleFont = new wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	resultContentFont = new wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT);


	resultTitleText = new wxHyperlinkCtrl(textcontentContainer, wxID_STATIC, "", "");
	resultTitleText->SetFont(*resultTitleFont);
	resultTitleText->SetForegroundColour(*wxWHITE);
	resultTitleText->SetBackgroundColour(SIDEBAR_COLOUR);

	companyName = new wxHyperlinkCtrl(textcontentContainer, wxID_STATIC, "", "https://merojob.com/employer/cyberarrow-2/");
	companyName->SetFont(*resultContentFont);
	companyName->SetForegroundColour(*wxWHITE);
	companyName->SetBackgroundColour(SIDEBAR_COLOUR);
	
	companyLocation = new wxStaticText(textcontentContainer, wxID_STATIC, "");
	companyLocation->SetFont(*resultContentFont);
	companyLocation->SetForegroundColour(*wxWHITE);
	companyLocation->SetBackgroundColour(SIDEBAR_COLOUR);
	
	deadline = new wxStaticText(textcontentContainer, wxID_STATIC, "");
	deadline->SetFont(*resultContentFont);
	deadline->SetForegroundColour(*wxWHITE);
	deadline->SetBackgroundColour(SIDEBAR_COLOUR);
	

	wxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(panel, 2, wxEXPAND | wxALL, 8);
	wxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* infoSizer = new wxBoxSizer(wxHORIZONTAL);
	textSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

	
	panelSizer->Add(infoContainer);
	


	infoSizer->Add(textcontentContainer, 3, wxEXPAND | wxALL , 12);

	textSizer->Add(resultTitleText, 0, wxALL, 2);
	textSizer->Add(companyName, 0, wxALL, 2);
	textSizer->Add(companyLocation, 0,  wxALL, 2);
	textSizer->Add(deadline, 0,  wxALL, 2);
	textSizer->AddStretchSpacer();
	textSizer->Add(buttonContainer, 0, wxEXPAND | wxALL, 1);

	buttonSizer->Add(MoreDetails, 1, wxEXPAND | wxLEFT | wxRIGHT, 5);
	buttonSizer->Add(CompanyDetails, 1, wxEXPAND | wxRIGHT | wxLEFT,  5);


	this->SetSizerAndFit(mainSizer);
	panel->SetSizer(panelSizer);
	infoContainer->SetSizer(infoSizer);
	textcontentContainer->SetSizerAndFit(textSizer);
	buttonContainer->SetSizer(buttonSizer);


}

void InternshipCard::setData(std::string jobTitle, std::string jobLink, std::string companyTitle, std::string companyLink, std::string location, std::string image, std::string appdeadline)
{
	this->companyName->SetLabel(companyTitle);
	this->companyName->SetURL(companyLink);
	this->resultTitleText->SetLabel(jobTitle);
	this->resultTitleText->SetURL(jobLink);
	this->deadline->SetLabel(appdeadline);
	this->companyLocation->SetLabel(location);

	textSizer->Layout();
}

void InternshipCard::onButtonClick(wxCommandEvent& event, MeroJob &m)
{
	wxButton* button = (wxButton*)event.GetEventObject();
	if (button == MoreDetails->buttonText) {
		Internships::page = 2;
		States::jobName = resultTitleText->GetLabelText();
		m.RetrieveJobDetails(resultTitleText->GetURL().ToStdString().c_str());
		States::internships->Initialize();
		States::selectedPage = 1;
	}
	else if (button == CompanyDetails->buttonText) {
		Internships::page = 3;
		m.RetrieveCompanyDetails(companyName->GetURL().ToStdString().c_str());
		States::internships->Initialize();
		States::selectedPage = 1;
	
	}
}
