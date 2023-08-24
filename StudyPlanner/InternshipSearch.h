#pragma once
#include <wx/wx.h>
#include "MeroJob.h"
#include "InternshipCard.h"


class InternshipSearch : public wxPanel
{
	wxScrolled<wxPanel>* searchResult;
	wxSizer* resultSizer;
	wxSizer* panelSizer;
	wxSizer* mainSizer;
	wxPanel* mainSearchPage;
	InternshipCard** resultItem = new InternshipCard * [6];

public:
	InternshipSearch(wxPanel*);
	void Initialize(MeroJob& mero);
	void OnSearchButton(wxCommandEvent& event, MeroJob &m);
	
	void LoadSearchResults(const std::vector<JobCard>& industrycards, MeroJob &m);

};

