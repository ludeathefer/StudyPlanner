#include "SidebarMenuItem.h"
#include "SidebarMenu.h"
#include "States.h"
#include "Mainframe.h"

SidebarMenuItem::SidebarMenuItem(wxWindow* parent, int _index, wxString _label, int _imageId) : index(_index), label(_label), imageId(_imageId), wxPanel(parent)
{
	itemTitleText = new wxStaticText(this, wxID_STATIC, States::minimizedSidebar ? wxT("") : label);
	itemTitleFont = new wxFont(16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, States::selectedWindow == index ? wxFONTWEIGHT_NORMAL : wxFONTWEIGHT_LIGHT);
	sidebarMenuItemSizer = new wxBoxSizer(wxHORIZONTAL);
};

void SidebarMenuItem::OnClick(wxMouseEvent& evt)
{
	if (States::selectedWindow == index) return;
	States::selectedWindow = index;
	States::mainframe->ChangePage();
	SidebarMenuItem::OnClickStatic();
	SetBackgroundColour(wxColour(83, 80, 96));
	Refresh();
	States::sidebarMenu->Refresh();
}

void SidebarMenuItem::OnClickStatic() {
	for (SidebarMenuItem* item : SidebarMenu::items) {
		item->SetBackgroundColour(wxColour(44, 40, 59));
		item->Refresh();
	};
};

void SidebarMenuItem::SizeChange() {
	for (SidebarMenuItem* item : SidebarMenu::items) {
		item->itemTitleText->SetLabelText(States::minimizedSidebar ? wxT("") : item->label);
		item->sidebarMenuItemSizer->GetItem(size_t(0))->SetBorder(States::minimizedSidebar ? 25 : 50);
		item->sidebarMenuItemSizer->GetItem(size_t(1))->SetBorder(States::minimizedSidebar ? 0 : 20);
		item->SetSizerAndFit(item->sidebarMenuItemSizer);
	};
};

void SidebarMenuItem::Initialize()
{
	SetBackgroundColour(States::selectedWindow == index ? wxColour(83, 80, 96) : wxColour(44, 40, 59));
	itemTitleText->SetFont(*itemTitleFont);
	itemTitleText->SetForegroundColour(wxColour(233, 233, 233));

	wxPNGHandler* handler = new wxPNGHandler();
	wxImage::AddHandler(handler);
	wxStaticBitmap* titleImage = new wxStaticBitmap(this, wxID_ANY, States::LoadPNGFromResource(imageId, "PNG"), wxDefaultPosition, wxSize(30, 30));

	sidebarMenuItemSizer->Add(titleImage, 0, wxALIGN_CENTER_VERTICAL | wxLEFT , 25);
	sidebarMenuItemSizer->Add(itemTitleText, 1, wxALIGN_CENTER_VERTICAL | wxLEFT, 0);
	sidebarMenuItemSizer->SetMinSize(wxSize(0, 60));
	SetSizerAndFit(sidebarMenuItemSizer);

	Bind(wxEVT_LEFT_DOWN, &SidebarMenuItem::OnClick, this);
	itemTitleText->Bind(wxEVT_LEFT_DOWN, &SidebarMenuItem::OnClick, this);
	titleImage->Bind(wxEVT_LEFT_DOWN, &SidebarMenuItem::OnClick, this);
	SetCursor(wxCURSOR_HAND);
};
