#include "States.h"
#include "Sidebar.h"
#include "SidebarMenu.h"
#include "SidebarMenuItem.h"
#include "Assets.h"

Sidebar::Sidebar(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition)
{

}

wxBoxSizer* titleSizer = new wxBoxSizer(wxHORIZONTAL);
wxStaticText* titleText;
wxBoxSizer* sidebarSizer = new wxBoxSizer(wxVERTICAL);
SidebarMenu* sidebarMenu;
wxPanel* titlePanel;

void Sidebar::OnClick(wxMouseEvent& evt) {
	States::minimizedSidebar = !States::minimizedSidebar;
	titleText->SetLabelText(States::minimizedSidebar ? wxT("") : wxT("Study Planner"));
	titleSizer->GetItem(size_t(0))->SetBorder(States::minimizedSidebar ? 0 : 10);
	titlePanel->SetSizerAndFit(titleSizer);
	SidebarMenuItem::SizeChange();
	States::sidebarMenu->SetSizerAndFit(sidebarMenu->sidebarMenuSizer);
	States::mainframe->ShowSidebar();
};

void Sidebar::Initialize()
{
	SetBackgroundColour(SIDEBAR_COLOUR);
	titlePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	wxFont* titleFont = new wxFont(20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	titleText = new wxStaticText(titlePanel, wxID_STATIC, States::minimizedSidebar ? wxT("") : wxT("Study Planner"));
	titleText->SetFont(*titleFont);
	titleText->SetForegroundColour(TEXT_THEME_COLOUR);

	wxPNGHandler* handler = new wxPNGHandler();
	wxImage::AddHandler(handler);
	wxStaticBitmap* titleImage = new wxStaticBitmap(titlePanel, wxID_ANY, States::LoadPNGFromResource(LOGO_PNG, "PNG"), wxDefaultPosition);

	titleSizer->Add(titleText, 0, wxALIGN_BOTTOM | wxRIGHT, States::minimizedSidebar ? 0 : 10);
	titleSizer->Add(titleImage, 0, wxALIGN_BOTTOM | wxBOTTOM, 5);
	titlePanel->SetSizerAndFit(titleSizer);

	titlePanel->SetCursor(wxCursor(wxCURSOR_HAND));
	titlePanel->Bind(wxEVT_LEFT_DOWN, &Sidebar::OnClick, this);
	titleText->Bind(wxEVT_LEFT_DOWN, &Sidebar::OnClick, this);
	titleImage->Bind(wxEVT_LEFT_DOWN, &Sidebar::OnClick, this);

	sidebarMenu = new SidebarMenu(this);
	sidebarMenu->Initialize();

	sidebarSizer->Add(titlePanel, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP , 90);
	sidebarSizer->Add(sidebarMenu, 1, wxTOP | wxEXPAND, 60);
	SetSizerAndFit(sidebarSizer);
};
