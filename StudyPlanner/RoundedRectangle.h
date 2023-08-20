#pragma once
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

class RoundedRectangle : public wxPanel
{
private:
public:
	RoundedRectangle(wxWindow* parent, wxSize size, wxColour color, wxColour bg, int r);
	void OnPaint(wxPaintEvent& evt);
	wxColour bg;
	wxColour color;
	int r;
};