#include "Titlebar.h"
#include "States.h"

Titlebar::Titlebar(wxWindow* parent) : wxPanel(parent, wxID_ANY), isCloseHovered(false), isMinimizeHovered(false) {

}

wxRect* closeRect = new wxRect(wxGetDisplaySize().GetWidth() - 36, 1, 36, 26);
wxRect* maximizeRect = new wxRect(wxGetDisplaySize().GetWidth() - 2 * 35, 1, 36, 26);
wxRect* minimizeRect = new wxRect(wxGetDisplaySize().GetWidth() - 3 * 35, 1, 36, 26);

void Titlebar::HandleControls(wxMouseEvent& click) {
    if (closeRect->Contains(click.GetPosition())) States::mainframe->Close();
    else if (minimizeRect->Contains(click.GetPosition())) States::mainframe->Iconize();
};


void Titlebar::HandleControlsHover(wxMouseEvent& hover) {
    if (closeRect->Contains(hover.GetPosition())) {
        SetCursor(wxCursor(wxCURSOR_HAND));
        Titlebar::isCloseHovered = true; 
        Refresh(); 
    }
    else if (minimizeRect->Contains(hover.GetPosition())) { 
        SetCursor(wxCursor(wxCURSOR_HAND));
        Titlebar::isMinimizeHovered = true; 
        Refresh(); 
    }
    else if (Titlebar::isCloseHovered || Titlebar::isMinimizeHovered) { 
        SetCursor(wxCursor(wxCURSOR_ARROW));
        Titlebar::isCloseHovered = false; 
        Titlebar::isMinimizeHovered = false; 
        Refresh(); 
    }
};

void Titlebar::HandleControlsLeave(wxMouseEvent& hover) {
    Titlebar::isCloseHovered = false; Titlebar::isMinimizeHovered = false; Refresh();
}


void Titlebar::Initialize() {
    SetDoubleBuffered(true);
    SetSize(wxSize(wxGetDisplaySize().GetWidth(), 25));
    SetBackgroundColour(wxColour(180, 180, 180));
    Bind(wxEVT_LEFT_UP, &Titlebar::HandleControls, this);
    Bind(wxEVT_MOTION, &Titlebar::HandleControlsHover, this);
    Bind(wxEVT_LEAVE_WINDOW, &Titlebar::HandleControlsLeave, this);
    Bind(wxEVT_PAINT, &Titlebar::OnPaint, this);
}

void Titlebar::OnPaint(wxPaintEvent&) {
    wxPaintDC* dc = new wxPaintDC(this);
    wxFont* titleFont = new wxFont(10, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MAX);
    dc->SetFont(*titleFont);
    dc->SetBrush(wxColour(64, 61, 79));
    dc->DrawRectangle(0, 0, wxGetDisplaySize().GetWidth(), 26);
    dc->SetTextForeground(wxColour(180, 180, 180));
    dc->DrawText("STUDY PLANNER", 10, 6);
    dc->SetPen(wxColour(64, 61, 79));
    dc->SetBrush(Titlebar::isCloseHovered ? wxColour(180, 41, 59) : wxColour(64, 61, 79));
    dc->DrawRectangle(*closeRect);
    dc->SetTextForeground(wxColour(200, 200, 200));
    dc->DrawText(wxT("❌"), wxGetDisplaySize().GetWidth() - 24, 7);
    dc->SetBrush(wxColour(64, 61, 79));
    dc->DrawRectangle(*maximizeRect);
    dc->SetTextForeground(wxColour(100, 100, 100));
    dc->DrawText(wxT("🗖"), wxGetDisplaySize().GetWidth() - 22 - 35, 6);
    dc->SetBrush(Titlebar::isMinimizeHovered ? wxColour(84, 61, 99) : wxColour(64, 61, 79));
    dc->DrawRectangle(*minimizeRect);
    dc->SetTextForeground(wxColour(180, 180, 180));
    dc->DrawText(wxT("-"), wxGetDisplaySize().GetWidth() - 22 - 2 * 35, 6);
}