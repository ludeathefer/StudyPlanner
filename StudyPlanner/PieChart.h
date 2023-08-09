#pragma once
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <cmath>
#include "RoundedRectangle.h"

class PieChart : public wxPanel
{
private:
	int r;
	std::vector<float> data;
	std::vector<wxString> dataLabel;
	std::vector<wxColour> colors;
	RoundedRectangle* parent;
	wxString label;
	void OnPaint(wxPaintEvent& evt);
public:
	PieChart(RoundedRectangle* parent, std::vector<float> data, std::vector<wxString> dataLabel, wxString label);
	void AddLabel();
};