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
	std::vector<int> dataX;
	std::vector<double> dataY;
	std::vector<wxString>* month;
	wxString label;
	void OnPaint(wxPaintEvent& evt);
public:
	LineGraph(RoundedRectangle* parent, std::vector<int> dataX, std::vector<double> dataY, wxString label, bool oddSem = true);
	void AddLabel();
};

