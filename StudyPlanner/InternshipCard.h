#pragma once
#include "RoundedRectangle.h"
#include "wx/wx.h"
#include <wx/hyperlink.h>
#include "RoundedButton.h"
#include "Assignment.h"

class InternshipCard : public RoundedRectangle
{
private:
	wxString label;
	wxHyperlinkCtrl* resultTitleText;
	wxFont* resultTitleFont;
	wxFont* resultContentFont;
	wxHyperlinkCtrl* companyName;
	wxStaticText* companyLocation;
	wxStaticText* deadline;
	wxBoxSizer* textSizer;



public:

	enum {
		ID_MORE_DETAILS = 1,
		ID_COMPANY_DETAILS = 2
	};

	InternshipCard(wxWindow* parent);
	RoundedButton* MoreDetails;
	RoundedButton* CompanyDetails;
	void setData(std::string jobTitle = "N/A", std::string jobLink = "N/A",
		std::string companyTitle = "N/A", std::string companyLink = "N/A",
		std::string location = "N/A", std::string image = "N/A", std::string appdeadline = "N/A");
	void onButtonClick(wxCommandEvent& event);
};

