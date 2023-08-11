#pragma once
#include "RoundedRectangle.h"
#include "wx/wx.h"
class InternshipCard : public RoundedRectangle
{
	wxString label;
	int imageId;
	int index;
	wxStaticText* resultTitleText;
	wxFont* resultTitleFont;
	wxFont* resultContentFont;

public:
	InternshipCard(wxWindow* parent);
};

