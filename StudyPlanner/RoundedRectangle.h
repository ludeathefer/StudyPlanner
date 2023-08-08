#pragma once
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

class RoundedRectangle : public wxPanel
{
private:
	int r;
	void OnPaint(wxPaintEvent& evt);
public:
	RoundedRectangle(wxWindow* parent, wxSize size, wxColour color, wxColour bg, int r);
	wxColour bg;
	wxColour color;
};