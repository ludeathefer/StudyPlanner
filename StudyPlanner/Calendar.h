#pragma once
#include <wx/wx.h>

class Calendar : public wxPanel
{
private:
	typedef std::vector<wxPanel*> CPanelList;

	void AddSavedTasks();
	void AddSavedTasks(int pra);
	void onCalendarText(wxMouseEvent& evt, int pra);

	wxCheckListBox* todocheckListBox;
	wxCheckListBox* checkListBox;
	wxButton** calendardateText = new wxButton* [35];
<<<<<<< Updated upstream
	wxStaticText* engdateInfo;
=======
	
	wxMenu contextMenu;
	void BuildContextMenu();
	void onContextMenuEvent(wxContextMenuEvent&);
>>>>>>> Stashed changes

public:
	Calendar(wxWindow* parent);
	~Calendar();
	void Initialize();
	void SidebarChange();
};

