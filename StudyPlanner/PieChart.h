#pragma once
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <cmath>

class PieChart : public wxPanel
{
private:
	int r;
	wxColour bg;
	std::vector<float> data;
public:
	PieChart(wxWindow* parent, int r, wxColour bg, std::vector<float> data);
	virtual void OnPaint(wxPaintEvent& evt);
};