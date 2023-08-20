#include "ProgressBar.h"
#include "Assets.h"

ProgressBar::ProgressBar(wxWindow* parent, wxSize size, wxColour color, wxColour bg, int r, float _progress) : RoundedRectangle(parent, size, color, bg, r), progress(_progress/100)
{
	Bind(wxEVT_PAINT, &ProgressBar::OnPaint, this);
};

void ProgressBar::OnPaint(wxPaintEvent& evt)
{
	SetBackgroundColour(bg);
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();
	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
	wxRect customRect = GetRect();
	if (gc) {
		gc->SetBrush(color);
		gc->DrawRoundedRectangle(0, 0, customRect.width, customRect.height, r);
		gc->SetPen(FOCUS_COLOR);
		gc->SetBrush(FOCUS_COLOR);
		gc->DrawRoundedRectangle(-1, -1, customRect.width * progress + 1, customRect.height + 1, r);
	};
};
