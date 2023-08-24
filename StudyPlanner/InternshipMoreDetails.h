#pragma once
#include <wx/wx.h>
#include "MeroJob.h"


class InternshipMoreDetails : public wxPanel
{
public:
	InternshipMoreDetails(wxPanel*);
	void Initialize(MeroJob &m);

};

