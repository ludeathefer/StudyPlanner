#pragma once
#include "RoundedRectangle.h"
class RoundedButton : public RoundedRectangle
{
public:
	RoundedButton(wxWindow* parent, wxSize buttonSize, std::string label, int a);
	wxButton* buttonText;
};

