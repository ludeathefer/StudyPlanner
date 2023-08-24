#pragma once
#include "RoundedButton.h"
#include "wx/wx.h"
#include <wx/hyperlink.h>


class SimilarJobs : public RoundedRectangle
{
private:
	wxHyperlinkCtrl* resultTitleText;
	wxFont* resultTitleFont;
	wxFont* resultContentFont;
	wxHyperlinkCtrl* companyName;
	wxStaticText* deadline;
	wxBoxSizer* textSizer;



public:
	SimilarJobs(wxWindow* parent);

	void setData(std::string jobTitle = "N/A", std::string jobLink = "N/A",
		std::string companyTitle = "N/A", std::string companyLink = "N/A",
										std::string appdeadline = "N/A");

};

