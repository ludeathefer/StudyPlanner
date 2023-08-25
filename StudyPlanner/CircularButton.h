#include <wx/renderer.h> // include the header file for wxControlRenderer
#include <wx/wx.h>

class CircularButton : public wxButton
{
public:
    CircularButton(wxWindow* parent, wxWindowID id, const wxString& label)
        : wxButton(parent, id, label) {}

protected:
    // override the default drawing method
    virtual void DoDraw(wxControlRenderer* renderer) override;
};