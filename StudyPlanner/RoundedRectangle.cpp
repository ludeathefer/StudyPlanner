#include "RoundedRectangle.h"

RoundedRectangle::RoundedRectangle(wxWindow* parent, wxSize size, wxColour _color, wxColour _bg, int _r) : wxPanel(parent, wxID_ANY, wxDefaultPosition, size), color(_color), r(_r), bg(_bg)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	Bind(wxEVT_PAINT, &RoundedRectangle::OnPaint, this);
};

void RoundedRectangle::OnPaint(wxPaintEvent&)
{
	SetBackgroundColour(bg);
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();
	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
	wxRect customRect = GetRect();
	if (gc) {
		gc->SetBrush(color);
		gc->DrawRoundedRectangle(0, 0, customRect.width, customRect.height, r);
	};
};
