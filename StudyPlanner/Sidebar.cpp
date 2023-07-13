#include "Sidebar.h"
#include "SidebarMenu.h"

Sidebar::Sidebar(wxWindow* parent, wxSize size) : minimized(false), wxPanel(parent, wxID_ANY, wxDefaultPosition, size)
{

}

void Sidebar::Initialize()
{
	SetBackgroundColour(wxColour(44, 41, 59));
	wxBoxSizer* titleSizer = new wxBoxSizer(wxHORIZONTAL);
	wxPanel* titlePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	wxStaticText* titleText = new wxStaticText(titlePanel, wxID_STATIC, wxT("Study Planner"));
	wxFont* titleFont = new wxFont(20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	titleText->SetFont(*titleFont);
	titleText->SetForegroundColour(wxColour(233, 233, 233));

	wxPNGHandler* handler = new wxPNGHandler();
	wxImage::AddHandler(handler);
	wxStaticBitmap* titleImage = new wxStaticBitmap(titlePanel, wxID_ANY, wxBitmap(wxT("assets/img/logoImg.png"), wxBITMAP_TYPE_PNG), wxDefaultPosition);

	titleSizer->Add(titleText, 0, wxALIGN_BOTTOM | wxRIGHT, 15);
	titleSizer->Add(titleImage, 0, wxALIGN_BOTTOM | wxBOTTOM, 5);
	titlePanel->SetSizerAndFit(titleSizer);

	SidebarMenu* sidebarMenu = new SidebarMenu(this);
	sidebarMenu->Initialize();

	wxBoxSizer* sidebarSizer = new wxBoxSizer(wxVERTICAL);
	sidebarSizer->Add(titlePanel, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 60);
	sidebarSizer->Add(sidebarMenu, 1, wxLEFT, 30);
	SetSizer(sidebarSizer);
}