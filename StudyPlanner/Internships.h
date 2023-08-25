#pragma once
#include <wx/wx.h>
#include "InternshipMoreDetails.h"
#include "InternshipSearch.h"
#include "InternshipCompanyDetails.h"


class Internships : public wxPanel
{	
public:
	static int page;
	wxBoxSizer* sizerMain;
	InternshipMoreDetails* IMD;
	InternshipSearch* IS;
	InternshipCompany* ICD;
	MeroJob m;
	Internships(wxWindow* parent);
	void Initialize();
};

