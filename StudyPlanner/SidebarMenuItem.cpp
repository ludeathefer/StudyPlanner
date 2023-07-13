#include "SidebarMenuItem.h"

//wxBEGIN_EVENT_TABLE(SidebarMenuItem, wxPanel)
//EVT_COMMAND_LEFT_CLICK(wxID_ANY, SidebarMenuItem::OnClick)
//wxEND_EVENT_TABLE()

int SidebarMenuItem::selected = 0;

SidebarMenuItem::SidebarMenuItem(wxWindow* parent, int _index, wxString _label, wxString _imagePath) : index(_index), label(_label), imagePath(_imagePath), wxPanel(parent)
{

}

void SidebarMenuItem::OnClick(wxMouseEvent&)
{
	wxLogStatus("%d, %d", selected, index);
	if (selected != index) {
		selected = index;
	}
	wxLogStatus("%d, %d", selected, index);
	//selected == index ? SetBackgroundColour(wxColor(120, 120, 120)) : NULL;
	Refresh();
}

void SidebarMenuItem::OnEnter(wxMouseEvent&)
{
	SetBackgroundColour(wxColour(100, 100, 100));
	Refresh();
}

void SidebarMenuItem::OnExit(wxMouseEvent&)
{
	SetBackgroundColour(wxColour(44, 41, 59));
	Refresh();
}

void SidebarMenuItem::Initialize()
{
	wxRect rect = GetRect();
	wxStaticText* titleText = new wxStaticText(this, wxID_STATIC, label);
	wxFont* titleFont = new wxFont(16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	titleText->SetFont(*titleFont);
	titleText->SetForegroundColour(wxColour(233, 233, 233));

	wxPNGHandler* handler = new wxPNGHandler();
	wxImage::AddHandler(handler);
	wxStaticBitmap* titleImage = new wxStaticBitmap(this, wxID_ANY, wxBitmap(imagePath, wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(30, 30));

	wxBoxSizer* sidebarMenuItemSizer = new wxBoxSizer(wxHORIZONTAL);
	sidebarMenuItemSizer->Add(titleImage, 0, wxALIGN_CENTER_VERTICAL);
	sidebarMenuItemSizer->Add(titleText, 0, wxALIGN_BOTTOM | wxLEFT, 40);
	SetSizerAndFit(sidebarMenuItemSizer);

	//selected == index ? SetBackgroundColour(wxColor(120, 120, 120)) : NULL;

	Bind(wxEVT_LEFT_DOWN, &SidebarMenuItem::OnClick, this);
	titleText->Bind(wxEVT_LEFT_DOWN, &SidebarMenuItem::OnClick, this);
	titleImage->Bind(wxEVT_LEFT_DOWN, &SidebarMenuItem::OnClick, this);

	//Bind(wxEVT_ENTER_WINDOW, &SidebarMenuItem::OnEnter, this);
	//Bind(wxEVT_LEAVE_WINDOW, &SidebarMenuItem::OnExit, this);
}
