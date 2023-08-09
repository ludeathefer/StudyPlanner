#pragma once
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include "RoundedRectangle.h"

class LineGraph : public wxPanel
{
private:
	RoundedRectangle* parent;
	wxColour bg;
	wxColour color;
	std::vector<float> dataX;
	std::vector<float> dataY;
	wxString label;
	void OnPaint(wxPaintEvent& evt);
public:
	LineGraph(RoundedRectangle* parent, std::vector<float> dataX, std::vector<float> dataY, wxString label);
	void AddLabel();
};

