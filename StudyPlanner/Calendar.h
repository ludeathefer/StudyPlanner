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

public:
	Calendar(wxWindow* parent);
	~Calendar();
	void Initialize();
};

