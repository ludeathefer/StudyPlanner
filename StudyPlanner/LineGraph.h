#pragma once

#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

class LineGraph : public wxPanel
{
private:
	wxColour bg;
	wxColour color;
	std::vector<float> dataX;
	std::vector<float> dataY;
	float xScale;
	float yScale;
	void OnPaint(wxPaintEvent& evt);
public:
	LineGraph(wxWindow* parent, wxSize size, wxColour color, wxColour bg, std::vector<float> dataX, std::vector<float> dataY, float xScale, float yScale);
};

