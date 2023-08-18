#include "States.h"
#include "Sidebar.h"
#include "SidebarMenu.h"

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
	titleSizer->Layout();
	titlePanel->SetSizerAndFit(titleSizer);
	delete sidebarMenu;
	sidebarMenu = new SidebarMenu(this);
	sidebarMenu->Initialize();
	sidebarSizer->Add(sidebarMenu, 1, !States::minimizedSidebar ? wxLEFT : wxALIGN_CENTER_HORIZONTAL, 40);
	sidebarSizer->Layout();
	States::mainframe->ShowSidebar();
};

void Sidebar::Initialize()
{
	SetBackgroundColour(wxColour(44, 41, 59));
	titlePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	wxFont* titleFont = new wxFont(20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	titleText = new wxStaticText(titlePanel, wxID_STATIC, States::minimizedSidebar ? wxT("") : wxT("Study Planner"));
	titleText->SetFont(*titleFont);
	titleText->SetForegroundColour(wxColour(233, 233, 233));

	wxPNGHandler* handler = new wxPNGHandler();
	wxImage::AddHandler(handler);
	wxStaticBitmap* titleImage = new wxStaticBitmap(titlePanel, wxID_ANY, wxBitmap(wxT("C:/Games/StudyPlanner-main/StudyPlanner/assets/img/logoImg.png"), wxBITMAP_TYPE_PNG), wxDefaultPosition);

	titleSizer->Add(titleText, 0, wxALIGN_BOTTOM | wxRIGHT, 15);
	titleSizer->Add(titleImage, 0, wxALIGN_BOTTOM | wxBOTTOM, 5);
	titlePanel->SetSizerAndFit(titleSizer);
	titlePanel->Bind(wxEVT_LEFT_DOWN, &Sidebar::OnClick, this);
	titleText->Bind(wxEVT_LEFT_DOWN, &Sidebar::OnClick, this);
	titleImage->Bind(wxEVT_LEFT_DOWN, &Sidebar::OnClick, this);

	sidebarMenu = new SidebarMenu(this);
	sidebarMenu->Initialize();

	sidebarSizer->Add(titlePanel, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 60);
	sidebarSizer->Add(sidebarMenu, 1, !States::minimizedSidebar ? wxLEFT : wxALIGN_CENTER_HORIZONTAL, 40);
	SetSizer(sidebarSizer);
};
