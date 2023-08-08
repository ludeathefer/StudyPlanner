#include "PieChart.h"

PieChart::PieChart(wxWindow* parent, int _r, wxColour _bg, std::vector<float> _data) : wxPanel(), r(_r), bg(_bg), data(_data)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	Create(parent, wxID_ANY,wxDefaultPosition, wxSize(2*r+1, 2*r+1));
	Bind(wxEVT_PAINT, &PieChart::OnPaint, this);
};

void PieChart::OnPaint(wxPaintEvent&)
{
	SetBackgroundColour(bg);
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();
	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
	float total = 0;
	for (float value : data) total += value;
	double startAngle = 0;
	wxPoint2DDouble centrePoint = wxPoint2DDouble(r, r);
	wxPoint2DDouble circumPoint = wxPoint2DDouble(2*r, r);
	srand(time(0));
	if (gc) {
		for (double value : data)
		{
			double sweepAngle = value / total * 2 * M_PI;
			wxColour randomColour = wxColour(rand() % 256, rand() % 256, rand() % 256);
			gc->SetPen(randomColour);
			gc->SetBrush(wxBrush(randomColour));
			wxGraphicsPath path = gc->CreatePath();
			path.MoveToPoint(centrePoint);
			path.AddLineToPoint(circumPoint);
			path.AddArc(centrePoint, r, startAngle, startAngle+sweepAngle, true);
			circumPoint = path.GetCurrentPoint();
			path.MoveToPoint(centrePoint);
			startAngle += sweepAngle;
			gc->StrokePath(path);
			gc->FillPath(path);
		};
	};
};
