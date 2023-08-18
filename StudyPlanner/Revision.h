#pragma once
#include <wx/wx.h>

class Revision : public wxPanel
{
public:
	Revision(wxWindow* parent);
	void Initialize();

	void DisplayRevision();
	std::string FileName;
	std::string DisplaySubject;
	void BindEventHandlers(int f);

	wxCheckListBox* CheckListBox[7];
};

struct Revision_a {
	std::string item;
	bool done;
};

std::vector<Revision_a> LoadRevision(const std::string& filename);