#include "InternshipCompanyDetails.h"
#include "Assets.h"
#include "RoundedButton.h"
#include "InternshipSearch.h"
InternshipCompany::InternshipCompany(wxPanel* parent ) : wxPanel(parent)
{

	
}

void InternshipCompany::Initialize(MeroJob& m)
{
	wxFont* titleFont = new wxFont(28, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont* headingFont = new wxFont(18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MEDIUM);
	wxFont* bodyFont = new wxFont(13, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);


	wxPanel* mainDetailPage = new wxPanel(this);
	mainDetailPage->SetForegroundColour(TEXT_THEME_COLOUR);
	mainDetailPage->SetBackgroundColour(THEME_COLOUR);

	auto searchResult = new wxScrolled<wxPanel>(mainDetailPage, wxID_ANY, wxDefaultPosition, wxSize(500, 500));
	searchResult->SetBackgroundColour(wxColor(84, 78, 111));
	searchResult->SetDoubleBuffered(true);

	RoundedButton* backButton = new RoundedButton(mainDetailPage, wxSize(180, 80), "Back", 1);

	RoundedRectangle* CompanyInfoContainer = new RoundedRectangle(mainDetailPage, wxSize(500, 150), SIDEBAR_COLOUR, THEME_COLOUR, 20);
	CompanyInfoContainer->SetForegroundColour(TEXT_THEME_COLOUR);

	CompanyInfoContainer->SetFont(*bodyFont);

	wxBoxSizer* ICDSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* titleSizer = new wxBoxSizer(wxHORIZONTAL);
	wxGridSizer* companyInfoSizer = new wxGridSizer(2, 5, 5);
	wxBoxSizer* resultSizer = new wxBoxSizer(wxHORIZONTAL);

	searchResult->SetScrollRate(10, 0);


	m.RetrieveCompanyDetails("https://merojob.com/employer/cedar-gate-services-pvt-ltd/");

	wxStaticText* companyTitle = new wxStaticText(mainDetailPage, wxID_ANY, "Cedar Gate Services");
	companyTitle->SetFont(*titleFont);

	wxStaticText* companyInfo = new wxStaticText(mainDetailPage, wxID_ANY, "Company Info");
	companyInfo->SetFont(*headingFont);

	wxStaticText* industry = new wxStaticText(CompanyInfoContainer, wxID_ANY, "Industry");
	industry->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* industryValue = new wxStaticText(CompanyInfoContainer, wxID_ANY, m.GetCompanyDetails().industry);
	industryValue->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* companySize = new wxStaticText(CompanyInfoContainer, wxID_ANY, "Company Size");
	companySize->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* companySizeValue = new wxStaticText(CompanyInfoContainer, wxID_ANY, m.GetCompanyDetails().companysize);
	companySizeValue->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* companyLocation = new wxStaticText(CompanyInfoContainer, wxID_ANY, "Location");
	companyLocation->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* companyLocationValue = new wxStaticText(CompanyInfoContainer, wxID_ANY, m.GetCompanyDetails().location);
	companyLocationValue->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* jobPosted = new wxStaticText(mainDetailPage, wxID_ANY, "Job Posted by this Company");
	jobPosted->SetFont(*headingFont);


	wxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(mainDetailPage, 1, wxEXPAND | wxTOP, 25);
	ICDSizer->AddSpacer(50);
	ICDSizer->Add(titleSizer);
	titleSizer->Add(backButton, 0, wxLEFT, 25);
	titleSizer->Add(companyTitle, 0, wxLEFT, 25);
	ICDSizer->Add(companyInfo, 0, wxLEFT | wxTOP, 25);
	ICDSizer->Add(CompanyInfoContainer, 0, wxLEFT | wxTOP, 25);
	ICDSizer->Add(jobPosted, 0, wxLEFT | wxTOP, 25);
	ICDSizer->Add(searchResult, 1, wxEXPAND | wxLEFT | wxTOP, 25);


	companyInfoSizer->Add(industry, 0, wxLEFT | wxTOP, 15);
	companyInfoSizer->Add(industryValue, 0, wxLEFT | wxTOP, 15);
	companyInfoSizer->Add(companySize, 0, wxLEFT | wxTOP, 15);
	companyInfoSizer->Add(companySizeValue, 0, wxLEFT | wxTOP, 15);
	companyInfoSizer->Add(companyLocation, 0, wxLEFT | wxTOP, 15);
	companyInfoSizer->Add(companyLocationValue, 0, wxLEFT | wxTOP, 15);

	int i = 0;
	for (const JobCard& industrycard : m.GetCompanyDetails().companyjob_cards) {
		companyItem[i] = new InternshipCard(searchResult);
		companyItem[i]->setData(industrycard.name,
			"https://merojob.com" + industrycard.job_url, industrycard.company, "https://merojob.com" + industrycard.company_url,
			industrycard.location, industrycard.image, industrycard.deadline);
		resultSizer->Add(companyItem[i], 0, wxALL, 20);
		i++;
	}


	SetSizer(mainSizer);
	mainDetailPage->SetSizer(ICDSizer);
	mainSizer->Layout();
	ICDSizer->Layout();
	CompanyInfoContainer->SetSizer(companyInfoSizer);
	searchResult->SetSizer(resultSizer);
	Hide();
}
