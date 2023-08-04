#pragma once
#include <wx/wx.h>

class Titlebar : public wxPanel
{
	void OnPaint(wxPaintEvent&);
	void Close(wxMouseEvent&);
	bool isCloseHovered;
public:
	Titlebar(wxWindow* parent);
	void Initialize();
		
};

