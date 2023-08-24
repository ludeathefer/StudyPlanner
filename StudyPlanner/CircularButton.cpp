#include "CircularButton.h" // include the header file where the function is declared

CircularButton(wxWindow* parent, wxWindowID id, const wxString& label)
    : wxButton(parent, id, label) {}

void CircularButton::DoDraw(wxControlRenderer* renderer) override
{
    // your implementation here
}