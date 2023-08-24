#pragma once
#include <wx/wx.h>
#include "InternshipCard.h"
#include "MeroJob.h"

class InternshipCompany : public wxPanel
{
	InternshipCard** companyItem = new InternshipCard * [5];

public:
	InternshipCompany(wxPanel*);
	void Initialize(MeroJob& m);

};

