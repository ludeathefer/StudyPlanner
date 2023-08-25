#pragma once
#include "RoundedRectangle.h"
class RoundedButton : public RoundedRectangle
{
private:
	wxBoxSizer* sizer2;
	wxBoxSizer* sizer;
public:
	RoundedButton(wxWindow* parent, wxSize buttonSize, std::string label, int a);
	wxButton* buttonText;
};

