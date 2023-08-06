#pragma once
#include <wx/wx.h>

class Titlebar : public wxPanel
{
	void OnPaint(wxPaintEvent&);
	void HandleControls(wxMouseEvent&);
	void HandleControlsHover(wxMouseEvent&);
	void HandleControlsLeave(wxMouseEvent&);
	bool isCloseHovered;
	bool isMinimizeHovered;
public:
	Titlebar(wxWindow* parent);
	void Initialize();
};

