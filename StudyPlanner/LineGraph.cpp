#include "LineGraph.h"

LineGraph::LineGraph(wxWindow* parent, wxSize size, wxColour _color, wxColour _bg, std::vector<float> _dataX, std::vector<float> _dataY, float _xScale, float _yScale) :
	wxPanel(parent, wxID_ANY, wxDefaultPosition, size), color(_color), bg(_bg), dataX(_dataX), dataY(_dataY), xScale(_xScale), yScale(_yScale)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	Bind(wxEVT_PAINT, &LineGraph::OnPaint, this);
};

void LineGraph::OnPaint(wxPaintEvent&)
{
	SetBackgroundColour(bg);
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();
	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
	if (gc)
	{

	};
};
