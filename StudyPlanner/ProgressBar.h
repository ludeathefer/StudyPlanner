#pragma once
#include "RoundedRectangle.h"

class ProgressBar : public RoundedRectangle
{
private:
	void OnPaint(wxPaintEvent& evt);
	float progress;
public:
	ProgressBar(wxWindow* parent, wxSize size, wxColour color, wxColour bg, int r, float progress);
};

