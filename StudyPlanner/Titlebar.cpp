#include "Titlebar.h"
#include "States.h"

Titlebar::Titlebar(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
}

wxRect* closeRect = new wxRect(wxGetDisplaySize().GetWidth() - 25, 0, 26, 26);

void Titlebar::Close(wxMouseEvent& click) {
    if (closeRect->Contains(click.GetPosition())) States::mainframe->Close();
};

void Titlebar::Initialize() {
    SetSize(wxSize(wxGetDisplaySize().GetWidth(), 25));
    SetBackgroundColour(wxColour(180, 180, 180));
    Bind(wxEVT_LEFT_UP, &Titlebar::Close, this);
    Bind(wxEVT_PAINT, &Titlebar::OnPaint, this);
}

void Titlebar::OnPaint(wxPaintEvent&) {
    wxPaintDC* dc = new wxPaintDC(this);
    wxFont* titleFont = new wxFont(10, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MAX);
    wxFont* controlFont = new wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MAX);
    dc->SetFont(*titleFont);
    dc->SetBrush(wxColour(64, 61, 79));
    dc->SetTextForeground(wxColour(180, 180, 180));
    dc->DrawRectangle(0, 0, wxGetDisplaySize().GetWidth(), 26);
    dc->DrawText("STUDY PLANNER", 10, 6);
    dc->SetFont(*controlFont);
    dc->SetPen(wxColour(64, 61, 79));
    dc->SetBrush(wxColour(120, 41, 59));
    dc->DrawRectangle(*closeRect);
    dc->DrawText("x", wxGetDisplaySize().GetWidth() - 15, 3);
}