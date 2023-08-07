#pragma once
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include<wx/graphics.h>

class CustomPanel : public wxPanel
{
private:
	void OnPaint(wxPaintEvent& evt);
	int r;
	wxColour bg;
	wxBrush color;
public:
	CustomPanel(wxWindow* parent, wxPoint pos, wxSize size, wxBrush color, int r, wxColour bg);
};

