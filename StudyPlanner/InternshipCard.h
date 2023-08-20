#pragma once
#include "RoundedRectangle.h"
#include "wx/wx.h"
#include <wx/hyperlink.h>
class InternshipCard : public RoundedRectangle
{
	wxString label;
	wxHyperlinkCtrl* resultTitleText;
	wxFont* resultTitleFont;
	wxFont* resultContentFont;

public:
	InternshipCard(wxWindow* parent, std::string jobTitle = "N/A", std::string jobLink = "N/A",
								std::string companyTitle = "N/A", std::string companyLink= "N/A",
			std::string location = "N/A", std::string image = "N/A", std::string appdeadline = "N/A");
};

