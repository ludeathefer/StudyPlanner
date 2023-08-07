#include "CustomPanel.h"
#include "Assets.h"

CustomPanel::CustomPanel(wxWindow* parent, wxPoint pos, wxSize size, wxBrush _color, int _r, wxColour _bg) : wxPanel(parent, wxID_ANY, pos, size), r(_r), bg(_bg), color(_color)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	Bind(wxEVT_PAINT, &CustomPanel::OnPaint, this);
};

void CustomPanel::OnPaint(wxPaintEvent& evt)
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

