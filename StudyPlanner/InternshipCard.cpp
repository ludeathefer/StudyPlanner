#include "InternshipCard.h"
#include "wx/wx.h"
#include <wx/hyperlink.h>
#include "Assets.h"

InternshipCard::InternshipCard(wxWindow* parent, std::string jobTitle, std::string jobLink, std::string companyTitle, std::string companyLink, std::string location, std::string image, std::string appdeadline) : RoundedRectangle(parent, wxSize(425, 250), SIDEBAR_COLOUR, THEME_COLOUR, 30)
{
	
	auto panel = new RoundedRectangle(this, wxSize(400, 225), SIDEBAR_COLOUR, THEME_COLOUR, 30);
	panel->SetBackgroundColour(SIDEBAR_COLOUR);
	wxPanel* infoContainer = new wxPanel(panel, wxID_ANY, wxDefaultPosition, wxSize(390, 200));
	infoContainer->SetBackgroundColour(SIDEBAR_COLOUR);
	wxPanel* textcontentContainer = new wxPanel(infoContainer);
	textcontentContainer->SetBackgroundColour(SIDEBAR_COLOUR);
	RoundedRectangle* imageContainer = new RoundedRectangle(infoContainer, wxSize(120, 120), *wxWHITE, SIDEBAR_COLOUR, 20);



	resultTitleFont = new wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	resultContentFont = new wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT);


	resultTitleText = new wxHyperlinkCtrl(textcontentContainer, wxID_STATIC, jobTitle, jobLink);
	resultTitleText->SetFont(*resultTitleFont);
	resultTitleText->SetForegroundColour(*wxWHITE);
	resultTitleText->SetBackgroundColour(SIDEBAR_COLOUR);

	wxHyperlinkCtrl* companyName = new wxHyperlinkCtrl(textcontentContainer, wxID_STATIC, companyTitle, companyLink);
	companyName->SetFont(*resultContentFont);
	companyName->SetForegroundColour(*wxWHITE);
	companyName->SetBackgroundColour(SIDEBAR_COLOUR);
	
	wxStaticText* companyLocation = new wxStaticText(textcontentContainer, wxID_STATIC, location);
	companyLocation->SetFont(*resultContentFont);
	companyLocation->SetForegroundColour(*wxWHITE);
	companyLocation->SetBackgroundColour(SIDEBAR_COLOUR);
	
	wxStaticText* deadline = new wxStaticText(textcontentContainer, wxID_STATIC, appdeadline);
	deadline->SetFont(*resultContentFont);
	deadline->SetForegroundColour(*wxWHITE);
	deadline->SetBackgroundColour(SIDEBAR_COLOUR);
	

	wxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(panel, 2, wxEXPAND | wxALL, 8);
	wxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* infoSizer = new wxBoxSizer(wxHORIZONTAL);
	wxSizer* textSizer = new wxBoxSizer(wxVERTICAL);

	panelSizer->AddStretchSpacer();
	panelSizer->Add(infoContainer);
	panelSizer->AddStretchSpacer();

	infoSizer->Add(imageContainer, 2, wxEXPAND | wxALL, 5);
	infoSizer->Add(textcontentContainer, 3, wxEXPAND | wxALL, 5);

	textSizer->Add(resultTitleText, 1, wxEXPAND | wxALL, 5);
	textSizer->Add(companyName, 1, wxEXPAND | wxALL, 5);
	textSizer->Add(companyLocation, 1, wxEXPAND | wxALL, 5);
	textSizer->Add(deadline, 1, wxEXPAND | wxALL, 5);

	this->SetSizerAndFit(mainSizer);
	panel->SetSizer(panelSizer);
	infoContainer->SetSizer(infoSizer);
	textcontentContainer->SetSizer(textSizer);


}
