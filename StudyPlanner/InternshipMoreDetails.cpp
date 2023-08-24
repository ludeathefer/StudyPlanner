#include "InternshipMoreDetails.h"
#include "Assets.h"
#include "RoundedRectangle.h"
#include "InternshipSearch.h"
#include "RoundedButton.h"
#include "SimilarJobs.h"

InternshipMoreDetails::InternshipMoreDetails(wxPanel* parent) : wxPanel(parent)
{



}

void InternshipMoreDetails::Initialize(MeroJob &m)
{

	wxPanel* mainDetailPage = new wxPanel(this);
	mainDetailPage->SetForegroundColour(TEXT_THEME_COLOUR);
	mainDetailPage->SetBackgroundColour(THEME_COLOUR);
	RoundedRectangle* JobInfoContainer = new RoundedRectangle(mainDetailPage, wxSize(950, 400), SIDEBAR_COLOUR, THEME_COLOUR, 20);
	JobInfoContainer->SetForegroundColour(TEXT_THEME_COLOUR);


	RoundedButton* backButton = new RoundedButton(mainDetailPage, wxSize(180, 80), "Back", 1);


	wxFont* titleFont = new wxFont(28, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont* headingFont = new wxFont(18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MEDIUM);
	wxFont* bodyFont = new wxFont(13, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);


	JobInfoContainer->SetFont(*bodyFont);

	m.RetrieveJobDetails("https://merojob.com/software-engineer-laravel-reactjs-full-stack/");

	wxBoxSizer* IMDSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* JobsDetailSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* titleSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* MoreJobSizer = new wxBoxSizer(wxVERTICAL);
	wxGridSizer* JobInfoSizer = new wxGridSizer(2, 5, 5);

	wxStaticText* JobTitle = new wxStaticText(mainDetailPage, wxID_ANY, "Senior Software Engineer");
	JobTitle->SetFont(*titleFont);

	wxStaticText* SimilarJob = new wxStaticText(mainDetailPage, wxID_ANY, "Simiilar Jobs");
	SimilarJob->SetFont(*headingFont);

	wxStaticText* JobInfo = new wxStaticText(mainDetailPage, wxID_ANY, "Basic Job Information");
	JobInfo->SetFont(*headingFont);

	wxStaticText* JobCat = new wxStaticText(JobInfoContainer, wxID_ANY, "Job Category");
	JobCat->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* JobCatValue = new wxStaticText(JobInfoContainer, wxID_ANY, m.GetJobDetails().jobcat);
	JobCatValue->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* JobLevel = new wxStaticText(JobInfoContainer, wxID_ANY, "Job Level");
	JobLevel->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* JobLevelValue = new wxStaticText(JobInfoContainer, wxID_ANY, m.GetJobDetails().joblevel);
	JobLevelValue->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* EmpType = new wxStaticText(JobInfoContainer, wxID_ANY, "Employment Type");
	EmpType->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* EmpTypeValue = new wxStaticText(JobInfoContainer, wxID_ANY, m.GetJobDetails().emptype);
	EmpTypeValue->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* JobLocation = new wxStaticText(JobInfoContainer, wxID_ANY, "Job Location");
	JobLocation->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* JobLocationValue = new wxStaticText(JobInfoContainer, wxID_ANY, m.GetJobDetails().location);
	JobLocationValue->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* salaryText = new wxStaticText(JobInfoContainer, wxID_ANY, "Offerred Salary");
	salaryText->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* salaryValue = new wxStaticText(JobInfoContainer, wxID_ANY, m.GetJobDetails().salary);
	salaryValue->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* deadlineText = new wxStaticText(JobInfoContainer, wxID_ANY, "Deadline");
	deadlineText->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* deadlineValue = new wxStaticText(JobInfoContainer, wxID_ANY, m.GetJobDetails().deadline);
	deadlineValue->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* eduLevel = new wxStaticText(JobInfoContainer, wxID_ANY, "Education Level");
	eduLevel->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* eduLevelValue = new wxStaticText(JobInfoContainer, wxID_ANY, m.GetJobDetails().edulevel);
	eduLevelValue->SetBackgroundColour(SIDEBAR_COLOUR);

	wxStaticText* expLevel = new wxStaticText(JobInfoContainer, wxID_ANY, "Experience Level");
	expLevel->SetBackgroundColour(SIDEBAR_COLOUR);
		
	wxStaticText* expLevelValue = new wxStaticText(JobInfoContainer, wxID_ANY, m.GetJobDetails().explevel);
	expLevelValue->SetBackgroundColour(SIDEBAR_COLOUR);


	wxStaticText* jobDesc = new wxStaticText(mainDetailPage, wxID_ANY, "Job Description");
	jobDesc->SetFont(*headingFont);

	wxTextCtrl* jobDescField = new wxTextCtrl(mainDetailPage, wxID_ANY, m.GetJobDetails().jobDesc, wxDefaultPosition, wxSize(775, 376), wxTE_READONLY | wxTE_MULTILINE | wxNO_BORDER | wxTE_NO_VSCROLL);
	jobDescField->SetBackgroundColour(THEME_COLOUR);
	jobDescField->SetForegroundColour(TEXT_THEME_COLOUR);
	jobDescField->SetFont(*bodyFont);


	wxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(mainDetailPage, 1, wxEXPAND | wxTOP, 25);

	IMDSizer->Add(JobsDetailSizer, 3, wxEXPAND, 0);
	IMDSizer->Add(MoreJobSizer, 1, wxEXPAND, 0);

	JobsDetailSizer->AddSpacer(50);
	JobsDetailSizer->Add(titleSizer);
	titleSizer->Add(backButton, 0, wxLEFT, 25);
	titleSizer->Add(JobTitle, 0, wxLEFT, 25);
	JobsDetailSizer->Add(JobInfo, 0, wxALL, 25);
	JobsDetailSizer->Add(JobInfoContainer, 0, wxLEFT, 25);
	JobsDetailSizer->Add(jobDesc, 0, wxLEFT | wxTOP, 25);
	JobsDetailSizer->Add(jobDescField, 0, wxLEFT | wxTOP, 25);

	MoreJobSizer->AddSpacer(115);
	MoreJobSizer->Add(SimilarJob, 0, wxALL, 5);

	for (const JobCard& industrycard : m.GetJobDetails().similar_job_cards) {
		SimilarJobs* resultItem = new SimilarJobs(mainDetailPage);
		resultItem->setData(industrycard.name, industrycard.job_url, industrycard.company, industrycard.company_url, industrycard.deadline);
		MoreJobSizer->Add(resultItem, 0, wxTOP, 10);
	}

	JobInfoSizer->Add(JobCat, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(JobCatValue, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(JobLevel, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(JobLevelValue, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(EmpType, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(EmpTypeValue, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(JobLocation, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(JobLocationValue, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(salaryText, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(salaryValue, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(deadlineText, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(deadlineValue, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(eduLevel, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(eduLevelValue, 0, wxLEFT | wxTOP, 15);
	JobInfoSizer->Add(expLevel, 0, wxLEFT | wxTOP | wxBOTTOM, 15);
	JobInfoSizer->Add(expLevelValue, 0, wxLEFT | wxTOP | wxBOTTOM, 15);


	SetSizer(mainSizer);
	mainDetailPage->SetSizer(IMDSizer);
	JobInfoContainer->SetSizer(JobInfoSizer);
	Hide();
}
