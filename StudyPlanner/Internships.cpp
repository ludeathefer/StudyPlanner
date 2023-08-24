#include "Internships.h"
#include "Assets.h"
#include "InternshipSearch.h"
#include "InternshipMoreDetails.h"
#include "States.h"
#include "InternshipCompanyDetails.h"

int Internships::page = 0;
	
Internships::Internships(wxWindow* parent) : wxPanel(parent)
{
	States::internships = this;
	sizerMain = new wxBoxSizer(wxHORIZONTAL);
	IS = new InternshipSearch(this);
	IMD = new InternshipMoreDetails(this);
	ICD = new InternshipCompany(this, m);
	
	;


	this->SetSizer(sizerMain);	
	Hide();
	
}

void Internships::Initialize()
{
	switch (page) {
	case 0:
		sizerMain->Clear();
		IS->Initialize(m);
		sizerMain->Add(IS, 1, wxEXPAND, 0);
		IS->Show();
		break;
	case 1:
		sizerMain->Remove(0);
		IS->Initialize(m);
		sizerMain->Add(IS, 1, wxEXPAND, 0);
		IS->Show();
		IMD->Hide();
		ICD->Hide();
		sizerMain->Layout();
		break;
	case 2:
		sizerMain->Remove(0);
		IMD->Initialize(m);
		sizerMain->Add(IMD, 1, wxEXPAND| wxTOP, 0);
		IS->Hide();
		ICD->Hide();
		IMD->Show();
		sizerMain->Layout();
		
		break;
	case 3:
		sizerMain->Remove(0);
		ICD->Initialize();
		sizerMain->Add(ICD, 1, wxEXPAND, 0);
		IS->Hide();
		ICD->Show();
		sizerMain->Layout();
		break;
	}
}

