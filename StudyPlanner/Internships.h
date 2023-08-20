#pragma once
#include <wx/wx.h>
#include "MeroJob.h"
#include "InternshipCard.h"

class Internships : public wxPanel
{
public:
	Internships(wxWindow* parent);
	void Initialize();
	void OnSearchButton(wxCommandEvent& event);
	MeroJob m;
	void LoadSearchResults(const std::vector<IndustryCard>& industrycards);
	wxScrolled<wxPanel>* searchResult;
	wxSizer* resultSizer;
	InternshipCard* resultItem[6];

};

